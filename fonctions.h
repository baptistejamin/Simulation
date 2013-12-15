/**
* @file fonctions.h
* @author Baptiste JAMIN , Oc�ane GARIN
* @date Janvier 2013
* @brief Simulation de d�placement de population
*/

#include	<time.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>

/**
*@brief Indique le nombre de d�placements possibles
*/
#define DEPLACEMENTS 4
/**
*@brief Nombre g�n�rique pour d�clarer la taille maximale des tableaux
*/
#define TAILLE_TABLEAU 50

unsigned short int SIZE = 50; /*!< Indique la taille de la carte */

unsigned short int DOCTEURS = 2; /*!< Indique le nombre de docteurs */

unsigned short int SAINS = 6; /*!< Indique le nombre de personnages sains */

unsigned short int ZOMBIES = 6;  /*!< Indique le nombre de zombies */

unsigned short int VACCINS = 5; /*!< Indique le nombre de vaccins par docteur */

unsigned short int SILENT = 0; /*!< Variable qui sert � afficher ou non les massages */

unsigned short int NO_SLEEP = 0; /*!< Variable qui sert � supprimer ou non le d�lai d'attente */

unsigned short int NO_CARTE = 0; /*!< Variable qui sert � supprimer l'affichage de la carte */

short int infectes; /*!< indique le nombre de personnages infect�s */

/**
* @brief Structure repr�sentant les personnages
*/
struct type_personnage {
	short int type; /*!< Type de personnage 0:Medecin/1:Sain/2:Infect� */
	short x; /*!< Coordonn�es en abscisse */
	short y; /*!< Coordonn�es en ordonn�e */
	short vaccins; /*!< Nombre de vaccin */
};

/**
* @brief Tableau de structures repr�sentant les cases d'une carte
*/
struct type_personnage personnage[TAILLE_TABLEAU]; 

/**
*@brief Structure repr�senant un carte
*/
struct type_cartes {
	short int personnages; /*!< Nombre de personnage sur la case*/
	short int type; /*!< Type de personnage sur la case (inutile si ils sont plusieurs sur la case)*/
};
/**
* @brief Tableau de structures repr�sentant les cases d'une carte
*/
struct type_cartes carte[TAILLE_TABLEAU][TAILLE_TABLEAU];

/**
*	@brief	fonction	utilis�e	pour	les	positions	initiales	al�atoires	des	personnages
*	@return	int	compris	entre	0	et	49	inclus
*/
int	unePositionAleatoire();

/**
*	@brief	fonction	utilis�e	pour	les	d�placements	al�atoires
*	@return	int	compris	entre	0	et	3	inclus
*/
int	unDeplacement();

/**
*	@brief	Proc�dure utilis�e pour initialiser les parametres
*/
void initialisationParametres(int argc, char * argv[]);

/**
*	@brief	Proc�dure utilis�e pour initialiser les personnages
*/
void initialisation();

/**
*	@brief	Une fonction utilis�e pour g�n�rer les d�placements des personnages
*	@return	int compris entre 0 et 3 inclus
*	@param  index {repr�sentant index joueur}
*/
int ValiderDeplacement(int index);

/**
*	@brief	Une proc�dure qui d�place les personnages. Entr�e deplacement compris entre 0 et 3 inclus
*	@param  index {repr�sentant index joueur}
*	@param  deplacement {repr�sentant deplacement (0 � 3)}
*/
void Deplacer(int index, int deplacement);

/**
*	@brief	Proc�dure utilis�e pour v�rifier si un personnage est sur la case
*	@param  index {repr�sentant index joueur}
*/
void Verifier(int index);

/**
*	@brief	Proc�dure qui sert d'instruction d'attente
*/
void Sleep();

/**
*	\brief	Proc�dure qui sert � l'affichage du plateau
*/
void Affichage();