// Function : FUN_40184490
// Address  : 0x40184490
// Size     : 14 bytes


void FUN_40184490(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    param_1[1] = iVar1;
    *param_1 = *(int *)(iVar1 + 0x2c);
  }
  return;
}

