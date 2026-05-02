// Function : FUN_40131cbc
// Address  : 0x40131cbc
// Size     : 91 bytes


int FUN_40131cbc(int *param_1,int *param_2,int *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *param_2;
  if (iVar3 * *param_3 * param_4 < 0) {
    iVar1 = FUN_40186078(param_2,param_3);
    if (iVar1 < 0) {
      iVar1 = FUN_40131bcc(param_1,param_3,param_2);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar3 = -iVar3;
    }
    else {
      iVar2 = FUN_40131bcc(param_1,param_2,param_3);
      if (iVar2 != 0) {
        return iVar2;
      }
      if (iVar1 == 0) {
        iVar3 = 1;
      }
    }
  }
  else {
    iVar1 = FUN_40131b00(param_1,param_2,param_3);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  *param_1 = iVar3;
  memw();
  return 0;
}

