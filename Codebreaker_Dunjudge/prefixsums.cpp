// https://codebreaker.xyz/problem/prefixsums
#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n, q;
	std::cin >> n >> q;
	long long a[n + 1];
	a[0] = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		a[i] += a[i - 1];
	}
	while (q--) {
		int l, r;
		std::cin >> l >> r;
		std::cout << a[r] - a[l - 1] << '\n';
	}
}

