def topKFrequent(nums, k):
    counter = {}
    out = []
    for element in nums:
        if element in counter:
            counter[element] += 1
        else:
            counter[element] = 1

    # urutkan dari frekuensi terbesar → terkecil
    sorted_counter = dict(sorted(counter.items(), key=lambda item: item[1], reverse=True))

    list_key = list(sorted_counter.keys())

    for i in range(k):
        out.append(list_key[i])
    return out


nums = [4, 1, -1, 2, -1, 2, 3]
print(topKFrequent(nums, 2))  # Output: [-1, 2]
