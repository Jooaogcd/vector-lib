all:
	gcc *.c -o v

clean:
	rm ./v

run:
	./v

valg:
	valgrind ./v