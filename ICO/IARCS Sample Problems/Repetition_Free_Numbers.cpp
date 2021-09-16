#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

bool isRepFree(long unsigned int x) {
	bool a[9] = {false};
	do {
		if (x % 10 == 0 || a[x % 10 - 1]) {
			return false;
		}
		a[x % 10 - 1] = true;
		x /= 10;
	} while (x != 0);
	return true;
}

int main() {
	setup();
    long long MAX = 10000000000;
	input(long unsigned int, n);
	n++;
	while (!isRepFree(n) && n++ < MAX);
	print(n == MAX ? 0 : n);
}