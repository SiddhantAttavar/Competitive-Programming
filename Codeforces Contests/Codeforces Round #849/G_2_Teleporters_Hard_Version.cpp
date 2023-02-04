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

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, c;
		input(n, c);

		vector<int> a(n);
		arrPut(a);

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		range(i, 1, n + 1) {
			int y = i + a[i - 1];
			if (y <= c) {
				pq.push(make_pair(y, i));
			}
		}

		int res = 0;
		int m = 1e9;
		bool flag = true;
		bool flag2 = true;
		set<int> s, t;
		range(i, 1, n + 1) {
			t.insert(i);
		}

		while (flag) {
			while (!pq.empty()) {
				int x, i;
				tie(x, i) = pq.top();
				pq.pop();
				// print(x, i);

				if (c >= x) {
					if (s.count(i)) {
						continue;
					}

					c -= x;
					res++;
					s.insert(i);
					t.erase(i);
					// print('i', i, c);

					if (flag2) {
						m = max(0ll, 2 * i - (n + 1));
						range(j, 1, n + 1) {
							int y = (n + 1) - j + a[j - 1];
							pq.push(make_pair(y, j));
						}
						flag2 = false;
					}
				}
				else {
					break;
				}
			}

			if (!t.size()) {
				break;
			}

			for (int i : t) {
				int x = 2 * i - (n + 1);
				if (x <= 0) {
					flag = false;
					break;
				}

				if (x < m) {
					c += m - x;
					m = x;
				}
			}
		}

		print(res);
	}
}
