#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353

char b[4][4];

void solve(vector<string> &a, int k, vector<string> &b, vector<string> &res) {
	if (k == a.size()) {
		vector<string> c(b.begin(), b.end());
		range(i, 0, 4) {
			range(j, 0, 4) {
				if (c[i][j] == '?') {
					c[i][j] = 'A';
				}
			}
		}
		res = min(res, c);
		return;
	}

	range(i, 0, 4) {
		string s = "????";
		bool flag = true;
		range(j, 0, 4) {
			s[j] = b[i][j];
			if (b[i][j] != '?' and b[i][j] != a[k][j]) {
				flag = false;
			}
			b[i][j] = a[k][j];
		}
		if (flag) {
			solve(a, k + 1, b, res);
		}
		range(j, 0, 4) {
			b[i][j] = s[j];
		}

		flag = true;
		range(j, 0, 4) {
			if (b[i][j] != '?' and b[i][j] != a[k][3 - j]) {
				flag = false;
			}
			b[i][j] = a[k][3 - j];
		}
		if (flag) {
			solve(a, k + 1, b, res);
		}
		range(j, 0, 4) {
			b[i][j] = s[j];
		}
	}

	range(j, 0, 4) {
		string s = "????";
		bool flag = true;
		range(i, 0, 4) {
			s[i] = b[i][j];
			if (b[i][j] != '?' and b[i][j] != a[k][i]) {
				flag = false;
			}
			b[i][j] = a[k][i];
		}
		if (flag) {
			solve(a, k + 1, b, res);
		}
		range(i, 0, 4) {
			b[i][j] = s[i];
		}

		flag = true;
		range(i, 0, 4) {
			if (b[i][j] != '?' and b[i][j] != a[k][3 - i]) {
				flag = false;
			}
			b[i][j] = a[k][3 - i];
		}
		if (flag) {
			solve(a, k + 1, b, res);
		}
		range(i, 0, 4) {
			b[i][j] = s[i];
		}
	}
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<string> v(n);
		arrPut(v);

		vector<string> a;
		for (string s : v) {
			string t = s;
			reverse(t.begin(), t.end());
			if (find(a.begin(), a.end(), s) == a.end() and find(a.begin(), a.end(), t) == a.end()) {
				a.push_back(min(s, t));
			}
		}

		if (a.size() > 8) {
			print("grid\nsnot\nposs\nible\n");
			continue;
		}

		vector<string> b(4, "????"), res = {"grid", "snot", "poss", "ible"};
		solve(a, 0, b, res);
		for (string s : res) {
			print(s);
		}
		print("");
	}
}
