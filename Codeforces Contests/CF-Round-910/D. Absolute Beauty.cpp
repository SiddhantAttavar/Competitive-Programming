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
		int n;
		input(n);

		vector<pair<int, int>> v(n);
		range(i, 0, n) {
			input(v[i].first);
		}
		range(i, 0, n) {
			input(v[i].second);
		}
		sort(v.begin(), v.end());

		vector<int> a(n), b(n);
		range(i, 0, n) {
			tie(a[i], b[i]) = v[i];
		}

		int m = 1e18, res = 0;
		range(i, 0, n) {
			if (b[i] >= a[i]) {
				res = max(res, 2 * (a[i] - m));
				m = min(m, b[i]);
			}
			else {
				res = max(res, 2 * (b[i] - m));
				m = min(m, a[i]);
			}
			// print(m, res);
		}

		range(i, 0, n) {
			res += abs(a[i] - b[i]);
		}

		print(res);
	}
}
