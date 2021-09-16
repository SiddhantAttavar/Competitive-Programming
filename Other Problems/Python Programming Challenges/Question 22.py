freq = {}
for word in input().split():
    freq[word] = freq.get(word, 0) + 1

for key, value in freq.items():
    print(f'{key}: {value}')