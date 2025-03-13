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

int c = 0;
int query(int x, int y) {
	c++;
	print('?', x, y);
	cout.flush();
	int z;
	input(z);
	return z;
}

// int query(int x, int y) {
// 	c++;
// 	return x;
// }

int32_t main() {
	int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);
		k++;

		vector<int> a(n);
		arrput(a);

		c = 0;
		vector<int> b(n - k + 1);
		vector<int> p(n), s(n);

		int x = -1, y = -1;
		rep(i, 0, n - k + 1) {
			if (x < i) {
				int r = min(n - 1, x + k - 1);
				p[r] = a[r];
				for (int j = r - 1; j > x; j--) {
					p[j] = query(a[j], p[j + 1]);
				}

				// cout << "p: ";
				// rep(j, x + 1, r + 1) {
				// 	cout << p[j] << ' ';
				// }
				// cout << endl;

				int t = min(n - 1, r + k - 1);
				s[r + 1] = a[r + 1];
				rep(j, r + 2, t + 1) {
					s[j] = query(s[j - 1], a[j]);
				}

				// cout << "s: ";
				// rep(j, r + 1, t + 1) {
				// 	cout << s[j] << ' ';
				// }
				// cout << endl;

				x = r;
				y = t;
			}

			b[i] = query(p[i], s[i + k - 1]);
		}

		cout << "! ";
		arrprint(b);
		cout.flush();
		assert(c <= 3 * n);
	}
}
