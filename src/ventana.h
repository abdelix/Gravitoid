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


#ifndef VENTANA_H
#define VENTANA_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "cbloques.hpp"
#include "constantes.hpp"
#include "cbola.hpp"
#include "cbarra.hpp"

#include <list>
namespace ab{



class ventana : public sf::RenderWindow
{
public :
  ventana();
  void gestionar_sucesos();
  void comprobar_colisiones();
  void manejar_entrada();
  void dibujar_escena();
  void mostrar_puntuacion();
  void game_over();//Funcion que se ejecuta si el jugador pierde
  bool win();//Comprueba si el jugador  ha ganado
  void you_win();//Funcion que se ejecuta si el jugador gana
  void pausa();//funcion que se ejecuta cuando la ventana pierde el foco
  ~ventana();//DEstructor 
  unsigned nvidas();
  
private :
  
  //Funcioneds y procedimientos privados
  bool colision(sf::Sprite &a,sf::Sprite &b);
  sf::Vector2f obtener_centro(sf::Sprite &a);
 
  //-------------
  //- Atributos -
  //-------------
  const sf::Input *entrada;
  sf::Event suceso;
  sf::Font  fuente;
  float tiempo;
  sf::Clock reloj;
  
  //el fondo
  sf::Image  image_fondo;
  sf::Sprite fondo;
  
  //Clases de los elementos de juego
  Cbarra barra;
  CBloques bloques;
  
  cbola bola;
 //mosulo de la velocidad
  
  //audio
  sf::Music Musica;
  sf::Music Efecto_golpe;
  
  
  bool p;
  unsigned punt,vidas;
  
  
};

}
#endif // VENTANA_H
