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

string get(int x) {
	string res = to_string(x);
	if (res.size() == 1) {
		res = '0' + res;
	}
	return res;
}

string get_string(int x) {
	int h = (x / 60) / 60;
	int m = (x / 60) % 60;
	int s = x % 60;
	string a = get(h), b = get(m), c = get(s);
	return a + ":" + b + ":" + c;
}

int from_string(string a) {
	int h = 10 * (a[0] - '0') + (a[1] - '0');
	int m = 10 * (a[3] - '0') + (a[4] - '0');
	int s = 10 * (a[6] - '0') + (a[7] - '0');
	return s + 60 * m + 3600 * h;
}

int32_t main() {
	vector<int> l;
	rep(i, 0, 60 * 60 * 24) {
		string s = get_string(i);
		string t = s;
		reverse(t.begin(), t.end());
		if (s == t) {
			l.push_back(i);
		}
	}

	setup(); int tc; input(tc); while (tc--) {
		string s, t;
		input(s, t);

		int a = from_string(s), b = from_string(t);
		print(upper_bound(l.begin(), l.end(), b) - lower_bound(l.begin(), l.end(), a));
	}
}
