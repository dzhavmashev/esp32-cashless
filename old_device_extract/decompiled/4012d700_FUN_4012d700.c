// Function : FUN_4012d700
// Address  : 0x4012d700
// Size     : 80 bytes


int FUN_4012d700(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  
  if (*param_1 < 0) {
    return -0x45;
  }
  iVar1 = (*(code *)&SUB_400017dc)(*param_1,param_2,param_3);
  if (iVar1 < 0) {
    iVar1 = FUN_4012d6e0();
    if (iVar1 == 0) {
      piVar2 = (int *)FUN_40173a8c();
      if ((*piVar2 == 0x20) || (piVar2 = (int *)FUN_40173a8c(), *piVar2 == 0x68)) {
        return -0x50;
      }
      piVar2 = (int *)FUN_40173a8c();
      if (*piVar2 != 4) {
        return -0x4c;
      }
    }
    return -0x6900;
  }
  return iVar1;
}

