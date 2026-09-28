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
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;
inline int mpow(int a, int b) {int x = 1; for (; b; a = a * a % MOD, b >>= 1) {if (b & 1) {x = x * a % MOD;}} return x;};
inline int mdiv(int a, int b) {return a * mpow(b, MOD - 2) % MOD;};

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vi p(n), q(n);
		arrput(p);
		arrput(q);

		rep(i, 0, n) {
			p[i]--;
			q[i]--;
		}

		vi vis(n, false), c(n, -1);
		vector<vi> v(n + 1);
		rep(i, 0, n) {
			if (vis[i]) {
				continue;
			}

			vi l = {i};
			int j = i;
			vis[i] = true;
			c[i] = 0;
			while (p[j] != i) {
				c[p[j]] = c[j] + 1;
				j = p[j];
				l.push_back(j);
				vis[j] = true;
			}

			for (int j : l) {
				if (c[q[j]] != -1) {
					v[sz(l)].push_back((c[q[j]] - c[j] + sz(l)) % sz(l));
				}
			}

			for (int j : l) {
				c[j] = -1;
			}
		}

		vi res(k + 1, 0);
		rep(i, 1, n + 1) {
			sort(all(v[i]));
			int s = 0, t = -1;
			for (int j : v[i]) {
				if (j == t) {
					s++;
					continue;
				}
				if (t != -1) {
					for (int x = t; x <= k; x += i) {
						res[x] += s;
					}
				}
				s = 1;
				t = j;
			}
			if (t != -1) {
				for (int x = t; x <= k; x += i) {
					res[x] += s;
				}
			}
		}

		res[0] = 0;
		print(*max_element(all(res)));
	}
}
