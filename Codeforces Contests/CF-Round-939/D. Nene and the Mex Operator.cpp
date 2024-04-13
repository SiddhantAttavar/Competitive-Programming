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
const int MOD = (int) 1e9 + 7;

void solve(vector<int> &a, int i, vector<pair<int, int>> &res, int l) {
	if (i == l) {
		return;
	}

	solve(a, i - 1, res, l);
	if (a[i] == i - l - 1) {
		return;
	}

	a[i] = i - l - 1;
	res.push_back({l + 2, i + 1});
	solve(a, i - 1, res, l);
}

int32_t main() {
	setup();
	int n;
	input(n);

	vector<int> a(n);
	arrPut(a);

	int res = 0, m = 0;
	range(i, 0, 1 << n) {
		int x = 0, c = 0;
		range(j, 0, n) {
			if ((1 << j) & i) {
				c++;
			}
			else {
				x += c * c + a[j];
				c = 0;
			}
		}
		x += c * c;

		if (x > res) {
			res = x;
			m = i;
		}
	}

	vector<pair<int, int>> l;
	int c = 0;
	range(j, 0, n) {
		if ((1 << j) & m) {
			c++;
		}
		else {
			if (c) {
				solve(a, j - 1, l, j - 1 - c);
				l.push_back({j - c + 1, j});
				range(i, j - c, j) {
					a[i] = c;
				}
			}
			c = 0;
		}
	}
	if (c) {
		solve(a, n - 1, l, n - 1 - c);
		l.push_back({n - c + 1, n});
		range(i, n - c, n) {
			a[i] = c;
		}
	}

	print(res, l.size());
	for (pair<int, int> p : l) {
		print(p.first, p.second);
	}
}
