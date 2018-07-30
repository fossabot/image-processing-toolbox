/**
 * \file fonctionsPartieUn.c
 * \brief fonctions relatives à la partie 1
 */

#include "fonctionsPartieUn.h"

/*
 * Determine le nombre N de couleurs differentes dans le tableau precedent,
 * et stocke ces couleurs dans un tableau Palette de 3 lignes et N colonnes
 */
int** creePalette(DonneesImageRGB *image, int *nombreDeCouleurs)
{
    int hauteur=image->hauteurImage;
    int largeur=image->largeurImage;

    int **palette;
    int h,l,compteur;
    h=0;
    l=0;
    compteur=0;

    //Parcours des colonnes
    for(h=0;h<hauteur;h++)
    {
        //Parcours des lignes
        for(l=0;l<largeur;l++)
        {
            //Si le nombre de couleur est nulle
            if(*nombreDeCouleurs==0)
            {
                //On cree notre palette
                palette=malloc(sizeof(int*));
                palette[0]=tableauPalette(image->donneesRGB[compteur],image->donneesRGB[compteur+1],image->donneesRGB[compteur+2]);
                (*nombreDeCouleurs)++;
            }
            else
            {
                //Si la couleur existe dans la palette
                if(testCouleursPalette(palette,image->donneesRGB[compteur],image->donneesRGB[compteur+1],image->donneesRGB[compteur+2], nombreDeCouleurs))
                {
                    //On modifie la taille de notre palette
                    palette=realloc(palette,((*nombreDeCouleurs)+1)*sizeof(int*));
                    palette[*nombreDeCouleurs]=tableauPalette(image->donneesRGB[compteur],image->donneesRGB[compteur+1],image->donneesRGB[compteur+2]);
                    (*nombreDeCouleurs)++;
                }
            }
            compteur=compteur+3;
        }
    }
    return (palette);
}

/*
 * Stocke les couleurs déterminées dans le tableau
 * d'octets précédents dans un tableau palette de
 * 3 lignes (bleu, vert, rouge)
 */
int* tableauPalette(int bleu, int vert, int rouge)
{
    //On cree notre tableau contenant les couleurs BVR
    int *tableau=(int*)malloc(3*sizeof(int));
    tableau[0]=bleu;
    tableau[1]=vert;
    tableau[2]=rouge;

    return (tableau);
}

/*
 * Test les couleurs du tableau palette
 */
bool testCouleursPalette(int **palette, int bleu, int vert, int rouge, int *nombreDeCouleurs)
{
    int i;
    i=0;
    int *couleur;
    couleur=NULL;

    for(i=0;i<*nombreDeCouleurs;i++)
    {
        couleur=palette[i];
        //Si la couleur existe déjà
        if((couleur[0]==bleu)&&(couleur[1]==vert)&&(couleur[2]==rouge))
        {
            return (false);
        }
    }
    return (true);
}

/*
 * Transforme le tableau d'octets en une matrice hauteurImage x largeurImage d'entiers
 * La valeur entiere stockée dans la matrice sera l'indice dans Palette, correspondant
 * à la couleur du point.
 */
int** creeMatrice(int **palette, DonneesImageRGB *image, int *nombreDeCouleurs)
{
    int hauteur=image->hauteurImage;
    int largeur=image->largeurImage;

    int h,l,nb,compteur;
    h=0;
    l=0;
    nb=0;
    compteur=0;
    int *couleur;
    couleur=NULL;
    bool verif;
    verif=true;

    //On cree une matrice suivant hauteurImage
    int **matrice=malloc((hauteur)*sizeof(*matrice));

    //Parcours les colonnes
    for(h=0;h<hauteur;h++)
    {
        //On cree une matrice suivant largeurImage
        matrice[h]=(int *)malloc((largeur)*sizeof(**matrice));

        //Parcours les lignes
        for(l=0;l<largeur;l++)
        {
            //Parcours du nombre de couleurs
            for(nb=0;nb<(*nombreDeCouleurs);nb++)
            {
                couleur=palette[nb];
                //Si la couleur existe déjà
                if((verif)&&(couleur[0]==image->donneesRGB[compteur])&&(couleur[1]==image->donneesRGB[compteur+1])&&(couleur[2]==image->donneesRGB[compteur+2]))
                {
                    compteur=compteur+3;
                    verif=false;
                    matrice[h][l]=nb;
                }
            }
            verif=true;
        }
    }
    return (matrice);
}

/*
 * Transforme une matrice en tableau d'octets, grâce à Palette
 */
unsigned char* creeImage(int **matrice, int **palette, DonneesImageRGB *image)
{
    int hauteur=image->hauteurImage;
    int largeur=image->largeurImage;
    int h,l,compteur,id;
    h=0;
    l=0;
    compteur=0;
    id=0;
    int *couleur;
    couleur=NULL;

    //On cree un tableau suivant la hauteur et largeur de l'image
    unsigned char *tableau=malloc(3*(hauteur)*(largeur)*sizeof(unsigned char));

    //Parcours les colonnes
    for(h=0;h<hauteur;h++)
    {
        //Parcours les lignes
        for(l=0;l<largeur;l++)
        {
            id=matrice[h][l];
            couleur=palette[id];
            tableau[compteur]=couleur[0];
            tableau[compteur+1]=couleur[1];
            tableau[compteur+2]=couleur[2];
            compteur=compteur+3;
        }
    }
    return (tableau);
}
