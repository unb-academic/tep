n = int(input())
a = list(map(int, input().split()))

new = []
first = True

for i in range(len(a)):
    if first:
        new.append(a[i])
        first = False
        continue

    if a[i] > a[i - 1]:
        new.extend(range(a[i - 1] + 1, a[i]))
    else:
        new.extend(range(a[i - 1] - 1, a[i], -1))

    new.append(a[i])

print(" ".join(map(str, new)))
