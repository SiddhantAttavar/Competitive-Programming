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

int str_to_int(string s) {
	int res = 0;
	for (char c : s) {
		res = 10 * res + (c - '0');
	}
	return res;
}

int32_t main() {
	set<int> p;
	range(i, 1, 1e5) {
		string s = to_string(i);
		string t = s;
		reverse(t.begin(), t.end());

		p.insert(str_to_int(s + t));
		s.pop_back();
		p.insert(str_to_int(s + t));
	}

	int res = 0;
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		res ^= *p.lower_bound(4 * n) - n;
	}
	print(res);
}
