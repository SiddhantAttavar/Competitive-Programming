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

bool check(vector<int> &a, int n, int k, int x) {
	int h = 1;
	while ((1 << h) <= n) {
		h++;
	}
	h++;

	vector<vector<int>> p(n, vector<int>(h, -1));
	range(i, 0, n) {
		int j = upper_bound(a.begin(), a.end(), a[i + 1] - x) - a.begin() - 1;
		j = min(j, (int) i);
		if (j == -1) {
			continue;
		}

		p[i][0] = j - 1;
		range(j, 1, h) {
			if (p[i][j - 1] == -1) {
				break;
			}
			p[i][j] = p[p[i][j - 1]][j - 1];
		}

		int u = i;
		range(j, 0, h) {
			if (!((1 << j) & (k - 1))) {
				continue;
			}

			u = p[u][j];
			if (u == -1) {
				break;
			}
		}

		if (u != -1 and a[n] - a[i + 1] + a[u + 1] >= x) {
			return true;
		}
	}
	return false;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<int> a(n);
		arrPut(a);

		vector<int> p(n + 1, 0);
		range(i, 0, n) {
			p[i + 1] = p[i] + a[i];
		}

		int l = 1, r = 2e14, res = 0;
		while (l <= r) {
			int m = (l + r) / 2;
			if (check(p, n, k, m)) {
				res = m;
				l = m + 1;
			}
			else {
				r = m - 1;
			}
		}
		print(res);
	}
}
