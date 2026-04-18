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

string next(string s) {
	string t;
	s.insert(s.begin(), s.back());
	s.push_back(s[1]);
	rep(i, 1, sz(s) - 1) {
		int x = (s[i - 1] == '1') + (s[i] == '1') + (s[i + 1] == '1');
		if (x >= 2) {
			t += '1';
		}
		else {
			t += '0';
		}
	}
	return t;
}

int brute(string s) {
	int n = sz(s);
	rep(i, 0, n + 1) {
		string t = next(s);
		if (s == t) {
			return i + 1;
		}
		s = t;
	}
	return -1;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		string s;
		input(s);
		string o = s;

		int l = -1;
		rep(i, 0, n) {
			if (s[i] == s[(i + 1) % n]) {
				l = (i + 1) % n;
				break;
			}
		}
		if (l == -1) {
			print(-1);
			continue;
		}

		s = s.substr(l) + s.substr(0, l);

		int c = 1, x = 1;
		rep(i, 1, n) {
			if (s[i] == s[i - 1]) {
				c = 1;
			}
			else {
				c++;
			}
			x = max(x, c);
		}
		print((x + 1) / 2);
	}
}
