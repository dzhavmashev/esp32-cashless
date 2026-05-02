// Function : FUN_40185ad8
// Address  : 0x40185ad8
// Size     : 34 bytes


undefined4 FUN_40185ad8(int *param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(*param_1 + 0xb0);
  if (piVar1 != (int *)0x0) {
    for (; *piVar1 != 0; piVar1 = piVar1 + 1) {
      if (*piVar1 == param_2) {
        return 0;
      }
    }
  }
  return 0xffffffff;
}

