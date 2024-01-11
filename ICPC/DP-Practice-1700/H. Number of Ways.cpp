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

	int n;
	input(n);

	vector<int> a(n);
	arrPut(a);

	int s = 0;
	for (int i : a) {
		s += i;
	}

	if (s % 3 != 0) {
		print(0);
		return 0;
	}

	if (s == 0) {
		int x = 0;
		int c = 0;
		for (int i : a) {
			x += i;
			if (x == 0) {
				c++;
			}
		}
		print((c - 1) * (c - 2) / 2);
		return 0;
	}

	vector<int> pref(n + 1, 0);
	map<int, int> m;
	int res = 0;
	range(i, 0, n) {
		pref[i + 1] = pref[i] + a[i];
		if (pref[i + 1] % 2 == 0 and 3 * pref[i + 1] / 2 == s) {
			res += m[pref[i + 1] / 2];
		}
		m[pref[i + 1]]++;
	}

	print(res);
}
