// Function : FUN_40128e34
// Address  : 0x40128e34
// Size     : 58 bytes


int FUN_40128e34(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 auStack_2c [44];
  
  FUN_40186008(auStack_2c);
  iVar1 = FUN_40131700(auStack_2c,1);
  if (iVar1 == 0) {
    iVar1 = FUN_401368bc(param_1,param_4,auStack_2c,param_2,auStack_2c,param_3);
  }
  FUN_40131548(auStack_2c);
  return -(uint)(iVar1 != 0);
}

