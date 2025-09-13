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
		int n, k;
		input(n, k);

		vector<int> a(n);
		arrput(a);

		vector<int> v(n + 1);
		for (int i : a) {
			v[i]++;
		}

		bool flag = true;
		rep(i, 0, n + 1) {
			if (v[i] % k) {
				flag = false;
				break;
			}
		}

		if (!flag) {
			print(0);
			continue;
		}

		vector<int> c(n + 1);
		int x = 0, res = 0, l = 0;
		rep(i, 0, n) {
			x -= k * c[a[i]] > v[a[i]];
			c[a[i]]++;
			x += k * c[a[i]] > v[a[i]];
			while (x) {
				x -= k * c[a[l]] > v[a[l]];
				c[a[l]]--;
				x += k * c[a[l]] > v[a[l]];
				l++;
			}
			res += i - l + 1;
		}
		print(res);
	}
}
