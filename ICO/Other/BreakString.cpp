#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(x) cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

int main() {
	setup();
	int tc; input(tc); while (tc--) {
		int n, k;
		input(n);
		input(k);

		string s; input(s);

		int res1[n] = {true};
		int first = 0;
		int count1 = 1;
		int currSum = s[0] == '0' ? -1 : 1;
		range(i, 1, n) {
			currSum += s[i] == '0' ? -1 : 1;
			if (currSum > k) {
				res1[i] = true;
				currSum = s[i] == '0' ? -1 : 1;
				count1++;
			}
			else {
				res1[i] = false;
			}
		}

		bool flag1 = currSum >= -k;
		if (first > 0 && currSum <= 0) {
			res1[first] = false;
			count1--;
		}

		int res2[n] = {true};
		first = 0;
		currSum = s[0] == '0' ? -1 : 1;
		int count2 = 1;
		range(i, 1, n) {
			currSum += s[i] == '0' ? -1 : 1;
			if (currSum < -k) {
				res2[i] = true;
				first = i;
				currSum = s[i] == '0' ? -1 : 1;
				count2++;
			}
			else {
				res2[i] = false;
			}
		}

		bool flag2 = currSum <= k;
		if (first > 0 && currSum >= 0) {
			res2[first] = false;
			count2--;
		}

		if (!flag2 || (flag1 && count1 < count2)) {
			for (bool b : res1) {
				cout << b;
			}
		}
		else {
			for (bool b : res2) {
				cout << b;
			}
		}
		cout << endl;
	}
}