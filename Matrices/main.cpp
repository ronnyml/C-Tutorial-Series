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
#include "matrix.h"
#include "matrix.cpp"

using namespace std;

int main()
{
    // Para no generar los mismos números aleatorios
    srand(time(NULL));

    int n_rows;
    int n_cols;

    int col_1;
    int col_2;
    int row_1;
    int row_2;
    int scalar;

    cout << "Ingresa nro de filas: " << endl;
    cin >> n_rows;
    cout << "Ingresa nro de columnas: " << endl;
    cin >> n_cols;
    cout << endl;

    Matrix<int> a(n_rows, n_cols);
    Matrix<int> b(n_rows, n_cols);

    // Matriz para almacenar el resultado de las operaciones
    Matrix<int> c(n_rows, n_cols);

    a.fill_random();
    b.fill_random();

    cout << "********** Operaciones básicas con la Matriz A **********" << endl;
    cout << "Matriz A " << endl;
    a.print_matrix();

    cout << "El mayor de la Matriz es: " << a.get_max() << endl;
    cout << "El menor de la Matriz es: " << a.get_min() << endl;
    cout << "La moda de la Matrix es: " << a.get_mode() << endl;
    cout << (a.isSymmetric() ? "" : "No") << " Es simétrica." << endl;
    cout << (a.isIdentity() ? "" : "No") << " Es identidad." << endl;
    cout << endl;

    cout << "Ingresa el escalar: " << endl;
    cin >> scalar;
    a.multiply_by_scalar(scalar);
    a.print_matrix();

    cout << "Intercambio: Ingresa 2 columnas del 1 al " << n_cols << endl;
    cout << "Columna 1: " << endl;
    cin >> col_1;
    cout << "Columna 2: " << endl;
    cin >> col_2;
    a.swap_cols(col_1, col_2);
    a.print_matrix();

    cout << "Intercambio: Ingresa 2 filas del 1 al " << n_rows << endl;
    cout << "Fila 1: " << endl;
    cin >> row_1;
    cout << "Fila 2: " << endl;
    cin >> row_2;
    a.swap_rows(row_1, row_2);
    a.print_matrix();

    cout << "Transpuesta de A " << endl;
    a.get_transpose();

    cout << "********** Operaciones con matrices **********" << endl;
    cout << "Matriz A " << endl;
    a.print_matrix();

    cout << "Matriz B " << endl;
    b.print_matrix();

    cout << "Matriz A + B " << endl;
    c = a + b;
    c.print_matrix();

    cout << "Matriz A - B " << endl;
    c = a - b;
    c.print_matrix();

    cout << "Matriz A * B " << endl;
    c = a * b;
    c.print_matrix();

    a.delete_matrix();
    b.delete_matrix();
    c.delete_matrix();

    return 0;
}
