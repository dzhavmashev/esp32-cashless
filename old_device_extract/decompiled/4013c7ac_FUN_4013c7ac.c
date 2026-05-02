// Function : FUN_4013c7ac
// Address  : 0x4013c7ac
// Size     : 285 bytes


int FUN_4013c7ac(int param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  undefined1 auStack_38 [12];
  undefined1 auStack_2c [44];
  
  FUN_40186008(auStack_38);
  FUN_40186008(auStack_2c);
  if (param_4 == 0) {
LAB_4013c7c4:
    if (param_5 != 0) {
      if (param_2 == 0) goto LAB_4013c7d4;
      iVar1 = FUN_40131d74(auStack_38,param_2,1);
      if (((iVar1 != 0) || (iVar1 = FUN_40131d30(auStack_2c,param_5,param_3), iVar1 != 0)) ||
         (iVar1 = FUN_401320e0(auStack_2c,auStack_2c,auStack_38), iVar1 != 0)) goto LAB_4013c7d7;
      iVar1 = FUN_40131ad8(auStack_2c);
      if (iVar1 != 0) goto LAB_4013c83f;
    }
    if (param_6 != 0) {
      if ((param_1 == 0) || (param_2 == 0)) goto LAB_4013c7d4;
      iVar1 = FUN_4013d5d8(auStack_38,param_6,param_2);
      if ((iVar1 != 0) ||
         ((iVar1 = FUN_40131d74(auStack_38,auStack_38,1), iVar1 != 0 ||
          (iVar1 = FUN_401320e0(auStack_38,auStack_38,param_1), iVar1 != 0)))) goto LAB_4013c7d7;
      iVar1 = FUN_40131ad8(auStack_38);
      if (iVar1 != 0) goto LAB_4013c83f;
    }
    iVar1 = 0;
  }
  else {
    if (param_1 != 0) {
      iVar1 = FUN_40131d74(auStack_38,param_1,1);
      if (((iVar1 != 0) || (iVar1 = FUN_40131d30(auStack_2c,param_4,param_3), iVar1 != 0)) ||
         (iVar1 = FUN_401320e0(auStack_2c,auStack_2c,auStack_38), iVar1 != 0)) goto LAB_4013c7d7;
      iVar1 = FUN_40131ad8(auStack_2c);
      if (iVar1 == 0) goto LAB_4013c7c4;
LAB_4013c83f:
      iVar1 = -0x4200;
      goto LAB_4013c7d7;
    }
LAB_4013c7d4:
    iVar1 = -0x4080;
  }
LAB_4013c7d7:
  if (((iVar1 != 0) && (iVar1 != -0x4200)) && (iVar1 != -0x4080)) {
    iVar1 = iVar1 + -0x4200;
  }
  memw();
  FUN_40131548(auStack_38);
  FUN_40131548(auStack_2c);
  return iVar1;
}

