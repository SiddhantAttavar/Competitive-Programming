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
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<int> a(n), b(n);
		arrPut(a);
		arrPut(b);

		vector<pair<int, int>> p(n);
		range(i, 0, n) {
			p[i] = {b[i], a[i]};
		}
		sort(p.begin(), p.end());

		int x = 0;
		range(i, 0, n) {
			x += max(0ll, b[i] - a[i]);
		}

		priority_queue<int, vector<int>, greater<int>> pq;
		int y = 0;
		for (int i = n - 1; i >= n - k; i--) {
			int a, b;
			tie(b, a) = p[i];
			pq.push(-a);
			y += a;
			x -= max(0ll, b - a);
		}

		int res = x - y;
		for (int i = n - k - 1; i >= 0; i--) {
			int a, b;
			tie(b, a) = p[i];

			x -= max(0ll, b - a);
			pq.push(-a);
			y += a + pq.top();
			pq.pop();
			res = max(res, x - y);
		}

		print(max(0ll, res));
	}
}
