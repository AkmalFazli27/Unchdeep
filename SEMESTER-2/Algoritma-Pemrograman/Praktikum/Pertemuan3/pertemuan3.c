#include <stdio.h>

int main() {
    int i, ans;
    ans = 0;
    for ( i = 0; i < 10; i++) {
        int j = 0;
        while (j < 5) {
            ans = ans + j;
        }
    }
    return 0;
}