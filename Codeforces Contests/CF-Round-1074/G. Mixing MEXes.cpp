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
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<vi> a(n);
		rep(i, 0, n) {
			int l;
			input(l);
			a[i].resize(l);
			arrput(a[i]);
		}

		vi p(n), q(n);
		rep(i, 0, n) {
			set<int> s(all(a[i]));
			int x = 0;
			while (s.count(x)) {
				x++;
			}
			p[i] = x;
			x++;
			while (s.count(x)) {
				x++;
			}
			q[i] = x;
		}

		map<int, pii> m;
		rep(i, 0, n) {
			m[p[i]].first++;
			m[p[i]].second += q[i];
		}

		int z = accumulate(all(p), 0ll), res = 0;
		rep(i, 0, n) {
			map<int, int> f;
			for (int j : a[i]) {
				f[j]++;
			}
			for (int j : a[i]) {
				int x = j < p[i] and f[j] == 1 ? z - p[i] + j : z;
				res += (n - 1) * x;
				if (m.count(j)) {
					res += m[j].second - j * m[j].first;
				}
			}
		}
		print(res);
	}
}
