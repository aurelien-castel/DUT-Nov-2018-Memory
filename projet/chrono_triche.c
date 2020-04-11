/*Chronomètre et Triche*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graph.h>
#include "chrono_triche.h"
#include "graphismes.h"

unsigned int temps(void)
{ unsigned int tmps;

	tmps=time(NULL);

				return tmps; /*retourne le temps depuis l'ordinateur, compte de secondes en secondes*/
}

unsigned int chrono(unsigned int tmpsini)
{	unsigned int tmpscourant;
	tmpscourant = temps();
	return tmpscourant-tmpsini; /*retourne une durée de secondes*/
}

void affichagechrono(unsigned int tmps) {
char buffer [11];
couleur chiffre;
	chiffre=CouleurParComposante(102,82,27);
	ChoisirCouleurDessin(chiffre);
	sprintf (buffer, "%u", tmps);
	EcrireTexte(50,50,buffer,2);
}

unsigned long temps_memorisation() {
unsigned long petittemps;
petittemps=Microsecondes();
return petittemps;
}



void vider_tampon() {

while (SourisCliquee()) {
	SourisCliquee();
}

while (ToucheEnAttente()) {
	Touche();
}

}

int triche ( int tableau[], int longueurmax, int hauteurmax, int NB) {
int flagtriche;
int flagde1[NB];

for (int i = 0; i < NB ; ++i)
{
	flagde1[i]=1;
}

images(flagde1,tableau,longueurmax,hauteurmax);

if ((Touche()==XK_t)||(Touche()==XK_T)) { /*on attend que l'utilisateur réappuie*/
	flagtriche=1;
	return flagtriche;
	}
}
