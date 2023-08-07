class Automata:
    def __init__(self, estados, alphabet, transiciones, estadoInicial, estadoAceptacion):
        self.estados = estados
        self.alphabet = alphabet
        self.transiciones = transiciones
        self.estadoInicial = estadoInicial
        self.estadoAceptacion = estadoAceptacion

    def run(self, input_string):
        for symbol in input_string:
            if symbol not in self.alphabet:
                print("Error: El símbolo", symbol, "no es válido.")
                return

            if (self.estadoInicial, symbol) not in self.transiciones:
                print("Error: No existe una transición para el estado",
                      self.estadoInicial, "y el símbolo", symbol)
                return

            self.estadoInicial = self.transiciones[(
                self.estadoInicial, symbol)]

        if self.estadoInicial in self.estadoAceptacion:
            print("La cadena es aceptada.")
        else:
            print("La cadena es rechazada.")


# Ejemplo de uso
estados = {'s1', 's2', 's3', 's4', 's5', 's6'}
alphabet = {'a', 'b', 'c'}
transicionesDiccionario = {
    # estado, letra -> Estado a donde se dirige
    ('s1', 'b'): 's1',
    ('s1', 'a'): 's2',
    ('s1', 'c'): 's6',

    ('s2', 'a'): 's2',
    ('s2', 'b'): 's1',
    ('s2', 'c'): 's3',

    ('s3', 'a'): 's2',
    ('s3', 'b'): 's4',
    ('s3', 'c'): 's5',

    ('s4', 'a'): 's2',
    ('s4', 'b'): 's1',
    ('s4', 'c'): 's6',

    ('s5', 'a'): 's5',
    ('s5', 'b'): 's5',
    ('s5', 'c'): 's5',

    ('s6', 'a'): 's2',
    ('s6', 'b'): 's1',
    ('s6', 'c'): 's5',

}
estadoInicial = 's1'
estadoAceptado = {'s4'}

automata = Automata(estados, alphabet, transicionesDiccionario,
                    estadoInicial, estadoAceptado)
input_string = input("Ingresa una cadena: ")
automata.run(input_string)
