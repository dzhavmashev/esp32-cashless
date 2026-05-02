// Function : FUN_40185b00
// Address  : 0x40185b00
// Size     : 34 bytes


undefined4 FUN_40185b00(int *param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(*param_1 + 0xac);
  if (piVar1 != (int *)0x0) {
    for (; *piVar1 != 0; piVar1 = piVar1 + 1) {
      if (param_2 == *piVar1) {
        return 0;
      }
    }
  }
  return 0xffffffff;
}

