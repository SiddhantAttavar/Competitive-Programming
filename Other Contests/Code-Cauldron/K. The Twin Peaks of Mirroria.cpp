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

array<vi, 2> manacher(const vi& s) {
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
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vi a(n);
		arrput(a);

		vi z = manacher(a)[1];
		vi l(n, n - 1);
		for (int i = n - 2; i >= 0; i--) {
			if (a[i] >= a[i + 1]) {
				l[i] = i;
			}
			else {
				l[i] = l[i + 1];
			}
		}

		vi s(n, 1), t(n, 1);
		rep(i, 0, n) {
			int j = l[i], k = i + 2 * (j - i);
			if (k < n and z[j] >= (j - i)) {
				s[k] = max(s[k], k - i + 1);
				t[i] = max(t[i], k - i + 1);
			}
		}
		for (int i = n - 2; i >= 0; i--) {
			s[i] = max(s[i], s[i + 1] - 2);
		}
		rep(i, 1, n) {
			t[i] = max(t[i], t[i - 1] - 2);
		}

		pii q = {-1, -1};
		array<int, 5> res = {-1, -1, -1, -1, -1};
		rep(i, 1, n) {
			q = max(q, {s[i - 1], i - 1});
			res = max(res, {q.first + t[i], q.second - q.first + 1, q.second, i, i + t[i] - 1});
		}
		print(res[0]);
		rep(i, res[1], res[2] + 1) {
			cout << a[i] << ' ';
		}
		cout << endl;
		rep(i, res[3], res[4] + 1) {
			cout << a[i] << ' ';
		}
		cout << endl;
	}
}
