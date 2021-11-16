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

int n, q;

void solve1() {
	vector<pair<int, int>> m(n);
	stack<int> s;
	range(i, 0, n) {
		int t; input(t);
		if (t == 1) {
			int x; input(x);
			m[i] = {1, x};
			s.push(x);
		}
		else {
			m[i] = {2, s.top()};
			s.pop();
		}
	}
	while (q--) {
		int a, b;
		input(a, b);
		int ad = 0, bd = 0;
		int res = 0;
		for (pair<int, int> p : m) {
			if (p.first == 1) {
				if (p.second == a) {
					ad++;
				}
				else if (p.second == b) {
					bd++;
				}
				if (ad > 0 and bd > 0) {
					res++;
				}
			}
			else {
				if (p.second == a) {
					ad--;
				}
				else if (p.second == b) {
					bd--;
				}
			}
		}
		print(res);
	}
}

void solve2() {
	stack<int> s;
	map<int, int> m;
	range(i, 0, n) {
		int t, x; input(t);
		if (t == 1) {
			input(x);
			s.push(x);
			if (m.find(x) == m.end()) {
				m[x] = i;
			}
		}		
		else {
			s.pop();
		}
	}
	while (q--) {
		int a, b; input(a, b);
		if (m.find(a) != m.end() and m.find(b) != m.end()) {
			print(n - max(m[a], m[b]));
		}
		else {
			print(0);
		}
	}
}

int32_t main() {
	setup();
	input(n, q);
	if (n * q <= 10000000) {
		solve1();
	}
	else {
		solve2();
	}
}