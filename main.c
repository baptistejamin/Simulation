/**
* @file project.c
* @author Baptiste JAMIN , Océane GARIN
* @date Janvier 2013
* @brief Simulation de déplacement de population
*/

#include "fonctions.h"
#include "fonctions.c"

/**
*	@brief	Fonction principale, s'exécute en premier
*	@param  argc {représentant nombre paramètres}
*	@param  argv[] {représentant les parametres sous forme de tableau chaine de caractère}
*	@return 0 {Si les medecins gagnent}
*	@return 1 {Si les zombies gagnent}
*/
int	main(int argc, char * argv[]){
	
unsigned short int i = 0;

srand(time(NULL));

if (argc>1)
{
	initialisationParametres(argc,argv); //On initialise les paramètres
}

initialisation();

if (SILENT==0) //Si le paramètre -silent n'est pas précisé, alors on affiche ces messages:
{
	printf("Demarrage du jeu...\n");
}

while((infectes != (SAINS+ZOMBIES)) && (infectes != 0))
{
	if (i==DOCTEURS+SAINS+ZOMBIES) { i=0;}
	
	if (NO_CARTE==0) //Si le paramètre -no_carte n'est pas précisé, alors affiche la carte:
	{
		Affichage();
	}
	
	//On déplace le personnage
	Deplacer(i,ValiderDeplacement(i));
	//On vérifie si quelqu'un se trouve sur le case
	Verifier(i);
	
	//if (NO_SLEEP ==0)
	//{
		//Sleep();
	//}
	
	i++;
}

	if (infectes==0)
	{
		printf("Les medecins gagnent\n");
		return 0;
	}
	else
	{ 
		printf("Les zombies gagnent\n");
		return 1;
	}
}