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
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		string s, t;
		input(s, t);

		vector<int> a(26, 0), b(26, 0);
		for (char c : s) {
			a[c - 'a']++;
		}
		for (char c : t) {
			b[c - 'a']++;
		}

		bool flag = true;
		rep(i, 0, 26) {
			if (a[i] > b[i]) {
				flag = false;
				break;
			}
		}

		if (!flag) {
			print("Impossible");
			continue;
		}

		string res;
		for (char c : s) {
			rep(i, 0, c - 'a') {
				while (b[i] > a[i]) {
					res += i + 'a';
					b[i]--;
				}
			}
			res += c;
			a[c - 'a']--;
			b[c - 'a']--;
		}
		rep(i, 0, 26) {
			while (b[i]) {
				res += i + 'a';
				b[i]--;
			}
		}
		print(res);
	}
}
