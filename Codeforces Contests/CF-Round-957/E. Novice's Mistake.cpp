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
		int n;
		input(n);
		
		if (n == 1) {
			print(9999);
			continue;
		}

		if (n < 10) {
			int x = n;
			vector<pair<int, int>> res;
			range(l, 1, 7) {
				if ((x - l) >= (n - 1) and (x - l) % (n - 1) == 0) {
					int a = (x - l) / (n - 1);
					if (a <= 1e4 and a - l > 0) {
						res.push_back({a, a - l});
					}
				}
				x = 10 * x + n;
			}

			print(res.size());
			for (pair<int, int> p : res) {
				print(p.first, p.second);
			}
			continue;
		}

		vector<pair<int, int>> res;
		int x = n / 10, l = 1;
		while (x < 1e6) {
			if ((x - l) >= (n - 2) and (x - l) % (n - 2) == 0) {
				int a = (x - l) / (n - 2);
				if (a <= 1e4 and 2 * a - l <= 1e4 and 2 * a - l > 0) {
					res.push_back({a, 2 * a - l});
				}
			}
			x = 100 * x + 10 * (n % 10) + (n / 10);
			l += 2;
		}

		x = n;
		l = 2;
		while (x < 1e6) {
			if ((x - l) >= (n - 2) and (x - l) % (n - 2) == 0) {
				int a = (x - l) / (n - 2);
				if (a <= 1e4 and 2 * a - l <= 1e4 and 2 * a - l > 0) {
					res.push_back({a, 2 * a - l});
				}
			}
			x = 100 * x + n;
			l += 2;
		}

		print(res.size());
		for (pair<int, int> p : res) {
			print(p.first, p.second);
		}
	}
}
