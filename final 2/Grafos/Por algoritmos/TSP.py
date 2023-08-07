import networkx as nx
import matplotlib.pyplot as plt


def calcular_costo_total(ruta):
    costo_total = sum(grafo[u][v]['weight'] for u, v in zip(ruta, ruta[1:]))
    return costo_total


#Crea el grafo
grafo = nx.Graph()


grafo.add_nodes_from(['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'])

# Agregar aristas al grafo con pesos
grafo.add_edge('A', 'B', weight=675)
grafo.add_edge('A', 'C', weight=400)
grafo.add_edge('A', 'D', weight=166)
grafo.add_edge('A', 'E', weight=809)
grafo.add_edge('A', 'F', weight=720)
grafo.add_edge('A', 'G', weight=399)
grafo.add_edge('A', 'H', weight=233)

grafo.add_edge('B', 'A', weight=675)
grafo.add_edge('B', 'C', weight=540)
grafo.add_edge('B', 'D', weight=687)
grafo.add_edge('B', 'E', weight=179)
grafo.add_edge('B', 'F', weight=348)
grafo.add_edge('B', 'G', weight=199)
grafo.add_edge('B', 'H', weight=401)

grafo.add_edge('C', 'A', weight=400)
grafo.add_edge('C', 'B', weight=540)
grafo.add_edge('C', 'D', weight=107)
grafo.add_edge('C', 'E', weight=752)
grafo.add_edge('C', 'F', weight=521)
grafo.add_edge('C', 'G', weight=385)
grafo.add_edge('C', 'H', weight=280)

grafo.add_edge('D', 'A', weight=166)
grafo.add_edge('D', 'B', weight=687)
grafo.add_edge('D', 'C', weight=107)
grafo.add_edge('D', 'E', weight=111)
grafo.add_edge('D', 'F', weight=540)
grafo.add_edge('D', 'G', weight=990)
grafo.add_edge('D', 'H', weight=362)

grafo.add_edge('E', 'A', weight=809)
grafo.add_edge('E', 'B', weight=179)
grafo.add_edge('E', 'C', weight=752)
grafo.add_edge('E', 'D', weight=111)
grafo.add_edge('E', 'F', weight=206)
grafo.add_edge('E', 'G', weight=412)
grafo.add_edge('E', 'H', weight=576)

grafo.add_edge('F', 'A', weight=720)
grafo.add_edge('F', 'B', weight=348)
grafo.add_edge('F', 'C', weight=521)
grafo.add_edge('F', 'D', weight=540)
grafo.add_edge('F', 'E', weight=206)
grafo.add_edge('F', 'G', weight=155)
grafo.add_edge('F', 'H', weight=621)

grafo.add_edge('G', 'A', weight=399)
grafo.add_edge('G', 'B', weight=199)
grafo.add_edge('G', 'C', weight=385)
grafo.add_edge('G', 'D', weight=990)
grafo.add_edge('G', 'E', weight=412)
grafo.add_edge('G', 'F', weight=155)
grafo.add_edge('G', 'H', weight=100)

grafo.add_edge('H', 'A', weight=233)
grafo.add_edge('H', 'B', weight=401)
grafo.add_edge('H', 'C', weight=280)
grafo.add_edge('H', 'D', weight=361)
grafo.add_edge('H', 'E', weight=576)
grafo.add_edge('H', 'F', weight=621)
grafo.add_edge('H', 'G', weight=100)

# Obtener el diccionario de pesos de las aristas
weights = nx.get_edge_attributes(grafo, 'weight')




pos = nx.spring_layout(grafo, k=-5, iterations=50, seed= 50)
plt.figure(figsize=(15, 8))

nx.draw(grafo, pos, with_labels=True, node_size=6000, node_color='lightblue', font_size=10)
nx.draw_networkx_edge_labels(grafo, pos, edge_labels=weights, font_color='black', font_size=8)
plt.savefig('grafo.png')
plt.show()

init_cycle = list(grafo.nodes()) + [list(grafo.nodes())[0]]
ruta_aproximada = nx.approximation.threshold_accepting_tsp(grafo, init_cycle=init_cycle, weight='weight', max_iterations=100)
costo_total = calcular_costo_total(ruta_aproximada)

print ("Ruta más corta", ruta_aproximada)
print ("Costo total", costo_total)


plt.figure(figsize=(15, 8))
plt.title(f"\nGrafo\nMetodo: Algoritmo TSP\nIteraciones: 100\nRuta más corta: {ruta_aproximada}\nCosto: {costo_total}", loc="left")
nx.draw(grafo, pos, with_labels=True, node_size=6000, node_color='lightblue', font_size=10)
nx.draw_networkx_edge_labels(grafo, pos, edge_labels=weights, font_color='black', font_size=8)
nx.draw_networkx_edges(grafo, pos, edgelist=[(ruta_aproximada[i], ruta_aproximada[i + 1]) for i in range(len(ruta_aproximada) - 1)], edge_color='red', width=2)
nx.draw_networkx_edge_labels(grafo, pos, edge_labels=weights, font_color='red', font_size=8)


plt.savefig('ruta-mas-corta.png')
plt.show()