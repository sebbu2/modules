// mod.cpp : définit les fonctions exportées pour l'application DLL.
//

#include "mod.h"
#include <cstring>


// Il s'agit d'un exemple de variable exportée
/*MOD_API int nmod=0;

// Il s'agit d'un exemple de fonction exportée.
MOD_API int fnmod(void)
{
	return 42;
}

// Il s'agit du constructeur d'une classe qui a été exportée.
// consultez mod.h pour la définition de la classe
Cmod::Cmod()
{
	return;
}*/

extern "C" MOD_API void Pwet(char *buffer)
{
	strcpy(buffer,"Pwet !\n");
}
