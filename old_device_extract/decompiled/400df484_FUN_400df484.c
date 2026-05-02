// Function : FUN_400df484
// Address  : 0x400df484
// Size     : 46 bytes


char * FUN_400df484(uint param_1)

{
  char *pcVar1;
  
  pcVar1 = "NACTIVE";
  if (param_1 != 2) {
    if (param_1 < 3) {
      if (param_1 == 0) {
        return "ore 1)\n";
      }
      if (param_1 == 1) {
        return "ENABLED";
      }
    }
    else {
      if (param_1 == 3) {
        return "s found";
      }
      if (param_1 == 4) {
        return "started";
      }
    }
    pcVar1 = "_OPTION_UNKNOWN";
  }
  return pcVar1;
}

