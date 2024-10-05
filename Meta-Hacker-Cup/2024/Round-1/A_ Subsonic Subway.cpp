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
const int MOD = (int) 1e9 + 7; //998244353

int32_t main() {
	cout << setprecision(20) << fixed;
	setup(); int tc; input(tc); range(t, 1, tc + 1) {
		int n;
		input(n);

		vector<pair<int, int>> a(n);
		range(i, 0, n) {
			input(a[i].first, a[i].second);
		}

		double l = 0, r = 1e15;
		range(i, 0, n) {
			l = max(l, (i + 1.0) / a[i].second);
			if (a[i].first) {
				r = min(r, (i + 1.0) / a[i].first);
			}
		}

		cout << "Case #" << t << ": ";
		if (r < l) {
			print(-1);
		}
		else {
			print(l);
		}
	}
}
