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
#pragma GCC optimize "trapv"

int32_t main() {
	setup(); long long tc; input(tc); while (tc--) {
		long long n;
		input(n);

		string s;
		input(s);

		if (s[0] == '?') {
			string res = "1";
			range(i, 1, n) {
				if (s[i] == '?') {
					res += '0';
				}
			}
			print(res);
			continue;
		}

		int x = 0;
		for (char c : s) {
			if (c != '?') {
				x = (x + (c - '0')) % 9;
			}
		}

		string res;
		range(i, 0, n) {
			if (s[i] == '?') {
				res += '1';
			}
		}
		if (x == 0) {
			res = res.substr(0, res.size() - 1);
			res += '2';
		}

		print(res);
	}
}
