import math
import random

aleatorio = random.SystemRandom() 
def prueba(n, a): 
    exp = n - 1 
    while not exp & 1: 
        exp >>= 1 
    if pow(a, exp, n) == 1: 
        return True
    while exp < n - 1: 
        if pow(a, exp, n) == n - 1: 
            return True
        exp <<= 1
    return False

def Miller_Rabin(n, k = 40): 
    for i in range(k): 
        a = aleatorio.randrange(2, n - 1) 
        if not prueba(n, a): 
            return False
    return True

def gen_prime(bits):
    while True:
        a = (aleatorio.randrange(1 << bits - 1, 1 << bits) >> 1) + 1
        if Miller_Rabin(a): 
            return a

print("Generación numeros primos aleatorios de 16, 32 y 64 bits")
print("""
  Eligir
  Opcion 1(16 bits)
  Opcion 2(32 bits) 
  Opcion 3(64 bits) 
      """)
eleccion = int(input("Elija: "))
if eleccion == 1:
    for i in range(0, 10):
        print(gen_prime(16))
if eleccion == 2:
    for i in range(0, 10):
        print(gen_prime(32))
if eleccion == 3:
    for i in range(0, 10):
        print(gen_prime(64))
