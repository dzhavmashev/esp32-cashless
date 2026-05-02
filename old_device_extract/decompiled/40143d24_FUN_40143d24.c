// Function : FUN_40143d24
// Address  : 0x40143d24
// Size     : 119 bytes


int FUN_40143d24(undefined4 param_1,int *param_2,undefined4 param_3,int *param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = -0x2800;
  if (*param_5 == 0) {
    iVar1 = FUN_401394d8(param_1,param_3,param_4);
    if (iVar1 == 0) {
      if (*param_4 == 6) {
        iVar2 = FUN_4013ae30(1,8);
        iVar1 = -0x2880;
        if (iVar2 != 0) {
          iVar1 = FUN_40143800(param_2,param_3,iVar2,iVar2 + 4);
          if (iVar1 == 0) {
            *param_5 = iVar2;
            memw();
          }
          else {
            FUN_4013ae44(iVar2);
          }
        }
      }
      else if (((*param_2 != 5) && (*param_2 != 0)) || (iVar1 = 0, param_2[1] != 0)) {
        iVar1 = -0x2300;
      }
    }
    else {
      iVar1 = iVar1 + -0x2600;
    }
  }
  return iVar1;
}

