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

int solve(string s, string t) {
	vector<int> a(t.size(), 0);
	for (int i = s.size() - 1; i >= 0; i--) {
		a[0] += s[i] == t[0];
		range(j, 1, t.size()) {
			a[j] = min(a[j - 1], a[j] + (s[i] == t[j]));
		}
	}

	int res = 0;
	while (a.back()) {
		range(i, 0, t.size()) {
			a[i]--;
		}
		res++;
		a.back()++;
		for (int i = t.size() - 2; i >= 0; i--) {
			if (a[i] < a[i + 1]) {
				a[i]++;
				a[i + 1]--;
			}
		}
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);
		
		string s;
		input(s);

		string t(s);
		reverse(t.begin(), t.end());
		print(n - 3 * solve(s, "kcab") - 4 * solve(t, "front"));
	}
}
