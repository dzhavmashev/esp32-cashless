// Function : FUN_400ee484
// Address  : 0x400ee484
// Size     : 29 bytes


int FUN_400ee484(int param_1,int param_2)

{
  int iVar1;
  
  if ((param_2 < 0) && (iVar1 = (*(code *)&LAB_40184637_1)(param_1), iVar1 != 0)) {
    (**(code **)(**(int **)(param_1 + 8) + 0x3c))();
  }
  return param_2;
}

