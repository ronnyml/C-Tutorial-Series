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

#include "list.h"
#include "list.cpp"

using namespace std;

int main()
{
    List<int> list_1;
    List<int> list_2;
    int ele;

    int dim;
    int pos;
    string file_with_list;

    cout << "Ingresa la dimensión de la lista: " << endl;
    cin >> dim;

    list_1.fill_random(dim);

    cout << "Lista A al inicio " << endl;
    list_1.print();

    cout << "Agrega un elemento por la cabeza: " << endl;
    cin >> ele;
    list_1.add_head(ele);
    list_1.print();

    cout << "Lista invertida: " << endl;
    list_1.invert();
    list_1.print();

    cout << "Lista ordenada: " << endl;
    list_1.sort();
    list_1.print();

    cout << "Agrega un elemento. Será insertado ordenadamente: " << endl;
    cin >> ele;
    list_1.add_sort(ele);
    list_1.print();

    cout << "Busca un elemento: " << endl;
    cin >> ele;
    list_1.search(ele);

    cout << "Elimina un elemento por dato: " << endl;
    cin >> ele;
    list_1.del_by_data(ele);
    list_1.print();

    cout << "Elimina un elemento por posición: " << endl;
    cin >> pos;
    list_1.del_by_position(pos);
    list_1.print();

    cout << "Cargar una lista desde archivo - Ingresa el nombre(Ex: list.txt): " << endl;
    // El archivo debe estar en el mismo directorio que este programa
    cin >> file_with_list;
    list_2.load_file(file_with_list);
    cout << "Lista B: " << endl;
    list_2.print();

    cout << "Guardar la lista en un archivo - Ingresa el nombre(Ex: list2.txt): " << endl;
    cin >> file_with_list;
    list_2.save_file(file_with_list);

    cout << "Interseccion entre las listas A y B: " << endl;
    list_1.intersection(list_2);

    cout << "Listas A y B concatenadas: " << endl;
    list_1.concat(list_2);
    list_1.print();

    list_1.del_all();
    list_1.print();

    return 0;
}

