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
// #define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

pair<vector<vi>, vector<vi>> calc(vi &a, int k) {
	int n = sz(a);
	vector<vi> dp1(n, vi(k + 1, 0)), dp2(n, vi(k + 1, 0));
	rep(i, 0, n) {
		dp1[i][1] = a[i];
		rep(j, 2, k + 1) {
			dp1[i][j] = dp1[i][j - 1];
			if (i > 0) {
				dp1[i][j] = max({dp1[i][j], dp1[i - 1][j - 1], dp1[i - 1][j - 2] + a[i]});
			}
		}
	}
	rep(i, 0, n) {
		dp2[i][1] = a[i];
		if (k >= 2) {
			dp2[i][2] = a[i];
		}
		rep(j, 3, k + 1) {
			dp2[i][j] = dp2[i][j - 1];
			if (i > 0) {
				dp2[i][j] = max({dp2[i][j], dp2[i - 1][j - 2], dp2[i - 1][j - 3] + a[i]});
			}
		}
	}
	return {dp1, dp2};
}

vi brute(vi &a, int k) {
	int n = sz(a);
	vi res(n, 0);
	rep(s, 0, n) {
		rep(l, 0, s + 1) {
			std::priority_queue<int, vi, greater<int>> pq;
			int c = k - 2 * (s - l), z = 0;
			rep(r, l, n) {
				z += a[r];
				pq.push(a[r]);
				c -= r > s;
				if (c < 0) {
					break;
				}
				while (sz(pq) > c) {
					z -= pq.top();
					pq.pop();
				}
				res[s] = max(res[s], z);
			}
		}
		rep(r, s, n) {
			std::priority_queue<int, vi, greater<int>> pq;
			int c = k - 2 * (r - s), z = 0;
			for (int l = r; l >= 0; l--) {
				z += a[l];
				pq.push(a[l]);
				c -= l < s;
				if (c < 0) {
					break;
				}
				while (sz(pq) > c) {
					z -= pq.top();
					pq.pop();
				}
				res[s] = max(res[s], z);
			}
		}
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vi a(n);
		arrput(a);

		auto [dp1, dp2] = calc(a, k);

		reverse(all(a));
		auto [rdp1, rdp2] = calc(a, k);
		reverse(all(a));
		reverse(all(rdp1));
		reverse(all(rdp2));
		rdp1.push_back(vi(k + 1, 0));
		rdp2.push_back(vi(k + 1, 0));

		vi res(n);
		rep(i, 0, n) {
			res[i] = max(dp1[i][k], rdp1[i][k]);
			rep(x, 0, k) {
				res[i] = max(res[i], dp2[i][x] + rdp1[i + 1][k - x - 1]);
				if (x + 2 <= k) {
					res[i] = max(res[i], dp1[i][k - x - 2] + rdp2[i + 1][x]);
				}
			}
		}
		arrprint(res);
		// arrprint(brute(a, k));
		// cout.flush();
		// assert(res == brute(a, k));
	}
}
