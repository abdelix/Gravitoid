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


#ifndef BOLA_HPP
#define BOLA_HPP

#include <SFML/Graphics.hpp>

class cbola: public sf::Sprite
{
public :
  cbola();
  sf::Vector2f  velocidad() const ;//funcion para consultar la velocidad
  void  velocidad(float x,float  y) ;//Establecer una nueva velocidad
  void reset();//DEvuelve la vola a su estado inicial
  bool colision_campo();
  
  
  sf::Vector2f vel;//Velocidad de la bola
   float mod_vel_bola;
  
private :
  
  sf::Image img;//
  
  
  
};

#endif // BOLA_HPP
