#!/usr/bin/env bash

. ../../../testdata_tools/gen.sh

use_solution gustav.cpp

compile gen_random.py
compile gen_smart.py

samplegroup
limits nMax=10 aMax=10
sample 1
sample 2
sample 3

group group1 10
limits nMax=10 aMax=10
include_group samplegroup
tc g1_1 gen_random n=1 aMax=1
tc g1_2 gen_random n=5 aMax=1
tc g1_3 gen_random n=5 aMax=5
tc g1_4 gen_random n=10 aMax=10
tc g1_5 gen_random n=10 aMax=10
tc g1_6 gen_random n=10 aMax=10

group group2 10
limits nMax=20 aMax=20
include_group group1
tc g2_1 gen_random n=20 aMax=10
tc g2_2 gen_random n=10 aMax=20
tc g2_3 gen_random n=20 aMax=20

group group3 10
limits nMax=75 aMax=75
include_group group2
tc g3_1 gen_random n=20 aMax=75
tc g3_2 gen_random n=75 aMax=20
tc g3_3 gen_random n=75 aMax=75

group group4 10
limits nMax=250 aMax=1000000000
include_group group3
tc g4_1 gen_random n=250 aMax=5
tc g4_2 gen_random n=5 aMax=250
tc g4_3 gen_random n=250 aMax=75
tc g4_4 gen_random n=75 aMax=250
tc g4_5 gen_random n=250 aMax=1000000000

group group5 60
limits nMax=1500 aMax=1000000000
include_group group4
tc g5_1 gen_random n=1500 aMax=5
tc g5_2 gen_random n=5 aMax=1500
tc g5_3 gen_random n=1500 aMax=75
tc g5_4 gen_random n=75 aMax=1500
tc g5_5 gen_random n=1500 aMax=250
tc g5_6 gen_random n=250 aMax=1500
tc g5_7 gen_random n=1500 aMax=1000000000
