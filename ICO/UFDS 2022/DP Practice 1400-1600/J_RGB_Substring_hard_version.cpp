#include <bits/stdc++.h>
#include <iostream>
#include <vector>
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

		string s;
		input(s);

		vector<int> a(n);
		range(i, 0, n) {
			if (s[i] == 'R') {
				a[i] = 0;
			}
			else if (s[i] == 'G') {
				a[i] = 1;
			}
			else if (s[i] == 'B') {
				a[i] = 2;
			}
		}

		int res = 1e9;
		range(s, 0, 3) {
			int c = 0;
			range(i, 0, k) {
				c += (s + i) % 3 != a[i];
			}
			res = min(res, c);
			range(i, k, n) {
				c += ((s + i) % 3 != a[i]) - ((s + i - k) % 3 != a[i - k]);
				res = min(res, c);
			}
		}

		print(res);
	}
}
