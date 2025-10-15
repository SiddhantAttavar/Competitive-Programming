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
		rep(i, 0, n) {
			a[i] = i + 1;
		}

		if (k == 0) {
			arrprint(a);
			continue;
		}

		int x = 1ll << (63 - __builtin_clzll(k));
		if (x > n) {
			print(-1);
			continue;
		}

		if (x < k) {
			int y = x ^ k;
			a.erase(a.begin() + y - 1);
			a.insert(a.begin() + x - 1, y);
			arrprint(a);
			continue;
		}

		if (x == n) {
			print(-1);
			continue;
		}

		if (x == 1) {
			if (n == 2) {
				print(-1);
			}
			else {
				swap(a[1], a[2]);
				arrprint(a);
			}
			continue;
		}

		a.erase(a.begin());
		a.insert(a.begin() + x - 1, 1);
		swap(a[x - 2], a[x]);
		arrprint(a);
	}
}
