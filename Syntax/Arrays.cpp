#include <bits/stdc++.h>
using namespace std;

#define print(i) printf("%i\n", i)
#define printd(f) printf("%f\n", f)
#define prints(s) printf("%s\n", s.c_str())
#define println(...) printf(__VA_ARGS__); printf("\n")
#define range(i, n) for (int i = 0; i < n; i++)
#define reverseRange(i, n) for (int i = n - 1; i >= 0; i++)
#define stepRange(i, n, s) for (int i = 0; i < n; i += s)
#define len(a) sizeof(a) / sizeof(a[0])

int main() {
	int ages[4] = {1, 5, 513, 51};
	range(i, len(ages)) {
		println("The age of person %d is %d", i + 1, ages[i]);
	}
}
