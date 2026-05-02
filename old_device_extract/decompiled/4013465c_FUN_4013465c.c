// Function : FUN_4013465c
// Address  : 0x4013465c
// Size     : 84 bytes


int FUN_4013465c(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  
  if (*param_1 == 0) {
    iVar1 = FUN_401378f0(param_1);
    if (iVar1 != 0) {
      return -0x4e80;
    }
  }
  else if (*param_2 != *param_1) {
    return -0x4f80;
  }
  if (param_3 == 1) {
    iVar1 = FUN_4013572c(param_1 + 0x2b,param_2 + 0x22);
    return iVar1;
  }
  if (param_3 != 0) {
    return -0x4f80;
  }
  iVar1 = FUN_4013572c(param_1 + 0x22,param_2 + 0x22);
  if (iVar1 == 0) {
    iVar1 = FUN_4013167c(param_1 + 0x1f,param_2 + 0x1f);
    return iVar1;
  }
  return iVar1;
}

