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
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		string n;
		input(n);
		reverse(all(n));
		n += '0';

		int k = sz(n);
		vi dp1(k, 0), dp2(k, 0);
		dp1[0] = n[0] - '0';
		dp2[0] = 10 - (n[0] - '0');
		rep(i, 1, k) {
			int c = n[i] - '0';
			dp1[i] = min(dp1[i - 1] + c, dp2[i - 1] + c + 1);
			dp2[i] = min(dp2[i - 1] + 9 - c, dp1[i - 1] + 10 - c);
		}
		print(dp1[k - 1]);
	}
}
