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

int32_t main() {
	setup();

	int n, m, k;
	input(n, m, k);

	int u, v;
	input(u, v);
	u--;
	v--;
	
	vector<vector<int>> a(n, vector<int>(m));
	range(i, 0, n) {
		arrPut(a[i]);
	}

	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({{0, 0}, {u, v}});
	int res = 0;
	range(i, 0, 1e6) {
		int x, y;
		tie(x, y) = q.front().second;

		int e, b;
		tie(e, b) = q.front().first;
		q.pop();
		if (b > k) {
			break;
		}
		res = max(res, e + (k - b) * a[x][y]);

		if (x > 0) {
			q.push({{e + a[x - 1][y], b + 1}, {x - 1, y}});
		}
		if (x < n - 1) {
			q.push({{e + a[x + 1][y], b + 1}, {x + 1, y}});
		}
		if (y > 0) {
			q.push({{e + a[x][y - 1], b + 1}, {x, y - 1}});
		}
		if (y < m - 1) {
			q.push({{e + a[x][y + 1], b + 1}, {x, y + 1}});
		}
	}

	print(res);
}
