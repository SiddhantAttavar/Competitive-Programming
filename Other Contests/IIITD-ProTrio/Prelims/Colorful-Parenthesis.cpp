#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int k;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		k = (int) sqrt(n);

		string s;
		input(s);

		vector<int> c(n);
		arrPut(c);

		vector<int> a(2 * n);
		stack<int> st;
		int x = 0;
		vector<pair<int, pair<int, int>>> q(n);
		range(i, 0, 2 * n) {
			if (s[i] == '(') {
				a[i] = c[x];
				q[x] = {x, {i, -1}};
				st.push(x);
				x++;
			}
			else {
				a[i] = c[st.top()];
				q[st.top()].second.second = i;
				st.pop();
			}
		}

		// arrPrint(a);

		// sort queries
		sort(q.begin(), q.end(), [](pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
			return make_pair(a.second.first / k, a.second.second) < make_pair(b.second.first / k, b.second.second);
		});

		int l = 0, r = 0;
		unordered_map<int, int> curr;
		curr[a[0]] = 1;
		vector<int> res(n);
		for (pair<int, pair<int, int>> p : q) {
			int u = p.first;
			int i, j;
			tie(i, j) = p.second;
			// print('d', u, i, j);

			// l > i
			while (l > i) {
				l--;
				if (!curr.count(a[l])) {
					curr[a[l]] = 0;
				}
				curr[a[l]]++;
			}

			// r < j
			while (r < j) {
				r++;
				if (!curr.count(a[r])) {
					curr[a[r]] = 0;
				}
				curr[a[r]]++;
			}

			// l < i
			while (l < i) {
				curr[a[l]]--;
				if (curr[a[l]] == 0) {
					curr.erase(a[l]);
				}
				l++;
			}
			
			// r > j
			while (r > j) {
				curr[a[r]]--;
				if (curr[a[r]] == 0) {
					curr.erase(a[r]);
				}
				r--;
			}

			// print('d', u);
			// for (pair<int, int> z : curr) {
			// 	print(z.first, z.second);
			// }

			// get ans for current range
			res[u] = curr.size();
		}

		arrPrint(res);
		// cout << endl;
	}
}
