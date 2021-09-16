#include <bits/stdc++.h>
using namespace std; typedef long long ll; typedef vector<int> vi;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(arr) for (auto &inVar : arr) {cin >> inVar;}
#define arrPrint(arr) for (auto &outVar : arr) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	setup();
	
	string s; input(s);
	int r; input(r);

	int n = s.size();
	int a[n] = {1};
	range(i, 1, n) {
		a[i] = a[i - 1] * (s[i] == s[i - 1]) + 1;
	}

	int u = 0;
	string res;
	while (u < n) {
		if (u + r <= n && a[u + r - 1] == r) {
			u += r;
		}
		else {
			res += s[u];
			u++;
		}
	}

	print(res);
}