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

		int m;
		input(m);
		vector<string> s(m);
		arrPut(s);
		
		for (string i : s) {
			if (i.size() != n) {
				print("NO");
				continue;
			}

			map<char, int> l;
			bool res = true;
			range(j, 0, n) {
				if (!l.count(i[j])) {
					l[i[j]] = a[j];
					continue;
				}

				if (l[i[j]] != a[j]) {
					res = false;
					break;
				}
			}

			set<int> s;
			for (pair<char, int> p : l) {
				s.insert(p.second);
			}

			if (res and s.size() == l.size()) {
				print("YES");
			}
			else {
				print("NO");
			}
		}
	}
}
