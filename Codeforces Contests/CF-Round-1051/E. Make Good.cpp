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

		string s;
		input(s);

		if (n % 2 == 1) {
			print(-1);
			continue;
		}

		vector<int> l = {1};
		rep(i, 1, n) {
			if (s[i] == s[i - 1]) {
				l.back()++;
			}
			else {
				l.push_back(1);
			}
		}

		string t;
		int j = 0, z = 0;
		for (int i : l) {
			z += i - (i % 2);
			if (i % 2 == 1) {
				t += s[j];
			}
			j += i;
		}
		t = string(z, '(') + t;

		if (t[0] != '(') {
			print(-1);
			continue;
		}

		if (t.back() == '(') {
			int j = n - 2;
			while (j >= 0 and t[j] != t[j + 1]) {
				j--;
			}
 
			if (j == -1) {
				print(-1);
				continue;
			}
 
			char c = t[j];
			t.erase(t.begin() + j + 1);
			t.erase(t.begin() + j);
			t += ')';
			t += ')';
 
			if (n >= 3 and t[n - 3] == ')') {
				t[n - 2] = '(';
				t[n - 3] = '(';
			}
		}

		int x = n / 2 - count(t.begin(), t.end(), ')');
		for (int i = n - 2; i >= 0; i--) {
			if (x >= 2 and t[i] == '(' and t[i + 1] == '(') {
				x -= 2;
				t[i] = ')';
				t[i + 1] = ')';
			}
		}
 
		int c = 0;
		bool flag = true;
		for (char i : t) {
			if (i == '(') {
				c++;
			}
			else if (c == 0) {
				flag = false;
				break;
			}
			else {
				c--;
			}
		}
 
		if (flag and c == 0) {
			print(t);
		}
		else {
			print(-1);
		}
	}
}
