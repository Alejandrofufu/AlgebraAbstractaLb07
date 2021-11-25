#include <iostream>
#include<math.h>
using namespace std;

 long long  EuclidesGeneral( long long  a,  long long  b,  long long  & x,  long long  & y)
{
    if (a == 0)
    {
        x = 0, y = 1;
        return b;
    }
     long long  x1, y1;
     long long  gcd = EuclidesGeneral(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

 long long  inversoM( long long int a,  long long int m) {
     long long  x = 0, y = 0;
     long long  g = EuclidesGeneral(a, m, x, y);
    if (g != 1)
        return -1;
    else {
         long long int res = (x % m + m) % m;
        return res;
    }
}

 long long int Gcd( long long int a,  long long int b) {
     long long int t;
    while (true) {
        t = a % b;
        if (t == 0)
            return b;
        a = b;
        b = t;
    }
}

void NAIVE_RSA_KEY_GENERATOR( long long int p,  long long int q,  long long int & n,  long long int& e,  long long int& d) {
    n = p * q;
     long long int phi = (p - 1) * (q - 1);
     long long int pista = 0;
    while (e < phi) { // e = {2,(p - 1) * (q - 1)}
        pista = Gcd(e, phi);
        if (pista == 1) {
            d = inversoM(e, phi);
            break;
        }
        else
            e++;
    }
}
long long int modular(unsigned long long int base, unsigned long long int exp, unsigned long long int mod)
{
    long int x = 1;
    int i;
    long long int power = base % mod;

    for (i = 0; i < sizeof(int) * 64; i++) {
        int least_sig_bit = 0x00000001 & (exp >> i);
        if (least_sig_bit)
            x = (x * power) % mod;
        power = (power * power) % mod;
    }

    return x;
}

int main() {
     long long int mensaje = 0, p = 3, q = 11, n = 0, e = 2, d = 0, Pm = 0, Sc = 0;
    cout << "Tabla: " << "m" << " ^ " << "e" << " mod " << "n" << " = " << " c \n";
    while (mensaje < p * q) {
        NAIVE_RSA_KEY_GENERATOR(p, q, n, e, d);
        Pm = modular(mensaje,e,n); // mensaje cifrado  mensaje^e mod n
        Sc = modular(Pm, d,n);// mensaje descifrado  c ^d mod n = mensaje 
        cout <<d<< "\t\t" << mensaje << " ^ " << e << " mod " << n << " = " << Pm << "\t\tmensaje descifrado: " << Sc << "\n";
        mensaje = mensaje +1;
    }
    /////////////////////////////////////
    mensaje = 0, p = 3, q = 11, n = 0, e = 2, d = 0, Pm = 0, Sc = 0;
    cout << "\n\nEscriba un mensaje m[0,32]: ";
    cin >> mensaje;
    while (e < (p - 1) * (q - 1)) {
        NAIVE_RSA_KEY_GENERATOR(p, q, n, e, d);
        Pm = modular(mensaje, e, n);// mensaje cifrado
        if (Pm == mensaje) { // m ^ e mod n == m
            Sc = modular(Pm, d, n);// mensaje descifrado
            cout << "\t\t" << mensaje << " ^ " << e << " mod " << n << " = " << Pm << "\t\tmensaje descifrado: " << Sc << "\n";
        }
        e = e + 1;

    }
    
    return 0;
}