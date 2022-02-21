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
	freopen("cowtip.in", "r", stdin);
	freopen("cowtip.out", "w", stdout);
	
	int n;
	input(n);

	vector<vector<bool>> a(n, vector<bool>(n));
	range(i, 0, n) {
		string s;
		input(s);
		range(j, 0, n) {
			a[i][j] = s[j] == '1';
		}
	}

	int res = 0;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			if (a[i][j]) {
				range(k, 0, i + 1) {
					range(l, 0, j + 1) {
						a[k][l] = !a[k][l];
					}
				}
				res++;
			}
		}
	}
	
	print(res);
}
