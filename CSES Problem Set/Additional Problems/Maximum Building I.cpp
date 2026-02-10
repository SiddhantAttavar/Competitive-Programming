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

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<vi> a(m);
	rep(i, 0, n) {
		string s;
		input(s);
		rep(j, 0, m) {
			if (s[j] == '*') {
				a[j].push_back(i);
			}
		}
	}
	rep(j, 0, m) {
		a[j].push_back(n);
	}

	int res = 0;
	rep(l, 0, n) {
		vector<vi> b(n + 1);
		rep(j, 0, m) {
			b[*lower_bound(all(a[j]), l)].push_back(j);
		}
		multiset<int> s = {-1, m}, t = {m};
		rep(r, l, n) {
			for (int j : b[r]) {
				s.insert(j);
				multiset<int>::iterator i = s.find(j);
				t.erase(t.find(*next(i) - *prev(i) - 1));
				t.insert(*i - *prev(i) - 1);
				t.insert(*next(i) - *i - 1);
			}
			res = max(res, (r - l + 1) * *t.rbegin());
		}
	}
	print(res);
}
