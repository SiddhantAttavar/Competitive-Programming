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
		pair<int, int> a[n];
		range(i, 0, n) {
			cin >> a[i].first;
			a[i].second = i;
		}
		long long sum = a[0].first;
		sort(a, a + n);

		bool flag = true;
		range(i, 0, n) {
			if (a[i].second == i) {
				continue;
			}

			if (sum < a[i].first) {
				flag = false;
				break;
			}
			sum += a[i].first;
		}
		if (!flag) {
			print(-1);
			continue;
		}

		range(i, 1, n) {
			cout << a[i].second + 1 << " " << 1 << " " << a[i].first << endl;
		}
	}
}