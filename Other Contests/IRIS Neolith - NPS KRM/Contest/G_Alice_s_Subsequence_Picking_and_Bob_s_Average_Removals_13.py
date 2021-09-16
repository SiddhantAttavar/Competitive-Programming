# Alice and Bob are playing a game with an array a
#  of length n
# . In a move of the game, Alice can pick some subsequence of the array and give it to Bob. Bob will then delete all the numbers of the subsequence that are strictly larger than the average in the subsequence.
# Find the maximum number of elements Alice and Bob can remove together.

# A sequence b
#  is a subsequence of an array c
#  if b
#  can be obtained from c
#  by deletion of several (possibly, zero or all) elements

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
