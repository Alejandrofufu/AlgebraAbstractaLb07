# AlgebraAbstractaLb07
El código es una versión del NAIVE_RSA_KEY_GENERATOR donde cifra un mensaje usando P(m) = m^e mod n = c. y descifra usando S(c) = c^d mod n = m.
La primera parte del código imprima todas las encriptaciones para m∈ {0, 1, · · · , n − 1}, con e = 3, mostrando una tabla con su cifrado y descifrado.
La función NAIVE_RSA_KEY_GENERATOR utiliza p y q para calcular n y phi(n), luego halla un valor de e en el que sea coprino con phi y le saca inversa, siendo este d.
Segunda parte del código muestra todas las posibles casos donde m^e mod n = c ,donde c = m donde se le pide un m[0,n-1] y procederá a calcular d y e en la función NAIVE_RSA_KEY_GENERATOR
comprobamos que al cifrar m^e mod n = m , entonces imprimimos y desciframos, caso contrario incrementamos e en uno.
