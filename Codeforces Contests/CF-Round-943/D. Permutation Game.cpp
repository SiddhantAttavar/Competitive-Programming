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

int score(int n, int k, int i, vector<int> &p, vector<int> &a) {
	vector<int> d(n, -1), x(n, 0);
	queue<int> q;
	q.push(i);
	d[i] = 0;
	x[i] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();

		if (d[p[u]] != -1 or d[u] == k - 1) {
			break;
		}

		d[p[u]] = d[u] + 1;
		x[p[u]] = x[u] + a[u];
		q.push(p[u]);
	}

	int res = 0;
	range(j, 0, n) {
		if (d[j] != -1) {
			res = max(res, x[j] + (k - d[j]) * a[j]);
		}
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k, x, y;
		input(n, k, x, y);

		vector<int> p(n), a(n);
		arrPut(p);
		arrPut(a);

		range(i, 0, n) {
			p[i]--;
		}

		int s = score(n, k, x - 1, p, a);
		int t = score(n, k, y - 1, p, a);

		if (s == t) {
			print("Draw");
		}
		else if (s < t) {
			print("Sasha");
		}
		else {
			print("Bodya");
		}
	}
}
