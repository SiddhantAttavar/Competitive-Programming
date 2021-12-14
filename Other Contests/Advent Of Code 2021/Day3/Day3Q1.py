from aocd import get_data, submit
data = get_data(day = 3, year = 2021).splitlines()
# data = '''00100
# 11110
# 10110
# 10111
# 10101
# 01111
# 00111
# 11100
# 10000
# 11001
# 00010
# 01010'''.splitlines()

l = data
gamma = [0] * len(l[0])
epsilon = [0] * len(l[0])
for i in range(len(l[0])):
	zero = 0
	one = 0
	for j in range(len(l)):
		zero += l[j][i] == '0'
		one += l[j][i] == '1'
	if zero > one:
		gamma[i] = '0'
		epsilon[i] = '1'
	elif one > zero:
		gamma[i] = '1'
		epsilon[i] = '0'
	else:
		gamma[i] = '1'
		epsilon[i] = '0'
		print('Error')
finGamma = int(''.join(gamma), 2)
finEpsilon = int(''.join(epsilon), 2)

print(finGamma * finEpsilon)
# submit(finGamma * finEpsilon, part = 'a', day = 3, year = 2021)
