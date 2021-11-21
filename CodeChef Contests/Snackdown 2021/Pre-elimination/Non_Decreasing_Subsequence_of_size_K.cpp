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
	setup(); int tc; input(tc); while (tc--) {
		int n, k; input(n, k);
		vector<int> a(n); arrPut(a);
		sort(a.begin(), a.end());
		
		if (k == 1) {
			set<int> s;
			for (int i : a) {
				s.insert(i);
			}
			if (s.size() == n) {
				sort(a.begin(), a.end());
				reverse(a.begin(), a.end());
				arrPrint(a);
			}
			else {
				print(-1);
			}
			continue;
		}
		
		vector<int> res;
		int l = 0, r = n - 1;
		range(i, 0, n / k) {
			range(j, r - k, r) {
				res.push_back(a[j]);
			}
			r -= k;
			res.push_back(a[l]);
			l++;
		}
		range(i, l, r + 1) {
			res.push_back(a[i]);
		}
		
		int cnt = 1;
		int maxCnt = 0;
		range(i, 1, n) {
			if (res[i] >= res[i - 1]) {
				cnt++;
				maxCnt = max(maxCnt, cnt);
			}
			else {
				cnt = 1;
			}
		}
		if (maxCnt == k) {
			arrPrint(res);
		}
		else {
			print(-1);
		}
	}
}
