// https://codebreaker.xyz/problem/smurf
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
	vector<int> a(n), b(n);
	arrPut(b);
	reverse(b.begin(), b.end());
	int l = 0, r = n - 1;
	bool flag = true;
	range(i, 0, n) {
		if (flag) {
			a[l] = b[i];
			l++;
		}
		else {
			a[r] = b[i];
			r--;
		}
		flag = !flag;
	}
	arrPrint(a);
}
