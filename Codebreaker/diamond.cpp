// https://codebreaker.xyz/problem/diamond
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

string strMul(char c, int x) {
	string res;
	while (x--) {
		res += c;
	}
	return res;
}

int32_t main() {
	setup();
	
	int r;
	input(r);
	range(i, 0, r) {
		cout << strMul(' ', r - i - 1) << strMul('*', 2 * i + 1) << endl;
	}
	for (int i = r - 2; i >= 0; i--) {
		cout << strMul(' ', r - i - 1) << strMul('*', 2 * i + 1) << endl;
	}
}
