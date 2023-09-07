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

bool check(int m, int n, vector<pair<int, int>> &v) {
	range(i, 0, n) {
		if (v[i].first > m) {
			break;
		}

		if (v[i].second <= 2 * (m - v[i].first)) {
			return false;
		}
	}

	return true;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<pair<int, int>> v(n);
		range(i, 0, n) {
			int d, s;
			input(d, s);
			v[i] = {d, s};
		}
		sort(v.begin(), v.end());

		int l = 0, r = 1e9, res = 0;
		while (l <= r) {
			int m = (l + r) / 2;
			if (check(m, n, v)) {
				res = m;
				l = m + 1;
			}
			else {
				r = m - 1;
			}
		}

		print(res);
	}
}
