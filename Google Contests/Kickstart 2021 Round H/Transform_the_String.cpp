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
	int tc; input(tc); 
	range(t, 1, tc + 1) {
		string s, f;
		input(s, f);

		vector<int> a(s.size());
		for (int i = 0; i < s.size(); i++) {
			a[i] = s[i] - 'a';
		}
		vector<int> b(f.size());
		for (int i = 0; i < f.size(); i++) {
			b[i] = f[i] - 'a';
		}

		sort(b.begin(), b.end());

		int res = 0;
		for (int i : a) {
			int j = lower_bound(b.begin(), b.end(), i) - b.begin();
			int curr;
			if (j == b.size()) {
				curr = b[0] + 26 - i;
			} else {
				curr = b[j] - i;
			}
			if (j > 0) {
				curr = min(curr, i - b[j - 1]);
			}
			else {
				curr = min(curr, i - (b[b.size() - 1] - 26));
			}
			res += curr;
		}
		cout << "Case #" << t << ": ";
		print(res);
	}
}