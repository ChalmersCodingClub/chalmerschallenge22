#!/usr/bin/env python3
import math

def solve(R, S):
    r = R/S
    rlim = int(r+3) # Some margin
    loke = round(2*math.pi/3*r**3)

    base_exp = 1
    while 2**base_exp - 2 <= r:
        base_exp += 1
    base_val = 2**(base_exp-1) - 1

    abcs = [0]*4
    for x in range(1, rlim):
        for y in range(1, rlim):
            for z in range(1, rlim):
                # outermost distances
                if x**2 + y**2 + z**2 > r**2:
                    break
                zsmall = z <= base_val
                yzsmall = y <= base_val and zsmall
                xyzsmall = x <= base_val and yzsmall
                idx = [xyzsmall, yzsmall, zsmall, True].index(True)
                abcs[idx] += 8 # 8 octants, sign of xyz does not matter
    for i in range(4):
        if sum(abcs[:(1+i)]) >= loke:
            return 3*base_exp + i
    return "impossible"

last = -1
for R in range(1, 10000):
    S = 100
    ans = solve(R,S)
    if ans != last:
        last = ans
        print(f"{R=}, {S=}, {ans=}")
