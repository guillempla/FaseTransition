go: main
	@clear
	@./main

main: main.cc graph.cc unionfind.cc
	g++ $+ -o $@

graph: graph.cc
	g++ $+ -o $@

driverGraph: graphDriver.cc
	g++ $+ -o $@

unionfind: unionfind.cc
	g++ $+ -o $@

clean:
	rm -fv *.o

distclean: clean
	rm -fv main distclean
