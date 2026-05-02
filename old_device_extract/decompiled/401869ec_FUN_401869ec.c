// Function : FUN_401869ec
// Address  : 0x401869ec
// Size     : 46 bytes


char * FUN_401869ec(char param_1,char *param_2,uint param_3)

{
  uint uVar1;
  
  while( true ) {
    if (param_3 < 2) {
      return (char *)0x0;
    }
    uVar1 = (byte)param_2[1] + 2;
    if (param_3 < uVar1) break;
    if (*param_2 == param_1) {
      return param_2;
    }
    param_3 = param_3 + (-2 - (uint)(byte)param_2[1]);
    param_2 = param_2 + uVar1;
  }
  return (char *)0x0;
}

