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
		range(i, 0, 3) {
			string s;
			input(s);
			bool flag = false;
			bool a = false, b = false, c = false;
			range(j, 0, 3) {
				if (s[j] == '?') {
					flag = true;
				}
				else if (s[j] == 'A') {
					a = true;
				}
				else if (s[j] == 'B') {
					b = true;
				}
				else {
					c = true;
				}
			}
			if (flag) {
				if (a and b) {
					print('C');
				}
				else if (b and c) {
					print('A');
				}
				else {
					print('B');
				}
			}
		}
	}
}
