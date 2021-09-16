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
	vector<int> vector;
	stepRange(i, 100, 3) {
		vector.push_back(i);
	}

	range(i, vector.size()) {
		print(vector[i]);
	}

	println("Vector size: %d", vector.size());
	if (vector.empty()) {
		println("The vector is empty");
	}
	else {
		println("The vector is not empty");
	}
	println("Vector Max size: %d", vector.max_size());
	println("Vector storage space: %d", vector.capacity());
}