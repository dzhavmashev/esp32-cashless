// Function : FUN_400eddd4
// Address  : 0x400eddd4
// Size     : 46 bytes


void FUN_400eddd4(int param_1,ushort param_2)

{
  int iVar1;
  
  *(ushort *)(param_1 + 0x26) = param_2;
  iVar1 = (*(code *)&LAB_40184637_1)(param_1);
  if (iVar1 != 0) {
    (**(code **)(**(int **)(param_1 + 8) + 0x50))(*(int **)(param_1 + 8),(param_2 + 500) / 1000);
  }
  return;
}

