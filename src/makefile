CC    := $(cc)
EXECS := main driverGraph

go: main
	@clear
	@python3 graphgen.py > in.txt
	@time ./main < in.txt

main: main.cc graph.cc unionfind.cc
	$(CC) -O2 $+ -o $@

graph: graph.cc
	$(CC) $+ -o $@

driverGraph: graphDriver.cc
	$(CC) $+ -o $@

unionfind: unionfind.cc
	$(CC) $+ -o $@

clean:
	rm -fv *.o

distclean: clean
	rm -fv $(EXECS)
