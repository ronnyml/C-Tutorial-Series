#include <iostream>

using namespace std;

int main () {
    int a = 10;
    int b = 20;

    // Punteros de tipo entero
    int *p;
    int *p2;

    cout << "Antes" << endl;
    cout << "Variable a = " << a << endl;

    cout << "Direccion de a = " << &a << endl << endl;

    cout << "Variable b = " << b << endl;
    cout << "Direccion de b = " << &b << endl << endl;

    // Tiene basura al principio, podria inicializar con *p=0
    cout << "Contenido de p (Basura)= " << *p << endl;
    cout << "Direccion de p = " << &p << endl << endl;

    cout << "Despues" << endl;
    a++;
    p= &a;

    cout << "Contenido de p =  " << *p << endl;
    // p ahora tiene la dirección de b
    p = &b;
    // Le sumo 20 al contenido de p, es decir, estoy incrementando el valor de b
    *p +=20;

    cout << "Variable a = " << a << endl;
    cout << "Variable b = " << b << endl << endl;

    // p ahora tiene la dirección de a
    p=&a;

    // Contenido de p es igual al contenido de a * 5
    *p = a * 5;

    cout << "Contenido de p = " << *p << endl;
    cout << "Variable a = " << a << endl << endl;

    // Tiene basura al principio, podria inicializar con *p2=0
    cout << "Contenido de p2 (Basura) = " << *p2 << endl;
    cout << "Direccion de p2 = " << &p2 << endl << endl;

    // El contenido de p es asignado al contenido de p2
    p2 = p;

    // Incremento 15 al contenido de p2
    *p2 += 15;

    cout << "Contenido de p2 = " << *p2 << endl;
    // p apunta a otra dirección de memoria,se desplaza 4 bytes en memoria
    p++;

    // El contenido de esa nueva dirección
    cout << "Contenido de p (Basura) = " << *p << endl;

    return 0;
}
