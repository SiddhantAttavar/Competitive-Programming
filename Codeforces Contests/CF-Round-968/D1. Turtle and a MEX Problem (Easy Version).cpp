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

		vector<vector<int>> a(n);
		range(i, 0, n) {
			int l;
			input(l);
			a[i].resize(l);
			arrPut(a[i]);
		}

		vector<pair<int, int>> b(n);
		int res = 0;
		range(i, 0, n) {
			set<int> s(a[i].begin(), a[i].end());
			b[i].first = 0;
			while (s.count(b[i].first)) {
				b[i].first++;
			}
			b[i].second = b[i].first + 1;
			while (s.count(b[i].second)) {
				b[i].second++;
			}
			res = max(res, b[i].second);
		}

		if (m <= res) {
			print((m + 1) * res);
		}
		else {
			print(res * (res + 1) + m * (m + 1) / 2 - res * (res + 1) / 2);
		}
	}
}
