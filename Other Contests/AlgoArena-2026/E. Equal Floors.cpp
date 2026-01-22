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

vector<pii> get(int a) {
	vector<pii> res;
	int x = a;
	while (x > 0) {
		int k = a / x;
		int y = a / (k + 1) + 1;
		res.push_back({k, (x - y + 1) % MOD});
		x = y - 1;
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int a, b;
		input(a, b);

		vector<pii> x = get(a), y = get(b);
		vector<pii> z(sz(x) + sz(y));
		merge(all(x), all(y), z.begin());
		int res = 0;
		rep(i, 1, sz(z)) {
			if (z[i].first == z[i - 1].first) {
				res = (res + z[i].second * z[i - 1].second) % MOD;
			}
		}
		print(res);
	}
}
