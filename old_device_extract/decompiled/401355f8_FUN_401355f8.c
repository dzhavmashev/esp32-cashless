// Function : FUN_401355f8
// Address  : 0x401355f8
// Size     : 24 bytes


int * FUN_401355f8(int param_1)

{
  int *piVar1;
  
  piVar1 = &DAT_3f41e048;
  while( true ) {
    if (*piVar1 == 0) {
      return (int *)0x0;
    }
    if (*piVar1 == param_1) break;
    piVar1 = piVar1 + 3;
  }
  return piVar1;
}

