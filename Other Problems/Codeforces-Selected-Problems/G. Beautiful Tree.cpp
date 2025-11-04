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
		int n;
		input(n);

		if (n == 2) {
			print(-1);
			continue;
		}

		if (n == 3) {
			print(1, 3);
			print(2, 3);
			continue;
		}

		if (n == 4) {
			print(1, 2);
			print(3, 1);
			print(4, 1);
			continue;
		}

		if (n % 2 == 1) {
			print(2, 4);
			print(4, 5);
			print(5, 1);
			print(1, 3);

			if (n >= 6) {
				print(1, 6);
				rep(i, 7, n) {
					print(2, i);
				}
				print(1, n);
			}
			continue;
		}

		if (n % 2 == 0) {
			print(3, 6);
			print(6, 2);
			print(2, 5);
			print(5, 1);
			print(1, 4);

			if (n >= 7) {
				print(1, 7);
				rep(i, 8, n) {
					print(2, i);
				}
				print(1, n);
			}
		}
	}
}
