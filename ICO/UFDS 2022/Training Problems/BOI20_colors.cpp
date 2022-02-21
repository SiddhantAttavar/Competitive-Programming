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
	// setup();
	
	int n;
	input(n);
	
	int l = 0, r = n, c = 0;
	bool flag = false;
	while (l + 1 < r) {
		int m = (l + r) / 2;
		if (flag) {
			c -= m;
		}
		else {
			c += m;
		}
		l = m;
		flag = !flag;
	}

	if (c < 0) {
		c = -c;
	}

	l = 0;
	r = n;
	print("? ", c);
	bool f;
	input(f);
	set<int> done;
	while (l + 1 < r) {
		int m = (l + r) / 2;
		if (c + m <= n and !done.count(c + m)) {
			c += m;
		}
		else if (c - m >= 1 and !done.count(c - m)) {
			c -= m;
		}
		else {
			c = 1;
			print("? ", c);
			bool b;
			input(b);
			done.insert(1);
			continue;
		}

		print("? ", c);
		done.insert(c);

		bool b;
		input(b);
		if (b) {
			r = m;
		}
		else {
			l = m;
		}
	}
	print("= ", r);
}
