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
		int n;
		input(n);

		vector<vector<int>> a(n, vector<int>(n, 0));
		vector<vector<int>> res;

		int k = (n + 1) / 2;
		range(i, 0, n) {
			res.push_back({1, i + 1});
			range(j, 0, n) {
				a[i][j] = j + 1;
				res.back().push_back(j + 1);
			}
		}

		range(j, 0, k) {
			res.push_back({2, j + 1});
			range(i, 0, n) {
				a[i][j] = i + 1;
				res.back().push_back(i + 1);
			}
		}

		range(i, 0, n - k) {
			res.push_back({1, i + 1});
			range(j, 0, n) {
				a[i][j] = j + 1;
				res.back().push_back(j + 1);
			}
		}

		int s = 0;
		range(i, 0, n) {
			range(j, 0, n) {
				s += a[i][j];
			}
		}

		print(s, res.size());
		for (vector<int> v : res) {
			arrPrint(v);
		}
	}
}
