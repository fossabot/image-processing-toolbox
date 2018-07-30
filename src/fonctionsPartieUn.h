/**
 * \file Partie1.h
 * \brief définitions des prototypes des fonctions relatives à la partie 1
 */

#ifndef FONCTIONSPARTIEUN_H
#define FONCTIONSPARTIEUN_H

#include "constantes.h"

/**
 * \fn int** creePalette(DonneesImageRGB *image, int *nombreDeCouleurs)
 * \brief Determine le nombre N de couleurs differentes
 *
 * \param image
 * \param nombreDeCouleurs
 *
 * \return palette
*/
int** creePalette(DonneesImageRGB *image, int *nombreDeCouleurs);

/**
 * \fn int* tableauPalette(int bleu, int vert, int rouge)
 * \brief Stocke les couleurs déterminées dans un tableau Palette
 *
 * \param bleu
 * \param vert
 * \param rouge
 *
 * \return tableau
*/
int* tableauPalette(int bleu, int vert, int rouge);

/**
 * \fn bool testCouleursPalette(int **palette, int bleu, int vert, int rouge, int *nombreDeCouleurs)
 * \brief Test les couleurs du tableau Palette
 *
 * \param palette
 * \param bleu
 * \param vert
 * \param rouge
 * \param nombreDeCouleurs
 *
 * \return boolean
*/
bool testCouleursPalette(int **palette, int bleu, int vert, int rouge, int *nombreDeCouleurs);

/**
 * \fn int** creeMatrice(int **palette, DonneesImageRGB *image, int *nombreDeCouleurs)
 * \brief Transforme le tableau d'octets en une matrice hauteurImage x largeurImage d'entiers
 *
 * \param palette
 * \param image
 * \param nombreDeCouleurs
 *
 * \return matrice
*/
int** creeMatrice(int **palette, DonneesImageRGB *image, int *nombreDeCouleurs);

/**
 * \fn unsigned char* creeImage(int **matrice, int **palette, DonneesImageRGB *image)
 * \brief Transforme une matrice en tableau d'octets
 *
 * \param matrice
 * \param image
 * \param palette
 *
 * \return tableau
*/
unsigned char* creeImage(int **matrice, int **palette, DonneesImageRGB *image);

#endif
