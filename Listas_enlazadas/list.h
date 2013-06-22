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

#ifndef LIST_H
#define LIST_H

#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>

#include "node.h"
#include "node.cpp"

using namespace std;

template <class T>

class List
{
    public:
        List();
        ~List();

        void add_head(T);
        void add_end(T);
        void add_sort(T);
        void concat(List);
        void del_all();
        void del_by_data(T);
        void del_by_position(int);
        void fill_by_user(int);
        void fill_random(int);
        void intersection(List);
        void invert();
        void load_file(string);
        void print();
        void save_file(string);
        void search(T);
        void sort();

    private:
        Node<T> *m_head;
        int m_num_nodes;
};

#endif // LIST_H
