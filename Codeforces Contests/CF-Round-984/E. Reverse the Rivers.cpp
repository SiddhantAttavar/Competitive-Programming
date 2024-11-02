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
	setup();
	int n, k, q;
	input(n, k, q);

	vector<vector<int>> a(k, vector<int>(n));
	range(i, 0, n) {
		range(j, 0, k) {
			input(a[j][i]);
		}
	}

	range(i, 1, n) {
		range(j, 0, k) {
			a[j][i] |= a[j][i - 1];
		}
	}

	while (q--) {
		int m;
		input(m);

		int l = 0, r = n - 1;
		while (m--) {
			int i, x;
			char c;
			input(i, c, x);

			i--;
			if (c == '<') {
				r = min(r, (int) (lower_bound(a[i].begin(), a[i].end(), x) - a[i].begin() - 1));
			}
			else {
				l = max(l, (int) (upper_bound(a[i].begin(), a[i].end(), x) - a[i].begin()));
			}
		}

		if (l <= r) {
			print(l + 1);
		}
		else {
			print(-1);
		}
	}
}
