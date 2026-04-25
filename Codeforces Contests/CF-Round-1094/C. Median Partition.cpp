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

int median(vi &a, int i, int j) {
	vi b;
	rep(k, i, j + 1) {
		b.push_back(a[k]);
	}
	sort(all(b));
	return b[sz(b) / 2];
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vi a(n);
		arrput(a);

		vi b = a;
		sort(all(b));
		int x = b[n / 2];

		vi dp(n + 1, -1e18);
		dp[0] = 0;
		rep(i, 0, n) {
			int p = 0, q = 0;
			for (int j = i; j >= 0; j--) {
				p += a[j] < x;
				q += a[j] > x;
				if ((i % 2 == j % 2) and max(p, q) <= (i - j) / 2) {
					// assert(median(a, j, i) == x);
					dp[i + 1] = max(dp[i + 1], dp[j] + 1);
				}
			}
		}
		print(dp[n]);
	}
}
