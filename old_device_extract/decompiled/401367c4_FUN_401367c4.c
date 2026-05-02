// Function : FUN_401367c4
// Address  : 0x401367c4
// Size     : 142 bytes


int FUN_401367c4(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_40131ad8(param_3,0);
  if (iVar1 == 0) {
    iVar1 = FUN_40136114(param_1,param_4);
    if (iVar1 == 0) {
      iVar1 = FUN_40135764(param_2);
    }
  }
  else {
    iVar1 = FUN_40131ad8(param_3,1);
    if (iVar1 == 0) {
      iVar1 = FUN_40136114(param_1,param_4);
      if (iVar1 == 0) {
        iVar1 = FUN_4013572c(param_2,param_4);
      }
    }
    else {
      iVar1 = FUN_40131ad8(param_3,0xffffffff);
      if (iVar1 == 0) {
        iVar1 = FUN_40136114(param_1,param_4);
        if ((iVar1 == 0) && (iVar1 = FUN_4013572c(param_2,param_4), iVar1 == 0)) {
          param_2 = param_2 + 0xc;
          iVar2 = FUN_40131ad8(param_2,0);
          iVar1 = 0;
          if (iVar2 != 0) {
            iVar1 = FUN_40131d30(param_2,param_1 + 4,param_2);
          }
        }
      }
      else {
        memw();
        iVar1 = FUN_4013633c(param_1,param_2,param_3,param_4,0,0,param_5);
      }
    }
  }
  return iVar1;
}

