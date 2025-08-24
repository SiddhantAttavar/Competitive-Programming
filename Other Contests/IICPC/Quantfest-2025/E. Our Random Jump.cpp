#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
#define debug(...) cout << #__VA_ARGS__ << ": "; print(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int a, b, n;
		input(n);
		input(a, b);

		vector<int> v(n, 0);
		rep(i, 0, a) {
			int j;
			input(j);
			v[j - 1] = 1;
		}
		rep(i, 0, b) {
			int j;
			input(j);
			v[j - 1] = 2;
		}
		n = v.size();

		long double p = v.back() == 1, q = v.back() == 2;
		long double s = p, t = q;
		for (int i = n - 2; i >= 0; i--) {
			if (v[i] == 1) {
				p = 1;
				q = 0;
			}
			else if (v[i] == 2) {
				q = 1;
				p = 0;
			}
			else {
				p = s / (n - i - 1);
				q = t / (n - i - 1);
			}

			s += p;
			t += q;
		}

		cout << fixed << setprecision(18);
		print(q / (p + q));
	}
}
