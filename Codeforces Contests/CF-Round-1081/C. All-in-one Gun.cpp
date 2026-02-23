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
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

int get(vi &a, int i) {
	if (i == sz(a) - 1) {
		return accumulate(all(a), 0ll);
	}
	int x = accumulate(a.begin(), a.begin() + i + 1, 0ll);
	int l = *min_element(a.begin(), a.begin() + i + 1);
	int r = *max_element(a.begin() + i + 1, a.end());
	return x + max(0ll, r - l);
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, h, k;
		input(n, h, k);

		vi a(n);
		arrput(a);

		int s = accumulate(all(a), 0ll);
		int t = h / s;
		if (h % s == 0) {
			print(t * n + (t - 1) * k);
			continue;
		}

		int l = 0, r = n - 1, u = n;
		while (l <= r) {
			int m = (l + r) / 2;
			if (get(a, m) >= h % s) {
				u = m + 1;
				r = m - 1;
			}
			else {
				l = m + 1;
			}
		}
		print(t * (n + k) + u);
	}
}
