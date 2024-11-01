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

bool query(int a, int b) {
	print('?', a, b);
	cout.flush();
	int x;
	input(x);
	return x;
}

int32_t main() {
	int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<vector<int>> v = {{1}};
		int u = 2;
		while (u < n and query(1, u)) {
			v.push_back({u});
			u++;
		}

		vector<int> s(v.size()), t(v.size());
		range(i, 0, v.size()) {
			s[i] = (i + 1) % v.size();
			t[(i + 1) % v.size()] = i;
		}

		v[0].push_back(u);
		int l = s[0];
		range(i, u + 1, n) {
			while (query(v[l].back(), i)) {
				int p = t[l], q = s[l];
				s[p] = q;
				t[q] = p;
				l = q;
			}
			v[l].push_back(i);
			l = s[l];
		}

		vector<int> p(n - 1);
		for (vector<int> i : v) {
			int u = 0;
			for (int j : i) {
				p[j - 1] = u;
				u = j;
			}
		}
		cout << "! ";
		arrPrint(p);
		cout.flush();
	}
}
