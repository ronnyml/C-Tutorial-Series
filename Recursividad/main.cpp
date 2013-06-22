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

// Función factorial con tail recursion
int fact_tail_sum(int n, int sum) {
    if (n == 1) {
        return sum;
    } else {
        return fact_tail_sum(n - 1, sum * n);
    }
}

// Para mantener la sintaxis original de como se llama a la función factorial
int fact_tail(int n) {
    return fact_tail_sum(n, 1);
}

int main()
{
    int num = 0;
    cout << "Ingresa un nro " << endl;
    cin >> num;
    cout << "Su factorial es " << fact_tail(num) << endl;
    return 0;
}