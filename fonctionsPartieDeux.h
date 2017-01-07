/**
 * \file Partie2.h
 * \brief définitions des prototypes des fonctions relatives à la partie 2
 */

#ifndef FONCTIONSPARTIEDEUX_H
#define FONCTIONSPARTIEDEUX_H

#include "constantes.h"

/**
 * \struct point
 * \brief coordonnées d'un point dans la matrice
 */
typedef struct point
{
    int x; /*!<abcisse de la matrice */
    int y; /*!<ordonnées de la matrice */
    struct point *ptrPoint; /*!<pointeur sur structure point */
}point;

/**
 * \struct contour
 * \brief structure d'un contour
 */
typedef struct contour
{
    int couleur; /*!<couleur d'un contour */
    point *ptrPoint; /*!<pointeur sur structure point */
    int Xmin; /*!<Xmin du rectangle englobant */
    int Ymin; /*!<Ymin du rectangle englobant */
    int Xmax; /*!<Xmax du rectangle englobant */
    int Ymax; /*!<Ymax du rectangle englobant */
    struct contour *ptrContour; /*!<pointeur sur structure contour */
}contour;

/**
 * \fn bool determineFond(DonnesImageRGB *image)
 * \brief Determine la couleur du fond
 *
 * \param image
 *
 * \return boolean
 */
bool determineFond(DonneesImageRGB *image);

/**
 * \fn contour* detecteContour(int **matrice, int **palette, DonneesImageRGB *image)
 * \brief Cherche le premier point de la matrice qui n'est pas de la couleur du fond
 *
 * \param matrice
 * \param palette
 * \param image
 *
 * \return contour
 */
contour* detecteContour(int **matrice,int **palette,DonneesImageRGB *image);

/**
 * \fn bool detectePremierContour(int **matrice, int **palette, DonneesImageRGB *image)
 * \brief Test si le premier contour existe
 *
 * \param matrice
 * \param palette
 * \param image
 *
 * \return boolean
 */
bool detectePremierContour(int **matrice, int **palette, DonneesImageRGB *image);

/**
 * \fn point* creeContour(int **matrice, DonneesImageRGB *image, int ligne, int colonne)
 * \brief Creer la liste chainée des points du contour correspondant
 *
 * \param matrice liste chainée de points
 * \param image
 * \param ligne
 * \param colonne
 *
 * \return point
 */
point* creeContour(int **matrice, DonneesImageRGB *image, int ligne, int colonne);

/**
 * \fn void boiteEnglobante(point *traitePoint, contour *traiteContour)
 * \brief Efface le contour au fur et à mesure de sa détection
 *
 * \param traitePoint
 * \param traiteContour
 */
void boiteEnglobante(point *traitePoint, contour *traiteContour);

/**
 * \fn contour* detecteTousLesContours(int **matrice, int **palette, DonneesImageRGB *image)
 * \brief Creer la liste chainée des contours
 *
 * \param matrice
 * \param palette
 * \param image
 *
 * \return contour
 */
contour* detecteTousLesContours(int **matrice, int **palette, DonneesImageRGB *image);

/**
 * \fn void traceContour(int **matrice, contour *traiteContour, int indice)
 * \brief Trace un contour dans la matrice
 *
 * \param matrice
 * \param traiteContour
 * \param indice
 */
void traceContour(int **matrice, contour *traiteContour, int indice);

/**
 * \fn void traceTousLesContours(int **matrice, contour *traiteContour, int indice)
 * \brief Parcours la liste des contours et trace tous les contours
 *        dans la matrice
 *
 * \param matrice liste chainée de points
 * \param traiteContour
 * \param image l'image à traiter
 */
void traceTousLesContours(int **matrice, contour *traiteContour, int indice);

/**
 * \fn void libereContours(contour *traiteContour)
 * \brief Libere la mémoire allouée dynamiquement
 *
 * \param traiteContour
 */
void libereContour(contour *traiteContour);

/**
 * \fn void liberePoint(point *traitePoint)
 * \brief Libere la mémoire allouée dynamiquement
 *
 * \param traitePoint
 */
void liberePoint(point *traitePoint);

#endif
