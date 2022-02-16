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
	input(long long, n);
	while (n != 1) {
		cout << n << " ";
		if (n % 2 == 0) {
			n /= 2;
		}
		else {
			n = 3 * n + 1;
		}
	}
	print(1);
}
