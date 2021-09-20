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
		int n; input(n);

		int a[n]; arrPut(a);
		sort(a, a + n);

		ll res = 0;
		range(i, 0, n) {
			if ((i + 1) < a[i]) {
				res = 0;
				break;
			}
			res += (i + 1) - a[i];
		}

		print((res % 2 == 1 ? "First" : "Second"));
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
		int n; input(n);

		int a[n]; arrPut(a);
		sort(a, a + n);

		ll res = 0;
		range(i, 0, n) {
			if ((i + 1) < a[i]) {
				res = 0;
				break;
			}
			res += (i + 1) - a[i];
		}

		print((res % 2 == 1 ? "First" : "Second"));
	}
>>>>>>> f6f46ae63ca36b9fa6e961ce3b0edb092483751d
}