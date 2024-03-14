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
		int n;
		input(n);

		vector<int> a(n), b(n);
		arrPut(a);
		arrPut(b);

		bool flag = true;
		range(i, 0, n - 3) {
			if (a[i] == b[i]) {
				continue;
			}

			vector<int> t = {a[i] + a[i + 1] + a[i + 2], -a[i + 2], -a[i + 1], a[i + 1] + a[i + 2] + a[i + 3]};
			a[i] = t[0];
			a[i + 1] = t[1];
			a[i + 2] = t[2];
			a[i + 3] = t[3];

			if (a[i] != b[i]) {
				flag = false;
				break;
			}
		}

		if (flag and a[n - 3] == b[n - 3] and a[n - 2] == b[n - 2] and a[n - 1] == b[n - 1]) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
