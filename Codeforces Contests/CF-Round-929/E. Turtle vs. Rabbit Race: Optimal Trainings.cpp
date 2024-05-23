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

		vector<int> p(n + 1, 0);
		range(i, 0, n) {
			p[i + 1] = p[i] + a[i];
		}

		int q;
		input(q);
		while (q--) {
			int l, u;
			input(l, u);
			l--;

			int res = lower_bound(p.begin(), p.end(), p[l] + u) - p.begin();
			res = max(res - 1, l + 1);

			range(j, res + 1, n + 1) {
				if (abs(2 * (p[j] - p[l]) - (2 * u + 1)) < abs(2 * (p[res] - p[l]) - (2 * u + 1))) {
					res = j;
				}
				if (p[j] > p[l] + u) {
					break;
				}
			}
			cout << res << ' ';
		}
		cout << endl;
	}
}
