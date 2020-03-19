#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include<time.h>
#include "difficulty_tableau.h"
#include "graphismes.h"
#include "chrono_triche.h"

int main(void)
{
	int NB;
	int longueurmax;
  	int hauteurmax;
while (True) /*<- boucle infinie, le seul moyen d'en sortir est par le bouton esc dans difficulty*/
	{
	NB=difficulty(&longueurmax,&hauteurmax);
	int tableau[NB];

		FermerGraphique();
if (NB==0) {
		return EXIT_SUCCESS;
	}
			/*Tableau aléatoire: difficulty_tableau.c*/
			remplisseur_tableau(NB,tableau);
			srand(time(NULL));
			melanger(NB,tableau);

	int flag[NB]; /*Tableau de flags: graphismes.c*/
	int jeu=0;
	int nombredeclics = 0;

	int flagtriche;	/*Triche*/
	unsigned long duree,tmpsiniduree;
	int entreememorisation;

		unsigned int tmpsini, tmps, enregistreur; /*Chrono, initialisation; chrono_triche.c*/
		tmpsini = temps();
		tmps= chrono(tmpsini);

	couleur cache;
	cache=CouleurParComposante(255,255,255);

	initiaflag(NB,flag);

InitialiserGraphique();
CreerFenetre(10,10,longueurmax+150,hauteurmax+100);

	  while ((jeu == 0)) { /*boucle "infinie" pour le jeu*/

		enregistreur=tmps; /*Chrono, réitération*/
		tmps=chrono(tmpsini);
		if (enregistreur!=tmps)
		{
		ChoisirCouleurDessin(cache);
		RemplirRectangle(30,20,100,60); /*cache chrono*/
		affichagechrono(tmps); /*chrono_triche.c*/
		}
				/*Graphismes: graphismes.c*/
	    	images(flag,tableau,longueurmax,hauteurmax);
	  nombredeclics=sourisclic(nombredeclics,flag,longueurmax,hauteurmax);

		if (nombredeclics==2) {
		images(flag,tableau,longueurmax,hauteurmax); /*si on clique deux fois il faut afficher la carte du deuxième clique*/

				entreememorisation=completeurflag(NB,flag,tableau,&jeu); /*<- Correction des flags: graphismes.c*/
				/*on entre dans la memorisation si l'utilisateur n'a pas fait une paire bonne*/
				if (entreememorisation!=0) {
				tmpsiniduree=temps_memorisation();
				do {
				 	duree=temps_memorisation();
				 	duree=duree-tmpsiniduree;
				 	
				 	enregistreur=tmps;
				 	tmps=chrono(tmpsini);
				 	
				 	if (enregistreur!=tmps) {
				 	ChoisirCouleurDessin(cache);
				 	RemplirRectangle(30,20,100,60);
				 	affichagechrono(tmps);
				 	}
				 	
				 	vider_tampon();
				   } while (duree<1000000); /*temps de mémorisation, on reste bloqué dans cette boucle, on ne peut rien faire*/
				}

		nombredeclics=0;
		}

		if (ToucheEnAttente()) { /*Triche: chrono_triche.c*/
		if ((Touche()==XK_t)||(Touche()==XK_T)) { /*on touche une fois t*/
		flagtriche=0;
		duree=0;
			tmpsiniduree=temps();
			while (flagtriche==0) {	
				flagtriche=triche(tableau,longueurmax,hauteurmax,NB);
				vider_tampon();
				} 
				duree=chrono(tmpsiniduree);	/*temps de la triche ajouté au temps initial et moins la durée du jeu*/
				tmpsini=(tmpsiniduree+duree)-tmps;
			}

		}

 		}
		FermerGraphique();
	}
}
