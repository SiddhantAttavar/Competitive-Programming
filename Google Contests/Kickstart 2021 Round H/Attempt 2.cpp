#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	setup();
	int tc; input(tc);
	range(t, 1, tc + 1) {
		int n; input(n);
		string s; input(s);
		while (true) {
			bool flag = false;
			range(i, 0, 10) {
				string m;
				n = s.size();
				range(j, 0, n) {
					if (j < n - 1 and s[j] - '0' == i and (s[j + 1] - '0') == (i + 1) % 10) {
						flag = true;
						m += (char) ('0' + ((i + 2) % 10));
						j++;
					}
					else {
						m += s[j];
					}
				}
				s = m;
			}
			if (!flag) {
				break;
			}
		}

		cout << "Case #" << t << ": ";
		print(s);
	}
}