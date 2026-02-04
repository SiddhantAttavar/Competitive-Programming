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

int permToInt(vi& v) {
	int use = 0, i = 0, r = 0;
	for(int x:v) r = r * ++i + __builtin_popcount(use & -(1<<x)),
		use |= 1 << x;                     // (note: minus, not ~!)
	return r;
}

int32_t main() {
	setup();

	vi v(9);
	arrput(v);
	string s;
	rep(i, 0, 9) {
		s += v[i] + '0';
	}

	unordered_map<string, int> d;
	d[s] = 0;
	queue<string> q;
	q.push(s);
	while (!q.empty()) {
		string u = q.front();
		q.pop();

		int x = d[u];
		vector<string> l;
		rep(i, 0, 9) {
			if (i % 3 != 2) {
				string v = u;
				swap(v[i], v[i + 1]);
				l.push_back(v);
			}
			if (i < 6) {
				string v = u;
				swap(v[i], v[i + 3]);
				l.push_back(v);
			}
		}
		
		for (string &v : l) {
			if (!d.count(v)) {
				d[v] = x + 1;
				q.push(v);
			}
		}
	}

	string a(9, '-');
	iota(all(a), '1');
	print(d[a]);
}
