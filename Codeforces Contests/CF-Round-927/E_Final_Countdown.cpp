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

		string s;
		input(s);

		int z = -1;
		while (s[z + 1] == '0') {
			z++;
		}
		s = s.substr(z + 1, n - z - 1);
		n -= z + 1;

		int x = 0;
		for (char c : s) {
			x += c - '0';
		}
		// print(x);

		string res;
		int c = 0;
		for (int i = n - 1; i >= 0; i--) {
			int y = x + c;
			// print(x, y, c);
			res += '0' + (y % 10);
			c = y / 10;
			x -= s[i] - '0';
		}

		if (c) {
			string t = to_string(c);
			// print(t);
			reverse(t.begin(), t.end());
			res += t;
		}

		reverse(res.begin(), res.end());
		print(res);
	}
}
