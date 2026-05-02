// Function : FUN_400fc83c
// Address  : 0x400fc83c
// Size     : 38 bytes


int FUN_400fc83c(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  
  puVar1 = (undefined4 *)(*(code *)&SUB_400916b4)(0);
  if (puVar1 != (undefined4 *)0x0) {
    for (piVar2 = (int *)*puVar1; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[2]) {
      if (param_1 == *piVar2) {
        return piVar2[1];
      }
    }
  }
  return 0;
}

