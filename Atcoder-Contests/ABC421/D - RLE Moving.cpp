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

bool intersection(pair<pair<int, int>, pair<int, int>> l, pair<pair<int, int>, pair<int, int>> r) {
	if (l.first.first != l.second.first) {
		swap(l, r);
	}
	if (min(l.first.second, l.second.second) > r.first.second or max(l.first.second, l.second.second) < r.first.second) {
		return false;
	}
	if (min(r.first.first, r.second.first) > l.first.first or max(r.first.first, r.second.first) < l.first.first) {
		return false;
	}
	return abs(l.first.second - r.first.second) == abs(r.first.first - l.first.first);
}

int32_t main() {
	setup();

	int ax, ay, bx, by;
	input(ax, ay, bx, by);

	swap(ax, ay);
	swap(bx, by);

	int n, m, l;
	input(n, m, l);

	vector<pair<char, int>> s(m), t(l);
	rep(i, 0, m) {
		input(s[i].first, s[i].second);
	}
	rep(i, 0, l) {
		input(t[i].first, t[i].second);
	}

	vector<pair<pair<char, char>, int>> v;
	int i = 0, j = 0;
	while (i < s.size() and j < t.size()) {
		int k = min(s[i].second, t[j].second);
		v.push_back({{s[i].first, t[j].first}, k});
		s[i].second -= k;
		t[j].second -= k;
		if (s[i].second == 0) {
			i++;
		}
		if (t[j].second == 0) {
			j++;
		}
	}
	assert(i == s.size() and j == t.size());

	set<char> d = {'U', 'D'};
	int res = 0;
	for (auto [p, x] : v) {
		char a, b;
		tie(a, b) = p;

		pair<pair<int, int>, pair<int, int>> l = {{ax, ay}, {ax, ay}};
		if (a == 'U') {
			l.second.second -= x;
		}
		else if (a == 'D') {
			l.second.second += x;
		}
		else if (a == 'L') {
			l.second.first -= x;
		}
		else {
			l.second.first += x;
		}

		pair<pair<int, int>, pair<int, int>> r = {{bx, by}, {bx, by}};
		if (b == 'U') {
			r.second.second -= x;
		}
		else if (b == 'D') {
			r.second.second += x;
		}
		else if (b == 'L') {
			r.second.first -= x;
		}
		else {
			r.second.first += x;
		}

		if (a == b) {
			res += (l.first == r.first) * (x + 1);
		}
		else if (d.count(a) and d.count(b)) {
			int k = min(max(l.first.second, l.second.second), max(r.first.second, r.second.second)) -
					max(min(l.first.second, l.second.second), min(r.first.second, r.second.second)) + 1;
			res += l.first.first == r.first.first and k > 0 and k % 2;
		}
		else if (!d.count(a) and !d.count(b)) {
			int k = min(max(l.first.first, l.second.first), max(r.first.first, r.second.first)) -
					max(min(l.first.first, l.second.first), min(r.first.first, r.second.first)) + 1;
			res += l.first.second == r.first.second and k > 0 and k % 2;
		}
		else {
			res += intersection(l, r);
		}

		res -= l.first == r.first;
		tie(ax, ay) = l.second;
		tie(bx, by) = r.second;
		// print(ax, ay, bx, by, a, b);
	}
	print(res);
}
