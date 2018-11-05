//********************************************************************************
// Initialize all Controller NPlugins that where defined earlier
// and initialize the function call pointer into the CNPlugin array
//********************************************************************************

static const char ADDNPLUGIN_ERROR[] PROGMEM = "System: Error - To much N-Plugins";


// Because of compiler-bug (multiline defines gives an error if file ending is CRLF) the define is striped to a single line
/*
#define ADDNPLUGIN(NNN) \
  if (x < NPLUGIN_MAX) \
  { \
    NPlugin_id[x] = NPLUGIN_ID_##NNN; \
    NPlugin_ptr[x++] = &NPlugin_##NNN; \
  } \
  else \
    addLog(LOG_LEVEL_ERROR, FPSTR(ADDNPLUGIN_ERROR));
*/
#define ADDNPLUGIN(NNN) if (x < NPLUGIN_MAX) { NPlugin_id[x] = NPLUGIN_ID_##NNN; NPlugin_ptr[x++] = &NPlugin_##NNN; } else addLog(LOG_LEVEL_ERROR, FPSTR(ADDNPLUGIN_ERROR));


void NPluginInit(void)
{
  byte x;

  // Clear pointer table for all plugins
  for (x = 0; x < NPLUGIN_MAX; x++)
  {
    NPlugin_ptr[x] = 0;
    NPlugin_id[x] = 0;
  }

  x = 0;

#ifdef NPLUGIN_001
  ADDNPLUGIN(001)
#endif

#ifdef NPLUGIN_002
  ADDNPLUGIN(002)
#endif

#ifdef NPLUGIN_003
  ADDNPLUGIN(003)
#endif

#ifdef NPLUGIN_004
  ADDNPLUGIN(004)
#endif

#ifdef NPLUGIN_005
  ADDNPLUGIN(005)
#endif

#ifdef NPLUGIN_006
  ADDNPLUGIN(006)
#endif

#ifdef NPLUGIN_007
  ADDNPLUGIN(007)
#endif

#ifdef NPLUGIN_008
  ADDNPLUGIN(008)
#endif

#ifdef NPLUGIN_009
  ADDNPLUGIN(009)
#endif

#ifdef NPLUGIN_010
  ADDNPLUGIN(010)
#endif

#ifdef NPLUGIN_011
  ADDNPLUGIN(011)
#endif

#ifdef NPLUGIN_012
  ADDNPLUGIN(012)
#endif

#ifdef NPLUGIN_013
  ADDNPLUGIN(013)
#endif

#ifdef NPLUGIN_014
  ADDNPLUGIN(014)
#endif

#ifdef NPLUGIN_015
  ADDNPLUGIN(015)
#endif

#ifdef NPLUGIN_016
  ADDNPLUGIN(016)
#endif

#ifdef NPLUGIN_017
  ADDNPLUGIN(017)
#endif

#ifdef NPLUGIN_018
  ADDNPLUGIN(018)
#endif

#ifdef NPLUGIN_019
  ADDNPLUGIN(019)
#endif

#ifdef NPLUGIN_020
  ADDNPLUGIN(020)
#endif

#ifdef NPLUGIN_021
  ADDNPLUGIN(021)
#endif

#ifdef NPLUGIN_022
  ADDNPLUGIN(022)
#endif

#ifdef NPLUGIN_023
  ADDNPLUGIN(023)
#endif

#ifdef NPLUGIN_024
  ADDNPLUGIN(024)
#endif

#ifdef NPLUGIN_025
  ADDNPLUGIN(025)
#endif

  NPluginCall(NPLUGIN_PROTOCOL_ADD, 0);
}

byte NPluginCall(byte Function, struct EventStruct *event)
{
  int x;
  struct EventStruct TempEvent;

 if (event == 0)
    event=&TempEvent;

  switch (Function)
  {
    // Unconditional calls to all plugins
    case NPLUGIN_PROTOCOL_ADD:
      for (x = 0; x < NPLUGIN_MAX; x++)
        if (NPlugin_id[x] != 0)
          NPlugin_ptr[x](Function, event, dummyString);
      return true;
      break;
  }

  return false;
}
