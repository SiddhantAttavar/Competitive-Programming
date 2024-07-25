#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<int> a(n), c(n);
		arrPut(a);
		arrPut(c);

		vector<pair<int, int>> b(n);
		range(i, 0, n) {
			b[i] = {a[i], c[i]};
		}
		sort(b.begin(), b.end());

		int res = min(m - m % b[0].first, b[0].first * b[0].second);
		range(i, 1, n) {
			// print(b[i].first, res);
			res = max(res, min(m - m % b[i].first, b[i].first * b[i].second));
			if (b[i - 1].first != b[i].first - 1) {
				continue;
			}

			int x = b[i - 1].first;
			int p = b[i - 1].second, q = b[i].second;
			int k = min(p, m / x);
			int y = m - k * x;
			int l = min(q, y / (x + 1));
			y -= l * (x + 1);
			int o = min({k, q - l, y});
			y -= o;
			res = max(res, m - y);
		}
		print(res);
	}
}
