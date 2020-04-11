/*Interface graphique et tableau des flags*/
#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "graphismes.h"
#include "chrono_triche.h"

#define l 100 /*l et h sont en define car elles sont les tailles des cartes et elles ne changent pas*/
#define h 80

void initiaflag(int NB,int flag[]) {/*Initialisation flag. Attention par exemple le flag n°2 vaut la carte 3 graphiquement car tout commence à 0*/
int i;
    for (i = 0; i < NB; ++i)
  {
    flag[i]=0;
    }
  }

void images(int flag[], int tableau[], int longueurmax, int hauteurmax) {/*prise des caches depuis fenêtre 1 et les images sont mises en fonction des flags*/
  int x, y;
  int i, cadre;
  int ini;
  char buffer [30];
  ini=100;
  y=ini;    x=ini;	i=0;

  cadre=CouleurParComposante(64, 97, 164);

  for ( ; y < hauteurmax ; y=y+100)
  {
  		for ( ; x < longueurmax; x=x+100)
  		{
  			ChoisirCouleurDessin(cadre);
          	DessinerRectangle (x,y,100,80);

        if (flag[i]==0) { //caches//
  			ChargerImage("./Images/Fondcarton.png",x,y,0,0,l,h); }
                       //images//
  			else {
  				sprintf (buffer, "./Images/imageschiffres/%d.png", tableau[i]);
              	ChargerImage(buffer,x,y,0,0,l,h);	}

  			i++;

  			x=x+10; //séparateur cases//
  		}
  		x=ini;
  }

}

int sourisclic(int nombredeclics , int flag[], int longueurmax, int hauteurmax) {
int x, y;
int i;
int ini;
int xclic, yclic;
ini=100;
y=ini;    x=ini;	i=0;

  if(SourisCliquee())   {
    xclic=_X;
    yclic=_Y;
    /*printf("%d %d \n", xclic, yclic); <-- numeros positions sur le terminal*/

    for ( ; y < hauteurmax ; y=y+100)
    {
      for ( ; x < longueurmax; x=x+100)
      {
        if ((xclic>	x )&&(xclic< x+ l ) && (yclic> y )&&(yclic< y+ h ))
          { if (flag[i]==0) {nombredeclics++;} flag[i]=1;  }
            /* ^ pour éviter les double clic*/
      i++;

      x=x+10; //séparateur cases//
      }
     x=ini;
     }

   }
    return nombredeclics;
}

int completeurflag (int NB,int flag[],int tableau[], int* pointeurjeu) {
/*fonction qui sert à "nettoyer" le tableau de flags, dés qu'il y a eut plus de 2 clics on corrige ce que l'utilisateur a cliqué*/
  int i, imax , j;
    imax=NB/2; /*NB/2 car c'est le n° max des cartes*/
  int compteur, sauvgardeurj;
  int compteurdepasbon=0;
  
  for ( i = 0; i < imax; i++) { /*boucle n° carte*/

    for (j = 0, compteur = 0 ; j < NB; j++) {
      if ((i==tableau[j])&&(flag[j]==1))
      {
        compteur++; sauvgardeurj=j;
      }
    }
      /*si ce que l'utlisateur a entré est bon, le tableau de flag garde pour toujours les deux 1*/
      if (compteur==1) {
         flag[sauvgardeurj]=0;
         compteurdepasbon++;
      }
   }
   int compteurde1=0;
   /*vérificateur pour savoir si l'utilisateur a terminé le jeu*/
   for ( i = 0; i < NB; ++i)
   {
   	if (flag[i]==1) {
   		compteurde1++;
    }
   }
   if (compteurde1==NB) {
     *pointeurjeu=1;
   }
   /*comment ça marche:
   on cherche n° par n° (boucle principale)
   -si- la valeur de la case est égale au n° de la carte qu'on cherche
   -et- dés qu'on trouve un 1
    on enregistre sa position, et on compte combien on a eu de cas qui valident le -si- et le -et-
   après avoir cherché sur tous les flags
    si le compteur n'a trouvé qu'un 1 pour ce numéro on le remet à 0: on retourne la case, on a corrigé l'erreur de l'utilisateur*/
   
   return compteurdepasbon; /*permet de compter s'il y eut des erreurs*/
}
