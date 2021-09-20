#include <bits/stdc++.h>
#define range(it, start, end) for (int it = start; it < end; it++)
#define input(x) cin >> x
#define print(x) cout << x << endl
#define arrPut(var) for (auto &i : var) {cin >> i;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << " ";} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
	setup();
	int tc; input(tc); while (tc--) {
		string a, s1, s2;
		input(a);
		input(s1);
		input(s2);

		transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
		transform(s2.begin(), s2.end(), s2.begin(), ::tolower);

		if (a[0] == 'A') {
			s2[0] -= 32;
			print(s1 << s2);
		}
		else if (a[0] == 'B') {
			print(s1 << '_' << s2);
		}
		else if (a[0] == 'C') {
			transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
			transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
			print(s1 << '_' << s2);	
		}
		else if (a[0] == 'D') {
			s1[0] -= 32;
			s2[0] -= 32;
			print(s1 << '-' << s2);
		}
		else {
			for (int i = 1; i < s1.size(); i += 2) {
				s1[i] -= 32;
			}
			for (int i = 1; i < s2.size(); i += 2) {
				s2[i] -= 32;
			}
			print(s1 << '|' << s2);
		}
	}
}