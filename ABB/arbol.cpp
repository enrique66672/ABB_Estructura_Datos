//by: Roque Ramos Miguel Enrique
#include <iostream>
#include <conio.h>

using namespace std;

/**
 * El nodo contiene un espacio para el dato que puede ser de cualquier tipo
 * dos punteros, uno para apuntar un nodo a la izquierda y otro a la derecha
 * y un padre que nos ayudará a saber de quien deciende un nodo
*/
struct Nodo {
	int dato;
	Nodo *derecha;
	Nodo *izquierda;
	Nodo *padre;
};

Nodo *crearNodo(int, Nodo *);
void insertarNodo(Nodo *&, int, Nodo *);
void mostrarArbol(Nodo *, int);
bool busqueda(Nodo *, int);
void preOrden(Nodo *);
void inOrden(Nodo *);
void postOrden(Nodo *);
void eliminar(Nodo *, int);
void eliminarNodo(Nodo *);
Nodo *minimo(Nodo *);
void reemplazar(Nodo *, Nodo *);
void destruirNodo(Nodo *);

Nodo *arbol = NULL;

int main() {
	int dato, opcion;
	int cont = 0;
	do {
		cout<<"\n\t MENU"<<endl;
		cout<<"1.- Insertar un nuevo nodo"<<endl;
		cout<<"2.- Mostrar el arbol completo"<<endl;
		cout<<"3.- Buscar un elemento en el arbol"<<endl;
		cout<<"4.- Recorrer arbol en PreOrden"<<endl;
		cout<<"5.- Recorrer el arbol en InOrden"<<endl;
		cout<<"6.- Recorrer el arbol en PostOrden"<<endl;
		cout<<"7.- Eliminar nodo del arbol "<<endl;
		cout<<"8.- Salir"<<endl;
		cout<<"Ingrese una opcion: "<<endl;
		cin>>opcion;

		switch (opcion)	{
		case 1:
			cout<<"Ingrese el dato: "<<endl;
			cin>>dato;
			insertarNodo(arbol, dato, NULL);
			break;
		case 2:
			cout<<"\nMostrando arbol completo: \n\n";
			mostrarArbol(arbol, cont);
			cout<<endl;
			break;
		case 3:
			cout<<"ingrese el dato a buscar: "<<endl;
			cin>>dato;
			if (busqueda(arbol, dato)) {
				cout<<"\nElemento: "<<dato<<" a sido encontrado en el arbol"<<endl;
			} else {
				cout<<"\nElemento no encontrado"<<endl;
			}		
			break;
		case 4:
			cout<<"\nRecorrido en PreOrden:"<<endl;
			preOrden(arbol);
			cout<<endl;
			break;
		case 5: 
			cout<<"\nRecorrido en InOrden:"<<endl;
			inOrden(arbol);
			cout<<endl;
			break;
		case 6: 
			cout<<"\nRecorrido en PostOrden:"<<endl;
			postOrden(arbol);
			break;
		case 7:
			cout<<"\nDigite el numero a eliminar: "<<endl;
			cin>>dato;
			eliminar(arbol, dato);
			cout<<endl;
			break;
		case 8:
		default:
			break;
		}
	} while(opcion != 8);
	getch();
	return 0;
}

/**
 * La función crea un nodo pasa un dato y un nodo, se asigna valores NULL
 * a la izquierda y a la derecha y se le da la dirección del nodo padre
*/
Nodo *crearNodo(int n, Nodo *padre) {
	Nodo *nuevo_Nodo = new Nodo();

	nuevo_Nodo->dato = n;
	nuevo_Nodo->derecha = NULL;
	nuevo_Nodo->izquierda = NULL;
	nuevo_Nodo->padre = padre;

	return nuevo_Nodo;
}

/**
 * Se recibe un nodo del árbol el valor y un nodo padre
 * Primero se comprueba que el nodo no sea NULL en el caso que sí entonces se crea un Nodo, 
 * Va comparando el valor que recibimos con el valor del nodo, si es menor el valor se insertará
 * a la izquierda y si el valor es mayor se crea un nodo a la derecha.
*/
void insertarNodo(Nodo *&arbol, int n, Nodo *padre) {
	int valorRaiz;

	if (arbol == NULL) {
		Nodo *nuevo_Nodo = crearNodo(n, padre);
		arbol = nuevo_Nodo;
	} else {
		valorRaiz = arbol->dato;

		if (n < valorRaiz) {
			insertarNodo(arbol->izquierda, n, arbol);
		} else {
			insertarNodo(arbol->derecha, n, arbol);
		}
	}
}

/**
 * Comprueba que el arbol sea diferente de NULL
 * Imprime un arbol en foma horizontal, imprime todo el árbol derecho primero 
 * Deja los espacios necesarios y después imprime a la izquierda 
*/
void mostrarArbol(Nodo *arbol, int cont) {
	if (arbol == NULL) {
		return;
	} else {
		mostrarArbol(arbol->derecha, cont+1);

		for(int i = 0; i < cont; ++i) {
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->izquierda, cont+1);
	}
}

/**
 * Recibe el nodo del árbol y el valor a buscar, se comprueba que el árbol no esté vacio
 * y si el valor con el dato son iguales regresa un true, los casos descritos son los casos bases
 * también comprobamos que si el valor del dato recibido es menor que el del nodo o mayor en esos 
 * casos hacemos uso de la recursividad.
*/
bool busqueda(Nodo *arbol, int n) {
	if (arbol == NULL) {
		return false;
	} else if (arbol->dato == n) { //Elementos igual al dato buscado
		return true;
	} else if (n < arbol->dato) {
		return busqueda (arbol->izquierda, n);
	} else {
		return busqueda (arbol->derecha, n);
	}	
}

/**
 * Comprueba que haya un valor en el arbol, si lo hay imprimiremos de desde 
 * pasamos desde la raíz hasta la izquierda y después al derecho.
*/
void preOrden(Nodo *arbol) {
	if (arbol == NULL) {
		return;
	} else {
		cout<<arbol->dato<<" - ";
		preOrden(arbol->izquierda);
		preOrden(arbol->derecha);
	}
}

/**
 * Comprobamos que haya un valor en el árbol, si lo hay imprimiremos desde la 
 * izquierda pasando por la raizy luego por el sub árbol derecho
*/
void inOrden(Nodo *arbol) {
	if (arbol == NULL) {
		return;
	} else {
		inOrden(arbol->izquierda);
		cout<<arbol->dato<<" - ";
		inOrden(arbol->derecha);
	}
}

/**
 * Comprobamos que haya un valor que recorrer, si lo hay visitamos desde la derecha, 
 * pasamos por la raíz y luego visitamos el subarbol izquierdo.
*/
void postOrden(Nodo *arbol) {
	if (arbol == NULL) {
		return;
	} else {
		postOrden(arbol->izquierda);
		postOrden(arbol->derecha);
		cout<<arbol->dato<<" - ";
	}	
}

/**
 * Eliminar un nodo del árbol
 * Comienza comprobando que el árbol no esté vacio, si lo está dejará de buscar y mandará
 * el mensaje de que el valor no fue encontrado, si ya se buscó en todo el árbol
 * en caso contrario comprobará si el valor a eliminar es menos al valor del nodo actual
 * si es menor volverá a llamarse la función pasando el nodo de la izquierda, y valor a eliminar
 * otro caso es que el valor a eliminar y en ese caso llamamos a la función y le pasamos
 * el nodo de la derecha y el valor a eliminar.
 * Sino se cumple ninguno de los casos anteriores entonces estámos en el valor de interes
 * y llamamos a eliminar nodo.
*/
void eliminar(Nodo *arbol, int n) {
	if (arbol == NULL) {
		cout<<"Dato "<<n<<" no encontrado en el arbol"<<endl;
		return;
	} else if (n < arbol->dato) {
		eliminar(arbol->izquierda, n);
	} else if (n > arbol->dato) {
		eliminar(arbol->derecha, n);
	} else {
		eliminarNodo(arbol);
	}
}

/**
 * En el caso de que un nodo se tenga que eliminar después de que nos mande a la derecha del nodo nos iremos 
 * por la izquierda lo más que se pueda
*/
Nodo *minimo(Nodo *arbol) {
	if (arbol == NULL) {
		return NULL;
	}
	if (arbol->izquierda) {
		return minimo(arbol->izquierda);
	} else {
		return arbol;
	}
}

/**
 * Recibimos el nodo a eliminar y el nodo a remplazar, si el nodo a remplazar tiene papá 
 * comprobamos si está en la derecha si está ahí igualamos al nodo que recibimos para reemplazar
 * Sino estará en el lado izquierdo igualamos el nodo derecho por el que recibimos para reemplazar.
 * Sí el nodo a reemplazar existe vamos a darle el padre del nodo que borramos.
*/
void reemplazar(Nodo *arbol, Nodo *nuevoNodo) {
	if (arbol->padre) {
		if (arbol->dato == arbol->padre->izquierda->dato) {
			arbol->padre->izquierda = nuevoNodo;
		} else if(arbol->dato == arbol->padre->derecha->dato) {
			arbol->padre->derecha = nuevoNodo;
		}
	}
	if (nuevoNodo) {
		nuevoNodo->padre = arbol->padre;
	}
}

/**
 * Recibimos el nodo y damos valos del NULL a los punteros y luego borramos el nodo.
*/
void destruirNodo(Nodo *nodo) {
	nodo->izquierda = NULL;
	nodo->derecha = NULL;
	delete nodo;
}

/**
 * Eliminar un solo nodo
 * Creamos un nodo que va a ser el nodo con el que vamos a remplazar el nodo a eliminar
 * si el nodo tiene 2 hijos, buscamos el nodo para remplazar por la derecha una vez obtenido 
 * se hace lo mismo para ese nodo si cumple cualquiera de los 3 casos para evitar dejar huecos
 * Otro caso es que solo haya un nodo por la izquierda, comprobamos una vez encontrado remplazamos
 * y destruimos el nodo de interes.
 * En caso de que solo haya un nodo por la derecha se hace lo mismo, pero remplazamos por el nodo
 * de la derecha y destruimos el nodo de interes.
 * El ultimo caso es que el nodo sea una hoja, solo tenemos remplazar la dirección por NULL}
 * y eliminar el nodo
*/
void eliminarNodo(Nodo *nodoEliminar) {
	Nodo *menor;
	if (nodoEliminar->izquierda && nodoEliminar->derecha) {
		menor = minimo(nodoEliminar->derecha);
		nodoEliminar->dato = menor->dato;
		eliminarNodo(menor);
	} else if (nodoEliminar->izquierda) {
		reemplazar(nodoEliminar, nodoEliminar->izquierda);
		destruirNodo(nodoEliminar);
	} else if (nodoEliminar->derecha) {
		reemplazar(nodoEliminar, nodoEliminar->derecha);
		destruirNodo(nodoEliminar);
	} else {
		reemplazar(nodoEliminar, NULL);
		destruirNodo(nodoEliminar);
	}
}