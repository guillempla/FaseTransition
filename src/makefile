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

main_c: main_c.cc graph.cc unionfind.cc
	$(CC) -O2 $+ -o $@

main_d: main_d.cc graph.cc unionfind.cc
	$(CC) -O2 $+ -o $@

main1: zoom
	@clear
	@python3 graphgen.py > in.txt
	@time ./zoom < in.txt

zoom_c: zoom_c.cc graph.cc unionfind.cc
	$(CC) -O2 $+ -o $@

main2: zoom_c
	@clear
	@python3 barbasi.py > barbasi.in
	@time ./zoom_c < barbasi.in

watts_c: main_c
	@clear
	@python3 watts.py > watts.in
	@time ./main_c < watts.in

barbasi_c: main_c
	@clear
	@python3 barbasi.py > barbasi.in
	@time ./main_c < barbasi.in

watts_d: main_d
	@clear
	@python3 watts.py > watts.in
	@time ./main_d < watts.in

barbasi_d: main_d
	@clear
	@python3 barbasi.py > barbasi.in
	@time ./main_d < barbasi.in

graph: graph.cc
	$(CC) $+ -o $@

driverGraph: graphDriver.cc
	$(CC) $+ -o $@

unionfind: unionfind.cc
	$(CC) $+ -o $@

clean:
	rm -fv $(EXECS) *.txt
