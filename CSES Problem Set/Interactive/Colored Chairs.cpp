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

bool debug = false;
vector<bool> A;
int K = 30;

bool query(int i) {
	assert(K);
	K--;
	if (debug) {
		return A[i];
	}
	print('?', i + 1);
	cout.flush();
	char c;
	input(c);
	return c == 'R';
}

int32_t main() {
	setup();

	int n;
	input(n);

	K = 20;
	if (debug) {
		A.resize(n);
		string s;
		input(s);
		rep(i, 0, n) {
			A[i] = s[i] == 'R';
		}
	}

	bool x = query(0);
	int l = 1, r = n - 1, res = 0;
	while (l <= r) {
		int m = (l + r) / 2;
		if (query(m) ^ x ^ (m % 2)) {
			r = m - 1;
		}
		else {
			res = m;
			l = m + 1;
		}
	}
	print('!', res + 1);
	cout.flush();

	if (debug) {
		assert(A[res] == A[(res + 1) % n]);
	}
}
