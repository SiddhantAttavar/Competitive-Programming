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

vector<string> solve(int n) {
	if (n == 0) {
		return {"#"};
	}

	vector<string> a = solve(n - 1);
	vector<string> res(3 * a.size());
	range(i, 0, a.size()) {
		res[i] = a[i] + a[i] + a[i];
		res[i + a.size()] = a[i] + string(a.size(), '.') + a[i];
		res[i + 2 * a.size()] = a[i] + a[i] + a[i];
	}
	return res;
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<string> res = solve(n);
	for (string s : res) {
		print(s);
	}
}
