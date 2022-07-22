n = int(input())
s = list(map(int, input().split()))
while True:
	for i in range(len(s) - 1):
		if s[i] == s[i + 1] and (i > 0 and s[i - 1] == s[i] + 3) or (i < len(s) - 2 and s[i + 2] == s[i] + 3):
			s.pop(i + 1)
			s[i] += 3
			n -= 1
			break
	else:
		for i in range(len(s) - 1):
			if s[i] == s[i + 1]:
				s.pop(i + 1)
				s[i] += 3
				n -= 1
				break
		else:
			break
print(max(s))
