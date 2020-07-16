#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <dlfcn.h>  
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <iostream>
#include <sys/mman.h>
#include <errno.h>
#include <signal.h>
#include "Player.h"
#include "Monster.h"
#include "EntityManager.h"

//gcc -fpic -shared -o libB.so libB.cpp

//gcc -lstdc++  -L./ libA.cpp main.cpp -ldl libB.so 

//export LD_LIBRARY_PATH=./  

//kill -SIGUSR1 `pidof main`

extern EntityManager* gEntityMgr;


void ReplaceFunction(void* hanle_so, const std::string& fun_old, const std::string& fun_new)
{
	void * pOldAddr = dlsym(NULL, fun_old.c_str());
	printf("address of old function: %s ,addr:%x\n\n", fun_old.c_str(), pOldAddr);

	void* pNewAddr = dlsym(hanle_so, fun_new.c_str());
	printf("address of new function: %s ,addr:%x\n\n", fun_new.c_str(),pNewAddr);

	if (pOldAddr == NULL)
	{
		printf("fun_old symble not found!!!\n");
		return;
	}

	if (pNewAddr == NULL)
	{
		printf("fun_new symble not found!!!\n");
		return;
	}

	int pagesize = sysconf(_SC_PAGE_SIZE);
	int numpages = 2;
	if (mprotect((void*)((uintptr_t)pOldAddr & (~(pagesize - 1))), numpages * pagesize, PROT_READ | PROT_WRITE | PROT_EXEC))
	{
		printf("%s-----\n", strerror(errno));
	}
	memset(pOldAddr, 0x48, 1);
	memset((char*)pOldAddr + 1, 0xb8, 1);
	memcpy((char*)pOldAddr + 2, &pNewAddr, 8);
	memset((char*)pOldAddr + 10, 0xff, 1);
	memset((char*)pOldAddr + 11, 0xe0, 1);
	
	if (mprotect((void*)((uintptr_t)pOldAddr & (~(pagesize - 1))), numpages * pagesize, PROT_READ | PROT_EXEC) < 0)     {
		printf("%s=====\n", strerror(errno));
	}
}

void* g_handle_so = NULL;


void sig_user1_handler(int sig, siginfo_t *si, void *data)
{
	//void* handle_so = dlopen("./libMgrDo.so", RTLD_LAZY);
	void* handle_so = dlopen("./libMgrDo.so", RTLD_NOW);
	if (handle_so == NULL)
	{
		printf("%s-----\n", dlerror());
		return;
	}

	g_handle_so = handle_so;

	ReplaceFunction(handle_so, "_ZN13EntityManager19PrintEntityListInfoESsi", "_ZN13EntityManager19PrintEntityListInfoESsi");
	ReplaceFunction(handle_so, "_ZN6Player14GetVirtualNameEv", "_ZN6Player14GetVirtualNameEv");
	ReplaceFunction(handle_so, "_ZN13EntityManager16GetFunctionValueEv", "_ZN13EntityManager16GetFunctionValueEv");
	
	//ReplaceFunction(handle_so, "_ZN7Monster14GetVirtualNameEv", "_ZN7Monster14GetVirtualNameEv");
	//ReplaceFunction(handle_so, "_ZN12OperatorTestclEv", "_ZN12OperatorTestclEv");
}


void sig_user2_handler(int sig, siginfo_t *si, void *data)
{
	std::string fun_old;
	void * pOldAddr = NULL;
	fun_old = "_ZN13EntityManager19PrintEntityListInfoESsi";
	pOldAddr = dlsym(NULL, fun_old.c_str());
	printf("address of old function: %s ,addr:%x\n\n", fun_old.c_str(), pOldAddr);
	pOldAddr = dlsym(g_handle_so, fun_old.c_str());
	printf("address of new function: %s ,addr:%x\n\n", fun_old.c_str(), pOldAddr);


	fun_old = "_ZN13EntityManager15AddFuntiocnTestEv";
	pOldAddr = dlsym(NULL, fun_old.c_str());
	printf("address of old function: %s ,addr:%x\n\n", fun_old.c_str(), pOldAddr);
	pOldAddr = dlsym(g_handle_so, fun_old.c_str());
	printf("address of new function: %s ,addr:%x\n\n", fun_old.c_str(), pOldAddr);


	

	//ReplaceFunction(handle_so, "_ZN7Monster14GetVirtualNameEv", "_ZN7Monster14GetVirtualNameEv");
	//ReplaceFunction(handle_so, "_ZN12OperatorTestclEv", "_ZN12OperatorTestclEv");
}


struct OperatorTest
{
public:
	int a;
	void operator()()
	{
		std::cout << "OperatorTest ---" << std::endl;
	}
};



int main()
{
	struct sigaction newact, oldact;
	sigemptyset(&newact.sa_mask);
	newact.sa_sigaction = sig_user1_handler;
	sigaction(SIGUSR1, &newact, &oldact);


	struct sigaction newact2, oldact2;
	sigemptyset(&newact2.sa_mask);
	newact2.sa_sigaction = sig_user2_handler;
	sigaction(SIGUSR2, &newact2, &oldact2);


	Entity * pEntity = new Entity;
	gEntityMgr->AddEntity(pEntity);

	pEntity = new Monster;
	gEntityMgr->AddEntity(pEntity);

	pEntity = new Player;
	gEntityMgr->AddEntity(pEntity);

	std::cout << std::endl << std::endl;

	OperatorTest test;


	std::string str = "current index: ";

	int i = 0;
	while (true)
	{
		i++;
		gEntityMgr->PrintEntityListInfo(str, i);
		gEntityMgr->getClassName();

		sleep(3);
	}

	return 0;
}



#if 0





std::cout << "current index : " << ++i << std::endl;
gEntityMgr->PrintEntityListInfo(str, i);


#endif



/*void* handle2 = NULL;
typedef void(*testLibBFun)();
testLibBFun testLibB = NULL;
int i = 0;
while (true)
{
handle2 = dlopen("./libC.so", RTLD_LAZY);
if (handle2 == NULL) {
perror("error!");
//return 1;
continue;
}
testLibB = (void(*)())dlsym(handle2, "_Z4libBv");
if (testLibB == NULL) {
perror("error!");
//return 1;
continue;
}
testLibB();

libA();

dlclose(handle2);

i++;

printf("currnet %d \n", i);

sleep(3);

}*/