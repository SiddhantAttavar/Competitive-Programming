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
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<int> s(m);
		arrput(s);

		sort(s.begin(), s.end());
		reverse(s.begin(), s.end());

		vector<set<int>> a(n + 1);
		vector<int> res(n);
		bool flag = true;
		rep(i, 1, n + 1) {
			int l = 0;
			while (a[i].count(l)) {
				l++;
			}
			if (l >= m) {
				flag = false;
				break;
			}
			res[i - 1] = s[l];
			for (int j = 2 * i; j <= n; j += i) {
				a[j].insert(l);
			}
		}

		if (flag) {
			arrprint(res);
		}
		else {
			print(-1);
		}
	}
}
