import networkx as nx
import random
import time

N = 3
M = 2
seed = random.randint(1,101)
G = nx.barabasi_albert_graph(N, M, seed)
print (N)
for i in G.edges:
	print (i[0],end =' ')
	print (i[1])
print(seed)
