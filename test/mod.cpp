// mod.cpp�: d�finit les fonctions export�es pour l'application DLL.
//

#include "mod.h"
#include <cstring>


// Il s'agit d'un exemple de variable export�e
/*MOD_API int nmod=0;

// Il s'agit d'un exemple de fonction export�e.
MOD_API int fnmod(void)
{
	return 42;
}

// Il s'agit du constructeur d'une classe qui a �t� export�e.
// consultez mod.h pour la d�finition de la classe
Cmod::Cmod()
{
	return;
}*/

extern "C" MOD_API void Pwet(char *buffer)
{
	strcpy(buffer,"Pwet !\n");
}
