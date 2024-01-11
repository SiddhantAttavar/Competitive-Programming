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
	setup();

	int N = 1e7;

	int n;
	input(n);

	vector<int> a(n);
	arrPut(a);

	vector<int> c(N + 1, 0);
	for (int i : a) {
		c[i]++;
	}

	vector<bool> seive(N + 1, true);
	vector<int> pref(N + 1, 0);
	range(i, 2, N + 1) {
		pref[i] = pref[i - 1];
		if (seive[i]) {
			for (int j = i; j <= N; j += i) {
				seive[j] = false;
				pref[i] += c[j];
			}
		}
	}

	int m;
	input(m);
	while (m--) {
		int l, r;
		input(l, r);

		if (l > N) {
			print(0);
		}
		else {
			print(pref[min(r, N)] - pref[l - 1]);
		}
	}
}
