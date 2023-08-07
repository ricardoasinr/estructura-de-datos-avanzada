import json
import time
import matplotlib.pyplot as plt
import networkx as nx
from matplotlib.patches import Circle


def graficar_arbol(raiz, nivel=0, posx=0, posy=0, delta_x=600):
    plt.axis('off')
    if raiz is None:
        return

    y = -nivel
    x = posx

    # Graficar el nodo actual
    plt.text(x, y, str(raiz.nombre), color="black", fontweight="bold", ha="center", fontsize=8,bbox={'facecolor': 'none', 'edgecolor': 'none'})

    # Graficar las aristas y los subárboles
    if raiz.izquierda is not None:
        plt.plot([x, x - delta_x], [y, y - 1], color="black")
        graficar_arbol(raiz.izquierda, nivel + 1, posx - delta_x, posy - 1, delta_x / 2)

    if raiz.derecha is not None:
        plt.plot([x, x + delta_x], [y, y - 1], color="black")
        graficar_arbol(raiz.derecha, nivel + 1, posx + delta_x, posy - 1, delta_x / 2)

def mostrar_menu():
   
    print("\n\t\t     Menú ")
    print("---------------------------------------------")
    print("1. Listar villanos ordenados alfabéticamente")
    print("2. Mostrar superhéroes que empiezan con C")
    print("3. Mostrar cantidad de superhéroes")
    print("4. Modificar nombre de Doctor Strange")
    print("5. Listar superhéroes en orden descendente")
    print("6. Generar bosque y realizar tareas")
    print("0. Salir")
    print("---------------------------------------------")


class Nodo:
    def __init__(self, nombre, heroe):
        self.nombre = nombre
        self.heroe = heroe
        self.izquierda = None
        self.derecha = None

def agregarNodo(raiz, nombre, heroe):
    if raiz is None:
        return Nodo(nombre, heroe)
    else:
        if nombre < raiz.nombre:
            raiz.izquierda = agregarNodo(raiz.izquierda, nombre, heroe)
        else:
            raiz.derecha = agregarNodo(raiz.derecha, nombre, heroe)
        return raiz

def listarVillanos(raiz):
    if raiz:
        listarVillanos(raiz.izquierda)
        if not raiz.heroe:
            time.sleep(0.09)
            print(raiz.nombre)
        listarVillanos(raiz.derecha)

def listarSuperheroes(raiz):
    if raiz:
        listarSuperheroes(raiz.izquierda)
        if raiz.heroe:
            print(raiz.nombre)
            time.sleep(0.09) 
        listarSuperheroes(raiz.derecha)

def listarHeroesConC(raiz):
    if raiz:
        listarHeroesConC(raiz.izquierda)
        if raiz.heroe and raiz.nombre.startswith('C'):
            time.sleep(0.09)
            print(raiz.nombre)
        listarHeroesConC(raiz.derecha)

def contarSuperHeroes(raiz):
    if raiz is None:
        return 0
    else:
        return 1 + contarSuperHeroes(raiz.izquierda) + contarSuperHeroes(raiz.derecha)

def buscar_nodo(raiz, nombre):
    print("Buscando...")
    time.sleep(0.09)    
    if raiz is None or raiz.nombre == nombre:
        return raiz
    if nombre < raiz.nombre:
        return buscar_nodo(raiz.izquierda, nombre)
    return buscar_nodo(raiz.derecha, nombre)

def modificarNombre(raiz, nombre_actual, nombre_nuevo):
    nodo = buscar_nodo(raiz, nombre_actual)
    if nodo is not None:
        nodo.nombre = nombre_nuevo
        return True 
    else: 
        return False

def listarSuperheroesDescendente(raiz):
    if raiz:
        listarSuperheroesDescendente(raiz.derecha)
        if raiz.heroe:
            time.sleep(0.09)
            print(raiz.nombre)
        listarSuperheroesDescendente(raiz.izquierda)

def contarNodos(raiz):
    if raiz is None:
        return 0
    else:
        return 1 + contarNodos(raiz.izquierda) + contarNodos(raiz.derecha)
    
def generarBosque(raiz):
    bosque = None
    global arbol_superheroes, arbol_villanos
    if raiz:
        if raiz.heroe:
            arbol_superheroes = agregarNodo(arbol_superheroes, raiz.nombre, True)
        else:
            arbol_villanos = agregarNodo(arbol_villanos, raiz.nombre, False)
        generarBosque(raiz.izquierda)
        generarBosque(raiz.derecha)
        bosque = raiz
    return bosque

arbol = None

with open('hero.json', 'r') as archivo:
    datos_json = json.load(archivo)

lista_content = datos_json
i = 0 
for elemento in lista_content:
        i = i+1
        time.sleep(0.05)
        print(elemento)
        arbol = agregarNodo(arbol, elemento["name"], elemento["hero"])
print("--------------------------------")

time.sleep(2)


while True:
    mostrar_menu()
    opcion = input("Ingrese una opción: ")

    if opcion == "1":
        print("Villanos ordenados alfabéticamente:")
        time.sleep(1)
        listarVillanos(arbol)
        print("--------------------------------")
        time.sleep(2)
        
    elif opcion == "2":
        print("Superhéroes que empiezan con C:")
        time.sleep(1)
        listarHeroesConC(arbol)
        print("--------------------------------")
        time.sleep(2)
        
    elif opcion == "3":
        cantidad = contarSuperHeroes(arbol)
        print("Cantidad de superhéroes:", cantidad)
        print("--------------------------------")
        time.sleep(2)
        
    elif opcion == "4":
        print("--------------------------------")
        nombreActual = "Doctor Strange"
        nombreNuevo = input("Ingrese el nuevo nombre para Doctor Strange: ")
        modificado = modificarNombre(arbol, nombreActual, nombreNuevo)
        if(modificado):
            print("Nombre de Doctor Strange modificado.")
        else: 
            print("No se modifico")

        print("--------------------------------")
        time.sleep(2)    
        
    elif opcion == "5":
        print("--------------------------------")
        print("Superhéroes en orden descendente:")
        time.sleep(1)
        listarSuperheroesDescendente(arbol)
        print("--------------------------------")
        time.sleep(2)
        
    elif opcion == "6":
        arbol_superheroes = None
        arbol_villanos = None
        generarBosque(arbol)
        num_nodos_superheroes = contarNodos(arbol_superheroes)
        num_nodos_villanos = contarNodos(arbol_villanos)
        print("--------------------------------")
        print("Superhéroes en orden alfabético:")
        time.sleep(2)
        listarSuperheroes(arbol_superheroes)
        print("--------------------------------")
        print("Villanos en orden alfabético:")
        time.sleep(2)
        listarVillanos(arbol_villanos)
        print("--------------------------------")
        time.sleep(2)
        print("Cantidad de nodos en el árbol de: ")
        print("Superhéroes:", num_nodos_superheroes)
        print("Villanos:", num_nodos_villanos)
        print("--------------------------------")
        time.sleep(2)
        
        plt.figure(figsize=(15, 8))
        graficar_arbol(arbol_villanos)
        plt.title("Arbol villanos")
        plt.savefig('arbol-villanos.png')
        plt.show()
        
        plt.figure(figsize=(15, 8))
        graficar_arbol(arbol_superheroes)
        plt.title("Arbol superheroes")
        plt.savefig('arbol-superheroes.png')
        plt.show()
        
        plt.figure(figsize=(15, 8))
        graficar_arbol( generarBosque(arbol))
        plt.title("Bosque")
        plt.savefig('arbol-bosque.png')
        plt.show()
        
       
    elif opcion == "0":
        print("Usted ha salido del programa")
        break
    else:
        print("Opción inválida. Por favor, seleccione una opción válida.")