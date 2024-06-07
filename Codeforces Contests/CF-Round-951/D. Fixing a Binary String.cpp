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
		int n, k;
		input(n, k);

		string s;
		input(s);

		vector<int> v = {1};
		range(i, 1, n) {
			if (s[i] == s[i - 1]) {
				v.back()++;
			}
			else {
				v.push_back(1);
			}
		}

		if (v.back() > k) {
			print(-1);
			continue;
		}

		int u = 0;
		if (v.back() == k) {
			for (int i : v) {
				if (i > k) {
					u += k;
					break;
				}
				u += i;
			}
		}
		else {
			for (int i : v) {
				if (i == k - v.back()) {
					u += k - v.back();
					break;
				}
				if (i == 2 * k - v.back()) {
					u += k - v.back();
					break;
				}
				u += i;
			}
		}

		if (u == 0) {
			u = n;
		}

		reverse(s.begin(), s.begin() + u);
		string t = s.substr(u, n - u) + s.substr(0, u);
		bool flag = true;
		range(i, 1, k) {
			if (t[i] != t[0]) {
				flag = false;
				break;
			}
		}
		range(i, k, n) {
			if (t[i] == t[i - k]) {
				flag = false;
				break;
			}
		}

		if (flag) {
			print(u);
		}
		else {
			print(-1);
		}
	}
}
