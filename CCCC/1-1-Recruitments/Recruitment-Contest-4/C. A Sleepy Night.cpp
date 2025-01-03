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
	int n, q;
	input(n, q);

	vector<int> a(n);
	arrPut(a);
	sort(a.begin(), a.end());

	while (q--) {
		int x;
		input(x);

		int i = lower_bound(a.begin(), a.end(), x) - a.begin();
		if (i < n and a[i] == x) {
			print(0);
		}
		else {
			if (i % 2 == 0) {
				print(1);
			}
			else {
				print(-1);
			}
		}
	}
}
