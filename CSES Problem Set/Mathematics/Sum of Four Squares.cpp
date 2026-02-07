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

int32_t main() {
	const int N = 1e7;
	vector<pii> v(N + 1, {-1, -1});
	for (int i = 0; i * i <= N; i++) {
		for (int j = 0; i * i + j * j <= N; j++) {
			v[i * i + j * j] = {i, j};
		}
	}

	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		rep(x, 0, n + 1) {
			if (v[x].first != -1 and v[n - x].first != -1) {
				print(v[x].first, v[x].second, v[n - x].first, v[n - x].second);
				break;
			}
		}
	}
}
