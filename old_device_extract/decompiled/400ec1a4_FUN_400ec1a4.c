// Function : FUN_400ec1a4
// Address  : 0x400ec1a4
// Size     : 32 bytes


int FUN_400ec1a4(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_2 < *(uint *)(param_1 + 8)) {
    if (*(int *)(param_1 + 0x20) == 0) {
      iVar1 = *(uint *)(param_1 + 8) - param_2;
    }
    else {
      iVar1 = FUN_400ec104(param_1,param_2);
    }
  }
  return iVar1;
}

