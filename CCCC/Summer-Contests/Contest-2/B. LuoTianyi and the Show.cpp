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
		int n, m;
		input(n, m);

		vector<int> x(n);
		arrput(x);

		int a = 0, b = 0;
		vector<int> v;
		for (int i : x) {
			if (i == -1) {
				a++;
			}
			else if (i == -2) {
				b++;
			}
			else {
				v.push_back(i - 1);
			}
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());

		int res = min(m - (int) v.size(), max(a, b)) + v.size();
		rep(i, 0, v.size()) {
			int l = v[i] - i, r = (m - v[i] - 1) - (v.size() - i - 1);
			res = max(res, (int) v.size() + min(l, a) + min(r, b));
		}
		print(res);
	}
}
