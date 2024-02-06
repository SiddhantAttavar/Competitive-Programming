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
	setup();

	int q;
	input(q);

	vector<vector<int>> a;
	vector<int> v;
	range(i, 0, q) {
		int o;
		input(o);

		if (o == 1) {
			a.push_back(vector<int>(20, -1));
			v.push_back(i + 1);
			input(a.back()[0]);
			range(j, 1, 20) {
				if (a.size() <= (1 << (j - 1))) {
					break;
				}
				a.back()[j] = max(a.back()[j - 1], a[a.size() - 1 - (1 << (j - 1))][j - 1]);
			}
		}
		else {
			int y, k;
			input(y, k);

			int u = a.size();
			vector<int> res;
			range(i, 0, k) {
				u--;

				for (int j = 19; j >= 0; j--) {
					if (u < 0) {
						break;
					}
					if (a[u][j] != -1 and a[u][j] < y) {
						u -= 1 << j;
					}
				}

				if (u < 0) {
					break;
				}
				res.push_back(v[u]);
			}

			print(res.size());
			arrPrint(res);
		}
	}
}
