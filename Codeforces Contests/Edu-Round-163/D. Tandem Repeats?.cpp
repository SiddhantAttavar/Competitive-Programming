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

bool check(string s, int l) {
	int n = s.size();

	int x = -1;
	range(i, l, n) {
		if (s[i] != '?' and s[i - l] != '?' and s[i] != s[i - l]) {
			x = i - l;
		}

		if (x <= i - 2 * l) {
			return true;
		}
	}

	return false;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		string s;
		input(s);

		int res = 0;
		range(i, 1, s.size() / 2 + 1) {
			if (check(s, i)) {
				res = 2 * i;
			}
		}

		print(res);
	}
}
