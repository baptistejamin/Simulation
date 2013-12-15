/**
* @file fonctions.h
* @author Baptiste JAMIN , Océane GARIN
* @date Janvier 2013
* @brief Simulation de déplacement de population
*/

#include	<time.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>

/**
*@brief Indique le nombre de déplacements possibles
*/
#define DEPLACEMENTS 4
/**
*@brief Nombre générique pour déclarer la taille maximale des tableaux
*/
#define TAILLE_TABLEAU 50

unsigned short int SIZE = 50; /*!< Indique la taille de la carte */

unsigned short int DOCTEURS = 2; /*!< Indique le nombre de docteurs */

unsigned short int SAINS = 6; /*!< Indique le nombre de personnages sains */

unsigned short int ZOMBIES = 6;  /*!< Indique le nombre de zombies */

unsigned short int VACCINS = 5; /*!< Indique le nombre de vaccins par docteur */

unsigned short int SILENT = 0; /*!< Variable qui sert à afficher ou non les massages */

unsigned short int NO_SLEEP = 0; /*!< Variable qui sert à supprimer ou non le délai d'attente */

unsigned short int NO_CARTE = 0; /*!< Variable qui sert à supprimer l'affichage de la carte */

short int infectes; /*!< indique le nombre de personnages infectés */

/**
* @brief Structure représentant les personnages
*/
struct type_personnage {
	short int type; /*!< Type de personnage 0:Medecin/1:Sain/2:Infecté */
	short x; /*!< Coordonnées en abscisse */
	short y; /*!< Coordonnées en ordonnée */
	short vaccins; /*!< Nombre de vaccin */
};

/**
* @brief Tableau de structures représentant les cases d'une carte
*/
struct type_personnage personnage[TAILLE_TABLEAU]; 

/**
*@brief Structure représenant un carte
*/
struct type_cartes {
	short int personnages; /*!< Nombre de personnage sur la case*/
	short int type; /*!< Type de personnage sur la case (inutile si ils sont plusieurs sur la case)*/
};
/**
* @brief Tableau de structures représentant les cases d'une carte
*/
struct type_cartes carte[TAILLE_TABLEAU][TAILLE_TABLEAU];

/**
*	@brief	fonction	utilisée	pour	les	positions	initiales	aléatoires	des	personnages
*	@return	int	compris	entre	0	et	49	inclus
*/
int	unePositionAleatoire();

/**
*	@brief	fonction	utilisée	pour	les	déplacements	aléatoires
*	@return	int	compris	entre	0	et	3	inclus
*/
int	unDeplacement();

/**
*	@brief	Procédure utilisée pour initialiser les parametres
*/
void initialisationParametres(int argc, char * argv[]);

/**
*	@brief	Procédure utilisée pour initialiser les personnages
*/
void initialisation();

/**
*	@brief	Une fonction utilisée pour générer les déplacements des personnages
*	@return	int compris entre 0 et 3 inclus
*	@param  index {représentant index joueur}
*/
int ValiderDeplacement(int index);

/**
*	@brief	Une procédure qui déplace les personnages. Entrée deplacement compris entre 0 et 3 inclus
*	@param  index {représentant index joueur}
*	@param  deplacement {représentant deplacement (0 à 3)}
*/
void Deplacer(int index, int deplacement);

/**
*	@brief	Procédure utilisée pour vérifier si un personnage est sur la case
*	@param  index {représentant index joueur}
*/
void Verifier(int index);

/**
*	@brief	Procédure qui sert d'instruction d'attente
*/
void Sleep();

/**
*	\brief	Procédure qui sert à l'affichage du plateau
*/
void Affichage();