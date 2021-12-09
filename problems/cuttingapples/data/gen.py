#!/usr/bin/env python3

import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
RatioMax = int(cmdlinearg('RatioMax', 100))
SMax = int(cmdlinearg('SMax', 1000000))

S = random.randint(1, SMax)
R = random.randint(1, S*RatioMax // random.randint(1, 5))
print(R, S)
