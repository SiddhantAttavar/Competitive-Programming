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

void add(int x, multiset<int> &s, multiset<int> &t) {
	multiset<int>::iterator i = s.lower_bound(x);
	if (i == s.begin()) {
		if (i != s.end()) {
			t.insert(*i - x);
		}
	}
	else {
		if (i == s.end()) {
			t.insert(x - *prev(i));
		}
		else {
			t.erase(t.find(*i - *prev(i)));
			t.insert(x - *prev(i));
			t.insert(*i - x);
		}
	}
	s.insert(x);
}

void remove(int x, multiset<int> &s, multiset<int> &t) {
	multiset<int>::iterator i = s.lower_bound(x);
	if (i == s.begin()) {
		if (next(i) != s.end()) {
			t.erase(t.find(*next(i) - x));
		}
	}
	else {
		if (next(i) == s.end()) {
			t.erase(t.find(x - *prev(i)));
		}
		else {
			t.insert(*next(i) - *prev(i));
			t.erase(t.find(x - *prev(i)));
			t.erase(t.find(*next(i) - x));
		}
	}
	s.erase(s.find(x));
}

int32_t main() {
	setup();

	int n, d;
	input(n, d);

	vi a(n);
	arrput(a);

	int l = 0, res = 0;
	multiset<int> s, t;
	rep(r, 0, n) {
		add(a[r], s, t);
		while (!t.empty() and *t.begin() < d) {
			remove(a[l], s, t);
			l++;
		}
		res += r - l + 1;
	}
	print(res);
}
