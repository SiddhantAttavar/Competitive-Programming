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
	setup();

	int n;
	input(n);

	vector<string> s(n);
	arrput(s);

	vector<vi> dp1(n, vi(n)), dp2(n, vi(n));
	dp1[0][0] = 0;
	dp2[0][0] = 0;
	rep(i, 1, n) {
		dp1[i][0] = dp1[i - 1][0] + (s[i][0] == '@');
		dp2[i][0] = dp2[i - 1][0] + (s[i][0] == '@');
	}
	rep(j, 1, n) {
		dp1[0][j] = dp1[0][j - 1] + (s[0][j] == '@');
		dp2[0][j] = dp2[0][j - 1] + (s[0][j] == '@');
	}
	rep(i, 1, n) {
		rep(j, 1, n) {
			dp1[i][j] = min(dp1[i - 1][j], dp1[i][j - 1]) + (s[i][j] == '@');
			dp2[i][j] = max(dp2[i - 1][j], dp2[i][j - 1]) + (s[i][j] == '@');
		}
	}

	vi res(2 * n, 0);
	rep(i, 0, n) {
		rep(j, 0, n) {
			res[dp1[i][j]]++;
			res[dp2[i][j] + 1]--;
		}
	}
	rep(i, 1, 2 * n) {
		res[i] += res[i - 1];
	}
	res.pop_back();
	for (int i : res) {
		print(i);
	}
}
