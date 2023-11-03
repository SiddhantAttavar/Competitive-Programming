#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int f(int n) {
	int c = 0;
	int x = 1, y = 1;

	while (10 * x <= n) {
		c += 9 * x * y;
		y++;
		x *= 10;
	}

	return c + (n - x) * y;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int k;
		input(k);

		int l = 1, r = 1e18, res = 1;
		while (l <= r) {
			int m = (l + r) / 2;
			if (f(m) < k) {
				res = m;
				l = m + 1;
			}
			else {
				r = m - 1;
			}
		}

		vector<int> d;
		int x = res;
		while (x) {
			d.push_back(x % 10);
			x /= 10;
		}
		reverse(d.begin(), d.end());

		print(d[k - f(res) - 1]);
	}
}
