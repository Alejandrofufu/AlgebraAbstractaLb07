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
    NAIVE_RSA_KEY_GENERATOR(p,q,n,e,d);
    int cont = 0;
    for (int i = 0; i < n; i++){
        mensaje = i;
        int c = modular(mensaje, e, n);
        if(mensaje == c)cont++;
        cout <<"\t"<<mensaje<<"^"<<e<<" mod "<<n<<" =c\tc: " << c<<"\n";
        cout << "mensaje: " << modular(c, d, n) <<"\n\n";
        
    }
    cout<<"son "<<cont<<" casos donde el mensaje y el mensaje cifrado son los mismos\n";
    
    return 0;
}