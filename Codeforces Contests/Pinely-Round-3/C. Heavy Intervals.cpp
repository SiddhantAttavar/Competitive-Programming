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

		vi l(n), r(n), c(n), x;
		arrput(l);
		arrput(r);
		arrput(c);
		sort(all(c));

		vector<pii> v;
		rep(i, 0, n) {
			v.push_back({l[i], 0});
			v.push_back({r[i], 1});
		}
		sort(all(v));

		stack<int> s;
		for (auto [c, b] : v) {
			if (!b) {
				s.push(c);
			}
			else {
				x.push_back(c - s.top());
				s.pop();
			}
		}
		sort(all(x));
		reverse(all(x));

		int res = 0;
		rep(i, 0, n) {
			res += x[i] * c[i];
		}
		print(res);
	}
}
