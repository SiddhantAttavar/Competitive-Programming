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

		int res = n * (n + 1) / 2;
		vector<int> v(n, -1);
		range(i, 0, n) {
			res -= (i - v[a[i]]) * (n - i);
			v[a[i]] = i;
		}

		vector<int> pref(n, -1), suff(n, n);
		stack<int> s;
		range(i, 0, n) {
			while (!s.empty() and a[s.top()] <= a[i]) {
				s.pop();
			}

			if (s.empty()) {
				pref[i] = -1;
			}
			else {
				pref[i] = s.top();
			}
			s.push(i);
		}
		while (!s.empty()) {
			s.pop();
		}

		for (int i = n - 1; i >= 0; i--) {
			while (!s.empty() and a[s.top()] < a[i]) {
				s.pop();
			}

			if (s.empty()) {
				suff[i] = n;
			}
			else {
				suff[i] = s.top();
			}
			s.push(i);
		}

		range(i, 0, n) {
			res += a[i] * (suff[i] - i) * (i - pref[i]);
		}

		print(res);
	}
}
