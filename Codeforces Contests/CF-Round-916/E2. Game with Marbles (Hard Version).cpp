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

		vector<int> a(n), b(n);
		arrPut(a);
		arrPut(b);

		vector<pair<int, int>> c(n);
		map<int, vector<int>> m;
		range(i, 0, n) {
			c[i] = {a[i] + b[i], i};
		}
		sort(c.begin(), c.end());
		reverse(c.begin(), c.end());

		int res = 0;
		range(i, 0, n) {
			if (i % 2 == 0) {
				res += a[c[i].second] - 1;
			}
			else {
				res -= b[c[i].second] - 1;
			}
		}
		print(res);
	}
}
