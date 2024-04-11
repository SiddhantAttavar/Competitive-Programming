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
		int n, m, k;
		input(n, m, k);

		vector<int> a(n), b(m);
		arrPut(a);
		arrPut(b);
		
		map<int, int> s, t;
		for (int i : b) {
			s[i]++;
		}

		range(i, 0, m) {
			t[a[i]]++;
		}

		int c = 0;
		for (pair<int, int> p : t) {
			if (s.count(p.first)) {
				c += min(p.second, s[p.first]);
			}
		}

		int res = c >= k;

		range(i, m, n) {
			t[a[i - m]]--;
			if (s.count(a[i - m]) and t[a[i - m]] < s[a[i - m]]) {
				c--;
			}

			t[a[i]]++;
			if (s.count(a[i]) and t[a[i]] <= s[a[i]]) {
				c++;
			}

			res += c >= k;
		}

		print(res);
	}
}
