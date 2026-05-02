// Function : FUN_400ec1c4
// Address  : 0x400ec1c4
// Size     : 37 bytes


int FUN_400ec1c4(int param_1,uint param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x20) == 0) {
    iVar1 = *(int *)(param_1 + 4);
    if ((iVar1 != 0) && (iVar1 = iVar1 + param_2, *(uint *)(param_1 + 8) <= param_2)) {
      iVar1 = 0;
    }
  }
  else {
    iVar1 = (*(code *)&LAB_401844be_2)(param_1,param_2);
  }
  return iVar1;
}

