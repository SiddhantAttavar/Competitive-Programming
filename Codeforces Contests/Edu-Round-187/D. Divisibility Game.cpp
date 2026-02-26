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
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vi a(n), b(m);
		arrput(a);
		arrput(b);

		sort(all(a));
		a.erase(unique(all(a)), a.end());
		vi v(n + m + 1, 0);
		for (int i : a) {
			for (int j = i; j <= n + m; j += i) {
				v[j]++;
			}
		}
		int x = 0, y = 0, z = 0;
		for (int i : b) {
			if (v[i] == 0) {
				y++;
			}
			else if (v[i] == sz(a)) {
				x++;
			}
			else {
				z++;
			}
		}

		if (z % 2) {
			if (x >= y) {
				print("Alice");
			}
			else {
				print("Bob");
			}
		}
		else {
			if (x > y) {
				print("Alice");
			}
			else {
				print("Bob");
			}
		}
	}
}
