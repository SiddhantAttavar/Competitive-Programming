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
	list<int> linkedList;
	range(i, 10) {
		linkedList.push_front(i);
		linkedList.push_back(i * 2);
	}

	printf("List: ");
	for (int i: linkedList) {
		printf("%d ", i);
	}
	println("");

	linkedList.pop_front();
	linkedList.pop_back();
	printf("List after popping: ");
	for (int i: linkedList) {
		printf("%d ", i);
	}
	println("");

	linkedList.sort();
	linkedList.reverse();
	printf("Reversed sorted list: ");
	for (int i: linkedList) {
		printf("%d ", i);
	}
	println("");

	linkedList.remove(10);
	linkedList.remove(5);
	printf("List after removing: ");
	for (int i: linkedList) {
		printf("%d ", i);
	}
	println("");

	linkedList.clear();
	println("List size: %d", linkedList.size());
}