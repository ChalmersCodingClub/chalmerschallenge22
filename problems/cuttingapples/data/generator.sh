#!/usr/bin/env bash

. ../../../testdata_tools/gen.sh

#use_solution gustav.cpp

compile gen_random.py

samplegroup
limits RMax=10 SMax=10
sample 1
sample 2
sample 3

group group1 10
limits RMax=1000000000 SMax=1000000000
tc R
tc 2
tc 3
tc g1_1 gen_random
tc g1_2 gen_random
tc g1_3 gen_random
tc g1_4 gen_random
tc g1_5 gen_random
tc g1_6 gen_random
tc g1_7 gen_random
tc g1_8 gen_random
tc g1_9 gen_random
tc g1_10 gen_random
tc g1_11 gen_random
