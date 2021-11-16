#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	setup();
	int n, q; input(n, q);
	priority_queue<int, vector<int>, greater<int>> pq;
	range(i, 0, n) {
		int x;
		input(x);
		pq.push(x);
	}
	int curr = 0;
	while (q--) {
		string o;
		int k;
		input(o, k);
		if (o == "A") {
			curr += k;
			while (!pq.empty() && pq.top() <= curr) {
				pq.pop();
			}
		}
		else {
			if (!pq.empty()) {
				int x = pq.top();
				pq.pop();
				pq.push(x + k);
			}
		}
	}
	print(n - pq.size());
}