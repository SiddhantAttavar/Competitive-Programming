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

	int n, m, MOD = 998244353;
	vector<pair<int, int>> a, b;

	input(n);
	a.resize(n);
	range(i, 0, n) {
		input(a[i].first);
	}
	range(i, 0, n) {
		input(a[i].second);
	}

	input(m);
	b.resize(m);
	range(i, 0, m) {
		input(b[i].first);
	}
	range(i, 0, m) {
		input(b[i].second);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int i = 0, j = 0;
	int res = 1;
	while (i < n or j < m) {
		if ((i == n) or (j < m and b[j].first < a[i].first)) {
			print(0);
			return 0;
		}
		else if ((j == m) or (i < n and a[i].first < b[j].first)) {
			i++;
			res = (res * 2) % MOD;
		}
		else {
			if (b[j].second > a[i].second) {
				print(0);
				return 0;
			}
			if (b[j].second != a[i].second) {
				res = (res * 2) % MOD;
			}
			i++;
			j++;
		}
	}

	print(res);
}
