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
		int n, m;
		input(n, m);

		vector<int> l(m);
		arrput(l);

		vector<vector<int>> v(m);
		rep(i, 0, n) {
			int a, b;
			input(a, b);

			v[b - 1].push_back(a);
		}

		vector<int> a(n + 1, 0);
		rep(i, 0, m) {
			if (v[i].size() < l[i]) {
				continue;
			}

			sort(v[i].begin(), v[i].end());
			reverse(v[i].begin(), v[i].end());

			a[l[i]] += accumulate(v[i].begin(), v[i].begin() + l[i], 0ll);
			rep(j, l[i], v[i].size()) {
				a[j + 1] += v[i][j];
			}
		}

		pair<int, int> res = {0, 1};
		int x = 0;
		rep(i, 1, n + 1) {
			x += a[i];
			pair<int, int> p = {x, i};
			int g = __gcd(p.first, p.second);
			p = {p.first / g, p.second / g};
			if (p.first * res.second > res.first * p.second) {
				res = p;
			}
		}
		cout << res.first << '/' << res.second << endl;
	}
}
