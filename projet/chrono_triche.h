/* PT11_APL2018 : fichier chrono_triche.h */

#ifndef CHRONO_H
#define CHRONO_H

unsigned int temps(void);
unsigned int chrono(unsigned int tmpsini);
void affichagechrono(unsigned int tmps);

unsigned long temps_memorisation();

void vider_tampon();
int triche ( int tableau[], int longueurmax, int hauteurmax, int NB);
#endif /* CHRONO_TRICHE_H */
