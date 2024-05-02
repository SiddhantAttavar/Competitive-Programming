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
		int n, q;
		input(n, q);

		vector<int> a(n);
		arrPut(a);

		vector<int> p(n + 1, 0);
		map<int, vector<int>> m;
		m[0] = {0};
		range(i, 0, n) {
			p[i + 1] = p[i] ^ a[i];
			m[p[i + 1]].push_back(i + 1);
		}

		while (q--) {
			int l, r;
			input(l, r);

			l--;
			r--;
			
			if (p[r + 1] == p[l]) {
				print("YES");
				continue;
			}

			int j = *lower_bound(m[p[r + 1]].begin(), m[p[r + 1]].end(), l + 1);
			int k = lower_bound(m[p[l]].begin(), m[p[l]].end(), j + 1) - m[p[l]].begin();
			if (k < m[p[l]].size() and m[p[l]][k] <= r) {
				print("YES");
			}
			else {
				print("NO");
			}
		}
	}
}
