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

int get(int i, int j, vector<int> &p) {
	double k = ((double) p[j] - p[i]) / (j - i) + 0.5;
	if (abs(k - round(k)) < -1e6) {
		return round(k);
	}
	return k;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrput(a);

		vector<int> p(n + 1, 0);
		rep(i, 0, n) {
			p[i + 1] = p[i] + a[i];
		}

		vector<int> res(n, 0);
		vector<int> s = {n};
		for (int i = n - 1; i >= 0; i--) {
			while (!s.empty() and p[s.back()] < p[i]) {
				s.pop_back();
			}
			while (s.size() >= 2 and get(i, s.back(), p) < get(i, s[s.size() - 2], p)) {
				s.pop_back();
			}
			if (s.empty()) {
				s.push_back(i);
				continue;
			}
			res[i] = s.back() - i;
			s.push_back(i);
		}
		arrprint(res);
	}
}
