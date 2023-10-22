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
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<int> a(n);
		arrPut(a);

		if (k == 4) {
			int res = 2;
			for (int i : a) {
				res -= (i % 2 == 0) + (i % 4 == 0);
			}

			if (res <= 0) {
				print(0);
				continue;
			}

			for (int i : a) {
				if ((i + 1) % 4 == 0 or (res == 1)) {
					res = 1;
					break;
				}
			}
			if (res == 1) {
				print(res);
			}
			else {
				print(2);
			}
		}
		else {
			int res = 10;
			for (int i : a) {
				if (i % k == 0) {
					res = 0;
				}
				else {
					res = min(res, k - i % k);
				}
			}
			print(res);
		}
	}
}
