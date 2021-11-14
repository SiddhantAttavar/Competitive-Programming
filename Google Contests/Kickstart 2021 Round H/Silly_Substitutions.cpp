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

string merge(string a, string b) {
	int l = a.size() - 1, r = 0;
	if (b[r] - a[l] != 1 or (a[l] == '9' and b[r] == '0')) {
		return a + b;
	}

	char curr = '0' + ((a[l] - '0' + 2) % 10);
	l--; r++;
	while (true) {
		if (l >= 0 and ((curr - a[l] == 1) or (a[l] == '9' and curr == '0'))) {
			curr = '0' + ((curr - '0' + 1) % 10);
			l--;
		}
		else if (r < b.size() and ((b[r] - curr == 1) or (curr == '9' and b[r] == '0'))) {
			curr = '0' + ((curr - '0' + 2) % 10);
			r++;
		}
		else {
			break;
		}
	}
	return a.substr(0, l + 1) + curr + b.substr(r);
}

string solve(string s, int n) {
	if (n == 1) {
		return s;
	}
	string a = s.substr(0, n / 2);
	string b = s.substr(n / 2);
	return merge(solve(a, n / 2), solve(b, n / 2 + n % 2));
}

int32_t main() {
	setup();
	int tc; input(tc);
	range(t, 1, tc + 1) {
		int n; input(n);
		string s; input(s);
		string res;
		string curr;
		range(i, 0, n) {
			curr += s[i];
			if (i < n - 1 and abs(s[i + 1] - s[i]) % 2 == 0) {
				res += solve(curr, curr.size());
				curr = "";
			}
		}
		res += solve(curr, curr.size());
		cout << "Case #" << t << ": ";
		print(res);
	}
}

/*
int32_t main() {
	setup();
	int tc; input(tc);
	range(t, 1, tc + 1) {
		int n; input(n);
		string s; input(s);
		range(i, 0, 10) {
			string m;
			n = s.size();
			range(j, 0, n) {
				if (j < n - 1 and (s[j] - '0') == i and (s[j + 1] - '0') == (i + 1) % 10) {
					int curr = (i + 3) % 10;
					int k = j + 2;
					while (k < n and (s[k] - '0') == curr) {
						k++;
						curr = (curr + 2) % 10;
					}
					j = k - 1;
					m += (char) ('0' + (((s[k - 1] - '0') + 1) % 10));
				}
				else {
					m += s[j];
				}
			}
			s = m;
		}

		cout << "Case #" << t << ": ";
		print(s);
	}
}
*/