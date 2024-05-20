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

		map<pair<int, int>, map<int, int>> m;
		map<pair<int, int>, int> x;
		int res = 0;
		range(i, 0, n - 2) {
			res += x[{a[i], a[i + 1]}] - m[{a[i], a[i + 1]}][a[i + 2]];
			m[{a[i], a[i + 1]}][a[i + 2]]++;
			x[{a[i], a[i + 1]}]++;
		}
		m.clear();
		x.clear();
		range(i, 0, n - 2) {
			res += x[{a[i], a[i + 2]}] - m[{a[i], a[i + 2]}][a[i + 1]];
			m[{a[i], a[i + 2]}][a[i + 1]]++;
			x[{a[i], a[i + 2]}]++;
		}
		m.clear();
		x.clear();
		range(i, 0, n - 2) {
			res += x[{a[i + 1], a[i + 2]}] - m[{a[i + 1], a[i + 2]}][a[i]];
			m[{a[i + 1], a[i + 2]}][a[i]]++;
			x[{a[i + 1], a[i + 2]}]++;
		}

		print(res);
	}
}
