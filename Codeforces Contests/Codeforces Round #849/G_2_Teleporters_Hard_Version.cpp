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

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, c;
		input(n, c);

		vector<int> a(n);
		arrPut(a);

		vector<pair<int, int>> v(n + 1, {0, -1});
		vector<int> ind(n);
		range(i, 0, n) {
			v[i + 1] = {min((i + 1ll), (n - i)) + a[i], i};
		}
		sort(v.begin(), v.end());

		range(i, 0, n) {
			v[i + 1].first += v[i].first;
			ind[v[i + 1].second] = i + 1;
		}

		// if (n == 5 and c == 8) {
		// 	print("");
		// 	range(i, 0, n + 1) {
		// 		print(v[i].first, v[i].second);
		// 	}
		// 	print("");
		// }

		int res = 0;
		range(i, 1, n + 1) {
			int l = 0, r = n;
			while (l <= r) {
				int m = (l + r) / 2;
				int x = v[m].first + ((v[i].second + 1) + a[v[i].second]);
				if (m >= i) {
					x -= v[i].first - v[i - 1].first;
				}

				// if (n == 2 and c == 14) {
				// 	print(i, m, x);
				// }

				if (x <= c) {
					res = max(res, m + (m < i));
					l = m + 1;
				}
				else {
					r = m - 1;
				}
			}
		}

		print(res);
	}
}
