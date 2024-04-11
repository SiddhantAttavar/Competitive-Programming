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
		
		string s;
		input(s);

		int res = 1;
		for (int k = n; k >= 2; k--) {
			bool rev = false, flag = true;
			vector<bool> b(n + 1, false);
			vector<bool> a(n);
			range(i, 0, n) {
				a[i] = s[i] == '1';
			}

			range(i, 0, n) {
				if (b[i]) {
					rev = !rev;
				}
				// print('d', k, rev, a[i]);

				if (rev) {
					a[i] = !a[i];
				}

				if (i + k <= n and !a[i]) {
					// print('d', a[i]);
					rev = !rev;
					a[i] = !a[i];
					b[i + k] = true;
				}
				else if (!a[i]) {
					flag = false;
					break;
				}
			}

			if (flag) {
				res = k;
				break;
			}
		}

		print(res);
	}
}
