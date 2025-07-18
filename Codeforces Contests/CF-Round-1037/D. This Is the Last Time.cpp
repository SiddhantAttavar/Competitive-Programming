#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
template<typename T> inline void dbg(T x) {cerr << x << '\n';}
template<typename T, typename... S> inline void dbg(T x, S... args) {cerr << x << ", "; dbg(args ...);}
#define debug(...) cerr << #__VA_ARGS__ << ": "; dbg(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<vector<int>> a(n);
		rep(i, 0, n) {
			int l, r, x;
			input(l, r, x);
			a[i] = {l, r, x};
		}

		sort(a.begin(), a.end(), [](vector<int> a, vector<int> b) {
			return a[2] < b[2];
		});

		if (k >= a[n - 1][2]) {
			print(k);
			continue;
		}

		for (int i = n - 2; i >= 0; i--) {
			a[i][0] = min(a[i][0], a[i + 1][0]);
			a[i][1] = max(a[i][0], a[i + 1][0]);
		}

		rep(i, 0, n) {
			if (a[i][1] < k) {
				continue;
			}
			if (a[i][0] > k) {
				break;
			}
			k = max(k, a[i][2]);
		}
		print(k);
	}
}
