//This file contains data and prototypes for autoruns. It is autogenerated by StructParser


// autogeneratednocheckin

extern "C"
{
extern void Add_Auto_Cmds_TurnstileServer(void);
extern void _TurnstileServer_AutoRun_SPECIALINTERNAL(void);
void doAutoRuns_UtilitiesLib_0(void);
void doAutoRuns_UtilitiesLib_1(void);
void doAutoRuns_UtilitiesLib_2(void);
void doAutoRuns_UtilitiesLib_3(void);
void doAutoRuns_UtilitiesLib_4(void);
void doAutoRuns_ServerLib_0(void);
void doAutoRuns_ServerLib_1(void);
void doAutoRuns_ServerLib_2(void);
void doAutoRuns_ServerLib_3(void);
void doAutoRuns_ServerLib_4(void);


void doAutoRuns_TurnstileServer_0(void)
{
	static int once = 0;
	if (once) return;
	once = 1;
	doAutoRuns_UtilitiesLib_0();
	doAutoRuns_ServerLib_0();
	_TurnstileServer_AutoRun_SPECIALINTERNAL();
}



void doAutoRuns_TurnstileServer_1(void)
{
	static int once = 0;
	if (once) return;
	once = 1;
	doAutoRuns_UtilitiesLib_1();
	doAutoRuns_ServerLib_1();
	Add_Auto_Cmds_TurnstileServer();
}



void doAutoRuns_TurnstileServer_2(void)
{
	static int once = 0;
	if (once) return;
	once = 1;
	doAutoRuns_UtilitiesLib_2();
	doAutoRuns_ServerLib_2();
}



void doAutoRuns_TurnstileServer_3(void)
{
	static int once = 0;
	if (once) return;
	once = 1;
	doAutoRuns_UtilitiesLib_3();
	doAutoRuns_ServerLib_3();
}



void doAutoRuns_TurnstileServer_4(void)
{
	static int once = 0;
	if (once) return;
	once = 1;
	doAutoRuns_UtilitiesLib_4();
	doAutoRuns_ServerLib_4();
}

extern void utilitiesLibPreAutoRunStuff(void);
int MagicAutoRunFunc_TurnstileServer(void)
{
	utilitiesLibPreAutoRunStuff();
	doAutoRuns_TurnstileServer_0();
	doAutoRuns_TurnstileServer_1();
	doAutoRuns_TurnstileServer_2();
	doAutoRuns_TurnstileServer_3();
	doAutoRuns_TurnstileServer_4();
	return 0;
}

};


#if 0
PARSABLE
2
"Add_Auto_Cmds_TurnstileServer" "autogen_magiccommands" 1 "" "" 
"_TurnstileServer_AutoRun_SPECIALINTERNAL" "_SPECIAL_INTERNAL" 0 "" "" 
#endif