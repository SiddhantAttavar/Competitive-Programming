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
		int n;
		input(n);

		string s;
		input(s);

		vi p(n + 1, 0), q(n + 1, 0), a(n + 1, 0), b(n + 1, 0);
		rep(i, 0, n) {
			p[i + 1] = p[i];
			q[i + 1] = q[i];
			if (s[i] == '(') {
				p[i + 1]++;
			}
			else if (s[i] == ')') {
				p[i + 1]--;
			}
			else if (s[i] == '[') {
				q[i + 1]++;
			}
			else if (s[i] == ']') {
				q[i + 1]--;
			}
			a[i + 1] = min(a[i], p[i + 1]);
			b[i + 1] = min(b[i], q[i + 1]);
		}

		int res = 0;
		pii upd = {0, 0};
		rep(i, 0, n) {
			int x = p[i + 1], y = q[i + 1], u = a[i + 1], v = a[i + 1];
			x += upd.first;
			u += upd.first;
			y += upd.second;
			v += upd.second;
			if (s[i] == '(') {
				x--;
				u--;
			}
			else if (s[i] == ')') {
				x++;
				u++;
			}
			else if (s[i] == '[') {
				y--;
				v--;
			}
			else if (s[i] == ']') {
				y++;
				v++;
			}

			vector<pair<pii, int>> l = {
				{{1, 0}, s[i] != '('},
				{{-1, 0}, s[i] != ')'},
				{{0, 1}, s[i] != '['},
				{{0, -1}, s[i] != '['}
			};
			tuple<pii, int, int> g = {{-1, -1}, -1, false};
			for (auto [t, c] : l) {
				bool b = true;
				if (u < 0 and t.first < 0 or v < 0 and t.second < 0) {
					b = false;
				}
				if (b and (x > 0 and t.first > 0 or y > 0 and t.second > 0)) {
					b = false;
				}
				if (get<1>(g) == -1) {
					g = {t, c, b};
				}
				else if (b and !get<2>(g)) {
					g = {t, c, b};
				}
				else if (b and get<1>(g)) {
					g = {t, c, b};
				}
				else if (!c and !get<2>(g)) {
					g = {t, c, b};
				}
			}
			upd = get<0>(g);
			res += get<1>(g);
		}
		print(res);
	}
}
