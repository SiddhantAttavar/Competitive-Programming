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

__int128_t gcd128(__int128_t a, __int128_t b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int32_t main() {
	int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vi dp(n, 0), a(n);
		for (int u = n - 1; u >= 0; u--) {
			int k;
			input(a[u], k);

			vi c(k);
			arrput(c);

			__int128_t x = 1;
			for (int v : c) {
				v--;
				x = gcd128(x * a[v], a[u]);
				dp[u] += dp[v];
			}

			if (x > 1) {
				a[u] = (int) x;
			}
			else {
				dp[u]++;
			}

			print(dp[u]);
			cout.flush();
		}
	}
}
