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
	
	int l, n;
	input(l, n);

	string s1;
	input(s1);
	vector<int> s(l);
	range(i, 0, l) {
		s[i] = s1[i] - 'a';
	}

	vector<int> a(n), b(n);
	vector<int> c(n);
	vector<vector<int>> d(26, vector<int>(26, 1e16));
	range(i, 0, 26) {
		d[i][i] = 0;
	}

	range(i, 0, n) {
		char x, y;
		input(x, y, c[i]);
		a[i] = x - 'a';
		b[i] = y - 'a';
		d[a[i]][b[i]] = min(d[a[i]][b[i]], c[i]);
	}

	range(k, 0, 26) {
		range(i, 0, 26) {
			range(j, 0, 26) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	int res = 0;
	range(i, 0, l / 2) {
		int x = 1e16;
		range(j, 0, 26) {
			x = min(x, d[s[i]][j] + d[s[l - i - 1]][j]);
		}
		if (x >= (int) 1e16) {
			res = -1;
			break;
		}
		res += x;
	}
	print(res);
}
