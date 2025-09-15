import tkinter as tk
from tkinter import messagebox
from paho.mqtt import client as mqtt_client
import threading
import json
import random

BROKER = "test.mosquitto.org"  # bisa diganti localhost / IP broker
PORT = 1883
TOPIC_COMMAND = "simon/command"
TOPIC_STATUS = "simon/status"
CLIENT_ID = f"simon_gui_{random.randint(0,1000)}"


class SimonSaysGUI:
    """
    GUI permainan Simon Says dengan komunikasi MQTT ke ESP32.
    """

    def __init__(self, root, broker: str, port: int, client_id: str):
        self.root = root
        self.broker = broker
        self.port = port
        self.client_id = client_id
        self.client = None

        self.state = "LOBBY"
        self.score = 0

        # buat widget
        self._setup_widgets()

        # koneksi mqtt di thread terpisah
        t = threading.Thread(target=self._connect_mqtt, daemon=True)
        t.start()

    def _setup_widgets(self):
        self.root.title("Simon Says - MQTT GUI")

        frame = tk.Frame(self.root)
        frame.pack(pady=10)

        # tombol warna
        colors = ["green", "red", "yellow", "blue"]
        self.color_buttons = {}
        for i, color in enumerate(colors):
            btn = tk.Button(
                frame,
                text=color.capitalize(),
                bg=color,
                width=12,
                height=3,
                state="disabled",
                command=lambda c=color: self._handle_color_press(c),
            )
            r, c = divmod(i, 2)
            btn.grid(row=r, column=c, padx=5, pady=5)
            self.color_buttons[color] = btn

        # tombol Start
        self.start_btn = tk.Button(
            self.root, text="Start", width=10, command=self._handle_start_press
        )
        self.start_btn.pack(pady=10)

        # label status
        self.status_lbl = tk.Label(self.root, text="State: LOBBY | Score: 0", font=("Arial", 12))
        self.status_lbl.pack(pady=5)

    def _connect_mqtt(self) -> mqtt_client.Client:
        client = mqtt_client.Client(client_id=self.client_id, callback_api_version=4)
        client.on_connect = lambda c, u, f, rc: client.subscribe(TOPIC_STATUS)
        client.on_message = self._on_mqtt_message

        try:
            client.connect(self.broker, self.port)
        except Exception as e:
            print("Gagal konek ke broker:", e)
            return None

        self.client = client
        client.loop_forever()
        return client

    def _on_mqtt_message(self, client, userdata, msg):
        try:
            payload = msg.payload.decode()
            data = json.loads(payload)
        except Exception as e:
            print("Payload error:", e)
            return

        state = data.get("state", "LOBBY")
        score = data.get("score", 0)

        # update UI di main thread tkinter
        self.root.after(0, lambda: self.update_ui_state(state, score))

    def _publish_command(self, command: str):
        if self.client is None:
            print("MQTT belum siap")
            return
        payload = json.dumps({"command": command})
        self.client.publish(TOPIC_COMMAND, payload)

    def _handle_start_press(self):
        self._publish_command("start")

    def _handle_color_press(self, color: str):
        self._publish_command(color)

    def update_ui_state(self, state: str, score: int = 0):
        self.state = state
        self.score = score

        # update label
        self.status_lbl.config(text=f"State: {state} | Score: {score}")

        if state == "LOBBY":
            self.start_btn.config(state="normal")
            for b in self.color_buttons.values():
                b.config(state="disabled")

        elif state == "WAITING_FOR_INPUT":
            self.start_btn.config(state="disabled")
            for b in self.color_buttons.values():
                b.config(state="normal")

        elif state == "GAME_OVER":
            self.start_btn.config(state="normal")
            for b in self.color_buttons.values():
                b.config(state="disabled")
            messagebox.showinfo("Game Over", f"Skor akhir: {score}")


# --- Fungsi utama untuk menjalankan aplikasi ---
def main():
    root = tk.Tk()
    app = SimonSaysGUI(root, BROKER, PORT, CLIENT_ID)
    root.mainloop()


if __name__ == "__main__":
    main()
