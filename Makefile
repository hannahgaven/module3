CFLAGS=-Wall -pedantic -std=c11 -I. -g

all: test1 test2 test3 test4 test5 test6 test7 test8 test9 test10

%.o:		%.c %.h
				gcc $(CFLAGS) -c $<

test1:	list.o test1.o
				gcc $(CFLAGS) list.o test1.o -o test1

test2:	list.o test2.o
				gcc $(CFLAGS) list.o test2.o -o test2

test3:	list.o test3.o
				gcc $(CFLAGS) list.o test3.o -o test3

test4: list.o test4.o
				gcc $(CFLAGS) list.o test4.o -o test4

test5: list.o test5.o
				gcc $(CFLAGS) list.o test5.o -o test5

test6: list.o test6.o
				gcc $(CFLAGS) list.o test6.o -o test6

test7: list.o test7.o
				gcc $(CFLAGS) list.o test7.o -o test7

test8: list.o test8.o
				gcc $(CFLAGS) list.o test8.o -o test8

test9: list.o test9.o
				gcc $(CFLAGS) list.o test9.o -o test9

test10: list.o test10.o
				gcc $(CFLAGS) list.o test10.o -o test10

clean:
				rm -f *.o test1 test2 test3 test4 test5 test6 test7 test8 test9 test10
