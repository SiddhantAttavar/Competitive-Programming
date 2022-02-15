#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
template<typename T> inline void print(T x) {cout << x << endl;}
template<typename T, typename... S> inline void print(T x, S... y) {cout << x << ' '; print(y ...);}
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... y) {cin >> x; input(y ...);}
#define range(i, j, n) for (int i = j; i < n; i++)
#define arrPut(x) for (auto &i : x) {cin >> i;}
#define arrPrint(x) for (auto i : x) {cout << i << ' ';} cout << endl;
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

string nextString(string s) {
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] != 'z') {
			s[i]++;
			range(j, i + 1, s.size()) {
				s[j] = 'a';
			}
			return s;
		}
	}
	return s;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		char k;
		input(n, k);

		string a, b;
		input(a, b);

		if (a.find(k) != string::npos) {
			print(a);
			continue;
		}

		bool flag = false;
		while (a < b) {
			a = nextString(a);
			if (a.find(k) != string::npos) {
				print(a);
				flag = true;
				break;
			}
		}
		if (!flag) {
			print("NO");
		}
	}
}
