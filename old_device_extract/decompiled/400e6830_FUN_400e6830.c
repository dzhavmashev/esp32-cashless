// Function : FUN_400e6830
// Address  : 0x400e6830
// Size     : 86 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e6830(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_400f0be8(auStack_34,param_2);
  uVar1 = FUN_400f12d8(param_1,auStack_34);
  FUN_400f0a50(auStack_34);
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
    FUN_400f0a50(auStack_34);
    thunk_FUN_401710d8(uVar1);
  }
  return;
}

