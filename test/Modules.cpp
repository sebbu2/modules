#include "stdafx.h"
#include "Modules.h"

#include <cstdlib>
#include <cstdio>
#include <cstring>

#if !defined(__WIN32__)&&!defined(WIN32)
#include <unistd.h>
#endif

Module::Module()
: handle(NULL)
{
}

Module::~Module()
{
#if defined(__WIN32__)||defined(WIN32)
	if(handle)
	FreeLibrary(handle);
#else
	if(handle)
	dlclose(handle);
#endif
}

int Module::Load(const char *name)
{
	int len = strlen(name);
#if defined(__WIN32__)||defined(WIN32)
	char *real_name = new char[len + 4 + 1];
	strcpy(real_name, name);
	strcpy(&real_name[len], ".dll");
	//printf("%s%s",real_name,"\n");

	handle = LoadLibraryA(real_name);
	if(!handle)
	return -1;
	else
	return 0;
#else
	char cwd[512];
	getcwd(cwd, 512);
	int cwd_len = strlen(cwd);
	char *real_name = new char[cwd_len+1 + len + 3 + 1];
	strcpy(real_name, cwd);
	real_name[cwd_len] = '/';
	strcpy(&real_name[cwd_len+1], name);
	strcpy(&real_name[cwd_len + 1 + len], ".so");

	//fprintf(stderr, "Charge \"%s\"\n", real_name);
	handle = dlopen(real_name, RTLD_LAZY);
	if(!handle)
	return -1;
	else
	return 0;
#endif
}

void *Module::GetFonction(const char *name)
{
#if defined(__WIN32__)||defined(WIN32)
	if(!handle)
	return NULL;
	return (void*)GetProcAddress(handle, name);
#else
	if(!handle)
	return NULL;
	return dlsym(handle, name);
#endif
}
