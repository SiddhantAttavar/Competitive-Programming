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

		string s;
		input(s);

		int x = 0;
		for (char c : s) {
			x += c == 'B';
		}

		if (x == k) {
			print(0);
			continue;
		}

		if (x > k) {
			range(i, 0, n) {
				x -= s[i] == 'B';
				if (x == k) {
					print(1);
					print(i + 1, 'A');
					break;
				}
			}
		}
		else {
			range(i, 0, n) {
				x -= s[i] == 'B';
				if (x + i + 1 == k) {
					print(1);
					print(i + 1, 'B');
					break;
				}
			}
		}
	}
}
