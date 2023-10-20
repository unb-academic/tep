n, m = map(int, input().split())

matrix = []
all_nums = {i for i in range(1, n + 1)}

base = {}
bad_mood = []

first = True

for _ in range(m):
    row = list(map(int, input().split()))

    for i, num in enumerate(row):
        if num not in base:
            base[num] = set()

        if i == 0:
            base[num].add(row[i + 1])
        elif i == n - 1:
            base[num].add(row[i - 1])
        else:
            base[num].add(row[i - 1])
            base[num].add(row[i + 1])

for key, value in base.items():
    for i in (all_nums - value - {key}):
        if (key, i) in bad_mood or (i, key) in bad_mood:
            continue

        bad_mood.append((key, i))

print(len(bad_mood))
