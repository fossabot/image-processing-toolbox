/**
 * \file main.c
 * \brief fonction principale du projet
 */

#include "fonctionsPartieUn.h"
#include "fonctionsPartieDeux.h"
#include "fonctionsPartieTrois.h"

/**
 *\fn  int main(int argc, char **argv)
 * \brief premier fonction utilisée au lancement du programme
 *
 * \param argc nombre de chaine contenue dans argv
 * \param argv argument pour lancer le programme
 *
 * \return 0 si le programme c'est bien exécutée
 */
int main(int argc, char **argv)
{
    DonneesImageRGB *image;
    char nomImage[30];
    int nombreDeCouleurs=0;
    contour *traiteContour;
    int *couleur;
    int i,j;

    /** PARTIE I **/
    printf("PARTIE I \n\n");

    //Recupere le contenue d'une image BMP dans un tableau d'octet
    printf("nom du fichier : ");
    scanf("%s",nomImage);
    image=lisBMPRGB(nomImage);
    printf("\n\n");

    //Infos sur l'image
    printf("Informations sur la taille de l'image\n");
    printf("hauteur : %d \n", image->hauteurImage);
    printf("largeur : %d \n", image->largeurImage);
    printf("\n\n");

    //Creer la palette
    printf("Creation de la palette\n");
    int** palette=creePalette(image,&nombreDeCouleurs);
    for(i=0;i<nombreDeCouleurs;i++)
    {
        couleur=palette[i];
        printf("couleur%d -> bleu:%d vert:%d rouge:%d adresse:%d\n", i, couleur[0],couleur[1],couleur[2],palette[i]);
    }
        printf("Nombre de couleurs detectees: %d \n", nombreDeCouleurs);
        printf("\n\n");

        //Transforme le tableau d'octets en matrice
        printf("Transformation du tableau d'octets en matrice\n");
        int **matrice=creeMatrice(palette,image,&nombreDeCouleurs);
        //affiche la matrice
        for(i=0;i<image->hauteurImage;i++)
        {
            for(j=0;j<image->largeurImage;j++)
            {
                printf("%d\t",matrice[i][j]);
            }
            printf("\n");
        }
        printf("\n\n");

        //Transforme la matrice en tableau d'octets
        //Sauvergade le tableau d'octets dans une second image BMP
        printf("Transformation la matrice en tableau d'octets\n");
        printf("Sauvegarde du tableau d'octets dans une seconde image BMP\n");
        DonneesImageRGB *secondeImage =(DonneesImageRGB*)calloc(1, sizeof(DonneesImageRGB));
        unsigned char *tableauSecondeImage=creeImage(matrice,palette,image);
        secondeImage->donneesRGB=tableauSecondeImage;
        secondeImage->hauteurImage=image->hauteurImage;
        secondeImage->largeurImage=image->largeurImage;
        printf("nom du fichier : ");
        scanf("%s",nomImage);
        printf("\n");
        if(ecrisBMPRGB_Dans(secondeImage, nomImage))
        {
            printf("image sauvergadee\n");
            system(nomImage);
        }
        free(secondeImage);
        secondeImage=NULL;
        printf("\n\n\n");

        /** PARTIE II **/
        printf("PARTIE II \n\n");
        DonneesImageRGB *troisiemeImage =(DonneesImageRGB*)calloc(1, sizeof(DonneesImageRGB));
        unsigned char *tableauTroisiemeImage=creeImage(matrice,palette,image);
        troisiemeImage->hauteurImage=image->hauteurImage;
        troisiemeImage->largeurImage=image->largeurImage;

        printf("Determiner le fond de l'image BMP\n");
        if(determineFond(image))
        {
            printf("Le fond de l'image est noir\n");

            if(detectePremierContour(matrice, palette, image))
            {
                printf("Contour detecte\n");
                printf("Votre image a un contour\n");

                traiteContour=detecteTousLesContours(matrice, palette, image);
                traceTousLesContours(matrice, traiteContour, 2);

                tableauTroisiemeImage=creeImage(matrice, palette, image);
                troisiemeImage->donneesRGB=tableauTroisiemeImage;

                printf("nom du fichier : ");
                scanf("%s",nomImage);
                printf("\n");
                if(ecrisBMPRGB_Dans(troisiemeImage, nomImage))
                {
                    printf("Image sauvegardee \n");
                    system(nomImage);
                }
            }
            else
            {
                printf("Aucun contour detectee");
            }
        }
        else
        {
            printf("Le fond de l'image est blanc\n");
        }
        printf("\n\n\n");

        /** PARTIE III **/

    return (0);
}
