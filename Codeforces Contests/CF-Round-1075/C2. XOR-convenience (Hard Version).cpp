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
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vi res(n);
		res[0] = n - (n % 2);
		rep(i, 1, n - 2) {
			res[i] = (i + 1) ^ 1;
		}
		res[n - 2] = 1;
		res[n - 1] = (n - 1) ^ 1;

		if (n % 2 == 1) {
			arrprint(res);
			continue;
		}

		set<int> s = {res[n - 1], res[n - 2]};
		bool flag = false;
		for (int i = n - 3; i > 0; i--) {
			if (s.count(n ^ (i + 1))) {
				flag = true;
				swap(res[0], res[i]);
				break;
			}
			s.insert(res[i]);
		}

		if (flag) {
			arrprint(res);
		}
		else {
			print(-1);
		}
	}
}
