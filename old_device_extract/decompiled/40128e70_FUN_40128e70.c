// Function : FUN_40128e70
// Address  : 0x40128e70
// Size     : 128 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40128e70(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 auStack_2ec [76];
  undefined1 auStack_2a0 [636];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  memw();
  FUN_40137f54(auStack_2a0);
  FUN_40133d88(auStack_2ec);
  iVar1 = FUN_40133dcc(auStack_2ec,0x40137fd4,auStack_2a0,0);
  if (iVar1 == 0) {
    iVar1 = FUN_401367a4(param_1,param_4,param_3,param_2,0x40133f60,auStack_2ec);
  }
  FUN_40133da8(auStack_2ec);
  FUN_40137fb0(auStack_2a0);
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    (*(code *)&SUB_40082ec4)();
  }
  return -(uint)(iVar1 != 0);
}

