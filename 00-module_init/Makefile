all: test_initcall.o initcall.ld
	gcc test_initcall.o -T initcall.ld -o test_initcall

test_initcall.o: init.h

clean:
	rm test_initcall test_initcall.o

.PHONY: all clean