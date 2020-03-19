/* PT11_APL2018 : fichier graphismes.h */

#ifndef GRAPHISMES_H
#define GRAPHISMES_H

void initiaflag(int NB,int flag[]);

void images(int flag[],int tableau[],int longueurmax, int hauteurmax);

int sourisclic(int nombredeclics,int flag[],int longueurmax, int hauteurmax);
int completeurflag (int NB,int flag[],int tableau[],int* pointeurjeu);
#endif /* GRAPHISMES_H */
