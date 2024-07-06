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
		
		int x = *min_element(a.begin(), a.end());
		int res = a[0] == x;
		range(i, 1, n) {
			res += a[i] == x and a[i - 1] != x;
		}

		if (res != 1) {
			print("NO");
			continue;
		}

		bool flag = true;
		range(i, 0, n) {
			if (i and a[i] > a[i - 1]) {
				flag = false;
				break;
			}
			if (a[i] == x) {
				break;
			}
		}

		for (int i = n - 1; i >= 0; i--) {
			if (i < n - 1 and a[i] > a[i + 1]) {
				flag = false;
				break;
			}
			if (a[i] == x) {
				break;
			}
		}

		if (flag) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
