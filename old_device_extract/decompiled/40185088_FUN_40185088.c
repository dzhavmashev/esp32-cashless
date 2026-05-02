// Function : FUN_40185088
// Address  : 0x40185088
// Size     : 17 bytes


int FUN_40185088(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  *(int *)(param_1 + 4) = param_2 + iVar1;
  memw();
  return *(int *)(param_1 + 8) + iVar1;
}

