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
		int n, x;
		input(n, x);

		vector<int> a(n);
		arrPut(a);

		vector<int> p(n + 1, 0);
		range(i, 0, n) {
			p[i + 1] = p[i] ^ a[i];
		}

		int res = -1;
		vector<bool> b(n, true);
		for (int i = 29; i >= 0; i--) {
			if (((1 << i) & x) == 0) {
				range(j, 0, n) {
					if ((1 << i) & p[j + 1]) {
						b[j] = false;
					}
				}
				continue;
			}

			if (b[n - 1] and ((1 << i) & p[n]) == 0) {
				int c = 0;
				range(j, 0, n) {
					if (b[j] and ((1 << i) & p[j + 1]) == 0) {
						c++;
					}
				}
				res = max(res, c);
			}
		}

		if (b[n - 1]) {
			int c = 0;
			range(j, 0, n) {
				if (b[j]) {
					c++;
				}
			}
			res = max(res, c);
		}

		print(res);
	}
}
