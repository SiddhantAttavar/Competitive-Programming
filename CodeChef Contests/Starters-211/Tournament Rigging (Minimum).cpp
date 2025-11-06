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
	setup(); int tc; input(tc); while (tc--) {
		int n, w;
		input(n, w);

		int m = 1 << n;
		vector<int> res(2 * m - 1);
		rep(i, 0, m) {
			res[i + m - 1] = i + 1;
		}
		res.erase(res.begin() + w - 1 + m - 1);
		res.push_back(w);
		int k = 0;
		for (int i = m - 2; i >= 0; i--) {
			if (res[2 * i + 1] == w or res[2 * i + 2] == w) {
				res[i] = w;
				k += w != min(res[2 * i + 1], res[2 * i + 2]);
			}
			else {
				res[i] = min(res[2 * i + 1], res[2 * i + 2]);
			}
		}
		arrprint(res);
	}
}
