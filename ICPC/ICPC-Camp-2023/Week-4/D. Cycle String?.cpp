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
	int n = (int) s.size() / 2;
	map<char, int> m;
	for (char c : s) {
		m[c]++;
	}

	char c = '0';
	for (pair<char, int> p : m) {
		if (p.second > n) {
			c = p.first;
			break;
		}
	}

	if (c == '0') {
		print("YES");
		string res;
		for (pair<char, int> p : m) {
			range(i, 0, p.second) {
				res += p.first;
			}
		}
		print(res);
		return 0;
	}

	if ((m[c] >= 2 * n - 1) or (m[c] == 2 * n - 2 and m.size() == 2)) {
		print("NO");
		return 0;
	}

	char x;
	for (pair<char, int> p : m) {
		if (p.first != c) {
			x = p.first;
			break;
		}
	}

	string res;
	range(i, 0, n) {
		res += c;
	}
	res += x;
	range(i, 0, m[c] - n) {
		res += c;
	}
	for (pair<char, int> p : m) {
		if (p.first == c) {
			continue;
		}
		range(i, 0, p.second - (p.first == x)) {
			res += p.first;
		}
	}

	print("YES");
	print(res);
}
