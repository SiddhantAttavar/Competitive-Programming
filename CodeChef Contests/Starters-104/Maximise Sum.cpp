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
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		int j = max_element(a.begin(), a.end()) - a.begin();

		int c = 0, res = a[j];
		range(i, 1, j) {
			if (a[i] > a[c]) {
				res += (i - c) * a[c];
				c = i;
			}
		}
		res += (j - c) * a[c];

		c = n - 1;
		for (int i = n - 2; i > j; i--) {
			if (a[i] > a[c]) {
				res += (c - i) * a[c];
				c = i;
			}
		}
		res += (c - j) * a[c];

		print(res);
	}
}
