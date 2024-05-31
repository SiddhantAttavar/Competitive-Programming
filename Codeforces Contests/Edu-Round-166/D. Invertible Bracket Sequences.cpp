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
		string s;
		input(s);

		int n = s.size();
		vector<vector<int>> a(2 * n);
		int x = 0;
		range(i, 0, n) {
			if (s[i] == '(') {
				x++;
			}
			else {
				x--;
			}
			a[x].push_back(i);
		}

		int res = 0;
		x = 0;
		range(i, 0, n) {
			if (s[i] == '(') {
				x++;
			}
			else {
				x--;
			}

			int y = 2 * x + 1;
			int p = lower_bound(a[y].begin(), a[y].end(), i) - a[y].begin();
			int j;
			if (p == a[y].size()) {
				j = n;
			}
			else {
				j = a[y][p];
			}

			res += lower_bound(a[x].begin(), a[x].end(), j) - lower_bound(a[x].begin(), a[x].end(), i) - 1;
		}

		print(res);
	}
}
