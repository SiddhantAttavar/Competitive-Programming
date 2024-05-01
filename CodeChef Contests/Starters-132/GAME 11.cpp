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
		int n, m;
		input(n, m);

		vector<int> a(n), b(m);
		arrPut(a);
		arrPut(b);

		if (min(n, m) < 4 or n + m < 11) {
			print(-1);
			continue;
		}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());


		int res = 0;
		range(i, 0, 4) {
			res += a[i] + b[i];
		}

		int l = 4, r = 4;
		range(i, 0, 3) {
			if (l == a.size() or (r < b.size() and a[l] < b[r])) {
				res += b[r];
				r++;
			}
			else {
				res += a[l];
				l++;
			}
		}

		print(res);
	}
}
