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
inline int mpow(int a, int b) {int x = 1; for (; b; a = a * a % MOD, b >>= 1) {if (b & 1) {x = x * a % MOD;}} return x;};
inline int mdiv(int a, int b) {return a * mpow(b, MOD - 2) % MOD;};

vi get(const string &s, char c) {
	vi v(26, -1), res(sz(s));
	rep(i, 0, sz(s)) {
		if (v[s[i] - c] == -1) {
			v[s[i] - c] = i;
		}
		res[i] = v[s[i] - c];
	}
	return res;
}

int32_t main() {
	setup();

	string s;
	input(s);

	vi v(26, -1);
	vi x = get(s, 'a');

	const int N = 1e7;
	bitset<N + 1> b = 0;
	b = ~b;
	rep(i, 2, N + 1) {
		if (!b[i]) {
			continue;
		}
		if (x == get(to_string(i), '0')) {
			cout << i << endl;
			return 0;
		}
		for (int j = i; j <= N; j += i) {
			b[j] = false;
		}
	}
	cout << -1 << endl;
}
