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

		vector<int> a(n);
		arrPut(a);

		vector<int> p(30), q(30), y(30), x(30);
		int res = 0, c = 0;
		range(z, 0, n) {
			for (int i = 30; i >= 0; i--) {
				if ((1 << i) & a[z]) {
					y[i]++;
					p[i] += x[i];
					q[i] += (z + 1 - x[i]);
					break;
				}
			}

			c ^= a[z];
			range(i, 0, 30) {
				if ((1 << i) & c) {
					res += p[i];
				}
				else {
					res += q[i];
				}
			}

			range(i, 0, 30) {
				x[i] += ((1 << i) & c) > 0;
			}
		}

		print(res);
	}
}
