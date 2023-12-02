from aocd import get_data, submit
data = get_data(day = 1, year = 2023).splitlines()
# data = '''1abc2
# pqr3stu8vwx
# a1b2c3d4e5f
# treb7uchet'''.splitlines()

res = 0
for s in data:
	for i in s:
		if i.isdigit():
			res += 10 * int(i)
			break
	for i in s[::-1]:
		if i.isdigit():
			res += int(i)
			break

# print(res)
submit(res, part = 'a', day = 1, year = 2023)
