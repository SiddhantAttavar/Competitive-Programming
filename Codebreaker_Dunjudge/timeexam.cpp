// https://codebreaker.xyz/problem/timeexam
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
	int n;
	input(n);

	n %= 24 * 60;
	int h = n / 60;
	int m = n % 60;
	if (h < 10) {
		cout << '0' << h;
	}
	else {
		cout << h;
	}
	if (m < 10) {
		cout << '0' << m;
	}
	else {
		cout << m;
	}
	cout << endl;
}
