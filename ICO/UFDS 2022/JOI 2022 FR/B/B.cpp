#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... y) {cin >> x; input(y ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... y) {cout << x << ' '; print(y ...);}
#define range(i, j, n) for (int i = j; i < n; i++)
#define arrPut(x) for (auto &i : x) {cin >> i;}
#define arrPrint(x) for (auto i : x) {cout << i << ' ';} << cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

vector<int>	a, b;

bool possible(int k, int n, int m) {
	int c = 0;
	range(i, 0, n) {
		if (a[i] * m >= k) {
			if (k % a[i] == 0) {
				c += k / a[i];
			}
			else {
				c += k / a[i] + 1;
			}
		}
		else {
			c += m;
			int x = k - a[i] * m;
			if (x % b[i] == 0) {
				c += x / b[i];
			}
			else {
				c += x / b[i] + 1;
			}
		}
		if (c > n * m) {
			return false;
		}
	}
	return true;
}

int32_t main() {
	setup();

	int n, k;
	input(n, k);

	a.resize(n);
	b.resize(n);
	arrPut(a);
	arrPut(b);
	range(i, 0, n) {
		a[i] = max(a[i], b[i]);
	}
	
	int res = 0, l = 0, r = 1e18;
	while (l <= r) {
		int m = (l + r) / 2;
		if (possible(m, n, k)) {
			res = m;
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
	print(res);
}
