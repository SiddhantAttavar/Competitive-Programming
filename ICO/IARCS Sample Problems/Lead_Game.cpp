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
	int a = 0, b = 0;
	int res = 0;
	bool winner;
	range(i, 0, n) {
		input(int, s);
		input(int, t);
		a += s;
		b += t;
		if (res < abs(a - b)) {
			res = abs(a - b);
			winner = b > a;
		}
	}

	cout << winner + 1 << " " << res << endl;
}