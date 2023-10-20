from itertools import permutations

n, m = map(int, input().split())
strings = []

def is_changeable(s1, s2):
    return sum([1 for i in range(len(s1)) if s1[i] != s2[i]]) == 1

for _ in range(n):
    strings.append(input())

for k in list(permutations(strings)):
    x = [is_changeable(k[i], k[i + 1]) for i in range(len(k) - 1)]

    if all(x):
        print('Yes')
        break
else:
    print('No')
