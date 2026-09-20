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
inline int mpow(int a, int b) {int x = 1; for (; b; a = a * a % MOD, b >>= 1) {if (b & 1) {x = x * a % MOD;}} return x;};
inline int mdiv(int a, int b) {return a * mpow(b, MOD - 2) % MOD;};

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, c;
		input(n, c);

		vector<vector<pii>> a(n), b(n);
		vector<vi> p(n);
		rep(i, 0, n) {
			int l;
			input(l);

			vi u(l), v(l);
			arrput(u);
			arrput(v);

			int x = 0, y = 0;
			p[i].push_back(0);
			rep(j, 0, l) {
				b[i].push_back({u[j], v[j] - u[j]});
				x -= u[j];
				y = max(y, -x);
				x += v[j];
				if (x >= 0) {
					a[i].push_back({y, x});
					x = 0;
					y = 0;
					p[i].push_back(j + 1);
			 	}
			}
		}

		std::priority_queue<pii, vector<pii>, greater<pii>> pq;
		vi v(n, 0);
		rep(i, 0, n) {
			if (!a[i].empty()) {
				pq.push({a[i][0].first, i});
			}
		}

		while (!pq.empty()) {
			auto [x, i] = pq.top();
			pq.pop();
			
			if (c < x) {
				break;
			}

			if (a[i][v[i]].second < 0) {
				continue;
			}

			c += a[i][v[i]].second;
			v[i]++;
			if (v[i] < sz(a[i])) {
				pq.push({a[i][v[i]].first, i});
			}
		}

		vi res(n);
		rep(i, 0, n) {
			int d = c, j = p[i][v[i]];
			while (j < sz(b[i]) and d >= b[i][j].first) {
				d += b[i][j].second;
				j++;
			}
			res[i] = j;
		}

		int i = max_element(all(res)) - res.begin();
		print(res[i], i + 1);
	}
}
