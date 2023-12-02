from aocd import get_data, submit
data = get_data(day = 1, year = 2023).splitlines()
# data = '''1abc2
# pqr3stu8vwx
# a1b2c3d4e5f
# treb7uchet'''.splitlines()

res = 0
n = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine', 'ten']
for s in data:
	for i in range(len(s)):
		for j in range(0, 11):
			if s[i] == str(j) or s[i: i + len(n[j])] == n[j]:
				res += 10 * j
				break
		else:
			continue
		break
	
	for i in range(len(s) - 1, -1, -1):
		for j in range(0, 11):
			if s[i] == str(j) or s[i - len(n[j]) + 1: i + 1] == n[j]:
				res += j
				break
		else:
			continue
		break

# print(res)
submit(res, part = 'b', day = 1, year = 2023)
