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

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrput(a);

		vector<int> l(n), r(n);
		set<pair<int, int>> s;
		rep(i, 0, n) {
			l[i] = (i + n - 1) % n;
			r[i] = (i + 1) % n;
			s.insert({max(a[i], a[r[i]]), i});
		}

		int res = 0;
		rep(i, 0, n - 1) {
			res += s.begin()->first;
			int j = s.begin()->second;

			s.erase({max(a[j], a[r[j]]), j});
			s.erase({max(a[r[j]], a[r[r[j]]]), r[j]});
			s.erase({max(a[l[j]], a[j]), l[j]});

			a[j] = max(a[j], a[r[j]]);
			l[r[r[j]]] = j;
			r[j] = r[r[j]];
			s.insert({max(a[l[j]], a[j]), l[j]});
			s.insert({max(a[j], a[r[j]]), j});
		}
		print(res);
	}
}
