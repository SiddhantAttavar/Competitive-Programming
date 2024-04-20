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
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

int32_t main() {
	setup();

	string s;
	input(s);

	reverse(s.begin(), s.end());
	while (s.size() % 3) {
		s += '0';
	}

	bool flag = false;
	int y = 0;
	for (int i = 0; i < s.size(); i += 3) {
		int x = 100 * (s[i + 2] - '0') + 10 * (s[i + 1] - '0') + (s[i] - '0');
		if (flag) {
			x = -x;
		}
		flag = !flag;
		y = (y + x + 1000) % MOD;
	}

	if (y % 7 == 0) {

	}
}
