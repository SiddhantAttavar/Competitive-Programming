#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, x, y;
		input(n, x, y);

		vector<int> a(x);
		arrPut(a);
		sort(a.begin(), a.end());
		range(i, 0, x) {
			a[i]--;
		}

		vector<int> q;
		int p = 0;
		int r = 0;
		range(i, 0, x) {
			int t = (a[(i + 1) % x] - a[i] + n) % n;
			if (t % 2 == 0) {
				q.push_back(t / 2 - 1);
				r += t / 2 - 1;
			}
			else {
				p += t / 2;
				r += t / 2;
			}
		}

		sort(q.begin(), q.end());

		int k = 0;
		r = min(r, y);
		int res = 2 * r + x - 2;
		range(i, 0, q.size()) {
			k += q[i];
			if (k > y) {
				break;
			}

			res = max(res, i + 1 + 2 * r + x - 2);
		}

		print(res);

	}
}
