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
	setup();

	int n, k;
	input(n, k);

	vi x(n);
	int a, b, c;
	input(x[0], a, b, c);
	rep(i, 1, n) {
		x[i] = (a * x[i - 1] + b) % c;
	}

	vi p(n + 1, 0), s(n + 1, 0);
	for (int l = 0; l < n; l += k) {
		int r = min(n, l + k) - 1;
		p[l] = x[l];
		s[r] = x[r];
		rep(i, l + 1, r + 1) {
			p[i] = p[i - 1] | x[i];
		}
		for (int i = r - 1; i >= l; i--) {
			s[i] = s[i + 1] | x[i];
		}
	}

	int res = 0;
	rep(i, 0, n - k + 1) {
		res ^= s[i] | p[i + k - 1];
	}
	print(res);
}
