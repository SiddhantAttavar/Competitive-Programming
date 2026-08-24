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

int32_t main() {
	setup();

	int n, k;
	input(n, k);

	vi a(n);
	arrput(a);

	rep(i, 0, n) {
		a[i] -= i;
	}

	vector<vi> c(n, vi(n));
	rep(i, 0, n) {
		std::priority_queue<int> p;
		std::priority_queue<int, vector<int>, greater<int>> q;
		int x = 0, y = 0;
		rep(j, i, n) {
			x += a[j];
			p.push(a[j]);
			while (true) {
				if (sz(p) > sz(q)) {
					x -= p.top();
					y += p.top();
					q.push(p.top());
					p.pop();
				}
				else if (sz(q) > sz(p) + 1) {
					y -= q.top();
					x += q.top();
					p.push(q.top());
					q.pop();
				}
				else if (p.top() > q.top()) {
					x -= p.top();
					y += p.top();
					q.push(p.top());
					p.pop();
				}
				else {
					break;
				}
			}
			int t = q.top();
			c[i][j] = (sz(p) * t - x) + (y - sz(q) * t);
		}
	}

	vector<vi> dp(n, vi(k, 1e18));
	rep(i, 0, n) {
		dp[i][0] = c[0][i];
	}
	rep(x, 1, k) {
		rep(i, 0, n) {
			rep(j, 0, i) {
				dp[i][x] = min(dp[i][x], dp[j][x - 1] + c[j + 1][i]);
			}
		}
	}
	print(dp[n - 1][k - 1]);
}
