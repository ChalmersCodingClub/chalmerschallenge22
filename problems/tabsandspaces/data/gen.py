from random import randint

tab = randint(1, 40)
file = randint(1, 10)

files = []
for _ in range(file):
    lines = randint(1, 20)
    f = []
    for _ in range(lines):
        l = tab * randint(0, 80 // tab)
        f.append(l + randint(0, 80 - l))
    files.append(f)

print(file)
for f in files:
    print(len(f))
    print(*f, sep="\n")
