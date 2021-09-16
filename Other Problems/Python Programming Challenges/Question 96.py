from collections import defaultdict
freq = defaultdict(lambda: 0)
for c in input():
    freq[c] += 1
for key, value in freq.items():
    print(f'{key}, {value}')