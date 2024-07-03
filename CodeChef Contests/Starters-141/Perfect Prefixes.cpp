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

		set<int> s;
		vector<bool> b(n, false), c(n, false);
		range(i, 0, n - 1) {
			s.insert(a[i + 1] - 1);
			c[i] = s.size() == (i + 1) and *s.rbegin() == i;
			s.erase(a[i + 1] - 1);
			s.insert(a[i] - 1);
			b[i] = s.size() == (i + 1) and *s.rbegin() == i;
		}
		b[n - 1] = true;

		vector<int> p(n, 0);
		p[0] = c[0] - b[0];
		p[1] = c[1] - b[1];
		range(i, 2, n) {
			p[i] = p[i - 2] + c[i] - b[i];
		}

		int m = accumulate(b.begin(), b.end(), 0);
		int res = m;
		int x = 0, y = 0;
		range(i, 0, n - 1) {
			if (i % 2 == 0) {
				res = max(res, m + p[i] - x);
				x = min(x, p[i]);
			}
			else {
				res = max(res, m + p[i] - y);
				y = min(y, p[i]);
			}
		}
		print(res);
	}
}
