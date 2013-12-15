/**
* @file fonctions.c
* @author Baptiste JAMIN , Océane GARIN
* @date Janvier 2013
* @brief Simulation de déplacement de population
*/
/**
*	@brief	fonction	utilisée	pour	les	positions	initiales	aléatoires	des	personnages
*	@return	int	compris	entre	0	et	49	inclus
*/
int	unePositionAleatoire(){
return	rand()	%	SIZE;
}

/**
*	@brief	fonction	utilisée	pour	les	déplacements	aléatoires
*	@return	int	compris	entre	0	et	3	inclus
*/
int	unDeplacement(){
return	rand()	%	DEPLACEMENTS;
}

/**
*	@brief	Procédure utilisée pour initialiser les parametres
*/
void initialisationParametres(int argc, char * argv[]){
unsigned short int i;
for(i=1;i<argc;i++)
{
	if(strcmp(argv[i],"-size") == 0) //On teste si un paramètre à pour valeur -size
	{
		SIZE = atoi(argv[i+1]);	//Si oui, on assigne SIZE à la valeur du paramètre suivant	
		printf("SIZE initalisee a %s\n",argv[i+1]);
	}
	
	if(strcmp(argv[i],"-docteurs") == 0) //On teste si un paramètre à pour valeur -docteurs
	{
		DOCTEURS = atoi(argv[i+1]); //Si oui, on assigne DOCTEURS à la valeur du paramètre suivant		
		printf("DOCTEURS initalises a %s\n",argv[i+1]);
	}
	
	if(strcmp(argv[i],"-sains") == 0) //On teste si un paramètre à pour valeur -sains
	{
		SAINS = atoi(argv[i+1]); //Si oui, on assigne SAINS à la valeur du paramètre suivant		
		printf("SAINS initalises a %s!\n",argv[i+1]);
	}
	
	if(strcmp(argv[i],"-zombies") == 0) //On teste si un paramètre à pour valeur -zombies
	{
		ZOMBIES = atoi(argv[i+1]); //Si oui, on assigne ZOMBIES à la valeur du paramètre suivant			
		printf("ZOMBIES  initalises a %s\n",argv[i+1]);
	}
	
	if(strcmp(argv[i],"-vaccins") == 0) //On teste si un paramètre à pour valeur -vaccins
	{
		VACCINS = atoi(argv[i+1]); //Si oui, on assigne VACCINS à la valeur du paramètre suivant	
		printf("VACCINS initalises a %s\n",argv[i+1]);
	}
	
	
	if(strcmp(argv[i],"-silent") == 0) //On teste si un paramètre à pour valeur -silent
	{
		SILENT=1; //SILENT Mode activé. Ce mode diminue considérablement le nombre d'informations que retourne le programme
		printf("SILENT initialise\n");
	}
	
	if(strcmp(argv[i],"-no_sleep") == 0) //On teste si un paramètre à pour valeur -no_sleep
	{
		NO_SLEEP=1; //NO_SLEEP Mode activé. Ce mode supprime le délai d'attendre entre chaque tour
		printf("NO_SLEEP initialise\n");
	}
	
	if(strcmp(argv[i],"-no_carte") == 0) //On teste si un paramètre à pour valeur -no_carte
	{
		NO_CARTE=1; //NO_CARTE Mode activé. Ce mode supprime l'affichage de la carte
		printf("NO_CARTE initialise\n");
	}
}

if (SILENT==0) //Si le paramètre -silent n'est pas précisé, alors on affiche ces messages:
{
	printf("Initialisation des personnages...\n");
}


if ((SIZE>24) && (NO_CARTE==0)) //Si l'affichage est activé et la taille de carte trop grande, alors on réduit la taille
{
	SIZE=24;
	printf("\nPour des raisons d'ergonomie, la taille de la carte a ete reduite a 25\n");
}

if (SILENT==0) //Si le paramètre -silent n'est pas précisé, alors on affiche ces messages:
{
	printf("Initialisation des personnages...\n");
}

}

/**
*	@brief	Procédure utilisée pour initialiser les personnages
*/
void initialisation(){
short int i = 0;
short int x = 0;
short int y = 0;

infectes=ZOMBIES; //On initialise la variable qui sert à la condition de continuation de la boucle principale

//On initialise toutes les cases de la carte
for (x=0;x<SIZE;x++)
{
	for (y=0;y<SIZE;y++)
	{
		carte[x][y].personnages=0; //On précise qu'il n'y a personne sur la case
		carte[x][y].type=0; //On initialise à 0, mais peut être un autre chiffre positif
	}
}

i=0;
while(i < (DOCTEURS+SAINS+ZOMBIES))
{		
	//Initialisation des docteurs
	if (i < DOCTEURS)
	{
		personnage[i].type=0; //Type de personnage 0: docteur
		personnage[i].vaccins=VACCINS; //Donne au docteur un certain nombre de vaccins
	}
	//Initialisation des sains
	if ((i >= DOCTEURS) && (i < SAINS+DOCTEURS))
	{
		personnage[i].type=1; //Type de personnage 1: sain
		personnage[i].vaccins=0;  //On ne donne pas de vaccins
	}
	//Initialisation des zombies
	if (i >= SAINS+DOCTEURS)
	{
		personnage[i].type=2; //Type de personnage 2: zombie
		personnage[i].vaccins=0; //On ne donne pas de vaccins
	}
	
	personnage[i].x=unePositionAleatoire(); //On le place aléatoirement en X
	personnage[i].y=unePositionAleatoire(); //On le place aléatoirement en Y
		
	//Cette partie est utilisée pour l'affichage de la carte 
	carte[personnage[i].x][personnage[i].y].personnages++; //On place le personnage de coordonnées X et Y sur la case correspondante de la carte
	carte[personnage[i].x][personnage[i].y].type = personnage[i].type; //On précise que la case X Y de la carte comporte un personnage
		
	if (SILENT==0) //Si le paramètre -silent n'est pas précisé, alors on affiche ces messages:
	{
		printf("personnage[%i].type=%i\n",i,personnage[i].type);
		printf("personnage[%i].vaccins=%i\n",i,personnage[i].vaccins);
		printf("personnage[%i].x=%i\n",i,personnage[i].x);
		printf("personnage[%i].y=%i\n",i,personnage[i].y);
		printf("\n");
	}
	
	i++;
}
}

/**
*	@brief	Une fonction utilisée pour générer les déplacements des personnages
*	@return	int compris entre 0 et 3 inclus
*	@param  index {représentant index joueur}
*/
int ValiderDeplacement(int index){
unsigned short int deplacement;

deplacement = unDeplacement();

//On vérifie qu'il n'y a pas de dépassement

//Dépassement en haut
if ((personnage[index].y == 0) && (deplacement == 0))
{
	while(deplacement == 0)
	{
		deplacement = unDeplacement();
	}
}
//Dépassement en bas
if ((personnage[index].y == SIZE-1) && (deplacement == 1))
{
	while(deplacement == 1)
	{
		deplacement = unDeplacement();
	}
}
//Dépassement sur la gauche
if ((personnage[index].x == 0) && (deplacement == 2))
{
	while(deplacement == 2)
	{
		deplacement = unDeplacement();
	}
} 
//Dépassement sur la droite
if ((personnage[index].x == SIZE-1) && (deplacement == 3))
{
	while(deplacement == 3)
	{
		deplacement = unDeplacement();
	}
}
//Dépassement sur le coin inférieur droit
if ((personnage[index].y == SIZE-1) && (personnage[index].x == SIZE-1) && ((deplacement == 1) || (deplacement == 3)))
{
	while((deplacement == 3) || (deplacement == 1))
	{
		deplacement = unDeplacement();
	}
}
//Dépassement sur le coin inférieur gauche
if ((personnage[index].y == SIZE-1) && (personnage[index].x == 0) && ((deplacement == 1) || (deplacement == 2)))
{
	while((deplacement == 1) || (deplacement == 2))
	{
		deplacement = unDeplacement();
	}
}
//Dépassement sur le coin supérieur gauche
if ((personnage[index].y == 0) && (personnage[index].x == 0) && ((deplacement == 0) || (deplacement == 2)))
{
	while((deplacement == 0) || (deplacement == 2))
	{
		deplacement = unDeplacement();
	}
}
//Dépassement sur le coin supérieur droit
if ((personnage[index].y == 0) && (personnage[index].x == 49) && ((deplacement == 0) || (deplacement == 3)))
{
	while((deplacement == 0) || (deplacement == 3))
	{
		deplacement = unDeplacement();
	}
}

return deplacement;

}

/**
*	@brief	Une procédure qui déplace les personnages. Entrée deplacement compris entre 0 et 3 inclus
*	@param  index {représentant index joueur}
*	@param  deplacement {représentant deplacement (0 à 3)}
*/
void Deplacer(int index, int deplacement){

carte[personnage[index].x][personnage[index].y].personnages--; //On enlève le personnage de sa case

switch (deplacement) 
{
	case 0: //Le personnage va vers le haut
	personnage[index].y--; //On déplace le personnage
	break;
	
	case 1: //Le personnage va vers le bas
	personnage[index].y++; //On déplace le personnage
	break;
	
	case 2: //Le personnage va la gauche
	personnage[index].x--; //On déplace le personnage
	break;
	
	case 3: //Le personnage va vers la droite
	personnage[index].x++; //On déplace le personnage
	break;
}

carte[personnage[index].x][personnage[index].y].personnages++; //On met le personnage sur sa nouvelle case
carte[personnage[index].x][personnage[index].y].type = personnage[index].type; //On actualise le type de personnage sur la nouvelle case

}

/**
*	@brief	Procédure utilisée pour vérifier si un personnage est sur la case
*	@param  index {représentant index joueur}
*/
void Verifier(int index){
unsigned short int i = 0;
while(i < DOCTEURS+SAINS+ZOMBIES)
{
	//On vérifie que le personnage est sur la même position, que ce n'est pas moi et qu'il est différent de moi
	if ((i!=index) && (personnage[index].type != personnage[i].type) && (personnage[index].y == personnage[i].y) && (personnage[index].x == personnage[i].x))
	{
		//Un médecin arrive sur un zombie et a assez de vaccin
		if ((personnage[index].type == 0) && (personnage[i].type == 2) && (personnage[index].vaccins > 0))
		{
			personnage[i].type = 1; //On soigne le personnage en lui donnant un nouveau type
			carte[personnage[i].x][personnage[i].y].type = personnage[i].type; //On actualise le type de personnage sur la case
			infectes--; //On décrémente le nombre d'infectés
			personnage[index].vaccins--; //Le Medecin perd un vaccin
			if (SILENT==0) //Si le paramètre -silent n'est pas précisé, alors on affiche ces messages:
			{
			printf("Un personnage est soigne\n");
			}
		}
		
		//Un zombie arrive sur un medecin avec assez de vaccin
		if ((personnage[index].type == 2) && (personnage[i].type == 0) && (personnage[i].vaccins > 0))
		{
			personnage[index].type = 1; //On soigne le personnage en lui donnant un nouveau type
			carte[personnage[index].x][personnage[index].y].type = personnage[index].type; //On actualise le type de personnage sur la case
			infectes--; //On décrémente le nombre d'infectés
			personnage[i].vaccins--; //Le Medecin perd un vaccin
			if (SILENT==0) //Si le paramètre -silent n'est pas précisé, alors on affiche ces messages:
			{
			printf("Un personnage est soigne\n");
			}
		}
		
		//Un zombie arrive sur un sain
		if ((personnage[index].type == 2) && (personnage[i].type == 1))
		{
			//On contamine
			personnage[i].type = 2; //On infecte le personnage en lui donnant un nouveau type
			carte[personnage[i].x][personnage[i].y].type = personnage[i].type; //On actualise le type de personnage sur la case
			infectes++; //On incrémente le nombre de zombies
			if (SILENT==0) //Si le paramètre -silent n'est pas précisé, alors on affiche ces messages:
			{
			printf("Un personnage est infecte\n");
			}
		}
		
		//Un sain arrive sur un zombie
		if ((personnage[index].type == 1) && (personnage[i].type == 2))
		{
			//On contamine
			personnage[index].type = 2; //On infecte le personnage en lui donnant un nouveau type
			carte[personnage[index].x][personnage[index].y].type = personnage[index].type; //On actualise le type de personnage sur la case
			infectes++; //On incrémente le nombre de zombies
			if (SILENT==0) //Si le paramètre -silent n'est pas précisé, alors on affiche ces messages:
			{
			printf("Un personnage est infecte\n");
			}
		}
	}
	i++;
}
}

/**
*	@brief	Procédure qui sert d'instruction d'attente
*/
void Sleep()
{
int i = 0;
while(i<(2000+NO_CARTE*10000)) //On choisi un nombre suffisemment grand pour que le délai d'attente soit long
{
	i++;
}
}

/**
*	\brief	Procédure qui sert à l'affichage du plateau
*/
void Affichage()
{
unsigned short int y;
unsigned short int x;

system("cls"); //On réinitialise la console (Pour Windows)
//system("clear"); //On réinitialise la console (Pour Unix)

for (y=0;y<SIZE;y++)
{
	for (x=0;x<SIZE;x++)
	{	
		if ((carte[x][y].personnages == 1) && (carte[x][y].type == 0))
		{
			printf("D|");
		}
		else if ((carte[x][y].personnages == 1) && (carte[x][y].type == 1))
		{
			printf("S|");
		}
		else if ((carte[x][y].personnages == 1) && (carte[x][y].type == 2))
		{
			printf("Z|");
		}
		else if ((carte[x][y].personnages > 1))
		{
			printf("%i|",carte[x][y].personnages);
		}
		else
		{
			printf(" |");
		}
	}
	printf("\n");
}
}