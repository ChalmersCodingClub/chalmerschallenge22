#!/usr/bin/env python3
import math

def index(val, small, medium):
    if val <= small:
        return 0
    if val <= medium:
        return 1
    return 2

def solve(R, S):
    r = R/S
    rlim = int(r+3) # Some margin
    loke = round(2*math.pi/3*r**3)

    base_exp = 1
    while (2**base_exp - 2)*3 <= 2*r:
        base_exp += 1
    small_radius = 2**(base_exp-1) - 1
    medium_radius = 2**base_exp - 1
    cubes = [[[0,0,0], [0,0,0], [0,0,0]] for _ in range(3)]
    for x in range(1, rlim):
        for y in range(1, rlim):
            for z in range(1, rlim):
                # outermost distances
                if x**2 + y**2 + z**2 > r**2:
                    break
                xi = index(x, small_radius, medium_radius)
                yi = index(y, small_radius, medium_radius)
                zi = index(z, small_radius, medium_radius)
                cubes[xi][yi][zi] += 8
    for i in range(9):
        for xi in range(3):
            for yi in range(3):
                zi = i - xi - yi
                if zi not in [0,1,2]:
                    break
                possible = 0
                for xx in range(xi+1):
                    for yy in range(yi+1):
                        for zz in range(zi+1):
                            possible += cubes[xx][yy][zz]
                if possible >= loke:
                    return 3*base_exp + i
    return "impossible"

last = -1
for R in range(1, 10000):
    S = 100
    ans = solve(R,S)
    if ans != last:
        last = ans
        print(f"{R=}, {S=}, {ans=}")
