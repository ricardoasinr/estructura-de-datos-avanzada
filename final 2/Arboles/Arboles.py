import json
import matplotlib.pyplot as plt
import networkx as nx

def graficar_arbol(raiz, nivel=0, posx=0, posy=0, delta_x=1):
    if raiz is None:
        return

    # Calcular las coordenadas x e y para el nodo actual
    y = -nivel
    x = posx

    # Graficar el nodo actual
    plt.text(x, y, str(raiz.valor), color="white", fontweight="bold", ha="center",
             bbox=dict(facecolor="skyblue", edgecolor="black", boxstyle="circle"))

    # Graficar las aristas y los subárboles
    if raiz.izquierda is not None:
        plt.plot([x, x - delta_x], [y, y - 1], color="black")
        graficar_arbol(raiz.izquierda, nivel + 1, posx - delta_x, posy - 1, delta_x / 2)

    if raiz.derecha is not None:
        plt.plot([x, x + delta_x], [y, y - 1], color="black")
        graficar_arbol(raiz.derecha, nivel + 1, posx + delta_x, posy - 1, delta_x / 2)

# Abre el archivo JSON en modo lectura
# with open('hero.json', 'r') as archivo:
#     datos_json = json.load(archivo)


# i = 0 
# print(lista_content[0])
# # for elemento in lista_content:
# #         i = i+1
# #         print("\n", i, elemento)



class Nodo:
    def __init__(self, valor):
        self.valor = valor
        self.izquierda = None
        self.derecha = None
        self.altura = 1
def insertar(raiz, valor):
    if raiz is None:
        return Nodo(valor)

    if valor < raiz.valor:
        raiz.izquierda = insertar(raiz.izquierda, valor)
    else:
        raiz.derecha = insertar(raiz.derecha, valor)

    return raiz

def calcular_altura(nodo):
    if nodo is None:
        return 0
    return max(calcular_altura(nodo.izquierda), calcular_altura(nodo.derecha)) + 1

def obtener_altura(nodo):
    if nodo is None:
        return 0
    return nodo.altura

def obtener_balance(nodo):
    if nodo is None:
        return 0
    return obtener_altura(nodo.izquierda) - obtener_altura(nodo.derecha)

def rotar_izquierda(nodo):
    nodo_derecha = nodo.derecha
    nodo_derecha_izquierda = nodo_derecha.izquierda

    nodo_derecha.izquierda = nodo
    nodo.derecha = nodo_derecha_izquierda

    nodo.altura = max(obtener_altura(nodo.izquierda), obtener_altura(nodo.derecha)) + 1
    nodo_derecha.altura = max(obtener_altura(nodo_derecha.izquierda), obtener_altura(nodo_derecha.derecha)) + 1

    return nodo_derecha

def rotar_derecha(nodo):
    nodo_izquierda = nodo.izquierda
    nodo_izquierda_derecha = nodo_izquierda.derecha

    nodo_izquierda.derecha = nodo
    nodo.izquierda = nodo_izquierda_derecha

    nodo.altura = max(obtener_altura(nodo.izquierda), obtener_altura(nodo.derecha)) + 1
    nodo_izquierda.altura = max(obtener_altura(nodo_izquierda.izquierda), obtener_altura(nodo_izquierda.derecha)) + 1

    return nodo_izquierda

def balancear_arbol(nodo):
    if nodo is None:
        return None

    nodo.altura = max(obtener_altura(nodo.izquierda), obtener_altura(nodo.derecha)) + 1

    balance = obtener_balance(nodo)

    if balance > 1:
        if obtener_balance(nodo.izquierda) < 0:
            nodo.izquierda = rotar_izquierda(nodo.izquierda)
        return rotar_derecha(nodo)

    if balance < -1:
        if obtener_balance(nodo.derecha) > 0:
            nodo.derecha = rotar_derecha(nodo.derecha)
        return rotar_izquierda(nodo)

    return nodo

def insertar_nodo(raiz, valor):
    if raiz is None:
        return Nodo(valor)
    elif valor < raiz.valor:
        raiz.izquierda = insertar_nodo(raiz.izquierda, valor)
    else:
        raiz.derecha = insertar_nodo(raiz.derecha, valor)

    raiz = balancear_arbol(raiz)  # Balancear el árbol después de insertar el nodo

    return raiz

def es_arbol_balanceado(nodo):
    if nodo is None:
        return True

    altura_izquierda = calcular_altura(nodo.izquierda)
    altura_derecha = calcular_altura(nodo.derecha)

    if abs(altura_izquierda - altura_derecha) > 1:
        return False

    return es_arbol_balanceado(nodo.izquierda) and es_arbol_balanceado(nodo.derecha)

def recorrido_preorden(raiz):
    if raiz is None:
        return

    print(raiz.valor)
    recorrido_preorden(raiz.izquierda)
    recorrido_preorden(raiz.derecha)


def recorrido_inorden(raiz):
    if raiz is None:
        return []

    inorden = []
    inorden.extend(recorrido_inorden(raiz.izquierda))
    inorden.append(raiz.valor)
    inorden.extend(recorrido_inorden(raiz.derecha))

    return inorden


def recorrido_postorden(raiz):
    if raiz is None:
        return

    recorrido_postorden(raiz.izquierda)
    recorrido_postorden(raiz.derecha)
    print(raiz.valor)

valores = ['A', 'B', 'D', 'H', 'I', 'E', 'J', 'K', 'C', 'F', 'L', 'M', 'G', 'N', 'O']
#valores = [1,2,3,4,5,6]
#valores = ['A','B','C','D','F','G', 'H', 'I']

# Crear el árbol binario
raiz = None
# for elemento in lista_content:
#     raiz = insertar_nodo(raiz, elemento['name'])
raiz = None
for valor in valores:
    raiz = insertar_nodo(raiz, valor)

# Imprimir el árbol para verificar su estructura
def imprimir_arbol(raiz):
    if raiz is None:
        return

    imprimir_arbol(raiz.izquierda)
    print(raiz.valor)
    imprimir_arbol(raiz.derecha)

imprimir_arbol(raiz)
print("Pre orden")
print(recorrido_preorden(raiz))
print("Entre orden")
print(recorrido_inorden(raiz))
print("Post orden")
print(recorrido_postorden(raiz))


print("Arbol balanceado: ", es_arbol_balanceado(raiz))

fig, ax = plt.subplots()
ax.set_aspect('equal', adjustable='box')
ax.axis('off')

# Graficar el árbol
graficar_arbol(raiz)

# Mostrar el gráfico
plt.show()



