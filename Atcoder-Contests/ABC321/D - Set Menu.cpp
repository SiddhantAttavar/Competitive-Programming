#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	setup();

	int n, m, p;
	input(n, m, p);
	vector<int> a(n), b(m);
	arrPut(a);
	arrPut(b);

	sort(b.begin(), b.end());

	vector<int> pref(m + 1, 0);
	range(i, 0, m) {
		pref[i + 1] = pref[i] + b[i];
	}

	int res = 0;
	for (int i : a) {
		int x = lower_bound(b.begin(), b.end(), p - i) - b.begin();
		// print(res, i, x, pref[x], p, m);
		res += i * x + pref[x] + p * (m - x);
	}
	print(res);
}
