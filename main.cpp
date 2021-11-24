#include <iostream>
#include<math.h>
using namespace std;

long long EuclidesGeneral(long long a, long long b, long long& x, long long& y)
{
    if (a == 0)
    {
        x = 0, y = 1;
        return b;
    }
    long long x1, y1;
    long long gcd = EuclidesGeneral(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;

    return gcd;
}

long long inversoM(long long a, long long m) {
    long long x = 0, y = 0;
    long long g = EuclidesGeneral(a, m, x, y);
    if (g != 1)
        return -1;
    else {
        long long res = (x % m + m) % m;
        return res;
    }
}

long long Gcd(long long a, long long b) {
    long long t;
    while (true) {
        t = a % b;
        if (t == 0)
            return b;
        a = b;
        b = t;
    }
}

void NAIVE_RSA_KEY_GENERATOR(long long p, long long q, long long& n, long long& e, long long& d) {
    n = p * q;
    long long phi = (p - 1) * (q - 1);
    long long pista = 0;
    while (e < n) { // e = {2,n-1}
        pista = Gcd(e, phi);
        if (pista == 1) {
            d = inversoM(e, phi);
            break;
        }
        else
            e++;
    }
}

int main() {
    long long mensaje = 0, p = 3, q = 11, n = 0, e = 2, d = 0, Pm = 0, Sc = 0;
    cout << "Tabla: " << "m" << " ^ " << "e" << " mod " << "n" << " = " << " c \n";
    while (mensaje < p * q) {
        NAIVE_RSA_KEY_GENERATOR(p, q, n, e, d);
        Pm = pow(mensaje, e);
        Pm = (Pm % n + n) % n;// mensaje cifrado
        Sc = pow(Pm, d);
        Sc = (Sc % n + n) % n;// mensaje descifrado
        cout << "\t\t" << mensaje << " ^ " << e << " mod " << n << " = " << Pm << "\t\tmensaje descifrado: " << Sc << "\n";
        mensaje = mensaje + 1;
    }
    /////////////////////////////////////
    mensaje = 0, p = 3, q = 11, n = 0, e = 2, d = 0, Pm = 0, Sc = 0;
    cout << "\n\nEscriba un mensaje m[0,32]: ";
    cin >> mensaje;
    while (e < p * q) {
        NAIVE_RSA_KEY_GENERATOR(p, q, n, e, d);
        Pm = pow(mensaje, e);
        Pm = (Pm % n + n) % n;// mensaje cifrado
        if (Pm == mensaje) { // m ^ e mod n == m
            Sc = pow(Pm, d);
            Sc = (Sc % n + n) % n;// mensaje descifrado
            cout <<"\t\t" << mensaje << " ^ " << e << " mod " << n << " = " << Pm << "\t\tmensaje descifrado: " << Sc << "\n";
        }
        e = e+1;
    }

    return 0;
}