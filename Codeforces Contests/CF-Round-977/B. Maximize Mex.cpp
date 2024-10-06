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
const int MOD = (int) 1e9 + 7; //998244353

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, x;
		input(n, x);

		vector<int> a(n);
		arrPut(a);

		map<int, multiset<int>> m;
		for (int i : a) {
			m[i % x].insert(i);
		}

		int res = 0;
		while (true) {
			if (!m.count(res % x)) {
				break;
			}

			multiset<int>::iterator i = m[res % x].upper_bound(res);
			if (i == m[res % x].begin()) {
				break;
			}
			i--;
			m[res % x].erase(i);
			res++;
		}
		print(res);
	}
}
