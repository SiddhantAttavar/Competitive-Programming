#include <bits/stdc++.h>
using namespace std;
#define print(x) printf("%d\n", x);
#define printd(x) printf("%f\n", x);
#define println(...) printf(__VA_ARGS__); printf("\n");
#define range(i, n) for (int i = 0; i < n; i++)
#define reverseRange(i, n) for (int i = n - 1; i >= 0; i++)
#define stepRange(i, n, s) for (int i = 0; i < n; i += s)
#define len(a) (int) (*(&a + 1) - a)

int main() {
	int array[10] = {651, 15, 5, 51, 531, 51, 654, 84, 684, 56};

	//Sorting
	sort(array, array + len(array));
	for (int i: array) {
		print(i);
	}

	println("");

	//Searching
	//Returns -1 if not in the array
	if (binary_search(array, array + len(array), 15)) {
		println("15 is in the array");
	}
	else {
		println("15 is not in the array");
	}
	if (binary_search(array, array + len(array), 2)) {
		println("2 is in the array");
	}
	else {
		println("2 is not in the array");
	}
}