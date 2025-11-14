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
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int a, b, c;
		input(a);
		vector<int> p(a);
		arrput(p);
		input(b);
		vector<int> q(b);
		arrput(q);
		input(c);
		vector<int> r(c);
		arrput(r);

		ordered_set o;
		vector<int> x(b);
		rep(i, 0, b) {
			if (i < a) {
				o.insert(p[i]);
			}
			x[i] = o.order_of_key(q[i] + 1);
		}
		o.clear();
		for (int i = c - 1; i >= b; i--) {
			o.insert(r[i]);
		}
		int res = 0;
		for (int i = b - 1; i >= 0; i--) {
			if (i < c) {
				o.insert(r[i]);
			}
			res += x[i] * (o.size() - o.order_of_key(q[i]));
		}
		print(res);
	}
}
