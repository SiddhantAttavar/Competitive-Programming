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

bool check(string s) {
	range(i, 0, s.size()) {
		map<char, int> m;
		int x = 0;
		range(j, i, s.size()) {
			m[s[j]]++;
			x = max(x, m[s[j]]);
			if (2 * x < (j - i + 1)) {
				return false;
			}
		}
	}
	return true;
}

int solve(string s, string a) {
	// print(s, a);
	// print(s.size(), a.size());
	// print(s[a.size()], a + s[a.size()]);
	if (a.size() == s.size()) {
		return check(a);
	}

	if (s[a.size()] != '?') {
		return solve(s, a + s[a.size()]);
	}

	return (
		solve(s, a + '1') +
		solve(s, a + '2') +
		solve(s, a + '3')
	) % MOD;
}

int32_t main() {
	setup();

	int n;
	input(n);

	string s;
	input(s);

	print(solve("?", ""));
	print(solve("??", ""));
	print(solve("???", ""));
	print(solve("????", ""));
	print(solve("?????", ""));
	print(solve("??????", ""));
	print(solve("???????", ""));
	print(solve("????????", ""));
	print(solve("?????????", ""));
	print(solve("??????????", ""));
	print(solve("???????????", ""));
	print(solve("????????????", ""));

	print(solve(s, ""));
}
