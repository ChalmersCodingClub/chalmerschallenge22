#!/usr/bin/env python3
import math

# We first scale space by 1/S so that Loke eats unit cubes.
#
# Consider the easier problem of cutting some number of unit cubes from a
# large cubiod. Each direction is cut independently. In one dimension,
# we can cut 2^a - 2 pieces in a cuts, discarding the endpoints.
#
# Cutting up a ball is equivalent to cutting up a cube circumscribing the ball,
# while only being allowed to actually use some of the unit cubes.
# Our task is then to choose a number of cuts a, b, c in every direction,
# cut the ball in (2^a - 2)(2^b - 2)(2^c - 2) unit cubes, discarding the curved
# ends and those unit cubes that aren't completely filled. This is a valid
# choice of cuts if the number of real unit cubes is greater than or equal to
# the number of cubes required.
#
# By symmetry we can assume a <= b <= c. It is unnecessary for 2^c - 2 to be
# larger than the smallest value that exceeds r = R/S. Note that
# 2pi/3 r^3 > (2r)(2r)(2r/3), so (2^a - 2) > 2r/3
#
# Let's brute force every combination a <= b <= c where a is not too small and
# c is not too large. 4 * 2r/3 > 2r, we can start above 2r/3 and only check the
# two next values.
#
# This relies on the assumption that cutting out unit cubes from a sphere cannot
# be done more efficently than using the cuts that would be used to cut the
# smallest cubiod containing all unit cubes to be cut out. I cannot prove this,
# but I feel like it should hold for convex shapes.

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
            for yi in range(xi+1):
                zi = i - xi - yi
                if zi < 0 or zi > yi:
                    break
                possible = 0
                for xx in range(xi+1):
                    for yy in range(yi+1):
                        for zz in range(zi+1):
                            possible += cubes[xx][yy][zz]
                print("DEBUG2", possible, base_exp+xi, base_exp+yi, base_exp+zi)
                if possible >= loke:
                    return 3*base_exp + i
    return "impossible"

R, S = [int(x) for x in input().split()]
print(solve(R, S))
