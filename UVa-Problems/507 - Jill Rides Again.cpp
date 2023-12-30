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
	setup(); int tc; input(tc); range(t, 0, tc) {
		int n;
		input(n);

		n--;
		vector<int> a(n);
		arrPut(a);

		int u = 0, x = 0;
		int m = 0;
		pair<int, int> res = {0, 0};
		range(i, 0, n) {
			if (x < 0) {
				x = 0;
				u = i;
			}

			x += a[i];
			if (x > m) {
				m = x;
				res = {u, i + 1};
			}
			else if (x == m) {
				if ((i + 1 - u) > (res.second - res.first)) {
					res = {u, i + 1};
				}
			}
		}

		if (m == 0) {
			printf("Route %d has no nice parts\n", t + 1);
		}
		else {
			printf("The nicest part of route %d is between stops %Ld and %Ld\n", t + 1, res.first + 1, res.second + 1);
		}
	}
}
