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
	setup();

	int n;
	input(n);

	string s;
	input(s);

	vector<int> c(n);
	arrPut(c);

	vector<int> pref0(n), pref1(n), suff0(n), suff1(n);
	pref0[0] = c[0] * (s[0] == '1');
	pref1[0] = c[0] * (s[0] == '0');
	range(i, 1, n) {
		if (s[i] == '0') {
			pref0[i] = pref0[i - 1] + c[i] * (i % 2 == 1);
			pref1[i] = pref1[i - 1] + c[i] * (i % 2 == 0);
		}
		else {
			pref0[i] = pref0[i - 1] + c[i] * (i % 2 == 0);
			pref1[i] = pref1[i - 1] + c[i] * (i % 2 == 1);
		}
	}

	suff0[n - 1] = c[n - 1] * (s[n - 1] == '1');
	suff1[n - 1] = c[n - 1] * (s[n - 1] == '0');
	for (int i = n - 2; i >= 0; i--) {
		if (s[i] == '0') {
			suff0[i] = suff0[i + 1] + c[i] * ((n - i) % 2 == 0);
			suff1[i] = suff1[i + 1] + c[i] * ((n - i) % 2 == 1);
		}
		else {
			suff0[i] = suff0[i + 1] + c[i] * ((n - i) % 2 == 1);
			suff1[i] = suff1[i + 1] + c[i] * ((n - i) % 2 == 0);
		}
	}

	int res = 1e15;
	range(i, 0, n - 1) {
		if (n % 2 == 0) {
			res = min({res, pref0[i] + suff0[i + 1], pref1[i] + suff1[i + 1]});
		}
		else {
			res = min({res, pref0[i] + suff1[i + 1], pref1[i] + suff0[i + 1]});
		}
	}

	print(res);
}
