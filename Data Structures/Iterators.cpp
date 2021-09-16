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
	vector<int> array;
	stepRange(i, 100, 5) {
		array.push_back(i);
	}

	vector<int>::iterator iterator;
	for (iterator = array.begin(); iterator < array.begin() + array.size() / 2; iterator++) {
		print(*iterator);
	}

	advance(iterator, 2);
	vector<int>::iterator nextIterator = next(iterator, 5);
	print(*nextIterator);
	vector<int>::iterator previousIterator = prev(iterator, 5);
	print(*previousIterator);
}