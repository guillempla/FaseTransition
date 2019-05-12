CC    := g++
EXECS := main driverGraph zoom 

go: main
	@clear
	@python3 graphgen.py > in.txt
	@time ./main < in.txt

main: main.cc graph.cc unionfind.cc
	$(CC) -O2 $+ -o $@

zoom: zoom.cc graph.cc unionfind.cc
	$(CC) -O2 $+ -o $@

main1: zoom
	@clear
	@python3 graphgen.py > in.txt
	@time ./zoom < in.txt
	
graph: graph.cc
	$(CC) $+ -o $@

driverGraph: graphDriver.cc
	$(CC) $+ -o $@

unionfind: unionfind.cc
	$(CC) $+ -o $@

clean:
	rm -fv $(EXECS) *.txt
