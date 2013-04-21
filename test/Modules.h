#ifndef MODULE_H
#define MODULE_H

#include "stdafx.h"
#if defined(__WIN32__)||defined(WIN32)||defined(__CYGWIN__)
#include <windows.h>
#else
#include <dlfcn.h>
#endif

/**
 * Représente un module.
 *
 * Surcouche qui permet d'utiliser simplement des modules, en chargeant des
 * DLL sous Windows et des SO sous Linux de manière transparente.
 */
class Module {

#if defined(__WIN32__)||defined(WIN32)||defined(__CYGWIN__)
private:
    HMODULE handle;
#else
private:
    void *handle;
#endif

public:
    /**
     * Constructeur.
     */
    Module();
    
    /**
     * Destructeur.
     */
    ~Module();
    
    /**
     * Charge un module.
     *
     * @param name Nom du fichier à charger, sans extension.
     * @return 0 si le chargement a réussi.
     */
    int Load(const char *name);
    
    /**
     * Retourne un pointeur sur la fonction demandée, ou NULL si elle n'a pas
     * été trouvée.
     *
     * @param name Nom de la fonction à trouver.
     * @return Un pointeur à caster vers le type voulu avant d'appeler la
     * fonction.
     */
    void *GetFonction(const char *name);

};

#endif
