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

vector<int> mad(vector<int> a) {
	set<int> s;
	vector<int> b(a.size(), 0);
	s.insert(a[0]);
	range(i, 1, a.size()) {
		b[i] = b[i - 1];
		if (s.count(a[i])) {
			b[i] = max(b[i], a[i]);
		}
		s.insert(a[i]);
	}
	return b;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		vector<int> b = mad(a);
		vector<int> c = mad(b);

		int res = 0;
		for (int i : a) {
			res += i;
		}

		for (int i : b) {
			res += i;
		}

		range(i, 0, n) {
			res += (n - i) * c[i];
		}
		print(res);
	}
}
