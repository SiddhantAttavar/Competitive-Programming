#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T &x) {cin >> x;}
template<typename T, typename... S> inline void input(T &x, S&... y) {cin >> x; input(y ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... y) {cout << x << ' '; print(y ...);}
#define arrPut(x) for (auto &i : x) {cin >> i;}
#define arrPrint(x) for (auto i : x) {cout << i << ' ';} cout << '\n'
#define range(i, j, n) for (int i = j; i < n; i++)
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	setup();

	int n, k;
	input(n, k);	
	vector<int> x(n), a(k), b(k);
	arrPut(x);
	sort(x.begin(), x.end());
	for (int i = n - 1; i > 0; i--) {
		x[i] -= x[i - 1];
	}
	range(i, 0, k) {
		input(a[i], b[i]);
		a[i] *= 2;
	}

	range(u, 0, k) {	
		vector<int> dp(n, 1e18);
		int res = a[u];
		range(i, 1, n) {
			res += min(
				x[i] * b[u],
				a[u]
			);
		}
		print(res);
	}
}
