// Function : FUN_400fa6e4
// Address  : 0x400fa6e4
// Size     : 57 bytes


void FUN_400fa6e4(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  
  while (piVar2 = (int *)*param_1, piVar2 != (int *)0x0) {
    iVar1 = *piVar2;
    piVar2 = (int *)piVar2[1];
    if (iVar1 == 0) {
      *param_1 = piVar2;
      memw();
    }
    else {
      *(int **)(iVar1 + 4) = piVar2;
    }
    if (piVar2 == (int *)0x0) {
      param_1[1] = iVar1;
      memw();
    }
    else {
      *piVar2 = iVar1;
    }
    param_1[2] = param_1[2] + -1;
    memw();
    (*(code *)&SUB_40094d80)();
  }
  return;
}

