#ifndef MODULE_H
#define MODULE_H

#include "stdafx.h"
#if defined(__WIN32__)||defined(WIN32)||defined(__CYGWIN__)
#include <windows.h>
#else
#include <dlfcn.h>
#endif

/**
 * Repr�sente un module.
 *
 * Surcouche qui permet d'utiliser simplement des modules, en chargeant des
 * DLL sous Windows et des SO sous Linux de mani�re transparente.
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
     * @param name Nom du fichier � charger, sans extension.
     * @return 0 si le chargement a r�ussi.
     */
    int Load(const char *name);
    
    /**
     * Retourne un pointeur sur la fonction demand�e, ou NULL si elle n'a pas
     * �t� trouv�e.
     *
     * @param name Nom de la fonction � trouver.
     * @return Un pointeur � caster vers le type voulu avant d'appeler la
     * fonction.
     */
    void *GetFonction(const char *name);

};

#endif
