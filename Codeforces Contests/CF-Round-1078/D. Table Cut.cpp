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
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<vi> a(n, vi(m));
		rep(i, 0, n) {
			arrput(a[i]);
		}

		int c = 0;
		rep(i, 0, n) {
			c += accumulate(all(a[i]), 0ll);
		}

		int x = 0, u = 0, v = m - 1;
		vector<vi> b(n, vi(m, false));
		while (2 * (x + 1) <= c) {
			b[u][v] = true;
			x += a[u][v];
			v--;
			if (v < 0) {
				v = m - 1;
				u++;
			}
		}

		assert(x * (c - x) == (c / 2) * ((c + 1) / 2));
		print(x * (c - x));

		u = 0, v = 0;
		string res;
		while (u < n or v < m) {
			if (u == n) {
				res += 'R';
				v++;
			}
			else if (v == m) {
				res += 'D';
				u++;
			}
			else if (b[u][v]) {
				res += 'D';
				u++;
			}
			else {
				res += 'R';
				v++;
			}
		}
		print(res);
	}
}
