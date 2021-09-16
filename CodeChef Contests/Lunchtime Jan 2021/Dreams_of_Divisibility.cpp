#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

int n, k;
vector<int> a;

bool adding(int x, int i) {
	if (x == 0) {
		return true;
	}
	if (i == n || x < 0) {
		return false;
	}
	return adding(x, i + 1) || adding(x - a[i], i + 1);
}

bool isPowOf2(int x) {
	return ceil(log2(x)) == floor(log2(x));
}

int main() {
	setup();
	input(int, tc); while (tc--) {
		cin >> n >> k;
		a = vector<int>();
		range(i, 0, n) {
			input(int, x);
			if (x % k > 0) {
				a.push_back(x % k);
			}
		}
		sort(a.begin(), a.end(), greater<int>());

		bool flag = true;
		range(i, 0, a.size() - 1) {
			if (!adding(k - a[i], i + 1)) {
				flag = false;
				break;
			}
			a[i] = 0;
		}

		if ((k - a[a.size() - 1]) % a[a.size() - 1] == 0) {
			flag = flag || isPowOf2((k - a[a.size() - 1]) / a[a.size() - 1]);
		}
		else {
			flag = false;
		}

		print(flag ? "YES" : "NO");
	}
}