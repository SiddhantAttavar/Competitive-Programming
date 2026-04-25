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

bool check(string s, string t) {
	int l = 0, n = sz(s), r = n - 1;
	while (l < n and s[l] == t[l]) {
		l++;
	}
	if (l == n) {
		return true;
	}
	while (r >= 0 and s[r] == t[r]) {
		r--;
	}
	s = s.substr(l, r - l + 1);
	t = t.substr(l, r - l + 1);
	reverse(all(s));
	if (s == t) {
		return true;
	}
	string w;
	for (char c : s) {
		w += c == 'a' ? 'b' : 'a';
	}
	return w == t;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		string s;
		input(s);

		int n = sz(s);
		string x, y;
		rep(i, 0, n) {
			if (i % 2 == 0) {
				x += 'a';
				y += 'b';
			}
			else {
				x += 'b';
				y += 'a';
			}
		}
		if (check(s, x) or check(s, y)) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
