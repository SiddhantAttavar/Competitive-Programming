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
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup();

	int n;
	input(n);

	vector<vi> a(n, vi(n));
	rep(i, 0, n) {
		arrput(a[i]);
	}

	vi x(n), y;
	iota(all(x), 0);
	bool flag = true;
	while (flag) {
		flag = false;
		for (int i : x) {
			int p = 0, q = 0;
			for (int j : x) {
				p += a[i][j];
			}
			for (int j : y) {
				q += a[i][j];
			}
			if (p < q) {
				flag = true;
				x.erase(find(all(x), i));
				y.push_back(i);
				break;
			}
		}
		if (flag) {
			continue;
		}
		for (int i : y) {
			int p = 0, q = 0;
			for (int j : x) {
				p += a[i][j];
			}
			for (int j : y) {
				q += a[i][j];
			}
			if (p > q) {
				flag = true;
				y.erase(find(all(y), i));
				x.push_back(i);
				break;
			}
		}
	}

	string res(n, 'X');
	for (int i : y) {
		res[i] = 'Y';
	}
	print(res);
}
