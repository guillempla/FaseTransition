CC    := g++
EXECS := main driverGraph zoom main_c zoom_c main_d main1 main2 main3

go: main
	@clear
	@python3 grid.py > in.txt
	@time ./main < in.txt

main: main.cc graph.cc unionfind.cc
	$(CC) -O2 $+ -o $@

zoom: zoom.cc graph.cc unionfind.cc
	$(CC) -O2 $+ -o $@
zoom_c: zoom_c.cc graph.cc unionfind.cc
	$(CC) -O2 $+ -o $@

main_c: main_c.cc graph.cc unionfind.cc
	$(CC) -O2 $+ -o $@

main_d: main_d.cc graph.cc unionfind.cc
	$(CC) -O2 $+ -o $@

main1: zoom
	@clear
	@python3 grid.py > in.txt
	@time ./zoom < in.txt



main2: zoom_c
	@clear
	@python3 barabasi.py > barabasi.in
	@time ./zoom_c < barabasi.in

main3: zoom_c
	@clear
	@python3 watts.py > watts.in
	@time ./zoom_c < watts.in

watts_c: main_c
	@clear
	@python3 watts.py > watts.in
	@time ./main_c < watts.in

barabasi_c: main_c
	@clear
	@python3 barabasi.py > barabasi.in
	@time ./main_c < barabasi.in

watts_d: main_d
	@clear
	@python3 watts.py > watts.in
	@time ./main_d < watts.in

barabasi_d: main_d
	@clear
	@python3 barabasi.py > barabasi.in
	@time ./main_d < barabasi.in

graph: graph.cc
	$(CC) $+ -o $@

driverGraph: graphDriver.cc
	$(CC) $+ -o $@

unionfind: unionfind.cc
	$(CC) $+ -o $@

clean:
	rm -fv $(EXECS) *.txt *.in
