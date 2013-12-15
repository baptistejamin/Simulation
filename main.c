/**
* @file project.c
* @author Baptiste JAMIN , Oc�ane GARIN
* @date Janvier 2013
* @brief Simulation de d�placement de population
*/

#include "fonctions.h"
#include "fonctions.c"

/**
*	@brief	Fonction principale, s'ex�cute en premier
*	@param  argc {repr�sentant nombre param�tres}
*	@param  argv[] {repr�sentant les parametres sous forme de tableau chaine de caract�re}
*	@return 0 {Si les medecins gagnent}
*	@return 1 {Si les zombies gagnent}
*/
int	main(int argc, char * argv[]){
	
unsigned short int i = 0;

srand(time(NULL));

if (argc>1)
{
	initialisationParametres(argc,argv); //On initialise les param�tres
}

initialisation();

if (SILENT==0) //Si le param�tre -silent n'est pas pr�cis�, alors on affiche ces messages:
{
	printf("Demarrage du jeu...\n");
}

while((infectes != (SAINS+ZOMBIES)) && (infectes != 0))
{
	if (i==DOCTEURS+SAINS+ZOMBIES) { i=0;}
	
	if (NO_CARTE==0) //Si le param�tre -no_carte n'est pas pr�cis�, alors affiche la carte:
	{
		Affichage();
	}
	
	//On d�place le personnage
	Deplacer(i,ValiderDeplacement(i));
	//On v�rifie si quelqu'un se trouve sur le case
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