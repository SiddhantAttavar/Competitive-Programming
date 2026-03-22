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
		int n;
		input(n);

		vi a(n);
		arrput(a);

		int g = 0;
		for (int i : a) {
			g = gcd(g, i);
		}

		int z = count(all(a), g);
		if (z) {
			if (n - z == 1) {
				print("Bob");
			}
			else{
				print("Alice");
			}
			continue;
		}

		vi p = a, s = a;
		rep(i, 1, n) {
			p[i] = gcd(p[i - 1], a[i]);
		}
		for (int i = n - 2; i >= 0; i--) {
			s[i] = gcd(s[i + 1], a[i]);
		}

		if (p[n - 2] == g or s[1] == g) {
			print("Alice");
			continue;
		}

		bool flag = false;
		rep(i, 1, n - 1) {
			if (gcd(p[i - 1], s[i + 1]) == g) {
				flag = true;
				break;
			}
		}
		if (flag) {
			print("Alice");
		}
		else {
			print("Bob");
		}
	}
}
