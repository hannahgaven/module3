#!/bin/bash


for I in test1 test2 test3 test4 test5 test6 test7 test8 test9 test10
do
valgrind --leak-check=full ./${I} &> "log${I}.txt"
echo "For" ${I} ":"
grep -E "no leaks are possible" log${I}.txt
grep -E "ERROR SUMMARY: 0 errors from 0 contexts" log${I}.txt
echo -e
done


exit;
