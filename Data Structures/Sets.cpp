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
	set<int> sortedSet;
	sortedSet.insert(56);
	sortedSet.insert(654);
	sortedSet.insert(61);
	sortedSet.insert(5);
	sortedSet.insert(34);

	set<int, greater<int>> reverseSet;
	for (int i: sortedSet) {
		reverseSet.insert(i);
	}

	println("Set elements");
	for (int i: sortedSet) {
		print(i);
	}

	println("Reverse set elements");
	for (int i: reverseSet) {
		print(i);
	}

	sortedSet.erase(61);
	sortedSet.erase(sortedSet.begin(), sortedSet.find(34));
	println("After removing");
	for (int i: sortedSet) {
		print(i);
	}

	sortedSet.clear();
	println("Set size: %d", sortedSet.size());
}