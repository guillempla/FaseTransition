import networkx as nx
N = 3
G = nx.Graph()
G=nx.complete_graph(100)
G = nx.grid_2d_graph(N,N)
print ("Nodes of graph")
print (G.nodes)
print ("Edges of graph")
print (G.edges)
