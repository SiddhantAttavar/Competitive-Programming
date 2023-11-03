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
	setup();

	string s;
	input(s);

	map<char, int> m;
	for (char c : s) {
		m[c]++;
	}

	char c = ' ';
	for (pair<char, int> p : m) {
		if (p.second % 2) {
			if (c == ' ') {
				c = p.first;
			}
			else {
				print("NO SOLUTION");
				return 0;
			}
		}
	}

	string res;
	for (pair<char, int> p : m) {
		res += string(p.second / 2, p.first);
	}

	cout << res;
	if (c != ' ') {
		cout << c;
	}
	reverse(res.begin(), res.end());
	print(res);
}
