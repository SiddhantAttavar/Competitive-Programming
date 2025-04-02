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
	setup();

	int n, m;
	input(n, m);

	vector<int> a(n);
	arrput(a);

	int k = 350;
	vector<int> p(n), q(n);
	for (int i = 0; i < n; i += k) {
		int r = min(n - 1, i + k - 1);
		for (int j = r; j >= i; j--) {
			if (j + a[j] <= r) {
				p[j] = p[j + a[j]];
				q[j] = q[j + a[j]] + 1;
			}
			else if (j + a[j] < n) {
				p[j] = j + a[j];
				q[j] = 1;
			}
			else {
				p[j] = j;
				q[j] = 0;
			}
		}
	}

	while (m--) {
		int o, i;
		input(o, i);
		i--;

		if (o == 0) {
			int x;
			input(x);
			a[i] = x;
			int r = min(n - 1, i - i % k + k - 1);
			for (int j = r; j >= i - i % k; j--) {
				if (j + a[j] <= r) {
					p[j] = p[j + a[j]];
					q[j] = q[j + a[j]] + 1;
				}
				else if (j + a[j] < n) {
					p[j] = min(n, j + a[j]);
					q[j] = 1;
				}
				else {
					p[j] = j;
					q[j] = 0;
				}
			}
		}
		else {
			int res = 0, z = i;
			while (p[z] != z) {
				res += q[z];
				z = p[z];
			}
			print(z + 1, res + 1);
		}
	}
}
