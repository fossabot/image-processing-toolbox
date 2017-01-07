/**
 * \file fonctionsPartieDeux.c
 * \brief fonctions relatives à la partie 2
 */

#include "fonctionsPartieDeux.h"

/*
 * Determine de quelle couleur est le fond (noir/blanc)
 */
bool determineFond(DonneesImageRGB *image)
{
    bool test;
    test=false;

    //Si la premiere case vaut 0
    if(image->donneesRGB[0]==0)
    {
        //fond noir
        test=true;
    }
    else
    {
        //fond blanc
        test=false;
    }
    return (test);
}

/*
 * Cherche le premier point de la matrice qui n'est pas de la couleur du fond
 */
contour* detecteContour(int **matrice, int **palette, DonneesImageRGB *image)
{
    int hauteur=image->hauteurImage;
    int largeur=image->largeurImage;

    contour *traiteContour=malloc(sizeof(contour));

    int h,l;
    h=0;
    l=0;

    for(h=0;h<hauteur;h++)
    {
        for(l=0;l<largeur;l++)
        {
            if(matrice[h][l]!=0)
            {
                traiteContour->couleur=matrice[h][l];
                traiteContour->ptrPoint=creeContour(matrice, image , h, l);

                boiteEnglobante(traiteContour->ptrPoint,traiteContour);

                return (traiteContour);
            }
        }
    }
    return (traiteContour);
}

/*
 * Test si le premier contour existe
 */
bool detectePremierContour(int **matrice, int **palette, DonneesImageRGB *image)
{
    int hauteur=image->hauteurImage;
    int largeur=image->largeurImage;

    int h,l;
    h=0;
    l=0;

    for(h=0;h<hauteur;h++)
    {
        for(l=0;l<largeur;l++)
        {
            //Si différent de 0, on detecte une nouvelle couleur
            if(matrice[h][l]!=0)
            {
                return (true);
            }
        }
    }
    return (false);
}

/*
 * Creer la liste chainée des points du contour correspondant
 * et renvoie la structure contour correspond
 */
point* creeContour(int **matrice, DonneesImageRGB *image, int ligne,int colonne)
{
    int hauteur=image->hauteurImage;
    int largeur=image->largeurImage;

    int couleur=matrice[ligne][colonne];

    point *traitePoint=malloc(sizeof(point));
    traitePoint->y=ligne;
    traitePoint->x=colonne;

    point *neytPoint=malloc(sizeof(point));

    if(matrice[traitePoint->y][traitePoint->x+1]==couleur)
    {
        matrice[traitePoint->y][traitePoint->x+1]=0;
        neytPoint->y=ligne;
        neytPoint->x=colonne+1;
    }
    else if(matrice[traitePoint->y+1][traitePoint->x]==couleur)
    {
        matrice[traitePoint->y+1][traitePoint->x]=0;
        neytPoint->y=ligne+1;
        neytPoint->x=colonne;
    }
    else if(matrice[traitePoint->y-1][traitePoint->x]==couleur)
    {
        matrice[traitePoint->y-1][traitePoint->x]=0;
        neytPoint->y=ligne-1;
        neytPoint->x=colonne;
    }
    else if(matrice[traitePoint->y][traitePoint->x-1]==couleur)
    {
        matrice[traitePoint->y][traitePoint->x-1]=0;
        neytPoint->y=ligne;
        neytPoint->x=colonne-1;
    }

    traitePoint->ptrPoint=neytPoint;

    while((neytPoint->y!=ligne) || (neytPoint->x!=colonne))
    {
        point *currentPoint=neytPoint;
        neytPoint=malloc(sizeof(point));

        printf("\n y:%d  x:%d \n",currentPoint->y,currentPoint->x);

        if((matrice[currentPoint->y+1][currentPoint->x]==couleur) && (currentPoint->y+1<largeur))
        {
            matrice[currentPoint->y+1][currentPoint->x]=0;
            neytPoint->y=currentPoint->y+1;
            neytPoint->x=currentPoint->x;
        }
         else if((matrice[currentPoint->y][currentPoint->x+1]==couleur) && (currentPoint->x+1<hauteur))
        {
            matrice[currentPoint->y][currentPoint->x+1]=0;
            neytPoint->y=currentPoint->y;
            neytPoint->x=currentPoint->x+1;
        }
        else if((matrice[currentPoint->y-1][currentPoint->x]==couleur) && (currentPoint->y-1 >=0))
        {
            matrice[currentPoint->y-1][currentPoint->x]=0;
            neytPoint->y=currentPoint->y-1;
            neytPoint->x=currentPoint->x;
        }
        else if((matrice[currentPoint->y][currentPoint->x-1]==couleur) && (currentPoint->x-1 >=0))
        {
            matrice[currentPoint->y][currentPoint->x-1]=0;
            neytPoint->y=currentPoint->y;
            neytPoint->x=currentPoint->x-1;
        }
        currentPoint->ptrPoint=neytPoint;

    }
    neytPoint->ptrPoint=NULL;

    return (traitePoint);
}

/*
 * Efface le contour au fur et a mesure de sa détection
 */
void boiteEnglobante(point *traitePoint, contour *traiteContour)
{
    point *currentPoint=traitePoint;
    traiteContour->Xmin=currentPoint->x;
    traiteContour->Ymin=currentPoint->y;
    traiteContour->Xmax=currentPoint->x;
    traiteContour->Ymax=currentPoint->y;

    while(currentPoint!=NULL)
    {

        if(currentPoint->x<traiteContour->Xmin)
        {
            traiteContour->Xmin=currentPoint->x;
        }
        if(currentPoint->y<traiteContour->Ymin)
        {
            traiteContour->Ymin=currentPoint->y;
        }
        if(currentPoint->x>traiteContour->Xmax)
        {
            traiteContour->Xmax=currentPoint->x;
        }
        if(currentPoint->y>traiteContour->Ymax)
        {
            traiteContour->Ymax=currentPoint->y;
        }

        currentPoint=currentPoint->ptrPoint;
    }
}

/*
 * Creer la liste chainees des contours
 */
contour* detecteTousLesContours(int **matrice, int **palette, DonneesImageRGB *image)
{
    contour *traiteContour=malloc(sizeof(contour));
    contour *nextContour=malloc(sizeof(contour));
    contour *currentContour=malloc(sizeof(contour));
    int i;
    i=1;

    if(detectePremierContour(matrice,palette,image))
    {
        printf("\n contour n0\n", i);
        traiteContour=detecteContour(matrice,palette,image);
        i++;
    }
    else
    {
        return (NULL);
    }

    currentContour=traiteContour;
    while(detectePremierContour(matrice,palette,image))
    {
        printf("\n contour n%d\n", i);
        nextContour=detecteContour(matrice,palette,image);
        currentContour->ptrContour=nextContour;
        currentContour=nextContour;
        i++;
    }
    nextContour->ptrContour=NULL;

    return (traiteContour);
}

/*
 * Trace un contour dans la matrice à partir d'une liste chainee de points
 */
void traceContour(int **matrice, contour *traiteContour, int indice)
{
    point *currentPoint=traiteContour->ptrPoint;
    while(currentPoint!=NULL)
    {
        matrice[currentPoint->y][currentPoint->x]=indice;
        currentPoint=currentPoint->ptrPoint;
    }
}

/*
 * Parcours la liste de contours
 */
void traceTousLesContours(int **matrice, contour *traiteContour, int indice)
{
    contour *currentContour=traiteContour;
    while(currentContour!=NULL)
    {
        traceContour(matrice,currentContour,indice);
        currentContour=currentContour->ptrContour;
    }
}

/*
 * Liberer toute la mémoire dynamiquement
 */
void libereContour(contour *traiteContour)
{
    contour *currentContour=traiteContour;
    contour *effacerContour;
    while(currentContour!=NULL)
    {
        liberePoint(currentContour->ptrPoint);
        effacerContour=currentContour;
        currentContour=currentContour->ptrContour;
        free(effacerContour);
    }
}

/*
 * Liberer toute la mémoire dynamiquement
 */
void liberePoint(point *traitePoint)
{
    point *currentPoint=traitePoint;
    point *effacerPoint;
    while(currentPoint!=NULL)
    {
        effacerPoint=currentPoint;
        currentPoint=currentPoint->ptrPoint;
        free(effacerPoint);
    }
}
