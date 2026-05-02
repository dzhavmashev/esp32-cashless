// Function : FUN_4013c8d0
// Address  : 0x4013c8d0
// Size     : 475 bytes


int FUN_4013c8d0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                undefined4 param_7)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined1 auStack_38 [12];
  undefined1 auStack_2c [44];
  
  memw();
  FUN_40186008(auStack_38);
  FUN_40186008(auStack_2c);
  bVar1 = param_2 != 0;
  if ((param_6 != 0) && (bVar1)) {
    memw();
    iVar3 = FUN_40132914(param_2,0x32,param_6,param_7);
    if (iVar3 == 0) goto LAB_4013c904;
  }
  else {
LAB_4013c904:
    bVar2 = param_3 != 0;
    if ((param_6 != 0) && (bVar2)) {
      memw();
      iVar3 = FUN_40132914(param_3,0x32,param_6,param_7);
      if (iVar3 != 0) goto LAB_4013c9d9;
    }
    if ((bVar1 && bVar2) && (param_1 != 0)) {
      memw();
      iVar3 = FUN_4013d5d8(auStack_38,param_2,param_3);
      if (iVar3 != 0) goto LAB_4013c9dc;
      iVar3 = FUN_40131ad8(param_1,1);
      if ((iVar3 < 1) || (iVar3 = FUN_401860ec(auStack_38,param_1), iVar3 != 0)) goto LAB_4013c9d9;
    }
    if ((param_4 == 0 || param_5 == 0) || (param_1 == 0)) {
      if ((!bVar1 || !bVar2) || (param_4 == 0 || param_5 == 0)) goto LAB_4013caa8;
LAB_4013ca06:
      iVar3 = FUN_40131ad8(param_2,1);
      if ((0 < iVar3) && (iVar3 = FUN_40131ad8(param_3,1), 0 < iVar3)) {
        iVar3 = FUN_4013d5d8(auStack_38,param_4,param_5);
        if (((iVar3 != 0) ||
            ((iVar3 = FUN_40131d74(auStack_38,auStack_38,1), iVar3 != 0 ||
             (iVar3 = FUN_40131d74(auStack_2c,param_2,1), iVar3 != 0)))) ||
           (iVar3 = FUN_401320e0(auStack_38,auStack_38,auStack_2c), iVar3 != 0)) goto LAB_4013c9dc;
        iVar3 = FUN_40131ad8(auStack_38);
        if (iVar3 == 0) {
          iVar3 = FUN_4013d5d8(auStack_38,param_4,param_5);
          if ((((iVar3 != 0) || (iVar3 = FUN_40131d74(auStack_38,auStack_38,1), iVar3 != 0)) ||
              (iVar3 = FUN_40131d74(auStack_2c,param_3,1), iVar3 != 0)) ||
             (iVar3 = FUN_401320e0(auStack_38,auStack_38,auStack_2c), iVar3 != 0))
          goto LAB_4013c9dc;
          iVar3 = FUN_40131ad8(auStack_38);
          if (iVar3 == 0) goto LAB_4013caa8;
        }
      }
    }
    else {
      memw();
      iVar3 = FUN_40131ad8(param_4,1);
      if ((0 < iVar3) &&
         (((iVar3 = FUN_40131ad8(param_5,1), 0 < iVar3 &&
           (iVar3 = FUN_401860ec(param_4,param_1), iVar3 < 0)) &&
          (iVar3 = FUN_401860ec(param_5,param_1), iVar3 < 0)))) {
        if (bVar1 && bVar2) goto LAB_4013ca06;
LAB_4013caa8:
        iVar3 = 0;
        goto LAB_4013c9dc;
      }
    }
  }
LAB_4013c9d9:
  iVar3 = -0x4200;
LAB_4013c9dc:
  memw();
  FUN_40131548(auStack_38);
  FUN_40131548(auStack_2c);
  if ((iVar3 != 0) && (iVar3 != -0x4200)) {
    iVar3 = iVar3 + -0x4200;
  }
  return iVar3;
}

