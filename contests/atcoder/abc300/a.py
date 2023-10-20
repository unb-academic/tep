from collections import *
from math import *
from string import *
from itertools import *
from functools import *
from operator import *
from queue import *

def print_matrix(v):
    for i in range(len(v)):
        print(v[i], end=' ')
    print()

_, a, b = map(int, input().split())
v = list(map(int, input().split()))
print(v.index(a + b) + 1)
