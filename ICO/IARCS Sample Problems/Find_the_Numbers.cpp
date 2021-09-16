#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

bool solve(int s, int p, int k) {
	if (k == 1) {
		if (s == p) {
			cout << s;
			return true;
		}
		return false;
	}
	range(i, 1, s - k) {
		if (p % i == 0 && solve(s - i, p / i, k - 1)) {
			cout << " " << i;
			return true;
		}
	}
	return false;
}

int main() {
	setup();
	input(int, s);
	input(int, p);
	input(int, k);
	if (!solve(s, p, k)) {
		print("NO");
	}
}