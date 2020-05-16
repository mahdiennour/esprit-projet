#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

typedef struct
       {
		int num; 
		SDL_Surface *afficher_map; 
		SDL_Rect pos_map;   
                SDL_Surface *afficher_perso;
                SDL_Rect pos_perso; 
                
            
	}map;

typedef struct    
{     
                int num1; 
                SDL_Surface *afficher_minimap;
                SDL_Rect pos_minimap;
                SDL_Surface *afficher_miniperso;  
                SDL_Rect pos_miniperso;

       }minimap; 

 
 
		void initialiser_map(map *Map);
                void initialiser_minimap(minimap *Mmap);
		void afficher_map(map *Map,minimap*Mmap,SDL_Surface *screen,int mouv);
	        
      #endif
