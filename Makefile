CFLAGS=-Wall -pedantic -std=c11 -I. -g

all: test11

%.o:		%.c %.h
				gcc $(CFLAGS) -c $<

test1:	queue.o test1.o
				gcc $(CFLAGS) queue.o test1.o -o test1

test2:	queue.o test2.o
				gcc $(CFLAGS) queue.o test2.o -o test2

test3:	queue.o test3.o
				gcc $(CFLAGS) queue.o test3.o -o test3

test4: queue.o test4.o
				gcc $(CFLAGS) queue.o test4.o -o test4

test5: queue.o test5.o
				gcc $(CFLAGS) queue.o test5.o -o test5

test6: queue.o test6.o
				gcc $(CFLAGS) queue.o test6.o -o test6

test7: queue.o test7.o
				gcc $(CFLAGS) queue.o test7.o -o test7

test8: queue.o test8.o
				gcc $(CFLAGS) queue.o test8.o -o test8

test9: queue.o test9.o
				gcc $(CFLAGS) queue.o test9.o -o test9

test10: queue.o test10.o
				gcc $(CFLAGS) queue.o test10.o -o test10

test11: queue.o test11.o
				gcc $(CFLAGS) queue.o test11.o -o test11

clean:
				rm -f *.o test1 test2 test3 test4 test5 test6 test7 test8 test9 test10 test11
