#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
template<typename T> inline void dbg(T x) {cerr << x << '\n';}
template<typename T, typename... S> inline void dbg(T x, S... args) {cerr << x << ", "; dbg(args ...);}
#define debug(...) cerr << #__VA_ARGS__ << ": "; dbg(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> p(n), s(n);
		arrput(p);
		arrput(s);

		vector<int> a, b;
		a.push_back(p[0]);
		b.push_back(s[0]);
		rep(i, 1, n) {
			if (p[i] != p[i - 1] or s[i] != s[i - 1]) {
				a.push_back(p[i]);
				b.push_back(s[i]);
			}
		}

		n = a.size();
		bool flag = true;
		rep(i, 1, n) {
			if (a[i - 1] % a[i]) {
				flag = false;
				break;
			}
		}
		for (int i = n - 2; i >= 0; i--) {
			if (b[i + 1] % b[i]) {
				flag = false;
				break;
			}
		}

		rep(i, 1, n) {
			if (__gcd(a[i - 1], b[i]) != b[0]) {
				flag = false;
				break;
			}
		}

		if (!flag or a.back() != b[0]) {
			print("NO");
			continue;
		}

		print("YES");
	}
}
