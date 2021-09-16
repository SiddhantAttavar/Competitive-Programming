#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

int main() {
	setup();
	input(int, n);

	int f[max(n + 1, 2)] = {1, 1};
	int g[max(n + 1, 2)] = {0, 0};
	range(i, 2, n + 1) {
		f[i] = (f[i - 1] + f[i - 2] + 2 * g[i - 1]) % 10000;
		g[i] = (g[i - 1] + f[i - 2]) % 10000;
	}

	print(f[n]);
}