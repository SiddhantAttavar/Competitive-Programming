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
		int n, q;
		input(n, q);

		vector<int> a(n);
		arrput(a);

		sort(a.begin(), a.end());
		reverse(a.begin(), a.end());

		while (q--) {
			int c;
			input(c);

			std::priority_queue<int> pq;
			rep(i, 0, min(30ll, n)) {
				pq.push(a[i]);
			}
			int res = 0;
			for (int j = 29; j >= 0; j--) {
				if (!(c >> j & 1)) {
					continue;
				}

				int x = pq.top();
				pq.pop();

				if (x == 0) {
					res += c;
					break;
				}

				c ^= 1ll << j;
				int k = 63 - __builtin_clzll(x);
				if (k > j) {
					break;
				}
				else if (k < j) {
					res += (1ll << j) - x;
					pq.push(0);
				}
				else {
					x ^= 1ll << j;
					pq.push(x);
				}
			}
			print(res);
		}
	}
}
