// Function : FUN_40184bb4
// Address  : 0x40184bb4
// Size     : 28 bytes


void FUN_40184bb4(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = param_1[1];
  if (iVar1 != 0) {
    *(int **)(iVar1 + 4) = param_2;
  }
  *param_2 = iVar1;
  param_2[1] = 0;
  param_1[1] = (int)param_2;
  if (*param_1 == 0) {
    *param_1 = (int)param_2;
  }
  param_1[2] = param_1[2] + 1;
  memw();
  return;
}

