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

__int128_t solve(multiset<int> &a, multiset<int> &b, multiset<int> &c) {
	__int128_t x = 0;
	for (int i : a) {
		x += i;
	}
	for (int i : c) {
		x += i;
	}
	__int128_t res = 0;
	for (multiset<int>::reverse_iterator i = a.rbegin(); i != a.rend(); i++) {
		x -= *i;
		res += x;
	}
	for (int i : b) {
		x += i;
		res += x;
	}
	return res;
}

void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<int> c(n);
	arrput(c);

	string s, t;
	input(s, t);

	vector<bool> a(n), b(n);
	rep(i, 0, n) {
		a[i] = s[i] == '1';
		b[i] = t[i] == '1';
	}

	int x = 0;
	rep(i, 0, n) {
		x += a[i] * c[i];
	}

	vector<multiset<int>> v(4);
	rep(i, 0, n) {
		v[a[i] + 2 * b[i]].insert(c[i]);
	}
	__int128_t res = solve(v[1], v[2], v[3]);
	while (!v[3].empty()) {
		int t = *v[3].rbegin();
		v[3].erase(prev(v[3].end()));
		v[2].insert(t);
		v[1].insert(t);
		res = min(res, solve(v[1], v[2], v[3]));
	}
	print(res);
}
