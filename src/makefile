go: phasetrans
	@clear
	@./phasetrans

main: main.o unionfind.o
	g++ -o main main.o unionfind.o

main.o: main.cc
	g++ -c main.cc

phasetrans: phasetrans.o
	g++ -o phasetrans phasetrans.o

phasetrans.o: phasetrans.cc
	g++ -c phasetrans.cc

unionfind.o: unionfind.cc
	g++ -c unionfind.cc

clean:
	@rm -fv *.o

distclean: clean
	@rm -fv main phasetrans
