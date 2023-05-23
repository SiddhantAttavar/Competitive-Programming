#include "sequence.h"

#include <cassert>
#include <cstdio>

#include <vector>

int main() {
  int N;
  assert(1 == scanf("%d", &N));

  std::vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    assert(1 == scanf("%d", &A[i]));
  }

  int result = sequence(N, A);
  printf("%d\n", result);
  return 0;
}
