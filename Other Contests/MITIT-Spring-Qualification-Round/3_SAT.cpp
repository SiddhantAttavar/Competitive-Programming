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

		map<vector<int>, int> s;
		range(i, 0, m) {
			vector<int> a(3);
			arrPut(a);
			sort(a.begin(), a.end());
			s[a]++;
		}

		vector<set<int>> a(n);
		for (pair<vector<int>, int> p : s) {
			if (p.second % 2) {
				set<int> x(p.first.begin(), p.first.end());
				for (int i : x) {
					a[i - 1].insert(p.second);
				}
			}
		}

		vector<int> res(n, true);
		if (m % 2) {
			print("YES");
			arrPrint(res);
			continue;
		}

		bool flag = false;
		range(i, 0, n) {
			if (a[i].size() % 2 == 1) {
				res[i] = false;
				flag = true;
				break;
			}
		}

		if (flag) {
			print("YES");
			arrPrint(res);
		}
		else {
			print("NO");
		}
	}
}
