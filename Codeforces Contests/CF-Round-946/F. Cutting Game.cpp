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
		int a, b, n, m;
		input(a, b, n, m);

		vector<pair<int, int>> l(n);
		set<int> x, y;
		range(i, 0, n) {
			input(l[i].first, l[i].second);
			y.insert(l[i].first);
			y.insert(l[i].second);
		}

		map<int, int> u, v;
		int i = 0;
		for (int j : x) {
			u[j] = i;
			i++;
		}
		i = 0;
		for (int j : y) {
			v[j] = i;
			i++;
		}

		int p = 1, q = a, r = 1, s = b;
		while (m--) {
			char c;
			int k;
			input(c, k);

			if (c == 'U') {
				p += k;
			}
			else if (c == 'D') {
				q -= k;
			}
			else if (c == 'L') {
				r += k;
			}
			else {
				s -= k;
			}
		}
	}
}
