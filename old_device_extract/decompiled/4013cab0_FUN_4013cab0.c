// Function : FUN_4013cab0
// Address  : 0x4013cab0
// Size     : 118 bytes


int FUN_4013cab0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
                int param_6)

{
  int iVar1;
  undefined1 auStack_2c [44];
  
  FUN_40186008(auStack_2c);
  if ((((param_4 == 0) ||
       ((iVar1 = FUN_40131d74(auStack_2c,param_1,1), iVar1 == 0 &&
        (iVar1 = FUN_401320e0(param_4,param_3,auStack_2c), iVar1 == 0)))) &&
      ((param_5 == 0 ||
       ((iVar1 = FUN_40131d74(auStack_2c,param_2,1), iVar1 == 0 &&
        (iVar1 = FUN_401320e0(param_5,param_3,auStack_2c), iVar1 == 0)))))) &&
     (iVar1 = 0, param_6 != 0)) {
    iVar1 = FUN_40132650(param_6,param_2,param_1);
  }
  memw();
  FUN_40131548(auStack_2c);
  return iVar1;
}

