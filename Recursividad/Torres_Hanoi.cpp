/**
 * Las torres de Hanoi es un problema que supone la existencia de 3 varillas
 * (A, B, C), o postes en los que se alojaban discos (n discos), que se podían 
 * trasladar de una varilla a otra libremente pero con una condición: cada 
 * disco es inferior en diámetro al que estaba justo debajo de él.
 * Se puede comprobar en el siguiente enlace: 
 * http://www.uterra.com/juegos/torre_hanoi.php 
*/
#include <iostream>
#include <conio.h>

using namespace std;

void hanoi (char posteA, char posteB, char posteC, int n);

int main () {
    int discos;
    cout<<"Ingrese el número de discos: "<<endl;
    cin>>discos;
    hanoi ('A', 'B', 'C', discos);
    return 0;
}

void hanoi (char posteA, char posteB, char posteC, int n) {
    if (n == 1) { //Caso base
        cout<<"Mover disco "<<n<<" desde la varilla "<<posteA
        <<" a varilla "<<posteC<<endl;
    }
    else { //Caso recursivo
        hanoi (posteA, posteC, posteB, n-1);
        cout<<"Mover disco "<<n<<" desde la varilla "<<posteA
        <<" a varilla "<<posteC<<endl;
        hanoi (posteB, posteA, posteC, n-1);
    }
}
