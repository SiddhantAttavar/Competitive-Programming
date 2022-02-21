#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
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
		input(a[i].first);
		a[i].second = i;
	}
	sort(a.begin(), a.end());

	int q;
	input(q);
	while (q--) {
		int m;
		input(m);
		vector<int> b(m);
		arrPut(b);

		int c = -1;
		bool flag = true;
		for (int i : b) {
			int j = lower_bound(a.begin(), a.end(), pair<int, int>{i, c + 1}) - a.begin();
			if (j == n or a[j].first != i) {
				// print(i, j, c, a[j].first, a[j].second);
				flag = false;
				break;
			}
			c = a[j].second;
		}
		if (flag) {
			print("TAK");
		}
		else {
			print("NIE");
		}
	}
}
