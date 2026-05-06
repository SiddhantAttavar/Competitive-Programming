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

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) { b++; // (for right inclusive)
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vi p(n), a(n);
		arrput(p);
		arrput(a);

		vi l(n, 0), r(n, n - 1);
		stack<int> s;
		rep(i, 0, n) {
			while (!s.empty() and p[i] < p[s.top()]) {
				s.pop();
			}
			if (!s.empty()) {
				l[i] = s.top() + 1;
			}
			s.push(i);
		}
		while (!s.empty()) {
			s.pop();
		}
		for (int i = n - 1; i >= 0; i--) {
			while (!s.empty() and p[i] < p[s.top()]) {
				s.pop();
			}
			if (!s.empty()) {
				r[i] = s.top() - 1;
			}
			s.push(i);
		}

		vi v(n, 0);
		iota(all(v), 0);
		sort(all(v), [&](int i, int j) {
			return p[i] > p[j];
		});

		vector<pii> x(n);
		rep(i, 0, n) {
			x[i] = {p[i], i};
		}
		RMQ<pii> t(x);
		vector<vi> dp(n, vi(n + 1, 1e18));
		for (int i : v) {
			int p = i > l[i] ? t.query(l[i], i - 1).second : -1;
			int q = i < r[i] ? t.query(i + 1, r[i]).second : -1;

			dp[i][0] = 0;
			dp[i][1] = a[i];
			if (p != -1) {
				rep(x, 0, i - l[i] + 1) {
					dp[i][x] = min(dp[i][x], dp[p][x]);
					dp[i][x + 1] = min(dp[i][x + 1], dp[p][x] + a[i]);
				}
			}
			if (q != -1) {
				rep(y, 0, r[i] - i + 1) {
					dp[i][y] = min(dp[i][y], dp[q][y]);
					dp[i][y + 1] = min(dp[i][y + 1], dp[q][y] + a[i]);
				}
			}
			if (p != -1 and q != -1) {
				rep(x, 1, i - l[i] + 1) {
					rep(y, 1, r[i] - i + 1) {
						dp[i][x + y + 1] = min(dp[i][x + y + 1], dp[p][x] + dp[q][y] + a[i]);
					}
				}
			}
		}

		vi res = dp[v.back()];
		res.erase(res.begin());
		arrprint(res);
	}
}
