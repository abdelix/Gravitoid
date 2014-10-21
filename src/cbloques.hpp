/*
    Gravitoid 0.01 beta
    Copyright (C) 2012  Abdelfetah Hadij abdel.14@gmail.com

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef CBLOQUES_HPP
#define CBLOQUES_HPP


#include <SFML/Graphics.hpp>
#include <iostream>
#include "vector_dinamico.hpp"
#include "constantes.hpp"

class CBloques:public  vector_dinamico<sf::Sprite>
{

public:
    CBloques();
    void colocar_defecto();//Coloca los bloques por defecto
    bool cargar_archivo(std::ifstream &archivo);
    unsigned tipo(char c );
    unsigned tipoc ( unsigned  c );//Devuelve el tipo de elemento numero c
    virtual ~CBloques();
private:
   sf::Image imagen[TIPOS_BLOQUES];

};

#endif // CBLOQUES_HPP
