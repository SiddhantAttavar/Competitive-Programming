#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int sizeN[10] = {4, 5, 7, 9, 10, 12, 15, 18, 19, 20};

int ans[10][20] = {
	{8, 4, 2, 1},
{8, 4, 32, 2, 16},
{16, 32, 2, 64, 8, 4, 1},
{256, 32, 1, 2, 64, 4, 16, 128, 8},
{2, 512, 128, 8, 16, 64, 1, 32, 256, 4},
{1, 256, 2048, 128, 2, 64, 4, 16, 8, 512, 32, 1024},
{65536, 262144, 4096, 32768, 128, 524288, 16384, 8192, 512, 2048, 1024, 64, 256, 131072, 1048576},
{1048576, 2048, 262144, 128, 32, 256, 512, 8192, 32768, 4096, 131072, 65536, 64, 8, 16384, 524288, 16, 1024},
{64, 1048576, 262144, 8388608, 16384, 256, 4096, 8192, 32768, 4194304, 1024, 2048, 128, 131072, 65536, 16777216, 512, 2097152, 524288},
{1024, 4096, 33554432, 262144, 256, 128, 1048576, 2048, 4194304, 65536, 512, 2097152, 8388608, 67108864, 8192, 32768, 131072, 16777216, 524288, 16384}
};

int32_t main() {
	setup();
	int t; input(t);
	range(i, 0, sizeN[t - 1]) {
		cout << ans[t - 1][i] << ' ';
	}
	cout << endl;
}
