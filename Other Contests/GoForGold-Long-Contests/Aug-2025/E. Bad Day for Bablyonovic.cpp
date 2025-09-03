#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
#define debug(...) cout << #__VA_ARGS__ << ": "; print(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, q, k;
		input(n, q, k);

		vector<int> a(n);
		arrput(a);

		vector<vector<int>> p(n, vector<int>(20, -2));
		vector<int> x(k + 1, 0);
		int l = 0, c = 0;
		rep(i, 0, n) {
			c += x[a[i]] == 0;
			x[a[i]]++;

			while (x[a[l]] > 1) {
				x[a[l]]--;
				l++;
			}

			if (c < k) {
				continue;
			}

			p[i][0] = l - 1;
			rep(j, 1, 20) {
				if (p[i][j - 1] < 0) {
					break;
				}
				p[i][j] = p[p[i][j - 1]][j - 1];
			}
		}

		while (q--) {
			int l, r;
			input(l, r);

			l--;
			r--;

			int res = 0;
			for (int i = 19; i >= 0; i--) {
				if (r >= 0 and p[r][i] >= l - 1) {
					res |= 1 << i;
					r = p[r][i];
				}
			}
			print(res + 1);
		}
	}
}
