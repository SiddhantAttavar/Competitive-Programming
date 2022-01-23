// https://codebreaker.xyz/problem/card
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
	int m, k;
	input(m, k);
	string s;
	input(s);
	deque<int> dq;
	range(i, 0, m) {
		dq.push_front(i);
	}
	for (char c : s) {
		if (c == 'A') {
			int x = dq.back();
			dq.pop_back();
			dq.push_front(x);
		}
		else if (c == 'B') {
			int x = dq.back();
			dq.pop_back();
			int y = dq.back();
			dq.pop_back();
			dq.push_front(y);
			dq.push_back(x);
		}
		else {
			break;
		}
	}
	range(i, 0, k - 1) {
		dq.pop_back();
	}
	cout << dq.back() << ' ';
	dq.pop_back();
	cout << dq.back() << ' ';
	dq.pop_back();
	cout << dq.back();
}
