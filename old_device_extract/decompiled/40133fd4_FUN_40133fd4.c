// Function : FUN_40133fd4
// Address  : 0x40133fd4
// Size     : 54 bytes


int FUN_40133fd4(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_2c [44];
  
  FUN_40186008(auStack_2c);
  iVar1 = FUN_40131d74(auStack_2c,param_2,2);
  if ((iVar1 == 0) &&
     ((iVar2 = FUN_40131ad8(param_1,2), iVar2 < 0 ||
      (iVar2 = FUN_401860ec(param_1,auStack_2c), 0 < iVar2)))) {
    iVar1 = -0x3080;
  }
  FUN_40131548(auStack_2c);
  return iVar1;
}

