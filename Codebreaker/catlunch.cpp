// https://codebreaker.xyz/problem/catlunch
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
	
	int n, k;
	input(n, k);
	vector<int> t(n);
	arrPut(t);
	
	int res = 0;
	int curr = 0;
	priority_queue<int> pq;
	range(i, 0, k) {
		pq.push(t[i]);
	}
	range(i, 0, n) {
		curr += pq.top();
		res = max(res, curr);
		pq.pop();
		if (i + k < n) {
			pq.push(t[i + k]);
		}
	}
	print(res);
}
