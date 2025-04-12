#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
template<typename T> inline void dbg(T x) {cerr << x << '\n';}
template<typename T, typename... S> inline void dbg(T x, S... args) {cerr << x << ", "; dbg(args ...);}
#define debug(...) cerr << #__VA_ARGS__ << ": "; dbg(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup();

	int n, k;
	input(n, k);

	string s;
	input(s);

	if (n == 1) {
		if (k == 0) {
			print('.');
		}
		else {
			print('o');
		}
		return 0;
	}

	if (s[1] == 'o') {
		s[0] = '.';
	}
	if (s[n - 2] == 'o') {
		s[n - 1] = '.';
	}

	rep(i, 1, n - 1) {
		if (s[i - 1] == 'o' or s[i + 1] == 'o') {
			s[i] = '.';
		}
	}

	for (char c : s) {
		k -= c == 'o';
	}

	if (k == 0) {
		rep(i, 0, n) {
			if (s[i] == '?') {
				s[i] = '.';
			}
		}
		print(s);
		return 0;
	}

	int x = 0;
	rep(i, 0, n) {
		if (s[i] == '?') {
			x++;
		}
		else {
			k -= (x + 1) / 2;
			x = 0;
		}
	}
	k -= (x + 1) / 2;

	if (k < 0) {
		print(s);
		return 0;
	}

	rep(i, 0, n) {
		if (s[i] != '?') {
			continue;
		}

		int j = i;
		while (j < n - 1 and s[j + 1] == '?') {
			j++;
		}

		if ((j - i + 1) % 2 == 0) {
			i = j;
			continue;
		}

		for (int k = i; k <= j; k += 2) {
			s[k] = 'o';
		}
		for (int k = i + 1; k <= j; k += 2) {
			s[k] = '.';
		}
		i = j;
	}
	print(s);
}
