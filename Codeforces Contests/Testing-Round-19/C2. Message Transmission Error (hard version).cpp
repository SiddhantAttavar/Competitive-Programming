#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

vector<int> z(string s) {
	int N = size(s), L = 1, R = 0; s += '#';
	vector<int> ans(N); ans[0] = N; 
	range(i,1,N) {
		if (i <= R) ans[i] = min(R-i+1,ans[i-L]);
		while (s[i+ans[i]] == s[ans[i]]) ++ans[i];
		if (i+ans[i]-1 > R) L = i, R = i+ans[i]-1;
	}
	return ans;
}

int32_t main() {
	setup();

	string s;
	input(s);

	vector<int> a = z(s);

	int n = s.size();
	for (int l = n % 2 ? 1 : 2; l < n; l += 2) {
		int x = (n + l) / 2;
		if (a[n - x] >= x - l and a[n - l] == l) {
			print("YES");
			print(s.substr(n - x));
			return 0;
		}
	}

	print("NO");
}
