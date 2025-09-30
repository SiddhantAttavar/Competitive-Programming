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
		string p, q;
		input(p, q);

		int a = stoll(p), b = stoll(q);
		int g = gcd(a, b);
		a /= g;
		b /= g;

		pair<int, int> res = {stoll(p), stoll(q)};
		rep(i, 1, 1 << p.size()) {
			string t, r;
			vector<int> v(10);
			rep(j, 0, p.size()) {
				if (i >> j & 1) {
					t += p[j];
				}
				else if (!t.empty() or p[j] != '0') {
					r += p[j];
				}
			}
			int c = stoll(t);
			if (c == 0 or c >= res.first or c % a) {
				continue;
			}
			int d = (c / a) * b;
			string s = to_string(d), u;
			int l = s.size() - 1;
			for (int j = q.size() - 1; j >= 0; j--) {
				if (l >= 0 and s[l] == q[j]) {
					l--;
				}
				else if (l >= 0 or q[j] != '0') {
					u += q[j];
				}
			}
			if (l >= 0) {
				continue;
			}
			sort(r.begin(), r.end());
			sort(u.begin(), u.end());
			if (r == u) {
				res = {c, d};
			}
		}
		print(res.first, res.second);
	}
}
