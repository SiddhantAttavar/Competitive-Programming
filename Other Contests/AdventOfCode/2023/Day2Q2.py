from aocd import get_data, submit
data = get_data(day = 2, year = 2023).splitlines()
# data = '''Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
# Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue
# Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red
# Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
# Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green'''.splitlines()

res = 0
for s in data:
	l = s.split()
	l[-1] += '\n'
	# print(l[-1])
	x = int(l[1][:-1])
	m = {'red': 0, 'blue': 0, 'green': 0}
	for i in range(2, len(l), 2):
		m[l[i + 1][:-1]] = max(m[l[i + 1][:-1]], int(l[i]))
	res += m['red'] * m['green'] * m['blue']

# print(res)
submit(res, part = 'b', day = 2, year = 2023)
