/*Choix difficultés et tableau aléatoire*/
#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include"difficulty_tableau.h"

int difficulty(int* pointeurlongueurmax, int* pointeurhauteurmax)
{
	int flag=0;
	int x=_X;
	int y=_Y;
	int res;
	InitialiserGraphique();
	CreerFenetre(50,50,1000,500);
	EcrireTexte(450,100,"Facile",2);/*Inscription du premier bouton*/
	EcrireTexte(450,250,"Moyen",2);/*Inscription du deuxième bouton*/
	EcrireTexte(450,400,"Difficile",2);/*Inscription du troisième bouton*/
	EcrireTexte(625,480,"Appuyez sur Escape (Esc) pour quitter",1);

	DessinerRectangle(400,50,200,100); /*Bouton mode facile*/
	DessinerRectangle(400,200,200,100); /*Bouton mode moyen*/
	DessinerRectangle(400,350,200,100); /*Bouton mode difficile*/
	while(flag==0) {

		if (SourisCliquee())
		{
			x=_X;
			y=_Y;

			if (button(400,50,200,100)==1)
			{
				res=16;
				*pointeurlongueurmax=500; /*4x4*/
				*pointeurhauteurmax=500;
				return res;
			}

			if (button(400,200,200,100)==1)
			{
				res=30;
				*pointeurlongueurmax=700; /*6x5*/
				*pointeurhauteurmax=600;
				return res;
			}

			if (button(400,350,200,100)==1)
			{
				res=42;
				*pointeurlongueurmax=800; /*7x6*/
				*pointeurhauteurmax=700;
				return res;
			}
		}
		if (ToucheEnAttente())
		{
			if (Touche()==XK_Escape)
			{
				flag=1;
				res=0;
				return res;
			}
		}
						}
}

int button(int x,int y,int l,int h)
{
	int res;
	int coor_x=_X;
	int coor_y=_Y;

	if (((coor_x <=l+x) && (coor_x >=x)) && ((coor_y <= h+y) && (coor_y >=y))) {

		res=1;
	}
	else {
		res=0;
	}
	return res;
}

/*Fonction permettant de pouvoir avoir avoir une action dans un ensemble de coordonnée qui seront fournie en argument par la coordonnée x de départ, le y de départ, la longueur et la hauteur.
elle renvoie un booléen. 1 si c'est dans l'intervalle de coordonnée et 0 si c'est hors des coordonnée.*/





void remplisseur_tableau(int taille,int tab[])
{
	for (int i = 0; i < taille; ++i)
	{
		tab[i]= i/2;
	}
}
/*Fonction ayant pour but de remplir un tableau avec une taille donner qui lui est fournie en argument. Le but de cette fonction
est de remplir ce tableau avec une valeur présente 2 fois et seulement 2 fois.*/

void melanger(int taille, int tab[])
{
	int nb1;
	int nb2;
	int i;
	int temp;

	for (i = 0; i<600;i++)
		{
			nb1 = rand()%taille;
			nb2 = rand()%taille;

			temp = tab[nb1];
			tab[nb1] = tab[nb2];
			tab[nb2] =temp;
		}
}
/*Fonction ayant pour but de mélanger les valeurs dans le tableau. Elle mélange le tableau de manière aléatoire avec des valeurs prit du rand. valeur séléctionner aléatoirement dans l'ensemble des cases
du tableau fournie en argument ainsi que sa taille.*/
