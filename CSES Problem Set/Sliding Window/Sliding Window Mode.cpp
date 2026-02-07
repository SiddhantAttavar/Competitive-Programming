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

	int n, k;
	input(n, k);

	vi x(n);
	arrput(x);

	map<int, int> m;
	set<pii> f;
	rep(i, 0, k) {
		if (m.count(x[i])) {
			f.erase(f.find({m[x[i]], -x[i]}));
		}
		m[x[i]]++;
		f.insert({m[x[i]], -x[i]});
	}

	cout << -f.rbegin()->second;
	rep(i, k, n) {
		if (m.count(x[i])) {
			f.erase(f.find({m[x[i]], -x[i]}));
		}
		m[x[i]]++;
		f.insert({m[x[i]], -x[i]});

		f.erase(f.find({m[x[i - k]], -x[i - k]}));
		m[x[i - k]]--;
		f.insert({m[x[i - k]], -x[i - k]});

		cout << ' ' << -f.rbegin()->second;
	}
	cout << endl;
}
