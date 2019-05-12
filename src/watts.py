import networkx as nx
import random
import time

N = 10
K = 3
P = 0.5
seed = random.randint(1,101)
G = nx.watts_strogatz_graph(N, K, P, seed)
print (N)
for i in G.edges:
	print (i[0],end =' ')
	print (i[1])
print(seed)
