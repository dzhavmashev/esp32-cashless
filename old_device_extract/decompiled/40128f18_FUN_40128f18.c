// Function : FUN_40128f18
// Address  : 0x40128f18
// Size     : 224 bytes


int FUN_40128f18(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_44 [12];
  undefined1 auStack_38 [12];
  undefined1 auStack_2c [44];
  
  iVar1 = (*(code *)&SUB_40094dd8)(1,0xc);
  if (iVar1 != 0) {
    FUN_40186008(auStack_44);
    FUN_40186008(auStack_38);
    FUN_40186008(auStack_2c);
    FUN_40186008(iVar1);
    iVar2 = FUN_4013d5d8(auStack_44,param_2,param_2);
    if ((iVar2 == 0) && (iVar2 = FUN_4013d5d8(auStack_44,auStack_44,param_2), iVar2 == 0)) {
      iVar3 = param_1 + 4;
      iVar2 = FUN_401320e0(auStack_44,auStack_44,iVar3);
      if (((iVar2 == 0) &&
          (((iVar2 = FUN_40131700(auStack_2c,0xfffffffd), iVar2 == 0 &&
            (iVar2 = FUN_4013d5d8(auStack_38,param_2,auStack_2c), iVar2 == 0)) &&
           (iVar2 = FUN_401320e0(auStack_38,auStack_38,iVar3), iVar2 == 0)))) &&
         (((iVar2 = FUN_40131d18(auStack_38,auStack_38,param_1 + 0x1c), iVar2 == 0 &&
           (iVar2 = FUN_401320e0(auStack_38,auStack_38,iVar3), iVar2 == 0)) &&
          (iVar2 = FUN_40131d18(auStack_38,auStack_38,auStack_44), iVar2 == 0)))) {
        iVar2 = FUN_401320e0(iVar1,auStack_38,iVar3);
      }
    }
    FUN_40131548(auStack_44);
    FUN_40131548(auStack_38);
    FUN_40131548(auStack_2c);
    if (iVar2 != 0) {
      FUN_40131548(iVar1);
      (*(code *)&SUB_40094d80)(iVar1);
      iVar1 = 0;
    }
  }
  return iVar1;
}

