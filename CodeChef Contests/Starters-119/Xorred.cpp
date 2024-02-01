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

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		map<int, vector<int>> m;
		m[0].push_back(-1);

		vector<int> b(n);
		int res = 0, x = 0;
		range(i, 0, n) {
			x ^= a[i];
			m[x].push_back(i);
			b[i] = a[i];

			for (int j = i - 1; j >= 0; j--) {
				if ((b[j] & a[i]) == b[j]) {
					break;
				}
				b[j] &= a[i];
			}

			int r = i;
			while (r >= 0) {
				int l = lower_bound(b.begin(), b.begin() + r + 1, b[r]) - b.begin();
				int z = x ^ b[r];
				res += upper_bound(m[z].begin(), m[z].end(), r - 1) - lower_bound(m[z].begin(), m[z].end(), l - 1);
				r = l - 1;
			}
		}

		print(res);
	}
}
