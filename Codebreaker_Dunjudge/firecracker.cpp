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

	vector<pair<int, int>> a(n);
	range(i, 0, n) {
		input(a[i].first, a[i].second);
	}

	sort(a.begin(), a.end(), [](pair<int, int> x, pair<int, int> y) {
		if (x.first == y.first) {
			return x.second > y.second;
		}
		return x.first < y.first;
	});

	int res = 0;
	int c = 0, x = 0;
	vector<vector<int>> ind(n + 1);
	range(i, 0, n) {
		c += a[i].first + a[i].second;
		for (int j : ind[i]) {
			c -= a[j].first + a[j].second;
			x--;
		}
		x++;
		res = max(res, c - a[i].first * x);

		int j = lower_bound(
			a.begin(), 
			a.end(), 
			pair<int, int>{a[i].first + a[i].second, -1}
		) - a.begin();
		ind[j].push_back(i);
	}
	print(res);
}
