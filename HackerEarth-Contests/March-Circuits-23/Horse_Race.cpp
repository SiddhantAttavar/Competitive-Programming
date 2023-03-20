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
		int n, m, x;
		input(n, m, x);

		vector<int> a(n);
		arrPut(a);
		range(i, 0, n) {
			a[i]--;
		}

		vector<int> b(m, 0);
		int c = 0;
		range(i, 0, n) {
			if (a[i] < m) {
				b[a[i]]++;
			}
			else {
				c++;
			}
		}

		priority_queue<int, vector<int>, greater<int>> pq1;
		priority_queue<int> pq2;
		range(i, 0, m) {
			pq1.push(b[i]);
			pq2.push(b[i]);
		}

		while (x--) {
			int k = pq1.top();
			pq1.pop();

			if (c) {
				c--;
				pq1.push(k + 1);
			}
			else {
				int l = pq2.top();
				if (l - 1 <= k) {
					pq1.push(k);
					break;
				}
				pq2.pop();
				pq2.push(l - 1);
				pq1.push(k + 1);
			}
		}

		print(pq1.top());
	}
}
