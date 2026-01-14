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

bool check(int n) {
	string s = to_string(n);
	for (char c : s) {
		if ((c - '0') % 2) {
			return true;
		}
	}
	return false;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		if (n % 2) {
			print(0);
			continue;
		}

		if (n < 10) {
			print(-1);
			continue;
		}

		int res = 1;
		while (!check(n)) {
			string s = to_string(n);
			int x = *max_element(s.begin(), s.end()) - '0';
			n -= x;
			res++;
		}
		print(res);
	}
}
