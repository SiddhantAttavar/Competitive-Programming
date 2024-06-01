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
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		vector<int> b(n, -1);
		priority_queue<pair<int, int>> pq;
		range(i, 0, n) {
			if (a[i] != -1) {
				b[i] = a[i];
				pq.push({a[i], i});
			}
		}

		if (pq.empty()) {
			b[0] = 1;
			pq.push({1, 0});
		}

		while (!pq.empty()) {
			int x, i;
			tie(x, i) = pq.top();
			pq.pop();

			int y = x / 2;
			if (x == 1) {
				y = 2;
			}

			if (i > 0 and b[i - 1] == -1) {
				b[i - 1] = y;
				pq.push({y, i - 1});
			}
			if (i < n - 1 and b[i + 1] == -1) {
				b[i + 1] = y;
				pq.push({y, i + 1});
			}
		}

		bool flag = true;
		range(i, 1, n) {
			if (b[i] / 2 != b[i - 1] and b[i - 1] / 2 != b[i]) {
				flag = false;
				break;
			}
		}

		if (flag) {
			arrPrint(b);
		}
		else {
			print(-1);
		}
	}
}
