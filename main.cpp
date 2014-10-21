#include <SFML/Graphics.hpp>

#include <iostream>
#include "src/ventana.h"

int main()
{
       
  ab::ventana gravitoid;
  std::cout<<"Bucle Principal"<<std::endl;
  while(gravitoid.IsOpened())
  {  
    
     
    gravitoid.gestionar_sucesos(); 
    
    gravitoid.dibujar_escena();
;
    gravitoid.comprobar_colisiones();
    
    
    
    gravitoid.manejar_entrada();
   
    if(gravitoid.nvidas()<=0) gravitoid.game_over();
    if(gravitoid.win()) gravitoid.you_win();
  }
  
  return 0;
}
