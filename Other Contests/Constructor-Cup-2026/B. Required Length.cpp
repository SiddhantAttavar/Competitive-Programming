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
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

int p(int x) {
	return pow(10, x);
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int x, y, z;
		input(x, y, z);

		if (z < max(x, y)) {
			print(0, 0);
		}
		else if (z > max(x, y) + 1) {
			print(0, 0);
		}
		else if (z == max(x, y)) {
			print(p(x - 1), p(y - 1));
		}
		else if (x > y) {
			print(p(x) - 1, p(y - 1));
		}
		else {
			print(p(x - 1), p(y) - 1);
		}
	}
}
