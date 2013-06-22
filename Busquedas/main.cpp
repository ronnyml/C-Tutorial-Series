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
#include <stdlib.h>
#include "quicksort.cpp"

using namespace std;

int lineal_search(int *array, int searched, int arraySize)
{
    for (int i = 0; i< arraySize; i++) {
        if (searched == array[i]) {
            cout << "Se encuentra en la posicion " << i + 1 << endl;
        }
   }
}

int binary_search(int *array, int searched, int arraySize)
{
    int first = 0;
    int middle;
    int last = arraySize - 1;

    while (first <= last) {
        middle = (first + last) / 2;

        if (searched == array[middle]) {
            cout << "Se encuentra en la posición " << middle + 1 << endl;
            return array[middle];
        } else {
            if (array[middle] > searched) {
                last = middle - 1;
            } else {
                first = middle + 1;
            }
        }
    }
    return -1;
}

void print(int *array, int arraySize)
{
   for (int i = 0; i < arraySize; i++) {
        cout << array[i] << "  ";
   }
   cout << endl << endl;
}

int main()
{
    int arraySize;
    int searched;
    cout << "Ingresa el tamanyo del array" << endl;
    cin >> arraySize;

    int array[arraySize];

    srand(time(NULL));
    for (int i = 0; i < arraySize; i++) {
        array[i] = rand() % 100;
    }

    cout << endl;
    cout << "Array al inicio: " << endl;
    print(array, arraySize);

    cout << "Busqueda lineal -> Ingresa el elemento a buscar: ";
    cin >> searched;
    lineal_search(array, searched, arraySize);

    cout << "Array ordenado: " << endl;
    quicksort(array, 0, arraySize);
    print(array, arraySize);

    cout << "Busqueda binaria -> Ingresa el elemento a buscar: ";
    cin >> searched;
    binary_search(array, searched, arraySize);
}

