// Function : FUN_400e05b8
// Address  : 0x400e05b8
// Size     : 52 bytes


char * FUN_400e05b8(byte param_1)

{
  char *pcVar1;
  
  pcVar1 = "t_based";
  if (param_1 != 2) {
    if (param_1 < 3) {
      if (param_1 == 0) {
        return "ecovery";
      }
      if (param_1 == 1) {
        return "";
      }
    }
    else {
      if (param_1 == 4) {
        return "h_relay";
      }
      if (param_1 < 4) {
        return "r_based";
      }
      if (param_1 == 5) {
        return "lay";
      }
    }
    pcVar1 = " OID is unknown";
  }
  return pcVar1;
}

