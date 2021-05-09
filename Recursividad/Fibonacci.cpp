#include <iostream>
#include <conio.h>

using namespace std;

int  fibonacci(int);

int main () {
    int n;
    cout<<"Ingrese un valor: "<<endl;
    cin>>n;
    cout<<fibonacci(n)<<"-";
    return 0;
}

/**
 * La función resive la posición que queremos saber de la serie, para esto utiliza la fórmula
 * [fn = f(n-1) + f(n-2)] cada una de ellas vuelve a llamar una suma igual hasta llegar al caso 
 * base, después comienza a resolver desde el caso base hasta el número que ingresamos
*/
int fibonacci (int n) {
    if((n == 0) || (n == 1)){ // Caso base cuando se terminan los números positivos
        return n;
    }
    else {
        return fibonacci(n-1) + fibonacci(n-2); 
    }
}