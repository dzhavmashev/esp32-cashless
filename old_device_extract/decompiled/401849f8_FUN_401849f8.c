// Function : FUN_401849f8
// Address  : 0x401849f8
// Size     : 36 bytes


void FUN_401849f8(undefined4 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_2;
  piVar2 = (int *)param_2[1];
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
  return;
}

