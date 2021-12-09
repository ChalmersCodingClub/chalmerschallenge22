import sys
from random import seed, randint

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

seed(int(cmdlinearg('seed', sys.argv[-1])))

d = randint(1, 10**4)
A = d*randint(1, 10**5)
B = d*randint(1, 10**5)
N = randint(1, 10**18)

print(N, A, B)
