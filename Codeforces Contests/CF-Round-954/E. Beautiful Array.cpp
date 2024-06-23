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
		int n, k;
		input(n, k);

		vector<int> a(n);
		arrPut(a);

		map<int, vector<int>> v;
		for (int i : a) {
			v[i % k].push_back(i / k);
		}

		int res = 0;
		int u = -1;
		for (pair<int, vector<int>> p : v) {
			if (p.second.size() % 2) {
				if (u == -1) {
					u = p.first;
					continue;
				}
				res = -1;
				break;
			}

			sort(p.second.begin(), p.second.end());
			range(i, 0, p.second.size() / 2) {
				res += p.second[2 * i + 1] - p.second[2 * i];
			}
		}

		if (res == -1 or u == -1) {
			print(res);
			continue;
		}

		vector<int> l = v[u];
		sort(l.begin(), l.end());
		vector<int> p = {0};
		range(i, 0, l.size() / 2) {
			p.push_back(p.back() + (l[2 * i + 1] - l[2 * i]));
		}

		int x = 0;
		int c = 1e9;
		for (int i = l.size() - 1; i >= 0; i -= 2) {
			c = min(c, x + p[i / 2]);
			if (i) {
				c = min(c, x + p[i / 2 - 1] + l[i] - l[i - 2]);
			}
			if (i < l.size()) {
				x += l[i] - l[i - 1];
			}
		}
		print(res + c);
	}
}
