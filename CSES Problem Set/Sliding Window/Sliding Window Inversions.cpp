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
#define ordered_set tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup();

	int n, k;
	input(n, k);

	vi x(n);
	arrput(x);

	int c = 0;
	ordered_set o;
	rep(i, 0, k) {
		c += sz(o) - o.order_of_key({x[i], n});
		o.insert({x[i], i});
	}

	cout << c;
	rep(i, k, n) {
		c += sz(o) - o.order_of_key({x[i], n});
		o.insert({x[i], i});
		c -= o.order_of_key({x[i - k], -1});
		o.erase({x[i - k], i - k});
		cout << ' ' << c;
	}
	cout << endl;
}
