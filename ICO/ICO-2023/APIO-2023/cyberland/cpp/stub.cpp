#include "cyberland.h"

#include <cassert>
#include <cstdio>

#include <vector>

int main() {
  int T;
  assert(1 == scanf("%d", &T));
  while (T--){
    int N,M,K,H;
    assert(4 == scanf("%d %d %d\n%d", &N, &M, &K, &H));
    std::vector<int> x(M);
    std::vector<int> y(M);
    std::vector<int> c(M);
    std::vector<int> arr(N);
    for (int i=0;i<N;i++)
      assert(1 == scanf("%d", &arr[i]));
    for (int i=0;i<M;i++)
      assert(3 == scanf("%d %d %d", &x[i], &y[i], &c[i]));
    printf("%.12lf\n", solve(N, M, K, H, x, y, c, arr));
  }
}
