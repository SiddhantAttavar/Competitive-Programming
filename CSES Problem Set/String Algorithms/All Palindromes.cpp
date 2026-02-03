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
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

array<vi, 2> manacher(const string& s) {
	int n = sz(s);
	array<vi,2> p = {vi(n+1), vi(n)};
	rep(z,0,2) for (int i=0,l=0,r=0; i < n; i++) {
		int t = r-i+!z;
		if (i<r) p[z][i] = min(t, p[z][l+t]);
		int L = i-p[z][i], R = i+p[z][i]-!z;
		while (L>=1 && R+1<n && s[L-1] == s[R+1])
			p[z][i]++, L--, R++;
		if (R>r) l=L, r=R;
	}
	return p;
}
int32_t main() {
	setup();

	string s;
	input(s);

	int n = sz(s);
	auto [p, q] = manacher(s);

	vi res(n, 0);
	set<int> m;
	vector<vi> l(n + 1);
	rep(i, 0, n) {
		for (int j : l[i]) {
			m.erase(j);
		}
		m.insert(i);
		l[i + q[i] + 1].push_back(i);
		res[i] = 2 * (i - *m.begin()) + 1;
	}

	l = vector<vi>(n + 1);
	m.clear();
	rep(i, 0, n) {
		m.insert(i);
		l[i + p[i]].push_back(i);
		for (int j : l[i]) {
			m.erase(j);
		}
		if (!m.empty()) {
			res[i] = max(res[i], 2 * (i - *m.begin() + 1));
		}
	}
	arrprint(res);
}
