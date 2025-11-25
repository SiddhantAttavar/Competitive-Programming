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

		if (k % 2) {
			print("No");
			continue;
		}

		if (n == 2 and k == 2) {
			print("Yes");
			print(1, 0);
			print(0, 1);
			continue;
		}

		if (k % 4 == 2 and (k == 2 or k == n * n - 2)) {
			print("No");
			continue;
		}

		vector<vector<bool>> res(n, vector<bool>(n, false));
		if (k % 4 == 0) {
			for (int i = 0; i < n; i += 2) {
				for (int j = 0; j < n; j += 2) {
					if (k) {
						res[i][j] = true;
						res[i + 1][j] = true;
						res[i][j + 1] = true;
						res[i + 1][j + 1] = true;
						k -= 4;
					}
				}
			}
		}
		else {
			res[0][1] = true;
			res[0][2] = true;
			res[1][0] = true;
			res[1][2] = true;
			res[2][0] = true;
			res[2][1] = true;
			k -= 6;
			if (k) {
				res[2][2] = true;
				res[2][3] = true;
				res[3][2] = true;
				res[3][3] = true;
				k -= 4;
			}
			for (int i = 0; i < n; i += 2) {
				for (int j = 0; j < n; j += 2) {
					if (k and (i >= 4 or j >= 4)) {
						res[i][j] = true;
						res[i + 1][j] = true;
						res[i][j + 1] = true;
						res[i + 1][j + 1] = true;
						k -= 4;
					}
				}
			}
		}

		print("Yes");
		rep(i, 0, n) {
			arrprint(res[i]);
		}
	}
}
