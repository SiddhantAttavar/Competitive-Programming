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
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	cout << fixed << setprecision(20);
	setup(); int tc; input(tc); while (tc--) {
		int n, k, x;
		input(n, k, x);

		vector<int> a(n);
		arrput(a);

		multiset<pair<double, int>> m;
		for (int i : a) {
			m.insert({-i, 1});
		}

		while (k) {
			auto [x, y] = *m.begin();
			m.erase(m.begin());

			if (y <= k) {
				k -= y;
				m.insert({x / 2, y * 2});
				continue;
			}

			m.insert({x / 2, k * 2});
			m.insert({x, y - k});
			k = 0;
		}

		while (x) {
			auto [z, y] = *m.begin();
			m.erase(m.begin());

			if (y >= x) {
				print(-z);
				break;
			}
			x -= y;
		}
	}
}
