#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, q;
		input(n, q);

		vector<int> a(n);
		arrPut(a);

		int x = 0;
		for (int i : a) {
			x += i;
		}

		map<int, pair<int, int>> s;
		range(i, 0, n) {
			range(j, 0, i) {
				s[2 * x - a[i] - a[j]] = {j, i};
			}
		}

		while (q--) {
			int y;
			input(y);

			if (!s.count(y)) {
				print(-1);
				continue;
			}

			vector<int> b(a.begin(), a.end());
			swap(b[0], b[s[y].first]);
			swap(b[n - 1], b[s[y].second]);

			arrPrint(b);
		}
	}
}
