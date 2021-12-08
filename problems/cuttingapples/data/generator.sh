#!/usr/bin/env bash

. ../../../testdata_tools/gen.sh

use_solution loke.cpp

compile gen.py

samplegroup
limits RatioMax=10 SMax=10
sample 1
sample 2

group group1 10
limits RatioMax=100 SMax=1000000
tc 1
tc 2
tc g1_1 gen
tc g1_2 gen
tc g1_3 gen
tc g1_4 gen
tc g1_5 gen
tc g1_6 gen
tc g1_7 gen
tc g1_8 gen
tc g1_9 gen
tc g1_10 gen
tc g1_11 gen
tc g1_12 gen
tc g1_13 gen
tc g1_14 gen
tc g1_15 gen
tc g1_16 gen
tc g1_17 gen
tc g1_18 gen
tc g1_19 gen
tc g1_20 gen
tc g1_21 gen
tc g1_22 gen
tc g1_23 gen
tc g1_24 gen
tc g1_25 gen
tc g1_26 gen
tc g1_27 gen
tc g1_28 gen
tc g1_29 gen
tc g1_30 gen
tc g1_31 gen
tc g1_32 gen
tc g1_33 gen
tc g1_34 gen
tc g1_35 gen
tc g1_36 gen
tc g1_37 gen
tc g1_38 gen
tc g1_39 gen
tc g1_40 gen
tc g1_41 gen
tc g1_42 gen
tc g1_43 gen
tc g1_44 gen
tc g1_45 gen
tc g1_46 gen
tc g1_47 gen
tc g1_48 gen
tc g1_49 gen
