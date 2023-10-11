#include <stdio.h>

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		int w[n], a[n];
		for (int i = 0; i < n; i++) {
			scanf("%d", &w[i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}

		int pref[n], suff[n];
		pref[0] = 0;
		for (int i = 1; i < n; i++) {
			if (a[i - 1] - w[i - 1] > (pref[i - 1] - w[i - 1])) {
				pref[i] = a[i - 1] - w[i - 1];
			}
			else {
				pref[i] = pref[i - 1] - w[i - 1];
			}
		}

		suff[n - 1] = 0;
		for (int i = n - 2; i >= 0; i--) {
			if (a[i + 1] - w[i + 1] > (suff[i + 1] - w[i + 1])) {
				suff[i] = a[i + 1] - w[i + 1];
			}
			else {
				suff[i] = suff[i + 1] - w[i + 1];
			}
		}

		// for (int i = 0; i < n; i++) {
		// 	printf("%d %d\n", w[i], a[i]);
		// 	printf("%d %d\n", pref[i], suff[i]);
		// }

		printf("%d ", a[0] - w[0] > suff[0] - w[0] ? a[0] - w[0] : suff[0] - w[0]);
		for (int i = 1; i < n - 1; i++) {
			printf("%d ", a[i] - w[i] > pref[i] + suff[i] - w[i] ? a[i] - w[i] : pref[i] + suff[i] - w[i]);
		}
		if (n > 1) {
			printf("%d\n", a[n - 1] - w[n - 1] > pref[n - 1] - w[n - 1] ? a[n - 1] - w[n - 1] : pref[n - 1] - w[n - 1]);
		}
	}
	return 0;
}
