#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		string s, t;
		input(s, t);

		string res(1, s[0]);
		range(i, 0, n - 1) {
			if (s[i + 1] > t[i]) {
				res += t.substr(i, n - i);
				break;
			}
			res += s[i + 1];
		}
		if (res.size() == n) {
			res += t[n - 1];
		}

		int l = 0;
		while (l + 1 < n and res[l + 1] == s[l + 1]) {
			l++;
		}

		int r = 0;
		while (n - r - 2 >= 0 and res[n - r - 1] == t[n - r - 2]) {
			r++;
		}

		// print(l, r);
		print(res);
		print(l - (n - r) + 2);
	}
}
