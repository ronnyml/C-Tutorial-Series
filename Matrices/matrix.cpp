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

#include "matrix.h"

// Constructor por defecto
template<typename T>
Matrix<T>::Matrix()
{
    m_rows = 4;
    m_cols = 4;
}

// Constructor copia
template<typename T>
Matrix<T>::Matrix(const Matrix &m)
{
    *this = m;
}

// Constructor por parámetro
template<typename T>
Matrix<T>::Matrix(int rows , int cols)
{
    m_cols = cols;
    m_rows = rows;
    m_matrix = new T*[m_rows];

    for (int i = 0; i < m_rows; i++) {
        m_matrix[i] = new T[m_cols];
    }
}

// Suma de matrices con sobrecarga de operadores
template<typename T>
Matrix<T> Matrix<T>::operator+ (const Matrix &matrix_2)
{
    Matrix matrix_result(m_rows, m_cols);
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            matrix_result.m_matrix[i][j] = m_matrix[i][j] + matrix_2.m_matrix[i][j];
        }
    }
    return matrix_result;
}

// Resta de matrices con sobrecarga de operadores
template<typename T>
Matrix<T> Matrix<T>::operator- (const Matrix &matrix_2)
{
    Matrix matrix_result(m_rows, m_cols);
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            matrix_result.m_matrix[i][j] = m_matrix[i][j] - matrix_2.m_matrix[i][j];
        }
    }
    return matrix_result;
}

// Multiplicación de matrices con sobrecarga de operadores
template<typename T>
Matrix<T> Matrix<T>::operator* (const Matrix &matrix_2)
{
    Matrix matrix_result(m_rows, matrix_2.m_cols);
    T total;

    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < matrix_2.m_cols; j++) {
            for (int k = 0; k < m_cols; k++) {
                total += (m_matrix[i][k] * matrix_2.m_matrix[k][j]);
            }
            matrix_result.m_matrix[i][j] = total;

            // Limpiar el total sumado arriba
            total = 0;
        }
    }
    return matrix_result;
}

// Verificar si una Matriz es simétrica
template<typename T>
bool Matrix<T>::isSymmetric()
{
    if (m_rows != m_cols) {
        return false;
    }

    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            if (m_matrix[i][j] != m_matrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}

// Verificar si una Matriz es identidad
template<typename T>
bool Matrix<T>::isIdentity()
{
    if (m_rows != m_cols) {
        return false;
    }

    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            if (i == j) {
                if (m_matrix[i][j] != 1)
                    return false;
            } else {
                if (m_matrix[i][j] != 0)
                    return false;
            }
        }
    }
    return true;
}

// Obtener el mayor de la Matriz
template<typename T>
T Matrix<T>::get_max()
{
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            if (m_matrix[i][j] > m_max) {
                m_max = m_matrix[i][j];
            }
        }
    }
    return m_max;
}

// Obtener el menor de la Matriz
template<typename T>
T Matrix<T>::get_min()
{
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            if (m_matrix[i][j] < m_min) {
                m_min = m_matrix[i][j];
            }
        }
    }
    return m_min;
}

// Obtener la moda de la Matriz
template<typename T>
T Matrix<T>::get_mode()
{
    // Creo una Matrix auxiliar
    Matrix matrix_aux(m_rows, m_cols);

    // Lleno la Matriz con ceros
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            matrix_aux.m_matrix[i][j] = 0;
        }
    }

    m_dim_matrix = m_rows * m_cols;

    // Para retener una fila n veces
    int y = 0;

    // Para retener una columna n veces
    int z = 0;

    // Empiezo a comparar cada elemento n veces
    for (int x = 0; x < m_dim_matrix; x++) {
        for (int i = 0; i < m_rows; i++) {
            for (int j = 0; j < m_cols; j++) {
                if (m_matrix[y][z] == m_matrix[i][j]) {
                    matrix_aux.m_matrix[i][j]++;
                }
            }
        }

        // Pasar a la siguiente columna despues de n comparaciones
        z++;

        /* Empiezo a comparar con la siguiente fila
           despues empiezo nuevamente en la 1era columna
           Y luego paso a la siguiente fila */
        if (z == m_cols) {
            z = 0;
            y++;
        }
    }

    // Obtengo el mayor valor de la Matriz
    m_max = matrix_aux.get_max();

    // Si ningun valor se ha repetido más de una vez, entonces no hay moda
    if (m_max == 1) {
        return -1;
    } else {
        for (int i = 0; i < m_rows; i++) {
            for (int j = 0; j < m_cols; j++) {
                if (matrix_aux.m_matrix[i][j] == m_max) {
                    m_mode = m_matrix[i][j];
                }
            }
        }
    }

    return m_mode;
}

template<typename T>
void Matrix<T>::delete_matrix()
{
    for (int i = 0; i < m_rows; i++) {
        delete[] m_matrix[i];
    }
    delete[] m_matrix;
}

// Llenar una Matriz desde teclado
template<typename T>
void Matrix<T>::fill_by_user()
{
    for (int i = 0; i < m_rows; i++) {
        cout << "Fila " << i + 1 << endl;
        for (int j = 0; j < m_cols; j++) {
            cout << "Ingresa el elemento " << j + 1 << endl;
            cin >> m_ele;
            m_matrix[i][j] = m_ele;
        }
        cout << endl;
    }
    m_max = m_matrix[0][0];
    m_min = m_matrix[0][0];
}

// Llenar aleatoriamente una Matriz
template<typename T>
void Matrix<T>::fill_random()
{
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            m_matrix[i][j] = rand() % 30;
        }
    }

    m_max = m_matrix[0][0];
    m_min = m_matrix[0][0];
    srand(time(NULL));
}

// Obtener la transpuesta de una Matriz
template<typename T>
void Matrix<T>::get_transpose()
{
    Matrix matrix_result(m_cols, m_rows);

    for (int i = 0; i < m_cols; i++) {
        for (int j = 0; j < m_rows; j++) {
            matrix_result.m_matrix[i][j]= m_matrix[j][i];
        }
    }
    matrix_result.print_matrix();
}

// Multiplicar a una Matriz por un escalar
template<typename T>
void Matrix<T>::multiply_by_scalar(T scalar)
{
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            m_matrix[i][j] = m_matrix[i][j] * scalar;
        }
    }
    cout << "Se multiplicó a la Matriz por el escalar " << scalar << endl;
}

// Imprimir Matriz
template<typename T>
void Matrix<T>::print_matrix()
{
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            cout << m_matrix[i][j] << " ";
        }
        cout << endl << endl;
    }
    cout << endl << endl;
}

// Intercambiar dos columnas en una Matriz
template<typename T>
void Matrix<T>::swap_cols(int col_1, int col_2)
{
    if (col_1 > m_cols || col_2 > m_cols) {
        cout << "Esa columna se encuentra fuera de rango." << endl;
    } else {
        T temp;
        col_1--;
        col_2--;

      for (int i = 0; i < m_rows; i++) {
          temp = m_matrix[i][col_1];
          m_matrix[i][col_1] = m_matrix[i][col_2];
          m_matrix[i][col_2] = temp;
      }
      cout << "Se intercambiaron las columnas " << col_1 + 1 << " y " << col_2 + 1 << endl;
    }
}

// Intercambiar dos filas en una Matriz
template<typename T>
void Matrix<T>::swap_rows(int row_1, int row_2)
{
    if (row_1 > m_rows || row_2 > m_rows) {
        cout << "Esa fila se encuentra fuera de rango." << endl;
    } else {
        T temp;
        row_1--;
        row_2--;

        for (int i = 0; i < m_cols; i++) {
            temp = m_matrix[row_1][i];
            m_matrix[row_1][i] =  m_matrix[row_2][i];
            m_matrix[row_2][i] = temp;
        }
        cout << "Se intercambiaron las filas: " << row_1 + 1 << " y " << row_2 + 1 << endl;
    }
}

template<typename T>
Matrix<T>::~Matrix() {}
