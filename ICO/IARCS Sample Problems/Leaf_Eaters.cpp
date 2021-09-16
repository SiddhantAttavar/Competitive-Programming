#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

int n, k;
long long a[25];

int solve(int i, long long lcm, int size) {
	if (i == k) {
		if (size % 2 == 0) {
			return -(1 + ((n - 1) / lcm));
		}
		return (1 + ((n - 1) / lcm));
	}
	return solve(i + 1, lcm, size) + solve(i + 1, (lcm * a[i]) / __gcd(lcm, a[i]), size + 1);
}

int main() {
	setup();
	cin >> n >> k;
	range(i, 0, k) {
		cin >> a[i];
	}
	print(-solve(0, 1, 0));
}