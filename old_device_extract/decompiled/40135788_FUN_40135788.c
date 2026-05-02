// Function : FUN_40135788
// Address  : 0x40135788
// Size     : 581 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40135788(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_74 [12];
  undefined1 auStack_68 [12];
  undefined1 auStack_5c [12];
  undefined1 auStack_50 [12];
  undefined1 auStack_44 [12];
  undefined1 auStack_38 [12];
  undefined1 auStack_2c [44];
  
  _DAT_3ffc78c8 = _DAT_3ffc78c8 + 1;
  iVar3 = param_3 + 0x18;
  memw();
  iVar1 = FUN_40131ad8(iVar3,0);
  iVar2 = param_4;
  if (iVar1 == 0) {
LAB_4013589e:
    iVar2 = FUN_4013572c(param_2,iVar2);
  }
  else {
    if (*(int *)(param_4 + 0x20) != 0) {
      iVar1 = FUN_40131ad8(param_4 + 0x18,0);
      iVar2 = param_3;
      if (iVar1 == 0) goto LAB_4013589e;
      if ((*(int *)(param_4 + 0x20) != 0) && (iVar2 = FUN_40131ad8(param_4 + 0x18,1), iVar2 != 0)) {
        return -0x4f80;
      }
    }
    FUN_40186008(auStack_74);
    FUN_40186008(auStack_68);
    FUN_40186008(auStack_5c);
    FUN_40186008(auStack_50);
    FUN_40186008(auStack_44);
    FUN_40186008(auStack_38);
    FUN_40186008(auStack_2c);
    iVar2 = FUN_40134f44(param_1,auStack_74,iVar3,iVar3);
    if ((((iVar2 == 0) && (iVar2 = FUN_40134f44(param_1,auStack_68,auStack_74,iVar3), iVar2 == 0))
        && (iVar2 = FUN_40134f44(param_1,auStack_74,auStack_74,param_4), iVar2 == 0)) &&
       ((iVar2 = FUN_40134f44(param_1,auStack_68,auStack_68,param_4 + 0xc), iVar2 == 0 &&
        (iVar2 = FUN_40134ebc(param_1,auStack_74,auStack_74,param_3), iVar2 == 0)))) {
      iVar2 = FUN_40134ebc(param_1,auStack_68,auStack_68,param_3 + 0xc);
      if (iVar2 == 0) {
        iVar2 = FUN_40131ad8(auStack_74,0);
        if (iVar2 == 0) {
          iVar2 = FUN_40131ad8(auStack_68,0);
          if (iVar2 == 0) {
            iVar2 = FUN_40135374(param_1,param_2,param_3);
          }
          else {
            iVar2 = FUN_40135764(param_2);
          }
        }
        else {
          iVar2 = FUN_40134f44(param_1,auStack_2c,iVar3,auStack_74);
          if (((((iVar2 == 0) && (iVar2 = FUN_40134f44(param_1,auStack_5c,auStack_74), iVar2 == 0))
               && ((iVar2 = FUN_40134f44(param_1,auStack_50,auStack_5c,auStack_74), iVar2 == 0 &&
                   (((iVar2 = FUN_40134f44(param_1,auStack_5c,auStack_5c,param_3), iVar2 == 0 &&
                     (iVar2 = FUN_4013167c(auStack_74,auStack_5c), iVar2 == 0)) &&
                    (iVar2 = FUN_40135358(param_1,auStack_74), iVar2 == 0)))))) &&
              ((iVar2 = FUN_40134f44(param_1,auStack_44,auStack_68), iVar2 == 0 &&
               (iVar2 = FUN_40134ebc(param_1,auStack_44,auStack_44,auStack_74), iVar2 == 0)))) &&
             ((iVar2 = FUN_40134ebc(param_1,auStack_44,auStack_44,auStack_50), iVar2 == 0 &&
              (((iVar2 = FUN_40134ebc(param_1,auStack_5c,auStack_5c,auStack_44), iVar2 == 0 &&
                (iVar2 = FUN_40134f44(param_1,auStack_5c,auStack_5c,auStack_68), iVar2 == 0)) &&
               ((iVar2 = FUN_40134f44(param_1,auStack_50,auStack_50,param_3 + 0xc), iVar2 == 0 &&
                (((iVar2 = FUN_40134ebc(param_1,auStack_38,auStack_5c,auStack_50), iVar2 == 0 &&
                  (iVar2 = FUN_4013167c(param_2,auStack_44), iVar2 == 0)) &&
                 (iVar2 = FUN_4013167c(param_2 + 0xc,auStack_38), iVar2 == 0)))))))))) {
            iVar2 = FUN_4013167c(param_2 + 0x18,auStack_2c);
          }
        }
      }
    }
    FUN_40131548(auStack_74);
    FUN_40131548(auStack_68);
    FUN_40131548(auStack_5c);
    FUN_40131548(auStack_50);
    FUN_40131548(auStack_44);
    FUN_40131548(auStack_38);
    FUN_40131548(auStack_2c);
  }
  return iVar2;
}

