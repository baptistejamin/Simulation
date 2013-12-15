/**
* @file fonctions.c
* @author Baptiste JAMIN , Oc�ane GARIN
* @date Janvier 2013
* @brief Simulation de d�placement de population
*/
/**
*	@brief	fonction	utilis�e	pour	les	positions	initiales	al�atoires	des	personnages
*	@return	int	compris	entre	0	et	49	inclus
*/
int	unePositionAleatoire(){
return	rand()	%	SIZE;
}

/**
*	@brief	fonction	utilis�e	pour	les	d�placements	al�atoires
*	@return	int	compris	entre	0	et	3	inclus
*/
int	unDeplacement(){
return	rand()	%	DEPLACEMENTS;
}

/**
*	@brief	Proc�dure utilis�e pour initialiser les parametres
*/
void initialisationParametres(int argc, char * argv[]){
unsigned short int i;
for(i=1;i<argc;i++)
{
	if(strcmp(argv[i],"-size") == 0) //On teste si un param�tre � pour valeur -size
	{
		SIZE = atoi(argv[i+1]);	//Si oui, on assigne SIZE � la valeur du param�tre suivant	
		printf("SIZE initalisee a %s\n",argv[i+1]);
	}
	
	if(strcmp(argv[i],"-docteurs") == 0) //On teste si un param�tre � pour valeur -docteurs
	{
		DOCTEURS = atoi(argv[i+1]); //Si oui, on assigne DOCTEURS � la valeur du param�tre suivant		
		printf("DOCTEURS initalises a %s\n",argv[i+1]);
	}
	
	if(strcmp(argv[i],"-sains") == 0) //On teste si un param�tre � pour valeur -sains
	{
		SAINS = atoi(argv[i+1]); //Si oui, on assigne SAINS � la valeur du param�tre suivant		
		printf("SAINS initalises a %s!\n",argv[i+1]);
	}
	
	if(strcmp(argv[i],"-zombies") == 0) //On teste si un param�tre � pour valeur -zombies
	{
		ZOMBIES = atoi(argv[i+1]); //Si oui, on assigne ZOMBIES � la valeur du param�tre suivant			
		printf("ZOMBIES  initalises a %s\n",argv[i+1]);
	}
	
	if(strcmp(argv[i],"-vaccins") == 0) //On teste si un param�tre � pour valeur -vaccins
	{
		VACCINS = atoi(argv[i+1]); //Si oui, on assigne VACCINS � la valeur du param�tre suivant	
		printf("VACCINS initalises a %s\n",argv[i+1]);
	}
	
	
	if(strcmp(argv[i],"-silent") == 0) //On teste si un param�tre � pour valeur -silent
	{
		SILENT=1; //SILENT Mode activ�. Ce mode diminue consid�rablement le nombre d'informations que retourne le programme
		printf("SILENT initialise\n");
	}
	
	if(strcmp(argv[i],"-no_sleep") == 0) //On teste si un param�tre � pour valeur -no_sleep
	{
		NO_SLEEP=1; //NO_SLEEP Mode activ�. Ce mode supprime le d�lai d'attendre entre chaque tour
		printf("NO_SLEEP initialise\n");
	}
	
	if(strcmp(argv[i],"-no_carte") == 0) //On teste si un param�tre � pour valeur -no_carte
	{
		NO_CARTE=1; //NO_CARTE Mode activ�. Ce mode supprime l'affichage de la carte
		printf("NO_CARTE initialise\n");
	}
}

if (SILENT==0) //Si le param�tre -silent n'est pas pr�cis�, alors on affiche ces messages:
{
	printf("Initialisation des personnages...\n");
}


if ((SIZE>24) && (NO_CARTE==0)) //Si l'affichage est activ� et la taille de carte trop grande, alors on r�duit la taille
{
	SIZE=24;
	printf("\nPour des raisons d'ergonomie, la taille de la carte a ete reduite a 25\n");
}

if (SILENT==0) //Si le param�tre -silent n'est pas pr�cis�, alors on affiche ces messages:
{
	printf("Initialisation des personnages...\n");
}

}

/**
*	@brief	Proc�dure utilis�e pour initialiser les personnages
*/
void initialisation(){
short int i = 0;
short int x = 0;
short int y = 0;

infectes=ZOMBIES; //On initialise la variable qui sert � la condition de continuation de la boucle principale

//On initialise toutes les cases de la carte
for (x=0;x<SIZE;x++)
{
	for (y=0;y<SIZE;y++)
	{
		carte[x][y].personnages=0; //On pr�cise qu'il n'y a personne sur la case
		carte[x][y].type=0; //On initialise � 0, mais peut �tre un autre chiffre positif
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
	
	personnage[i].x=unePositionAleatoire(); //On le place al�atoirement en X
	personnage[i].y=unePositionAleatoire(); //On le place al�atoirement en Y
		
	//Cette partie est utilis�e pour l'affichage de la carte 
	carte[personnage[i].x][personnage[i].y].personnages++; //On place le personnage de coordonn�es X et Y sur la case correspondante de la carte
	carte[personnage[i].x][personnage[i].y].type = personnage[i].type; //On pr�cise que la case X Y de la carte comporte un personnage
		
	if (SILENT==0) //Si le param�tre -silent n'est pas pr�cis�, alors on affiche ces messages:
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
*	@brief	Une fonction utilis�e pour g�n�rer les d�placements des personnages
*	@return	int compris entre 0 et 3 inclus
*	@param  index {repr�sentant index joueur}
*/
int ValiderDeplacement(int index){
unsigned short int deplacement;

deplacement = unDeplacement();

//On v�rifie qu'il n'y a pas de d�passement

//D�passement en haut
if ((personnage[index].y == 0) && (deplacement == 0))
{
	while(deplacement == 0)
	{
		deplacement = unDeplacement();
	}
}
//D�passement en bas
if ((personnage[index].y == SIZE-1) && (deplacement == 1))
{
	while(deplacement == 1)
	{
		deplacement = unDeplacement();
	}
}
//D�passement sur la gauche
if ((personnage[index].x == 0) && (deplacement == 2))
{
	while(deplacement == 2)
	{
		deplacement = unDeplacement();
	}
} 
//D�passement sur la droite
if ((personnage[index].x == SIZE-1) && (deplacement == 3))
{
	while(deplacement == 3)
	{
		deplacement = unDeplacement();
	}
}
//D�passement sur le coin inf�rieur droit
if ((personnage[index].y == SIZE-1) && (personnage[index].x == SIZE-1) && ((deplacement == 1) || (deplacement == 3)))
{
	while((deplacement == 3) || (deplacement == 1))
	{
		deplacement = unDeplacement();
	}
}
//D�passement sur le coin inf�rieur gauche
if ((personnage[index].y == SIZE-1) && (personnage[index].x == 0) && ((deplacement == 1) || (deplacement == 2)))
{
	while((deplacement == 1) || (deplacement == 2))
	{
		deplacement = unDeplacement();
	}
}
//D�passement sur le coin sup�rieur gauche
if ((personnage[index].y == 0) && (personnage[index].x == 0) && ((deplacement == 0) || (deplacement == 2)))
{
	while((deplacement == 0) || (deplacement == 2))
	{
		deplacement = unDeplacement();
	}
}
//D�passement sur le coin sup�rieur droit
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
*	@brief	Une proc�dure qui d�place les personnages. Entr�e deplacement compris entre 0 et 3 inclus
*	@param  index {repr�sentant index joueur}
*	@param  deplacement {repr�sentant deplacement (0 � 3)}
*/
void Deplacer(int index, int deplacement){

carte[personnage[index].x][personnage[index].y].personnages--; //On enl�ve le personnage de sa case

switch (deplacement) 
{
	case 0: //Le personnage va vers le haut
	personnage[index].y--; //On d�place le personnage
	break;
	
	case 1: //Le personnage va vers le bas
	personnage[index].y++; //On d�place le personnage
	break;
	
	case 2: //Le personnage va la gauche
	personnage[index].x--; //On d�place le personnage
	break;
	
	case 3: //Le personnage va vers la droite
	personnage[index].x++; //On d�place le personnage
	break;
}

carte[personnage[index].x][personnage[index].y].personnages++; //On met le personnage sur sa nouvelle case
carte[personnage[index].x][personnage[index].y].type = personnage[index].type; //On actualise le type de personnage sur la nouvelle case

}

/**
*	@brief	Proc�dure utilis�e pour v�rifier si un personnage est sur la case
*	@param  index {repr�sentant index joueur}
*/
void Verifier(int index){
unsigned short int i = 0;
while(i < DOCTEURS+SAINS+ZOMBIES)
{
	//On v�rifie que le personnage est sur la m�me position, que ce n'est pas moi et qu'il est diff�rent de moi
	if ((i!=index) && (personnage[index].type != personnage[i].type) && (personnage[index].y == personnage[i].y) && (personnage[index].x == personnage[i].x))
	{
		//Un m�decin arrive sur un zombie et a assez de vaccin
		if ((personnage[index].type == 0) && (personnage[i].type == 2) && (personnage[index].vaccins > 0))
		{
			personnage[i].type = 1; //On soigne le personnage en lui donnant un nouveau type
			carte[personnage[i].x][personnage[i].y].type = personnage[i].type; //On actualise le type de personnage sur la case
			infectes--; //On d�cr�mente le nombre d'infect�s
			personnage[index].vaccins--; //Le Medecin perd un vaccin
			if (SILENT==0) //Si le param�tre -silent n'est pas pr�cis�, alors on affiche ces messages:
			{
			printf("Un personnage est soigne\n");
			}
		}
		
		//Un zombie arrive sur un medecin avec assez de vaccin
		if ((personnage[index].type == 2) && (personnage[i].type == 0) && (personnage[i].vaccins > 0))
		{
			personnage[index].type = 1; //On soigne le personnage en lui donnant un nouveau type
			carte[personnage[index].x][personnage[index].y].type = personnage[index].type; //On actualise le type de personnage sur la case
			infectes--; //On d�cr�mente le nombre d'infect�s
			personnage[i].vaccins--; //Le Medecin perd un vaccin
			if (SILENT==0) //Si le param�tre -silent n'est pas pr�cis�, alors on affiche ces messages:
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
			infectes++; //On incr�mente le nombre de zombies
			if (SILENT==0) //Si le param�tre -silent n'est pas pr�cis�, alors on affiche ces messages:
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
			infectes++; //On incr�mente le nombre de zombies
			if (SILENT==0) //Si le param�tre -silent n'est pas pr�cis�, alors on affiche ces messages:
			{
			printf("Un personnage est infecte\n");
			}
		}
	}
	i++;
}
}

/**
*	@brief	Proc�dure qui sert d'instruction d'attente
*/
void Sleep()
{
int i = 0;
while(i<(2000+NO_CARTE*10000)) //On choisi un nombre suffisemment grand pour que le d�lai d'attente soit long
{
	i++;
}
}

/**
*	\brief	Proc�dure qui sert � l'affichage du plateau
*/
void Affichage()
{
unsigned short int y;
unsigned short int x;

system("cls"); //On r�initialise la console (Pour Windows)
//system("clear"); //On r�initialise la console (Pour Unix)

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