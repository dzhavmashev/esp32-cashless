// Function : FUN_4013aacc
// Address  : 0x4013aacc
// Size     : 542 bytes


int FUN_4013aacc(undefined4 *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  undefined1 auStack_30 [4];
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  if (param_3 == 0) {
    return -0x3d00;
  }
  memw();
  FUN_401397d0(&uStack_2c);
  pcVar4 = (char *)(param_2 + param_3 + -1);
  if (*pcVar4 != '\0') goto LAB_4013ac2e;
  memw();
  iVar1 = FUN_401397e4(&uStack_2c,"EY-----",&DAT_3f4223ed,param_2,param_4,param_5,auStack_30);
  if (iVar1 == 0) {
    uVar2 = FUN_40139b60(1);
    iVar1 = FUN_40139b8c(param_1,uVar2);
    if (iVar1 == 0) {
      uVar2 = FUN_4013a008(*param_1,param_1[1]);
      iVar1 = FUN_4013a498(uVar2,uStack_2c,uStack_28);
      goto LAB_4013ab2c;
    }
  }
  else {
    if (iVar1 == -0x1380) {
      return -0x3b80;
    }
    if (iVar1 == -0x1300) {
      return -0x3c00;
    }
    if (iVar1 != -0x1080) {
      return iVar1;
    }
    if (*pcVar4 != '\0') goto LAB_4013ac2e;
    memw();
    iVar1 = FUN_401397e4(&uStack_2c,"EY-----","EY-----",param_2,param_4,param_5,auStack_30);
    if (iVar1 == 0) {
      uVar2 = FUN_40139b60(2);
      iVar1 = FUN_40139b8c(param_1,uVar2);
      if (iVar1 != 0) goto LAB_4013ab30;
      uVar2 = FUN_4013a024(*param_1,param_1[1]);
      iVar1 = FUN_4013a628(uVar2,uStack_2c,uStack_28);
    }
    else {
      if (iVar1 == -0x1380) {
        return -0x3b80;
      }
      if (iVar1 == -0x1300) {
        return -0x3c00;
      }
      if (iVar1 != -0x1080) {
        return iVar1;
      }
      if (*pcVar4 != '\0') goto LAB_4013ac2e;
      memw();
      iVar1 = FUN_401397e4(&uStack_2c,"EY-----","EY-----",param_2,0,0,auStack_30);
      if (iVar1 == 0) {
        iVar1 = FUN_4013a7f4(param_1,uStack_2c,uStack_28);
      }
      else {
        if (iVar1 != -0x1080) {
          return iVar1;
        }
        if (*pcVar4 != '\0') {
LAB_4013ac2e:
          iVar1 = FUN_4013ae30(1,param_3);
          if (iVar1 == 0) {
            return -0x3f80;
          }
          (*(code *)&SUB_4008b3d0)(iVar1,param_2,param_3);
          iVar3 = FUN_4013a8c4(param_1,iVar1,param_3,param_4,param_5);
          FUN_4013ae54(iVar1,param_3);
          FUN_4013ae44(iVar1);
          if (iVar3 != 0) {
            FUN_40139b44(param_1);
            FUN_401864dc(param_1);
            if (iVar3 == -0x3b80) {
              return -0x3b80;
            }
            iVar1 = FUN_4013a7f4(param_1,param_2,param_3);
            if (iVar1 != 0) {
              FUN_40139b44(param_1);
              FUN_401864dc(param_1);
              uVar2 = FUN_40139b60(1);
              iVar1 = FUN_40139b8c(param_1,uVar2);
              if (iVar1 == 0) {
                uVar2 = FUN_4013a008(*param_1,param_1[1]);
                iVar1 = FUN_4013a498(uVar2,param_2,param_3);
                if (iVar1 == 0) {
                  return 0;
                }
              }
              FUN_40139b44(param_1);
              FUN_401864dc(param_1);
              uVar2 = FUN_40139b60(2);
              iVar1 = FUN_40139b8c(param_1,uVar2);
              if (iVar1 == 0) {
                uVar2 = FUN_4013a024(*param_1,param_1[1]);
                iVar1 = FUN_4013a628(uVar2,param_2,param_3);
                if (iVar1 == 0) {
                  return 0;
                }
              }
              FUN_40139b44(param_1);
              return -0x3d00;
            }
          }
          return 0;
        }
        memw();
        iVar1 = FUN_401397e4(&uStack_2c,"EY-----","EY-----",param_2,0,0,auStack_30);
        if (iVar1 != 0) {
          if (iVar1 != -0x1080) {
            return iVar1;
          }
          goto LAB_4013ac2e;
        }
        iVar1 = FUN_4013a8c4(param_1,uStack_2c,uStack_28,param_4,param_5);
      }
    }
LAB_4013ab2c:
    if (iVar1 == 0) goto LAB_4013ab35;
  }
LAB_4013ab30:
  FUN_40139b44(param_1);
LAB_4013ab35:
  FUN_40139ae0(&uStack_2c);
  return iVar1;
}

