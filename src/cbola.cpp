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


#include "cbola.hpp"
#include "constantes.hpp"
#include <SFML/Graphics.hpp>

cbola::cbola()

{
  //Inicializamos la bola
  //cargamos los graficos y los ponemos
  img.LoadFromFile("recursos/bola.png");
  SetImage(img);
  
  //ajustamos el tamaño
  Resize(20,20);
  
  //la colamos en medio
  SetPosition(ANCHO*PROP_CAMPO/2-10,ALTO/2-10); 
  
   vel.x=vel.y=VEL_BOLA;
}

sf::Vector2f cbola::velocidad() const
{
  return vel;
}

void  cbola::velocidad ( float x, float y )
{
  vel.x=x;
  vel.y=y;
  
  
}

bool cbola::colision_campo()
{
  bool b=false;
  
   //gestion de choques de la bola con la frontera del juego
  if(GetPosition().x<0 || (GetPosition().x+GetSize().x)>PROP_CAMPO*ANCHO)
  {
    Move(-vel);
   vel.x*=-1;
  }
  
  if(GetPosition().y<0 )
  {
      Move(-vel);
      vel.y*=-1;
   }
  
  if((GetPosition().y+GetSize().y)>ALTO)
      {
	 
	  b=true;
        reset();
	SetPosition(ANCHO*PROP_CAMPO/2-10,ALTO/2-10);
   }
  //**************************************///
  
  return b;

}


void cbola::reset()
{

  mod_vel_bola=vel.x=vel.y=VEL_BOLA;
  SetPosition(ANCHO*PROP_CAMPO/2-10,ALTO/2-10);
}





