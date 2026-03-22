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

vi brute(int n) {
	vi a(n);
	iota(all(a), 1);
	vi res = a;
	reverse(all(res));
	do {
		bool flag = true;
		int p = -1;
		for (int i : a) {
			int x = abs(i - p);
			if (x != 0 and x != 2 and x != 3 and x != 5 and x != 7) {
				flag = false;
				break;
			}
			p = i;
		}
		if (flag) {
			res = min(res, a);
		}
	} while (next_permutation(all(a)));
	return res;
}

int32_t main() {
	vector<vi> v(10, {-1});
	v[1] = {1};
	rep(i, 4, 10) {
		v[i] = brute(i);
	}
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		if (n < 10) {
			arrprint(v[n]);
			continue;
		}
		
		vi res;
		for (int i = 0; i + 10 <= n; i += 5) {
			res.push_back(i + 1);
			res.push_back(i + 3);
			res.push_back(i + 5);
			res.push_back(i + 2);
			res.push_back(i + 4);
		}

		for (int i : v[n % 5 + 5]) {
			res.push_back(i + (n - (n % 5 + 5)));
		}

		arrprint(res);

		// cout.flush();
		// sort(all(res));
		// assert(sz(res) == n);
		// assert(unique(all(res)) == res.end());
	}
}
