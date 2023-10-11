#include <stdio.h>

const int MAX_N = (int) 1e7;
int spf[(int) 1e7 + 10];

int main() {
	spf[1] = 1;
	for (int i = 2; i <= MAX_N; i++) {
		spf[i] = i;
	}

	for (int i = 4; i <= MAX_N; i += 2) {
		spf[i] = 2;
	}

	for (int i = 3; i * i <= MAX_N; i++) {
		if (spf[i] == i) {
			for (int j = i + i; j <= MAX_N; j += i) {
				if (spf[j] == j) {
					spf[j] = i;
				}
			}
		}
	}

	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		int a[n];
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
	}
	return 0;
}
