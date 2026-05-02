// Function : FUN_40135374
// Address  : 0x40135374
// Size     : 589 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40135374(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_50 [12];
  undefined1 auStack_44 [12];
  undefined1 auStack_38 [12];
  undefined1 auStack_2c [44];
  
  _DAT_3ffc78c4 = _DAT_3ffc78c4 + 1;
  memw();
  FUN_40186008(auStack_50);
  FUN_40186008(auStack_44);
  FUN_40186008(auStack_38);
  FUN_40186008(auStack_2c);
  if (*(int *)(param_1 + 0x18) == 0) {
    iVar1 = FUN_40134f44(param_1,auStack_44,param_3 + 0x18,param_3 + 0x18);
    if (((iVar1 == 0) && (iVar1 = FUN_40134f28(param_1,auStack_38,param_3,auStack_44), iVar1 == 0))
       && ((iVar1 = FUN_40134ebc(param_1,auStack_2c,param_3,auStack_44), iVar1 == 0 &&
           ((iVar1 = FUN_40134f44(param_1,auStack_44,auStack_38,auStack_2c), iVar1 == 0 &&
            (iVar1 = FUN_4013d778(auStack_50,auStack_44,3), iVar1 == 0)))))) {
      do {
        iVar1 = FUN_401860ec(auStack_50,param_1 + 4);
        if (iVar1 < 0) goto LAB_40135400;
        iVar1 = FUN_40131bcc(auStack_50,auStack_50,param_1 + 4);
      } while (iVar1 == 0);
    }
  }
  else {
    iVar1 = FUN_40134f44(param_1,auStack_44,param_3,param_3);
    if ((iVar1 == 0) && (iVar1 = FUN_4013d778(auStack_50,auStack_44,3), iVar1 == 0)) {
      do {
        iVar1 = FUN_401860ec(auStack_50,param_1 + 4);
        if (iVar1 < 0) {
          iVar1 = FUN_40131ad8(param_1 + 0x10,0);
          if ((iVar1 == 0) ||
             ((((iVar1 = FUN_40134f44(param_1,auStack_44,param_3 + 0x18,param_3 + 0x18), iVar1 == 0
                && (iVar1 = FUN_40134f44(param_1,auStack_38,auStack_44), iVar1 == 0)) &&
               (iVar1 = FUN_40134f44(param_1,auStack_44,auStack_38,param_1 + 0x10), iVar1 == 0)) &&
              (iVar1 = FUN_40134f28(param_1,auStack_50,auStack_50,auStack_44), iVar1 == 0))))
          goto LAB_40135400;
          break;
        }
        iVar1 = FUN_40131bcc(auStack_50,auStack_50,param_1 + 4);
      } while (iVar1 == 0);
    }
  }
LAB_40135516:
  FUN_40131548(auStack_50);
  FUN_40131548(auStack_44);
  FUN_40131548(auStack_38);
  FUN_40131548(auStack_2c);
  return;
LAB_40135400:
  iVar2 = param_3 + 0xc;
  iVar1 = FUN_40134f44(param_1,auStack_38,iVar2,iVar2);
  if (((((iVar1 == 0) && (iVar1 = FUN_40135358(param_1,auStack_38), iVar1 == 0)) &&
       (iVar1 = FUN_40134f44(param_1,auStack_44,param_3,auStack_38), iVar1 == 0)) &&
      ((iVar1 = FUN_40135358(param_1,auStack_44), iVar1 == 0 &&
       (iVar1 = FUN_40134f44(param_1,auStack_2c,auStack_38), iVar1 == 0)))) &&
     (((((iVar1 = FUN_40135358(param_1,auStack_2c), iVar1 == 0 &&
         ((iVar1 = FUN_40134f44(param_1,auStack_38,auStack_50,auStack_50), iVar1 == 0 &&
          (iVar1 = FUN_40134ebc(param_1,auStack_38,auStack_38,auStack_44), iVar1 == 0)))) &&
        (iVar1 = FUN_40134ebc(param_1,auStack_38,auStack_38,auStack_44), iVar1 == 0)) &&
       (((iVar1 = FUN_40134ebc(param_1,auStack_44,auStack_44,auStack_38), iVar1 == 0 &&
         (iVar1 = FUN_40134f44(param_1,auStack_44,auStack_44,auStack_50), iVar1 == 0)) &&
        (iVar1 = FUN_40134ebc(param_1,auStack_44,auStack_44,auStack_2c), iVar1 == 0)))) &&
      (((iVar1 = FUN_40134f44(param_1,auStack_2c,iVar2,param_3 + 0x18), iVar1 == 0 &&
        (iVar1 = FUN_40135358(param_1,auStack_2c), iVar1 == 0)) &&
       ((iVar1 = FUN_4013167c(param_2,auStack_38), iVar1 == 0 &&
        (iVar1 = FUN_4013167c(param_2 + 0xc,auStack_44), iVar1 == 0)))))))) {
    FUN_4013167c(param_2 + 0x18,auStack_2c);
  }
  goto LAB_40135516;
}

