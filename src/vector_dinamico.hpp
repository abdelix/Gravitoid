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


#ifndef VECTOR_DINAMICO_H
#define VECTOR_DINAMICO_H
#include <iostream>
template <class Clase>
class vector_dinamico
{

  public:
    vector_dinamico()
    {
      nodo_inicial=NULL;
      l=0;
    }

  virtual ~vector_dinamico()
  {
    clear();
  }

void anyadir(const Clase & e)
		{
			
			nodo *p,*aux;
			p=nodo_inicial;
			
			
			if(p==NULL)
			{
				nodo_inicial=new nodo;
				nodo_inicial->e=e;
				nodo_inicial->sig=NULL;
			}
			else 
			{
			  
				while(p->sig!=NULL)
				{
				
				aux=p->sig;
				p=aux;
		
					
				}
				
				p->sig=new nodo;
				p->sig->e=e;
				p->sig->sig=NULL;
			}
			
			l++;
		}
		
Clase consultar(unsigned indice)
		{
			Clase e;
			nodo *p;
			p=nodo_inicial;
			unsigned i=0;
			if(indice>=l) 
			{
			  //
			}
			else
			{
				for(i=0;i<indice;i++)
				{
					p=p->sig;
					
				}
				
			}
			
			return p->e;
	       }
		
Clase operator[](const unsigned indice) const
		{
			Clase e;
			e=consultar(indice);
			return e;
			
		}
		
Clase&  operator[](const unsigned indice)
		{
			nodo *p;
			
			p=nodo_inicial;
			if(indice<l)
			{
			for(unsigned i=0;i<indice;i++)
			{
				p=p->sig;
			}
			}
			return p->e;
			
		}
void clear()
		
		{
			nodo *p,*aux;
			p=nodo_inicial;
			
			while(p!=NULL)
			{
				aux=p->sig;
				delete p;
				p=aux;
			}
		        l=0;
			nodo_inicial=NULL;
		}
		
void eliminar(unsigned indice)
		{
		  nodo *p,*ant;
		  p=nodo_inicial;
		  if(longitud()!=0)
		  {
		    
		  indice==longitud()>indice?indice:longitud()-1;//si indice>=longitud eliminamos el ultimo 
		 
			  for(unsigned i=0;i<indice;i++)
			  {
			    
			    ant=p;
			    p=p->sig;
			  }
			   if(indice==0)
			   {
			     nodo_inicial=nodo_inicial->sig;
			   }
			  else  ant->sig=p->sig;
			  delete p;
			  l--;
		  }
			
		}
		
unsigned longitud()
		{
		  return l;
		}
		

private :
  
  struct nodo
  {
    Clase e;
    nodo *sig;
    
  };
 nodo *nodo_inicial;
 unsigned l;
};

#endif // VECTOR_DINAMICO_H
