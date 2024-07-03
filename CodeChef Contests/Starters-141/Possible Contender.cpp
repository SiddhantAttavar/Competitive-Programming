#include <bits/stdc++.h>
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

		if (n == 1) {
			print(1);
			continue;
		}

		vector<int> b(a.begin(), a.end());
		sort(b.begin(), b.end());

		vector<int> p(n, 0), s(n, 0);
		p[0] = a[0];
		range(i, 1, n) {
			p[i] = max(p[i - 1], min(a[i], a[i - 1]));
		}

		s[n - 1] = a[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			s[i] = max(s[i + 1], min(a[i], a[i + 1]));
		}

		vector<bool> res(n);
		res[0] = s[1] >= a[0];
		res[n - 1] = p[n - 2] >= a[n - 1];
		range(i, 1, n - 1) {
			int j = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
			res[i] = max(p[i - 1], s[i + 1]) >= a[i];
		}

		set<int> m;
		range(i, 0, n) {
			if (res[i]) {
				m.insert(a[i]);
			}
		}

		range(i, 0, n) {
			cout << (m.count(a[i]) > 0);
		}
		cout << endl;
	}
}
