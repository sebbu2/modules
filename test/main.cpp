#include "stdafx.h"
#include <cstdlib>
#include <iostream>

#include "Modules.h"

int main(int argc, char *argv[])
{
#ifdef _DEBUG
const char *mod_name = "modd";
#else
	const char *mod_name = "mod";
#endif

Module mod;
if(mod.Load(mod_name)!=0)
{
	fprintf(stderr, "Module::Load(%s) a echoue !\n", mod_name);
		fflush(stdout);fflush(stdin);
		getc(stdin);
	return 1;
}

static char buffer[2048];

	void (*Pwet)(char*) = (void (*)(char*))mod.GetFonction("Pwet");
if(!Pwet)
{
	fprintf(stderr, "Pwet() introuvable !\n");
		fflush(stdout);fflush(stdin);
		getc(stdin);
	return 1;
}
	Pwet(buffer);
	
	std::cout<<"using "<<mod_name<<".dll\n";
	std::cout<<buffer;

	fflush(stdout);
	getc(stdin);

return 0;
}
