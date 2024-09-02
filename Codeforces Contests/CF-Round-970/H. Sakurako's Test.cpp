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
		int n, q;
		input(n, q);

		vector<int> a(n);
		arrPut(a);

		vector<int> p(n + 1, 0);
		for (int i : a) {
			p[i]++;
		}
		range(i, 1, n + 1) {
			p[i] += p[i - 1];
		}

		vector<int> res(n + 1, -1);
		while (q--) {
			int x;
			input(x);

			if (res[x] != -1) {
				cout << res[x] << ' ';
				continue;
			}

			int l = 0, r = x - 1;
			res[x] = x - 1;
			while (l <= r) {
				int m = (l + r) / 2;
				int c = p[min(m, n)];
				for (int j = x; j <= n; j += x) {
					c += p[min(n, j + m)] - p[j - 1];
				}
				if (2 * c > n) {
					res[x] = m;
					r = m - 1;
				}
				else {
					l = m + 1;
				}
			}
			cout << res[x] << ' ';
		}
		cout << endl;
	}
}
