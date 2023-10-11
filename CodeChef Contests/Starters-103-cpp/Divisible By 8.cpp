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
		int x;
		input(x);
		string n;
		input(n);

		if (x == 1) {
			n = "00" + n;
		}
		else if (x == 2) {
			n = '0' + n;
		}
		x = max(x, 3ll);

		int a = 100 * (n[x - 3] - '0') + 10 * (n[x - 2] - '0') + (n[x - 1] - '0');
		if (a % 8 == 0) {
			if (n[0] == '0') {
				if (n[1] == '0') {
					n = n.substr(2, x - 2);
				}
				else {
					n = n.substr(1, x - 1);
				}
			}
			print(n);
			continue;
		}
		range(i, 0, 10) {
			a = 100 * (n[x - 3] - '0') + 10 * (n[x - 2] - '0') + i;
			if (a % 8 == 0) {
				n = n.substr(0, x - 1) + (char) ('0' + i);
				if (n[0] == '0') {
					if (n[1] == '0') {
						n = n.substr(2, x - 2);
					}
					else {
						n = n.substr(1, x - 1);
					}
				}
				print(n);
				break;
			}
		}
	}
}
