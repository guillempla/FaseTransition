import networkx as nx
N = 9
G = nx.Graph()
#G=nx.complete_graph(100)
G = nx.grid_2d_graph(N,N)

#print("Nombre de vertexos")
print (N*N)
#print("Nombre d'arestes")
for i in G.edges:
    print (N*i[0][0]+i[0][1], end = ' ')
    print (N*i[1][0]+i[1][1])
