// Function : FUN_4012d7a8
// Address  : 0x4012d7a8
// Size     : 25 bytes


int * FUN_4012d7a8(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)0x3f41bca8;
  while( true ) {
    if (*piVar1 == 0) {
      return (int *)0x0;
    }
    if (*piVar1 == param_1) break;
    piVar1 = piVar1 + 10;
  }
  return piVar1;
}

