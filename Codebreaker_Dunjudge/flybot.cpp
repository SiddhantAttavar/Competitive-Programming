// https://codebreaker.xyz/problem/flybot
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
	
	int h, w;
	input(h, w);
	
	vector<vector<int>> a(h, vector<int>(w));
	range(i, 0, h) {
		string s;
		input(s);
		range(j, 0, w) {
			a[i][j] = s[j] == '.';
		}
	}

	range(i, 1, h) {
		a[i][0] *= a[i - 1][0];
	}
	range(j, 1, w) {
		a[0][j] *= a[0][j - 1];
	}
	range(i, 1, h) {
		range(j, 1, w) {
			if (!a[i][j]) {
				continue;
			}
			a[i][j] = 0;
			if (a[i - 1][j]) {
				a[i][j] = a[i - 1][j];
			}
			if (a[i][j - 1]) {
				a[i][j] = (a[i][j] + a[i][j - 1]) % 1000000007;
			}
		}
	}
	print(a[h - 1][w - 1]);
}
