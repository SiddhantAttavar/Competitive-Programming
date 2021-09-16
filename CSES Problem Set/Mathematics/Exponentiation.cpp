#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

const long long MOD = 1e9 + 7;

int modPow(long long a , int b, int m) {
	long long res = 1;
	while (b > 0) {
		if (b % 2 == 1) {
			res = (res * a) % m;
		}
		b /= 2;
		a = (a * a) % m;
	}
	return (int) res;
}

int main() {
	setup();
	input(int, tc); while (tc--) {
		input(long long, a);
		input(long long, b);
		print(modPow(a, b, MOD));
	}
}