// Function : FUN_400f0834
// Address  : 0x400f0834
// Size     : 42 bytes


int FUN_400f0834(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_400f1a9c();
  param_1[3] = iVar1;
  do {
    iVar1 = (**(code **)(*param_1 + 0x1c))(param_1);
    if (-1 < iVar1) {
      return iVar1;
    }
    iVar1 = FUN_400f1a9c();
  } while ((uint)(iVar1 - param_1[3]) < (uint)param_1[2]);
  return -1;
}

