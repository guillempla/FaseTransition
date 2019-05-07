go: main
	clear
	./main

main: main.o unionfind.o
	g++ -o main main.o unionfind.o

main.o: main.cc
	g++ -c main.cc

unionfind.o: unionfind.cc
	g++ -c unionfind.cc

clean:
	@rm -fv main.o unionfind.o

distclean: clean
	@rm -fv main
