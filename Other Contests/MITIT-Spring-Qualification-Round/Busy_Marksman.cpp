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

		int x = 0;
		for (int i : a) {
			x += i;
		}

		multiset<pair<int, int>> m;
		range(i, 0, n) {
			if (a[i]) {
				m.insert({a[i], i});
			}
		}

		bool flag = false;
		vector<int> res;
		while (m.size()) {
			multiset<pair<int, int>>::iterator it;
			if (flag) {
				it = m.lower_bound({2, 0});
				if (it == m.end()) {
					res = {};
					break;
				}
			}
			else {
				it = m.begin();
			}

			flag = !flag;
			int x, i;
			tie(x, i) = *it;
			res.push_back(i + 1);
			m.erase(it);
			if (x > 1) {
				m.insert({x - 1, i});
			}
		}

		if (res.size()) {
			print("YES");
			arrPrint(res);
		}
		else {
			print("NO");
		}
	}
}
