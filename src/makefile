CC    := $(cc)
EXECS := main driverGraph

go: main
	@clear
	@python3 graphgen.py > in.txt
	@time ./main < in.txt

main: main.cc graph.cc unionfind.cc
	$(cc) -O2 $+ -o $@

graph: graph.cc
	$(cc) $+ -o $@

driverGraph: graphDriver.cc
	$(cc) $+ -o $@

unionfind: unionfind.cc
	$(cc) $+ -o $@

clean:
	rm -fv *.o

distclean: clean
	rm -fv $(EXECS)
