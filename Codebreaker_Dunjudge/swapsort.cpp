// https://codebreaker.xyz/problem/swapsort
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
	
	int n;
	input(n);
	vector<int> p(n);
	arrPut(p);
	vector<int> a(p.begin(), p.end());
	sort(a.begin(), a.end());
	vector<bool> b(n);
	int curr = 0;
	range(i, 0, n) {
		b[i] = a[i] == p[i];
		curr += b[i];
	}

	int q;
	input(q);
	int res = 0;
	while (q--) {
		int l, r;
		input(l, r);
		l--;
		r--;

		swap(p[l], p[r]);

		if (b[l] != (a[l] == p[l])) {
			b[l] = a[l] == p[l];
			if (b[l]) {
				curr++;
			}
			else {
				curr--;
			}
		}
		if (b[r] != (a[r] == p[r])) {
			b[r] = a[r] == p[r];
			if (b[r]) {
				curr++;
			}
			else {
				curr--;
			}
		}

		if (curr == n) {
			res++;
		}
	}
	print(res);
	arrPrint(p);
}
