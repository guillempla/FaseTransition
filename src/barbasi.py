import networkx as nx
import random as rand
N = 3
M = 2
#G=nx.complete_graph(100)
G = nx.barabasi_albert_graph(N,M,32)
print (N)
for i in G.edges:
	print (i[0],end =' ') 
	print (i[1])
