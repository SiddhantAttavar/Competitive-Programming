#include <bits/stdc++.h>
using namespace std;
#define print(x) printf("%d\n", x);
#define printd(x) printf("%f\n", x);
#define println(...) printf(__VA_ARGS__); printf("\n");
#define range(i, n) for (int i = 0; i < n; i++)
#define reverseRange(i, n) for (int i = n - 1; i >= 0; i++)
#define stepRange(i, n, s) for (int i = 0; i < n; i += s)
#define len(a) (*(&a + 1) - a)

int main() {
	vector<int> array = {10, 50, 2, 36};
	make_heap(array.begin(), array.end());
	for (int i: array) {
		print(i);
	}

	array.push_back(30);
	push_heap(array.begin(), array.end());
	println("After pushing");
	for (int i: array) {
		print(i);
	}

	pop_heap(array.begin(), array.end());
	println("After popping");
	for (int i: array) {
		print(i);
	}

	sort_heap(array.begin(), array.end());
	println("After sorting");
	for (int i: array) {
		print(i);
	}

	if (is_heap(array.begin(), array.end())) {
		println("The vector is a heap");
	}
	else {
		println("The vector is not a heap");
	}

	vector<int>::iterator heapIterator = is_heap_until(array.begin(), array.end());
	for (vector<int>::iterator iterator = array.begin(); iterator != heapIterator; iterator++) {
		print(*iterator);
	}
}