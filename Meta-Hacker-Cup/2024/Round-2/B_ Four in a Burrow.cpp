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

int a, b, c, d;
set<int> vis;

bool check(vector<string> &s, vector<int> &v, int i, int j, char c) {
	range(k, max(0ll, j - 3), min(4ll, j + 1)) {
		bool flag = true;
		range(l, k, k + 4) {
			if (v[l] - 1 >= i or s[i][l] != c) {
				flag = false;
				break;
			}
		}
		if (flag) {
			return true;
		}
	}

	if (i > 2) {
		return false;
	}

	bool flag = true;
	range(k, i, i + 4) {
		if (s[k][j] != c) {
			flag = false;
			break;
		}
	}
	if (flag) {
		return true;
	}

	if (j >= 3) {
		flag = true;
		range(k, 0, 4) {
			if (v[j - k] - 1 >= i + k or s[i + k][j - k] != c) {
				flag = false;
				break;
			}
		}
		if (flag) {
			return true;
		}
	}

	if (j <= 3) {
		flag = true;
		range(k, 0, 4) {
			if (v[j + k] - 1 >= i + k or s[i + k][j + k] != c) {
				flag = false;
				break;
			}
		}
		if (flag) {
			return true;
		}
	}

	return false;
}

void solve(vector<string> &s, vector<int> &v, int t) {
	int y = 0;
	for (int i : v) {
		y = 10 * y + i;
	}
	if (vis.count(y)) {
		return;
	}
	vis.insert(y);

	char x = t % 2 ? 'F' : 'C';
	range(j, 0, 7) {
		if (v[j] == 0 or s[v[j] - 1][j] != x) {
			continue;
		}

		vector<int> w(v.begin(), v.end());
		w[j]--;
		if (check(s, w, w[j], j, x)) {
			if (x == 'C') {
				a = min(a, t);
				b = max(b, t);
			}
			else {
				c = min(c, t);
				d = max(d, t);
			}
		}
		else {
			solve(s, w, t + 1);
		}
	}
}

int32_t main() {
	setup(); int tc; input(tc); range(t, 0, tc) {
		vector<string> s(6);
		arrPut(s);

		a = c = 1e9;
		b = d = -1;
		vis.clear();

		vector<int> v(7, 6);
		solve(s, v, 0);

		cout << "Case #" << t + 1 << ": ";
		if (b != -1 and (b < c or d == -1)) {
			cout << "C\n";
		}
		else if (d != -1 and (d < a or b == -1)) {
			cout << "F\n";
		}
		else if (b == -1 and d == -1) {
			cout << "0\n";
		}
		else {
			cout << "?\n";
		}
		cout.flush();
	}
}
