// Function : FUN_40134958
// Address  : 0x40134958
// Size     : 300 bytes


int FUN_40134958(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined1 auStack_74 [12];
  undefined1 auStack_68 [12];
  undefined1 auStack_5c [12];
  undefined1 auStack_50 [12];
  undefined1 auStack_44 [68];
  
  memw();
  FUN_4013562c(auStack_44);
  FUN_40186008(auStack_74);
  FUN_40186008(auStack_68);
  FUN_40186008(auStack_5c);
  FUN_40186008(auStack_50);
  if (*param_1 == 9) {
    return -0x4f80;
  }
  if (param_1[0x15] == 0) {
    return -0x4f80;
  }
  iVar1 = FUN_40131ad8(param_5,1);
  if (-1 < iVar1) {
    piVar3 = param_1 + 0x13;
    iVar1 = FUN_401860ec(param_5,piVar3);
    if (((iVar1 < 0) && (iVar1 = FUN_40131ad8(param_6,1), -1 < iVar1)) &&
       (iVar1 = FUN_401860ec(param_6,piVar3), iVar1 < 0)) {
      iVar1 = FUN_40134788(param_1,auStack_74,param_2,param_3);
      if ((((iVar1 != 0) || (iVar1 = FUN_40132650(auStack_68,param_6,piVar3), iVar1 != 0)) ||
          ((iVar1 = FUN_4013d5d8(auStack_5c,auStack_74,auStack_68), iVar1 != 0 ||
           ((iVar1 = FUN_401320e0(auStack_5c,auStack_5c,piVar3), iVar1 != 0 ||
            (iVar1 = FUN_4013d5d8(auStack_50,param_5,auStack_68), iVar1 != 0)))))) ||
         (iVar1 = FUN_401320e0(auStack_50,auStack_50,piVar3), iVar1 != 0)) goto LAB_40134a5c;
      memw();
      iVar1 = FUN_40136858(param_1,auStack_44,auStack_5c,param_1 + 10,auStack_50,param_4,0);
      if (iVar1 != 0) goto LAB_40134a5c;
      iVar1 = FUN_40135e44(auStack_44);
      if (iVar1 == 0) {
        iVar1 = FUN_401320e0(auStack_44,auStack_44,piVar3);
        if (iVar1 != 0) goto LAB_40134a5c;
        iVar2 = FUN_401860ec(auStack_44,param_5);
        iVar1 = 0;
        if (iVar2 == 0) goto LAB_40134a5c;
      }
    }
  }
  iVar1 = -0x4e00;
LAB_40134a5c:
  memw();
  FUN_401356a8(auStack_44);
  FUN_40131548(auStack_74);
  FUN_40131548(auStack_68);
  FUN_40131548(auStack_5c);
  FUN_40131548(auStack_50);
  return iVar1;
}

