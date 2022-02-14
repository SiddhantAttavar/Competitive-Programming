// https://codebreaker.xyz/problem/typo
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
	
	string a, b;
	input(a, b);

	if (a == b) {
		print("Yes");
		return 0;
	}

	bool flag = false;
	range(i, 0, a.size() - 1) {
		swap(a[i], a[i + 1]);
		if (a == b) {
			print("Yes");
			flag = true;
			break;
		}
		swap(a[i], a[i + 1]);
	}
	if (!flag) {
		print("No");
	}
}
