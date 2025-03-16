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
	int n;
	input(n);

	string s;
	input(s);

	vector<int> a(n + 1, 0), b(n + 1, 0), c(n + 1, 0), d(n + 1, 0);
	rep(i, 0, n) {
		a[i + 1] = a[i] + (s[i] == 'D');
		b[i + 1] = b[i] + (s[i] == 'U');
		c[i + 1] = c[i] + i * (s[i] == 'D');
		d[i + 1] = d[i] + i * (s[i] == 'U');
	}

	int y = 0, x = a[n];
	rep(i, 0, n) {
		int p, q, res;
		if (s[i] == 'U') {
			if (x <= y) {
				p = x;
				q = x;
				res = n - i;
			}
			else {
				p = y + 1;
				q = y;
				res = i + 1;
			}
			y++;
		}
		else {
			x--;
			if (y <= x) {
				q = y;
				p = y;
				res = i + 1;
			}
			else {
				q = x + 1;
				p = x;
				res = n - i;
			}
		}


		int r = lower_bound(a.begin(), a.end(), a[i + 1] + p) - a.begin();
		res += 2 * (c[r] - c[i + 1]);
		res -= 2 * p * i;

		int l = lower_bound(b.begin(), b.end(), b[i] - q) - b.begin();
		res += 2 * q * i;
		res -= 2 * (d[i] - d[l]);

		cout << res << ' ';
	}
	cout << endl;
}
