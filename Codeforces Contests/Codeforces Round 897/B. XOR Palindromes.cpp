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
		int n; input(n);

		string s; input(s);

		int x = 0, y = 0;
		range(i, 0, n / 2) {
			x += s[i] != s[n - i - 1];
			y += s[i] == s[n - i - 1];
		}

		vector<bool> res(n + 1, false);
		if (n % 2 == 0) {
			range(i, 0, y + 1) {
				res[x + 2 * i] = true;
			}
		}
		else {
			range(i, 0, y + 1) {
				res[x + 2 * i] = true;
				res[x + 2 * i + 1] = true;
			}
		}

		string t;
		for (bool b : res) {
			t += b + '0';
		}
		print(t);
	}
}
