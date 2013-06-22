/*
 * Copyright (C) 2009 Ronny Yabar Aizcorbe <ronnycontacto@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU Lesser General Public License,
 * version 2.1, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
 * more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <iostream>

using namespace std;

int main()
{
    int a;
    int b;

    cout << "Ingresa el valor de a: ";
    cin >> a;
    cout << endl;

    cout << "Ingresa el valor de b: ";
    cin >> b;
    cout << endl;

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

    cout << endl;
    cout << "---------- MATRICES Y ARITMÉTICA DE PUNTEROS ---------- " << endl;

    // Puntero a una matriz
    int **pm;

    int cols;
    int rows;

    cout << "Ingresa nro de filas: ";
    cin >> rows;

    cout << endl;
    cout << "Ingresa nro de columnas: ";
    cin >> cols;

    pm = new int* [rows];
    for (int i = 0; i < rows; i++) {
        pm[i] = new int[cols];
    }

    cout << "Elementos de la Matriz con sus direcciones: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            pm[i][j] = i + j;
            cout << pm[i][j] << "--> ";
            cout << &pm[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Elementos de la Matriz con sus direcciones, con aritmética de punteros: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Aritmética de punteros
            *(*(pm + i) + j) = i + j;
            cout << *(*(pm + i) + j) << "--> ";
            cout << &pm[i][j] << " ";
        }
        cout << endl;
    }

    // Elimino cada vector de la matriz
    for (int i = 0; i < rows; i++) {
        delete[] pm[i];
    }

    // Elimino el vector principal
    delete[] pm;

    return 0;
}

