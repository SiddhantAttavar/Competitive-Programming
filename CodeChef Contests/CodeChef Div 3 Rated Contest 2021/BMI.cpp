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
		int m, h;
		input(m);
		input(h);

		int bmi = m / (h * h);
		if (bmi <= 18) {
			print(1);
		}
		else if (bmi <= 24) {
			print(2);
		}
		else if (bmi <= 29) {
			print(3);
		}
		else {
			print(4);
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
		int m, h;
		input(m);
		input(h);

		int bmi = m / (h * h);
		if (bmi <= 18) {
			print(1);
		}
		else if (bmi <= 24) {
			print(2);
		}
		else if (bmi <= 29) {
			print(3);
		}
		else {
			print(4);
		}
	}
>>>>>>> f6f46ae63ca36b9fa6e961ce3b0edb092483751d
}