from aocd import get_data, submit
data = get_data(day = 18, year = 2021).splitlines()
data = '''[[[0,[5,8]],[[1,7],[9,6]]],[[4,[1,2]],[[1,4],2]]]
[[[5,[2,8]],4],[5,[[9,9],0]]]
[6,[[[6,2],[5,6]],[[7,6],[4,7]]]]
[[[6,[0,7]],[0,9]],[4,[9,[9,0]]]]
[[[7,[6,4]],[3,[1,3]]],[[[5,5],1],9]]
[[6,[[7,3],[3,2]]],[[[3,8],[5,7]],4]]
[[[[5,4],[7,7]],8],[[8,3],8]]
[[9,3],[[9,9],[6,[4,9]]]]
[[2,[[7,7],7]],[[5,8],[[9,3],[0,2]]]]
[[[[5,2],5],[8,[3,7]]],[[5,[7,5]],[4,4]]]'''.splitlines()

c = 0
graph = []
x = []



def add(a, b):
	res = [a, b]

	c = 0
	graph = []
	x = []
	createGraph(a, 0)

# def magnitude(a):

l = [eval(i) for i in data]
res = l[0]

for i in range(1, len(l)):
	res = add(res, l[i])

print(magnitude(res))
# submit(res, part = 'a', day = 18, year = 2021)
