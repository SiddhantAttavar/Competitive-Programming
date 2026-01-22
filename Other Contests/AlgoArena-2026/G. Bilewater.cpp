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
	const int N = 1e5;
	vector<vi> div(N + 1);
	rep(i, 1, N + 1) {
		for (int j = i; j <= N; j += i) {
			div[j].push_back(i);
		}
	}
	setup(); int tc; input(tc); while (tc--) {
		int n, l, r;
		input(n, l, r);

		vi a(n);
		arrput(a);

		int c = 0, x = 0;
		for (int i : a) {
			c += i % r;
			x += i / r;
		}

		vector<vi> v(r + 1);
		for (int i : a) {
			for (int j : div[i]) {
				if (j > r) {
					break;
				}
				v[j].push_back(i);
			}
		}

		int res = c;
		for (int i = r - 1; i >= l; i--) {
			c += x;
			for (int j : v[i]) {
				c -= i;
				x = j / i;
			}
			cout << c << ' ';
			res = max(res, c);
		}
		print(res);
	}
}
