def Sieve(num):
	l2=[]
	prime = [True for i in range(num+1)]
	p = 2
	while (p * p <= num):
		if (prime[p] == True):
			for i in range(p * p, num+1, p):
				prime[i] = False
		p += 1
	for p in range(2, num+1):
		if prime[p]:
			l2.append(p)
	return((l2))
# s = Sieve(50)

def op(x,y):
	# print("X==",x)
	# print("Y==",y)
	return(x+y)
class segtree():
	def __init__(self,init,func,ide):
		self.n=len(init)
		self.func=func
		self.ide=ide
		self.size=1<<(self.n-1).bit_length()
		self.tree=[self.ide for i in range(2*self.size)]
		for i in range(self.n):
			self.tree[self.size+i]=init[i]
		for i in range(self.size-1,0,-1):
			self.tree[i]=self.func(self.tree[2*i], self.tree[(2*i)|1])
  	
	def update(self,k,x):
		k+=self.size
		self.tree[k]=x

		k>>=1
		while k:
			self.tree[k]=self.func(self.tree[2*k],self.tree[k*2|1])
			k>>=1
  
	def get(self,i):
		return self.tree[i+self.size]
  
	def query(self,l,r):
		# Include left index but not right
		l+=self.size
		r+=self.size
		ans=0
		while l<r:
			if l&1:
				ans+= self.tree[l]
				l+=1
			if r&1:
				r-=1
				ans+= self.tree[r]
			l>>=1
			r>>=1
		return ans
		
		def debug(self,s=10):
			print([self.get(i) for i in range(min(self.n,s))])
		
class sortedlist:
	def __init__(self, iterable=[], _load=200):
		"""Initialize sorted list instance."""
		values = sorted(iterable)
		self._len = _len = len(values)
		self._load = _load
		self._lists = _lists = [values[i:i + _load] for i in range(0, _len, _load)]
		self._list_lens = [len(_list) for _list in _lists]
		self._mins = [_list[0] for _list in _lists]
		self._fen_tree = []
		self._rebuild = True
 
	def _fen_build(self):
		"""Build a fenwick tree instance."""
		self._fen_tree[:] = self._list_lens
		_fen_tree = self._fen_tree
		for i in range(len(_fen_tree)):
			if i | i + 1 < len(_fen_tree):
				_fen_tree[i | i + 1] += _fen_tree[i]
		self._rebuild = False
 
	def _fen_update(self, index, value):
		"""Update `fen_tree[index] += value`."""
		if not self._rebuild:
			_fen_tree = self._fen_tree
			while index < len(_fen_tree):
				_fen_tree[index] += value
				index |= index + 1
 
	def _fen_query(self, end):
		"""Return `sum(_fen_tree[:end])`."""
		if self._rebuild:
			self._fen_build()
 
		_fen_tree = self._fen_tree
		x = 0
		while end:
			x += _fen_tree[end - 1]
			end &= end - 1
		return x
 
	def _fen_findkth(self, k):
		"""Return a pair of (the largest `idx` such that `sum(_fen_tree[:idx]) <= k`, `k - sum(_fen_tree[:idx])`)."""
		_list_lens = self._list_lens
		if k < _list_lens[0]:
			return 0, k
		if k >= self._len - _list_lens[-1]:
			return len(_list_lens) - 1, k + _list_lens[-1] - self._len
		if self._rebuild:
			self._fen_build()
 
		_fen_tree = self._fen_tree
		idx = -1
		for d in reversed(range(len(_fen_tree).bit_length())):
			right_idx = idx + (1 << d)
			if right_idx < len(_fen_tree) and k >= _fen_tree[right_idx]:
				idx = right_idx
				k -= _fen_tree[idx]
		return idx + 1, k
 
	def _delete(self, pos, idx):
		"""Delete value at the given `(pos, idx)`."""
		_lists = self._lists
		_mins = self._mins
		_list_lens = self._list_lens
 
		self._len -= 1
		self._fen_update(pos, -1)
		del _lists[pos][idx]
		_list_lens[pos] -= 1
 
		if _list_lens[pos]:
			_mins[pos] = _lists[pos][0]
		else:
			del _lists[pos]
			del _list_lens[pos]
			del _mins[pos]
			self._rebuild = True
 
	def _loc_left(self, value):
		"""Return an index pair that corresponds to the first position of `value` in the sorted list."""
		if not self._len:
			return 0, 0
 
		_lists = self._lists
		_mins = self._mins
 
		lo, pos = -1, len(_lists) - 1
		while lo + 1 < pos:
			mi = (lo + pos) >> 1
			if value <= _mins[mi]:
				pos = mi
			else:
				lo = mi
 
		if pos and value <= _lists[pos - 1][-1]:
			pos -= 1
 
		_list = _lists[pos]
		lo, idx = -1, len(_list)
		while lo + 1 < idx:
			mi = (lo + idx) >> 1
			if value <= _list[mi]:
				idx = mi
			else:
				lo = mi
 
		return pos, idx
 
	def _loc_right(self, value):
		"""Return an index pair that corresponds to the last position of `value` in the sorted list."""
		if not self._len:
			return 0, 0
 
		_lists = self._lists
		_mins = self._mins
 
		pos, hi = 0, len(_lists)
		while pos + 1 < hi:
			mi = (pos + hi) >> 1
			if value < _mins[mi]:
				hi = mi
			else:
				pos = mi
 
		_list = _lists[pos]
		lo, idx = -1, len(_list)
		while lo + 1 < idx:
			mi = (lo + idx) >> 1
			if value < _list[mi]:
				idx = mi
			else:
				lo = mi
 
		return pos, idx
 
	def add(self, value):
		"""Add `value` to sorted list."""
		_load = self._load
		_lists = self._lists
		_mins = self._mins
		_list_lens = self._list_lens
 
		self._len += 1
		if _lists:
			pos, idx = self._loc_right(value)
			self._fen_update(pos, 1)
			_list = _lists[pos]
			_list.insert(idx, value)
			_list_lens[pos] += 1
			_mins[pos] = _list[0]
			if _load + _load < len(_list):
				_lists.insert(pos + 1, _list[_load:])
				_list_lens.insert(pos + 1, len(_list) - _load)
				_mins.insert(pos + 1, _list[_load])
				_list_lens[pos] = _load
				del _list[_load:]
				self._rebuild = True
		else:
			_lists.append([value])
			_mins.append(value)
			_list_lens.append(1)
			self._rebuild = True
 
	def discard(self, value):
		"""Remove `value` from sorted list if it is a member."""
		_lists = self._lists
		if _lists:
			pos, idx = self._loc_right(value)
			if idx and _lists[pos][idx - 1] == value:
				self._delete(pos, idx - 1)
 
	def remove(self, value):
		"""Remove `value` from sorted list; `value` must be a member."""
		_len = self._len
		self.discard(value)
		if _len == self._len:
			raise ValueError('{0!r} not in list'.format(value))
 
	def pop(self, index=-1):
		"""Remove and return value at `index` in sorted list."""
		pos, idx = self._fen_findkth(self._len + index if index < 0 else index)
		value = self._lists[pos][idx]
		self._delete(pos, idx)
		return value
 
	def bisect_left(self, value):
		"""Return the first index to insert `value` in the sorted list."""
		pos, idx = self._loc_left(value)
		return self._fen_query(pos) + idx
 
	def bisect_right(self, value):
		"""Return the last index to insert `value` in the sorted list."""
		pos, idx = self._loc_right(value)
		return self._fen_query(pos) + idx
 
	def count(self, value):
		"""Return number of occurrences of `value` in the sorted list."""
		return self.bisect_right(value) - self.bisect_left(value)
 
	def __len__(self):
		"""Return the size of the sorted list."""
		return self._len
 
	def __getitem__(self, index):
		"""Lookup value at `index` in sorted list."""
		pos, idx = self._fen_findkth(self._len + index if index < 0 else index)
		return self._lists[pos][idx]
 
	def __delitem__(self, index):
		"""Remove value at `index` from sorted list."""
		pos, idx = self._fen_findkth(self._len + index if index < 0 else index)
		self._delete(pos, idx)
 
	def __contains__(self, value):
		"""Return true if `value` is an element of the sorted list."""
		_lists = self._lists
		if _lists:
			pos, idx = self._loc_left(value)
			return idx < len(_lists[pos]) and _lists[pos][idx] == value
		return False
 
	def __iter__(self):
		"""Return an iterator over the sorted list."""
		return (value for _list in self._lists for value in _list)
 
	def __reversed__(self):
		"""Return a reverse iterator over the sorted list."""
		return (value for _list in reversed(self._lists) for value in reversed(_list))
 
	def __repr__(self):
		"""Return string representation of sorted list."""
		return 'SortedList({0})'.format(list(self))


from collections import deque,defaultdict
g = defaultdict()
def bfs(g, start):
	queue, enqueued = deque([(None, start)]), set([start])
	while queue:
		parent, n = queue.popleft()
		yield parent, n
		# Can use a variable fin, and break if n==fin
		new = set(g[n]) - enqueued
		enqueued |= new
		queue.extend([(n, child) for child in new])
# list(bfs(dict,initial pt)) gives ==> [(None,start),(start,x1),(x1,x2),(x1,x3),(x2,finish)]

class dsu:
	def __init__(self, n):
		self.parent = list(range(n))
		self.size = [1 for i in range(n)]
		self.num_sets = n
	def find(self, a):
		acopy = a
		while a != self.parent[a]:
			a = self.parent[a]
		while acopy != a:
			self.parent[acopy], acopy = a, self.parent[acopy]
		return a
	def union(self, a, b):
		a, b = self.find(a), self.find(b)
		if a != b:
			if self.size[a] < self.size[b]:
				a, b = b, a
			self.num_sets -= 1
			self.parent[b] = a
			self.size[a] += self.size[b]
			
# Initialize with u = dsu(No. of ele)[No.+1 for index out of range]
# Use while acopy != a loop to find tree-like properties


# Custom HashMap and Set for Anti-hash-table test
class CustomHashMap:
	def __init__(self, type = dict, arr = []):
		self.RANDOM = random.randrange(2**62)
		self.dict = type([self.wrapper(i) for i in arr])
	def wrapper(self,num):
		return num ^ self.RANDOM
	def __setitem__(self, key, value):
		self.dict[self.wrapper(key)] = value
	def __getitem__(self, key):
		return self.dict[self.wrapper(key)]
	def __contains__(self, key):
		return self.wrapper(key) in self.dict
	def __iter__(self):
		return iter(self.wrapper(i) for i in self.dict)
	def items(self):
		return [(self.wrapper(i),j) for i,j in self.dict.items()]
	def __repr__(self):
		return repr({self.wrapper(i):j for i,j in self.dict.items()})
#Use akin: a = CustomHashMap(Counter,a)  : {a is a LIST})
#          a.items() is a number of tuples like (2,3); len(a.items()) to get len(a)

from random import randint
# Random number from 1 to 10^9
RANDOM = randint(1, 10 ** 9)
class h(int):
	def __init__(self, x):
		int.__init__(x)

	def __hash__(self):
		return super(h, self).__hash__() ^ RANDOM
# h(x) gives a changed value of x which wont hash-collide

def pfactor(n):
	ans=defaultdict(int)
	s = Sieve(ceil(n**0.5))
	# print(s)
	for i in s:
		x = divmod(n,i)
		# print("X==",x)
		while(x[1]==0):
			ans[i]+=1
			n = x[0]
			x = divmod(n,i)
		if(n==1):
			break
	if(n!=1):
		ans[n]+=1
	return(ans)
# Returns a defaultdict of prime factorization   

# Calculate nCr%p
def ncr(n, r, p):
	num = den = 1
	for i in range(r):
		num = (num * (n - i)) % p
		den = (den * (i + 1)) % p
	return (num * pow(den,p - 2, p)) % p

def factor(n):
	lower,upper=[],[]
	i=1
	while i*i<=n:
		if n%i==0:
			lower.append(i)
			if i!=n//i:
				upper.append(n//i)
		i+=1
	return lower+upper[::-1]



import random
from sys import stdin,stdout
input=lambda :stdin.readline()[:-1]
from collections import defaultdict, Counter, deque, OrderedDict
import itertools;from itertools import permutations as perms, combinations as combs,combinations_with_replacement 
from bisect import bisect_left, bisect_right
from heapq import heapify, heappush, heappop, nlargest, nsmallest
import math
from functools import reduce
from math import inf,floor,ceil,comb,lcm,gcd,log2
from operator import itemgetter

def solve():
	n = int(input())
	res = deque(i for i in range(1,10))
	d = defaultdict(list)
	d[1] = [1,2,3,4,5,6,7,8,9,0]
	d[2] = [2,3,5,6,8,9,0]
	d[3] = [3,6,9]
	d[4] = [4,5,6,7,8,9,0]
	d[5] = [5,6,8,9]



for _ in range(int(input())):
	solve()
