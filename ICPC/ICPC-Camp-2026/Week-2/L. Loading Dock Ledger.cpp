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
	setup();

	int n, e;
	input(n, e);

	vector<pair<bool, int>> v;
	int t = 0;
	vi x;
	rep(i, 0, e) {
		string s;
		input(s);

		if (s[0] == 'I') {
			input(s);
			
			v.push_back({true, t});
			t++;
			if (s[0] == '?') {
				x.push_back(-1);
			}
			else {
				x.push_back(stoll(s));
			}
		}
		else{
			v.push_back({false, -1});
		}
	}

	set<int> s;
	rep(i, 0, n) {
		s.insert(i + 1);
	}
	for (int i : x) {
		if (i != -1) {
			s.erase(i);
		}
	}

	stack<int> z;
	vi res;
	for (auto [a, b] : v) {
		if (a) {
			z.push(b);
		}
		else if (z.empty()) {
			print("invalid");
			return 0;
		}
		else {
			res.push_back(z.top());
			z.pop();
		}
	}

	for (int i : res) {
		if (x[i] == -1) {
			print(*s.begin());
			s.erase(s.begin());
		}
		else {
			print(x[i]);
		}
	}
}
