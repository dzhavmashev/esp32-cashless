// Function : FUN_40135610
// Address  : 0x40135610
// Size     : 26 bytes


int * FUN_40135610(short param_1)

{
  int *piVar1;
  
  piVar1 = &DAT_3f41e048;
  do {
    if ((short)piVar1[1] == param_1) {
      return piVar1;
    }
    piVar1 = piVar1 + 3;
  } while (*piVar1 != 0);
  return (int *)0x0;
}

