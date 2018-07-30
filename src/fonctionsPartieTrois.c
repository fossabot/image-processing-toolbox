/**
 * \file fonctionsPartieTrois.c
 * \brief fonctions relatives à la partie 3
 */

#include "fonctionsPartieTrois.h"

/*
PARTIE 3, NON FONCTIONNELLES
arbre* creeArbre(contour* traiteContour, DonneesImageRGB* image, int indice)
{
    int hauteur=image->hauteurImage;
    int largeur=image->largeurImage;

    arbre* traiteArbre=malloc(sizeof(arbre));
    traiteArbre->hauteur=hauteur;
    traiteArbre->largeur=largeur;
    traiteArbre->indice=indice;

    int nombreContour=nombreDeContour(traiteContour);

    noeud *racine= creeNoeud(traiteContour);
    contour *contourActuel=traiteContour->ptrContour;

    while(contourActuel!=NULL)
    {
        noeud *traiteNoeud= creeNoeud(contourActuel);
        if(testNoeudFils(racine->contourNoeud, contourActuel))
        {
            if(racine->noeud1==NULL && racine->noeud2==NULL)
            {
                racine->noeud1=traiteNoeud;
            }
            else if(racine->noeud1!=NULL && racine->noeud2==NULL && !testNoeudFils(racine->noeud1->contourNoeud,contourActuel))
            {
                racine->noeud2=traiteNoeud;
            }
            else if(racine->noeud1!=NULL && testNoeudFils(racine->noeud1->contourNoeud,contourActuel))
            {
                racine->noeud1=creeArbreRecursif(racine->noeud1,traiteNoeud);
            }
            else if(racine->noeud2!=NULL &&  testNoeudFils(racine->noeud2->contourNoeud,contourActuel))
            {
                racine->noeud2=creeArbreRecursif(racine->noeud2,traiteNoeud);
            }
            else
            {
                if(racine->noeud1!=NULL && racine->noeud2!=NULL && testNoeudFils(contourActuel,racine->noeud1->contourNoeud) && testNoeudFils(contourActuel,racine->noeud2->contourNoeud))
                {
                    traiteNoeud->noeud1=racine->noeud1;
                    traiteNoeud->noeud2=racine->noeud2;
                    racine->noeud1=traiteNoeud;
                    racine->noeud2=NULL;
                }
                if(racine->noeud1!=NULL && testNoeudFils(contourActuel,racine->noeud1->contourNoeud))
                {
                    traiteNoeud->noeud1=racine->noeud1;
                    racine->noeud1=traiteNoeud;
                }
                else if(racine->noeud2!=NULL && testNoeudFils(contourActuel,racine->noeud2->contourNoeud))
                {
                    traiteNoeud->noeud2=racine->noeud2;
                    racine->noeud2=traiteNoeud;
                }
                else
                {
                    printf("erreur");
                }
            }

        }
        else
        {
            traiteNoeud->noeud1=racine;
            racine=traiteNoeud;
        }
        contourActuel=contourActuel->ptrContour;
   }
    traiteArbre->racine=racine;
    return (traiteArbre);
}

noeud* creeArbreRecursif(noeud *racine,noeud *traiteNoeud)
{
    if(testNoeudFils(racine->contourNoeud, traiteNoeud->contourNoeud))
        {
            if(racine->noeud1==NULL && racine->noeud2==NULL)
            {
                racine->noeud1=traiteNoeud;
            }
            else if(racine->noeud1!=NULL && racine->noeud2==NULL && !testNoeudFils(racine->noeud1->contourNoeud,traiteNoeud->contourNoeud))
            {
                racine->noeud2=traiteNoeud;
            }
            else if(racine->noeud1!=NULL && testNoeudFils(racine->noeud1->contourNoeud,traiteNoeud->contourNoeud))
            {
                racine->noeud1=creeArbreRecursif(racine->noeud1,traiteNoeud);
            }
            else if(racine->noeud2!=NULL &&  testNoeudFils(racine->noeud2->contourNoeud,traiteNoeud->contourNoeud))
            {
                racine->noeud2=creeArbreRecursif(racine->noeud2,traiteNoeud);

            }
            else

                if(racine->noeud1!=NULL && racine->noeud2!=NULL && testNoeudFils(traiteNoeud->contourNoeud,racine->noeud1->contourNoeud) && testNoeudFils(noeudCourant->contourNoeud,racine->noeud2->contourNoeud))
                {
                    traiteNoeud->noeud1=racine->noeud1;
                    traiteNoeud->noeud2=racine->noeud2;
                    racine->noeud1=traiteNoeud;
                    racine->noeud2=NULL;
                }
                if(racine->noeud1!=NULL && testNoeudFils(traiteNoeud->contourNoeud,racine->noeud1->contourNoeud))
                {
                    traiteNoeud->noeud1=racine->noeud1;
                    racine->noeud1=traiteNoeud;
                }
                else if(racine->noeud2!=NULL && testNoeudFils(traiteNoeud->contourNoeud,racine->noeud2->contourNoeud))
                {
                    traiteNoeud->noeud2=racine->noeud2;
                    racine->noeud2=traiteNoeud;
                }
                else
                {
                    printf("erreur");
                }
            }

        }
        else
        {
            traiteNoeud->noeud1=racine;
            racine=traiteNoeud;
        }

    return (racine);
}
*/
