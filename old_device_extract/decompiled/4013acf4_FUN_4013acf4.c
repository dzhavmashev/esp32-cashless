// Function : FUN_4013acf4
// Address  : 0x4013acf4
// Size     : 307 bytes


int FUN_4013acf4(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iStack_34;
  undefined1 auStack_30 [4];
  int iStack_2c;
  int iStack_28;
  
  if (param_3 == 0) {
    return -0x3d00;
  }
  FUN_401397d0(&iStack_2c);
  pcVar3 = (char *)(param_2 + param_3 + -1);
  if (*pcVar3 != '\0') goto LAB_4013add1;
  memw();
  iVar1 = FUN_401397e4(&iStack_2c,"EY-----","EY-----",param_2,0,0,auStack_30);
  if (iVar1 == 0) {
    iStack_34 = iStack_2c;
    memw();
    iVar1 = FUN_40139b60(1);
    if (iVar1 == 0) {
      FUN_40139ae0(&iStack_2c);
      return -0x3c80;
    }
    iVar1 = FUN_40139b8c(param_1,iVar1);
    if (iVar1 == 0) {
      iVar1 = iStack_34 + iStack_28;
      uVar2 = FUN_4013a008(*param_1,param_1[1]);
      iVar1 = FUN_4013a044(&iStack_34,iVar1,uVar2);
      if (iVar1 != 0) {
        FUN_40139b44(param_1);
      }
    }
  }
  else if (iVar1 == -0x1080) {
    if (*pcVar3 != '\0') {
LAB_4013add1:
      FUN_40139ae0(&iStack_2c);
      iVar1 = FUN_40139b60(1);
      if (iVar1 == 0) {
        return -0x3c80;
      }
      iVar1 = FUN_40139b8c(param_1,iVar1);
      if (iVar1 != 0) {
        return iVar1;
      }
      memw();
      iStack_34 = param_2;
      uVar2 = FUN_4013a008(*param_1,param_1[1]);
      iVar1 = FUN_4013a044(&iStack_34,param_2 + param_3,uVar2);
      if (iVar1 == 0) {
        return 0;
      }
      FUN_40139b44(param_1);
      if (iVar1 != -0x3b62) {
        return iVar1;
      }
      memw();
      iStack_34 = param_2;
      iVar1 = FUN_4013a9d8(&iStack_34,param_2 + param_3,param_1);
      return iVar1;
    }
    memw();
    iVar1 = FUN_401397e4(&iStack_2c,"EY-----","EY-----",param_2,0,0,auStack_30);
    if (iVar1 == 0) {
      iStack_34 = iStack_2c;
      memw();
      iVar1 = FUN_4013a9d8(&iStack_34,iStack_2c + iStack_28,param_1);
    }
    else if (iVar1 == -0x1080) goto LAB_4013add1;
  }
  FUN_40139ae0(&iStack_2c);
  return iVar1;
}

