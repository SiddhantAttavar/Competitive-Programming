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

		string s;
		input(s);

		int a = 1, b = 2;

		bool flag = true;
		vector<pair<int, int>> res(n);
		rep(i, 0, n) {
			if (a <= 2 * n and (b > 2 * n or a < b)) {
				res[i].first = a;
				a += 2;
			}
			else {
				res[i].first = b;
				b += 2;
			}

			if (res[i].first % 2 == (s[i] == 'O')) {
				if (b > 2 * n) {
					flag = false;
					break;
				}
				res[i].second = b;
				b += 2;
			}
			else {
				if (a > 2 * n) {
					flag = false;
					break;
				}
				res[i].second = a;
				a += 2;
			}
		}

		if (!flag) {
			print("NO");
			continue;
		}

		rep(i, 1, res.size()) {
			assert(res[i].first + res[i].second >= res[i - 1].first + res[i - 1].second);
		}

		print("YES");
		for (pair<int, int> p : res) {
			print(p.first, p.second);
		}
	}
}
