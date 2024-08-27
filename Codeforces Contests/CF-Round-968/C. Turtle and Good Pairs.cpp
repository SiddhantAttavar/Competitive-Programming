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

		string s;
		input(s);

		vector<int> a(26, 0);
		for (char c : s) {
			a[c - 'a']++;
		}

		int u = max_element(a.begin(), a.end()) - a.begin();
		string res;
		res += 'a' + u;
		a[u]--;

		range(i, 1, n) {
			int t = a[u];
			a[u] = 0;
			int v = u;
			u = max_element(a.begin(), a.end()) - a.begin();
			a[v] = t;
			if (a[u] == 0) {
				break;
			}
			res += 'a' + u;
			a[u]--;
		}

		range(i, 0, 26) {
			res += string(a[i], 'a' + i);
		}

		print(res);
	}
}
