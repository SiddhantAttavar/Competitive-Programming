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
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		string s;
		input(s);

		if (s == "1") {
			print(0);
			continue;
		}

		if (s == string(n, '0')) {
			print(-1);
			continue;
		}

		int x = count(all(s), '0') - count(all(s), '1');
		if (x <= 0) {
			print(n);
			continue;
		}

		if (x == 1) {
			print(n + 1);
			continue;
		}

		int p = 0, q = 0, r = 0, a = 0, b = 0;
		for (char c : s) {
			p += c == '0' ? 1 : -1;
			q = min(q, p);
			r = max(r, p);
			a = max(a, p - q);
			b = min(b, p - r);
		}

		if (a > x) {
			print(n + 1);
			continue;
		}
		if (b < -1) {
			print(n + 2);
			continue;
		}

		int l = 0;
		while (s[l] == '0') {
			l++;
		}

		p = 0, q = 0, r = 0, a = 0, b = 0;
		rep(i, l + 1, n) {
			p += s[i] == '0' ? 1 : -1;
			q = min(q, p);
			r = max(r, p);
			a = max(a, p - q);
			b = min(b, p - r);
		}

		if (a == x) {
			print(n + 2);
			continue;
		}

		l = n - 1;
		while (s[l] == '0') {
			l--;
		}

		p = 0, q = 0, r = 0, a = 0, b = 0;
		rep(i, 0, l) {
			p += s[i] == '0' ? 1 : -1;
			q = min(q, p);
			r = max(r, p);
			a = max(a, p - q);
			b = min(b, p - r);
		}

		if (a == x) {
			print(n + 2);
			continue;
		}

		print(n + 3);
	}
}
