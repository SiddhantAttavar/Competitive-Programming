#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		string s, r;
		input(s, r);

		int x = 0, y = 0, z = 0;
		rep(i, 1, n) {
			if (s[i] == s[i - 1]) {
				if (s[i] == '0') {
					y++;
				}
				else {
					z++;
				}
			}
			else {
				x++;
			}
		}

		char c = s[0];
		bool flag = true;
		rep(i, 0, n - 1) {
			char d = x % 2 == 1 ? '0' ^ '1' ^ c : c;

			if (x == 0) {
				flag = false;
				break;
			}

			if (r[i] == '0' and z > 0) {
				z--;
				continue;
			}
			if (r[i] == '1' and y > 0) {
				y--;
				continue;
			}

			if (d != r[i]) {
				x--;
				continue;
			}
			if (c != r[i]) {
				c ^= '0' ^ '1';
				x--;
				continue;
			}

			if (x < 2) {
				flag = false;
				break;
			}
			x -= 2;
			if (r[i] == '0') {
				y++;
			}
			else {
				z++;
			}
		}

		if (flag) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
