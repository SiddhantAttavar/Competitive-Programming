#include <bits/stdc++.h>
#include <iostream>
#include <vector>
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
	
	int n;
	input(n);

	vector<int> a(n), b(n);
	arrPut(a);
	arrPut(b);

	vector<int> dp1(n, 0), dp2(n, 0);
	dp1[0] = a[0];
	dp2[0] = b[0];
	range(i, 1, n) {
		dp1[i] = max(dp1[i - 1], dp2[i - 1] + a[i]);
		dp2[i] = max(dp2[i - 1], dp1[i - 1] + b[i]);
	}

	print(max(dp1[n - 1], dp2[n - 1]));
}
