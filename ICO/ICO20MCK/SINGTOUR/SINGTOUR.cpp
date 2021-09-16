#include <bits/stdc++.h>
#define range(var, start, end) for (int var = start; var < end; var++)
#define input(var) cin >> var
#define arrPut(arr) for (auto &var : arr) {cin >> var;}
#define print(msg) cout << msg << '\n'
#define arrPrint(arr) for (auto var : arr) {cout << var << " ";} cout << '\n';
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int compareInd = 0;

bool compare(array<int, 3> &a, array<int, 3> &b) {
	return a[1] >= b[1];
}

int main() {
	int tc; input(tc); while (tc--) {
		int n; input(n);
		array<int, 3> a[n];
		range(i, 0, n) {
			input(a[i][1]);
			input(a[i][0]);
			a[i][2] = i;
		}

		sort(a, a + n);

		int s[n];
		range(i, 0, n) {
			s[a[i][2]] = i;
		}

		compareInd++;
		sort(a, a + n, compare);
		range(i, 0, n) {
			s[a[i][2]] += i;
		}

		arrPrint(s);
	}
}