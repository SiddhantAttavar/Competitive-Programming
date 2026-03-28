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

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vi a(n), b(n);
		arrput(a);
		arrput(b);

		bool flag = true;
		rep(i, 0, k) {
			int x = -1, y = -1;
			for (int j = i; j < n; j += k) {
				if (b[j] != -1 and b[j] != a[j]) {
					x = a[j];
					y = b[j];
					break;
				}
			}

			if (x != -1) {
				for (int j = i; j < n; j += k) {
					if (a[j] != x or (b[j] != -1 and b[j] != y)) {
						flag = false;
						break;
					}
					b[j] = y;
				}
				continue;
			}

			bool c = true;
			for (int j = i; j < n; j += k) {
				if (a[j] != a[i] or b[j] != -1) {
					c = false;
					break;
				}
			}
			if (!c) {
				for (int j = i; j < n; j += k) {
					if (b[j] != -1 and b[j] != a[j]) {
						flag = false;
						break;
					}
					b[j] = a[j];
				}
				continue;
			}
		}

		multiset<int> s;
		rep(i, 0, k) {
			s.insert(a[i]);
		}

		rep(i, 0, k) {
			if (b[i] != -1) {
				multiset<int>::iterator j = s.find(b[i]);
				if (j == s.end()) {
					flag = false;
					break;
				}
				s.erase(j);
			}
		}

		rep(i, 0, k) {
			if (b[i] == -1) {
				b[i] = *s.begin();
				s.erase(s.begin());
			}
		}

		vi x(a.begin(), a.begin() + k);
		vi y(b.begin(), b.begin() + k);
		sort(all(x));
		sort(all(y));

		if (flag and x == y) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
