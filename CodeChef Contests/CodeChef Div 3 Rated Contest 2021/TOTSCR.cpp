<<<<<<< HEAD
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
		int n, k;
		input(n);
		input(k);

		int a[k]; arrPut(a);
		range(i, 0, n) {
			ll score = 0;
			string s; input(s);
			range(j, 0, k) {
				if (s[j] == '1') {
					score += a[j];
				}
			}
			print(score);
		}
	}
=======
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
		int n, k;
		input(n);
		input(k);

		int a[k]; arrPut(a);
		range(i, 0, n) {
			ll score = 0;
			string s; input(s);
			range(j, 0, k) {
				if (s[j] == '1') {
					score += a[j];
				}
			}
			print(score);
		}
	}
>>>>>>> f6f46ae63ca36b9fa6e961ce3b0edb092483751d
}