#!/bin/bash


for I in test11 test13 test15
do
valgrind --leak-check=full ./${I} &> "log${I}.txt"
echo "For" ${I} ":"
grep -E "no leaks are possible" log${I}.txt
grep -E "ERROR SUMMARY: 0 errors from 0 contexts" log${I}.txt
echo -e
done


exit;
