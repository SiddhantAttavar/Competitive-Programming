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

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m, q;
		input(n, m, q);

		vector<int> a(n), b(m);
		arrPut(a);
		arrPut(b);

		a.insert(a.begin(), 0);
		n++;

		vector<int> p(n, 0);
		range(i, 0, n) {
			p[a[i]] = i;
		}

		vector<set<int>> v(n + 1);
		v[0] = {-1};
		range(i, 0, m) {
			b[i] = p[b[i]];
			v[b[i]].insert(i);
		}
		range(i, 0, n + 1) {
			v[i].insert(m + 1);
		}

		int c = 0;
		range(i, 1, n + 1) {
			c += *v[i].begin() < *v[i - 1].begin();
		}


		if (c == 0) {
			print("YA");
		}
		else {
			print("TIDAK");
		}

		while (q--) {
			int i, x;
			input(i, x);

			i--;
			x = p[x];

			c -= *v[x].begin() < *v[x - 1].begin();
			c -= *v[x].begin() > *v[x + 1].begin();
			if (b[i] - 1 != x)
				c -= *v[b[i]].begin() < *v[b[i] - 1].begin();
			if (b[i] + 1 != x)
				c -= *v[b[i]].begin() > *v[b[i] + 1].begin();

			v[b[i]].erase(i);
			v[x].insert(i);

			c += *v[x].begin() < *v[x - 1].begin();
			c += *v[x].begin() > *v[x + 1].begin();
			if (b[i] - 1 != x)
				c += *v[b[i]].begin() < *v[b[i] - 1].begin();
			if (b[i] + 1 != x)
				c += *v[b[i]].begin() > *v[b[i] + 1].begin();

			b[i] = x;

			if (c == 0) {
				print("YA");
			}
			else {
				print("TIDAK");
			}
		}
	}
}
