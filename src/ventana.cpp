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


#include "ventana.h"
#include "constantes.hpp"

#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <iostream>
namespace ab
{
ventana::ventana()
  {
    
//iniciamos la pantalla    
    Create(sf::VideoMode(ANCHO,ALTO ),"Gravitoid 0.01_Beta",sf::Style::Close);
    SetFramerateLimit(60);
   UseVerticalSync(true);
   entrada=&GetInput();
   
   //Cargamos en memoria  la fuente de letras que vamos a usar
   fuente.LoadFromFile("recursos/DejaVu.ttf");
   
  //Cargamos los gráficos
 
  
  

 
  image_fondo.LoadFromFile("recursos/fondo.png");
  fondo.SetImage(image_fondo);
  fondo.Resize(ANCHO,ALTO);
  

  
  Musica.OpenFromFile("recursos/musica/musica1.wav");
  Musica.SetLoop(true);
  Musica.SetVolume(50);
  Musica.Play();
 
  
  Efecto_golpe.OpenFromFile("recursos/musica/nutfall.wav");
  Efecto_golpe.SetVolume(100);
  
  reloj.Reset();//inicializamos el crono
  
  
  //inicializamos la puntuacion y las vidas
  
  punt=0; 
  vidas=4;
  bola.mod_vel_bola=VEL_BOLA;
  }

  //gestionamos los eventos :cerrar ...
void ventana::gestionar_sucesos()
{
  while(GetEvent(suceso))
  {
    switch(suceso.Type)
    {
      case sf::Event::Closed :
    Musica.Stop();
	Close();
	
	sf::Sleep(0.1f);
	
	exit(0);
	break;
      case sf::Event::LostFocus :
	pausa();
	break;
      case sf::Event::GainedFocus :
	p=false;
	break;
      default:
	;
    }
  }
}
 
 //Comprobamos las colisiones
 bool ventana::colision(sf::Sprite &a,sf::Sprite &b)
{
  bool c=true;
  c=(a.GetPosition().x< b.GetPosition().x+b.GetSize().x);
  c=c&&(a.GetPosition().x+a.GetSize().x>b.GetPosition().x);
  
   c=c&&(a.GetPosition().y< b.GetPosition().y+b.GetSize().y);
  c=c&&(a.GetPosition().y+a.GetSize().y>b.GetPosition().y);
  
   
   return c;
  
}

void ventana::manejar_entrada()
{
  
      if(entrada->IsKeyDown(sf::Key::Right) && barra.GetPosition().x+barra.GetSize().x<PROP_CAMPO*GetWidth())
      {
	  barra.Move(VEL_BARRA,0);
      
      }
      if(entrada->IsKeyDown(sf::Key::Left)&& barra.GetPosition().x>0)
      {
	barra.Move(-VEL_BARRA,0);
      }

}

void ventana::dibujar_escena()
{
  Clear();
  Draw(fondo);
  Draw(bola);
  Draw(barra);
  mostrar_puntuacion();
  
  for(int i=0;i<bloques.longitud();i++)
  //for(int i=0;i<30;i++)
  {
    Draw(bloques[i]);
    
   
    
  }
  
  Display();
    
}



void ventana::comprobar_colisiones()
{
  sf::Vector2f dircc;
  float angulo;
  tiempo=reloj.GetElapsedTime();
  
 
  //Colision_campo maneja los rebotes con el campo y devuelco true si y solo si
  //la colision quita una vida
  if(bola.colision_campo()) vidas--;
  
  
  
  //Colision de bola con la barra
  if( colision(bola,barra))
  {
    //Calculamos la direccion de rebote basada en el angulo de incidencia
   
   dircc= obtener_centro(bola)-obtener_centro(barra);
   
   angulo=std::atan2(dircc.x,dircc.y);
   
   bola.vel.y=bola.mod_vel_bola*( SIG(std::cos(angulo))+std::cos(angulo));
   
   bola.vel.x=bola.mod_vel_bola*std::sin(angulo);
    
   
   Efecto_golpe.Play();
  }
  
  
 for(unsigned int i=0;i<bloques.longitud();i++)
  {
    if(colision(bloques[i],bola)) 
    {
     
     
      bola.Move(-bola.vel.x*0.3,-bola.vel.y*0.3);
     
      dircc= obtener_centro(bola)-obtener_centro(bloques[i]);
    
      angulo=std::atan2(dircc.x,dircc.y);
   
  
       bola.vel.y=bola.mod_vel_bola*std::cos(angulo);
       bola.vel.x=bola.mod_vel_bola*std::sin(angulo); 
       
       /*
	*  bola.vel.y=(std::abs(bola.vel.y))*SIG(std::cos(angulo));
       bola.vel.x=(std::abs(bola.vel.x))*SIG(std::sin(angulo)); 
	* */
      
       

   
        if(bloques.tipoc(i)!=0)
	{
	  bloques.eliminar(i);
	  i--;
	  punt ++;
	  
	}
    bola.mod_vel_bola*=1.01;//Aceleramos
     
    Efecto_golpe.Play();
     
     break;
    }
     
  }
  
  
  float mod=sqrt(bola.vel.x*bola.vel.x+bola.vel.y*bola.vel.y);
  
  
  bola.vel.y*=tiempo*(bola.mod_vel_bola/mod);
  bola.vel.x*= tiempo*(bola.mod_vel_bola/mod);
  
  
  bola.Move(bola.vel);
  
  reloj.Reset();
}


//obtener_centro :Funcion que obtiene las coordenadas del centro de un sprite
//param : sf::Sprite& a 
//devuelve : sf::Vector2f

sf::Vector2f ventana::obtener_centro ( sf::Sprite& a )
{
  sf::Vector2f centro;
  centro=a.GetSize();
  centro.x*=0.5;
  centro.y*=0.5;
  centro=centro+a.GetPosition();
  
  return centro;
}

void ventana::pausa()
{
  sf::String s("Pausa",fuente,60);
  p=true;
  float a=s.GetRect().GetWidth();
  s.SetPosition((GetWidth()*PROP_CAMPO-a)/2,(GetHeight())/2);
  Draw(s);
  do
  {
    gestionar_sucesos();
    Display();
  }while(p);
}


void ventana::mostrar_puntuacion()
{
   char msj[80];
  std::sprintf(msj,"Puntucion : %d\nVidas     : %d ",punt,vidas);
  sf::String mimsj(msj,fuente,20);
  
  mimsj.SetPosition(GetWidth()*PROP_CAMPO+10 ,10);
  
  
  Draw(mimsj);

}




 ventana::~ventana()
{

 Musica.Stop();
}


void ventana::game_over()
{
   sf::String s("Game Over",fuente,60);
 
  float a=s.GetRect().GetWidth();
  s.SetPosition((GetWidth()-a)/2,(GetHeight())/2);
  Draw(s);
  do
  {
    
    gestionar_sucesos();
    Display();
    
  }while(!entrada->IsKeyDown(sf::Key::Return));
  
  bola.reset();
  bloques.colocar_defecto();
  
  vidas=4;
  punt=0;
  
}

void ventana::you_win()
{
   sf::String s("You Win!!!",fuente,60);
 
  float a=s.GetRect().GetWidth();
  s.SetPosition((GetWidth()-a)/2,(GetHeight())/2);
  Draw(s);
  do
  {
    
    gestionar_sucesos();
    Display();
    
  }while(!entrada->IsKeyDown(sf::Key::Return));
  
  bola.reset();
  bloques.colocar_defecto();
  vidas=4;
  punt=0;
  
}

unsigned int ventana::nvidas()
{
  return vidas;
}

bool ventana::win()
{
  bool win=true;
  unsigned c=0;
  while(win&&c<bloques.longitud())
  {
    win=bloques.tipoc(c)==0; //comprueba que solo halla bloques indestructibles
    
    c++;
  }
  
  return win;

}


}//Fin del namespace ab


