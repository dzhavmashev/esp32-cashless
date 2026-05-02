// Function : FUN_4013c708
// Address  : 0x4013c708
// Size     : 161 bytes


int FUN_4013c708(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined1 auStack_38 [12];
  undefined1 auStack_2c [44];
  
  if ((((param_4 == 0) || (iVar1 = FUN_40131ad8(param_4,0), iVar1 != 0)) ||
      (iVar1 = FUN_40131ad8(param_1,1), iVar1 < 1)) ||
     ((iVar1 = FUN_40131ad8(param_2,1), iVar1 < 1 || (iVar1 = FUN_40131ad8(param_3,0), iVar1 == 0)))
     ) {
    iVar1 = -4;
  }
  else {
    FUN_40186008(auStack_38);
    FUN_40186008(auStack_2c);
    iVar1 = FUN_40131d74(auStack_38,param_1,1);
    if ((((iVar1 == 0) &&
         ((iVar1 = FUN_40131d74(auStack_2c,param_2,1), iVar1 == 0 &&
          (iVar1 = FUN_401322b4(param_4,auStack_38,auStack_2c), iVar1 == 0)))) &&
        (iVar1 = FUN_4013d5d8(auStack_38,auStack_38,auStack_2c), iVar1 == 0)) &&
       (iVar1 = FUN_40131da0(auStack_38,0,auStack_38,param_4), iVar1 == 0)) {
      iVar1 = FUN_40132650(param_4,param_3,auStack_38);
    }
    FUN_40131548(auStack_38);
    FUN_40131548(auStack_2c);
  }
  return iVar1;
}

