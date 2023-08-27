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

	int a, b;
	input(a, b);

	int x = ((a - b) % 9 + 9) % 9;
	
	string s = to_string(b);
	string r;
	range(i, 0, x) {
		r += '1';
	}
	s = r + s;

	stringstream ss(s);
	int k;
	ss >> k;

	bool flag = false;
	if (k < a) {
		flag = true;
		s = to_string(k);
		r = "";
		range(i, 0, 9) {
			r += '1';
		}
		s = r + s;

		ss = stringstream(s);
		ss >> k;
	}

	print("Stable");
	print(((k - a) > 0) + (x > 0 or flag));
	if (k - a) {
		print('+', (k - a) / 9);
	}
	if (x > 0 or flag) {
		print('-', x + flag * 9);
	}
}
