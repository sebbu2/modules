// stdafx.h�: fichier Include pour les fichiers Include syst�me standard,
// ou les fichiers Include sp�cifiques aux projets qui sont utilis�s fr�quemment,
// et sont rarement modifi�s
//

#pragma once

#include "targetver.h"
#include <stdio.h>
#if defined(__WIN32__)||defined(WIN32)
#include <tchar.h>

#define WIN32_LEAN_AND_MEAN             // Exclure les en-t�tes Windows rarement utilis�s
// Fichiers d'en-t�te Windows�:
#include <windows.h>

#endif /*WIN32*/


// TODO�: faites r�f�rence ici aux en-t�tes suppl�mentaires n�cessaires au programme
