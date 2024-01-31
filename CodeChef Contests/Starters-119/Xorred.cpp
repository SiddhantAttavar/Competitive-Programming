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

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		map<int, vector<int>> m;
		m[0].push_back(-1);

		vector<int> b(30, -1);
		int x = 0;
		int res = 0;
		range(i, 0, n) {
			x ^= a[i];

			range(j, 0, 30) {
				if (!((1 << j) & a[i])) {
					b[j] = i;
				}
			}

			vector<pair<int, int>> c(30);
			range(i, 0, 30) {
				c[i] = {b[i], i};
			}
			sort(c.begin(), c.end());
			reverse(c.begin(), c.end());

			int y = (1 << 30) - 1;
			vector<pair<int, int>> v;
			range(j, 0, 30) {
				y ^= 1 << c[j].second;
				if (j > 0 and c[j].first == c[j - 1].first) {
					v.back().first = y;
				}
				else {
					v.push_back({y, c[j].first});
				}
			}

			if (v.back().second != -1) {
				v.push_back({-1, -1});
			}
			range(j, 0, (int) v.size() - 1) {
				int r = v[j].second;
				int l = v[j + 1].second + 1;
				int z = x ^ v[j].first;
				res += m[z].end() - lower_bound(m[z].begin(), m[z].end(), l - 1);
			}

			m[x].push_back(i);
		}

		print(res);
	}
}
