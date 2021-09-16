<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

int main() {
	setup();
	input(int, tc); while (tc--) {
		input(int, n);
		input(int, x);

		if (x <= n || x == n * n) {
			print("Yes");
			continue;
		}
		else {
			print("No");
		}
	}
=======
#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

int main() {
	setup();
	input(int, tc); while (tc--) {
		input(int, n);
		input(int, x);

		if (x <= n || x == n * n) {
			print("Yes");
			continue;
		}
		else {
			print("No");
		}
	}
>>>>>>> f6f46ae63ca36b9fa6e961ce3b0edb092483751d
}