#include <iostream>
#include <conio.h>

using namespace std;

int factorial (int);

int main () {
    int valor;

    cout<<"Ingrese un numero: "<<endl;
    cin>>valor;

    cout<<"Factorial: "<<factorial(valor)<<endl;
    getch();
    return 0;
}
/**
 * La función realiza la llamada así misma misntras el valor sea mayor a 1 por lo que  
 * n igual a 1 es el caso base, si el valor es mayor a 1 entonces manda a la función pasando
 * el [valor - 1]
*/
int factorial (int valor) {
    if (valor == 0) {
        return 1;
    }
    else {
        valor *= factorial(valor-1); // es lo mismo que [valor = valor * factorial(valor - 1);]
    }
    return valor;
}