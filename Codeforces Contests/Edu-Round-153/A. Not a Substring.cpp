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
		string s;
		input(s);

		if (s == "()") {
			print("NO");
			continue;
		}

		print("YES");

		bool flag = false;
		bool b = true;
		for (char c : s) {
			if (c == ')') {
				flag = true;
			}
			else if (flag) {
				b = false;
				break;
			}
		}

		string res;
		if (b) {
			range(i, 0, (int) s.size()) {
				res += "()";
			}
		}
		else {
			range(i, 0, (int) s.size()) {
				res += '(';
			}
			range(i, 0, (int) s.size()) {
				res += ')';
			}
		}
		print(res);
	}
}
