#!/bin/bash
for i in {1..10}
do
    num=`expr $RANDOM % 4`

    case $num in
        0)  touch ./HUMAX_SKYD_$i.ts;;
        1)  touch ./HUMAX_MBC_$i.ts;;
        2)  touch ./HUMUX_SKYD_$i.ts;;
        3)  touch ./HUMUX_MBC_$i.ts;;
    esac
done

