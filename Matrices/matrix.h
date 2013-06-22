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

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

template <class T>
class Matrix {
    public:
        Matrix();
        Matrix(int, int);
        Matrix(const Matrix &m);
        ~Matrix();

        Matrix<T> operator+ (const Matrix &matrix_2);
        Matrix<T> operator- (const Matrix &matrix_2);
        Matrix<T> operator* (const Matrix &matrix_2);

        bool isSymmetric();
        bool isIdentity();

        T get_max();
        T get_min();
        T get_mode();

        void delete_matrix();
        void fill_by_user();
        void fill_random();
        void get_transpose();
        void multiply_by_scalar(T);
        void print_matrix();
        void swap_cols(int, int);
        void swap_rows(int, int);

    private:
        T m_ele;
        T m_max;
        T m_min;
        T m_mode;
        T **m_matrix;

        int m_dim_matrix;
        int m_cols;
        int m_rows;
};

#endif // MATRIX_H
