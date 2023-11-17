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

int solve(vector<int> &a) {
	int c = a[0], res = a[0];
	range(i, 1, (int) a.size()) {
		if (c < 0) {
			c = a[i];
		}
		else {
			c += a[i];
		}

		res = max(res, c);
	}

	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		vector<vector<int>> v;
		v.push_back({a[0]});
		range(i, 1, n) {
			if ((a[i] % 2 + 2) % 2 == (a[i - 1] % 2 + 2) % 2) {
				v.push_back({});
			}
			v.back().push_back(a[i]);
		}
		// print(v.size());

		int res = -1e18;
		for (vector<int> l : v) {
			// arrPrint(l);
			res = max(res, solve(l));
		}
		print(res);
	}
}
