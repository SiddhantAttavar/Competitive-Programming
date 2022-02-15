#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
template<typename T> inline void print(T x) {cout << x << endl;}
template<typename T, typename... S> inline void print(T x, S... y) {cout << x << ' '; print(y ...);}
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... y) {cin >> x; input(y ...);}
#define range(i, j, n) for (int i = j; i < n; i++)
#define arrPut(x) for (auto &i : x) {cin >> i;}
#define arrPrint(x) for (auto i : x) {cout << i << ' ';} cout << endl;
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		int p, q;
		input(p, q);

		if (p == q) {
			map<int, int> m;
			for (int i : a) {
				m[i]++;
			}

			int x = 0;
			for (pair<int, int> p : m) {
				x = max(x, p.second);
			}

			vector<int> res;
			range(i, 0, n) {
				if (m[a[i]] != x) {
					res.push_back(i + 1);
				}
			}
			print(res.size());
			arrPrint(res);
			continue;
		}
		
		if (q == 1) {
			double x;
			for (int i : a) {
				x += i;
			}
			x /= n;
	
			vector<int> res;
			range(i, 0, n) {
				if (a[i] > x) {
					res.push_back(i + 1);
				}
			}
			print(res.size());
			arrPrint(res);
			continue;
		}
	}
}
