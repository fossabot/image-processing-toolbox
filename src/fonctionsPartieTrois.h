/**
 * \file Partie3.h
 * \brief définitions des prototypes des fonctions relatives à la partie 3
 */

#ifndef FONCTIONSPARTIETROIS_H
#define FONCTIONSPARTIETROIS_H

#include "fonctionsPartieDeux.h"
#include "constantes.h"

/**
 * \struct noeud
 * \brief structure d'un noeud de l'arbre
 */
typedef struct noeud
{
    contour c;
    struct noeud *filsgauche;
    struct noeud *filsdroit;
}noeud;

/**
 * \struct arbre
 * \brief structure d'un arbre
 */
typedef struct arbre
{
    int DimX;
    int DimY;
    int fond;
    noeud* racine;
}arbre;

arbre* creeArbre(contour *traiteContour, DonneesImageRGB *image, int indice);
noeud* creeArbreRecursif(noeud *racine, noeud *traiteNoeud);
bool testNoeudFils(contour c1, contour c2);
noeud* creeNoeud(contour c);
int nombreDeContour(contour c);

#endif
