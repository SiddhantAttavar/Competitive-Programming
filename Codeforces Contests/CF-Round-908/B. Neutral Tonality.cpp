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
const int MOD = (int) 1e9 + 7; //998244353

int lis(vector<int> &a) {
	vector<int> v;
	for (int i : a) {
		vector<int>::iterator j = lower_bound(v.begin(), v.end(), i);
		if (j == v.end()) {
			v.push_back(i);
		}
		else {
			*j = i;
		}
	}
	return v.size();
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<int> a(n), b(m);
		arrPut(a);
		arrPut(b);

		sort(b.begin(), b.end());
		reverse(b.begin(), b.end());

		vector<int> c;
		int l = 0;
		for (int i : a) {
			while (l < m and b[l] >= i) {
				c.push_back(b[l]);
				l++;
			}
			c.push_back(i);
		}

		c.insert(c.end(), b.begin() + l, b.end());
		arrPrint(c);
		// assert(lis(c) == lis(a));
	}
}
