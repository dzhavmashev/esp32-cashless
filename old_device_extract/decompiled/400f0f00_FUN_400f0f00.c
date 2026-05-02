// Function : FUN_400f0f00
// Address  : 0x400f0f00
// Size     : 62 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400f0f00(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined1 param_5)

{
  undefined1 auStack_65 [65];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_400f0a18(param_1);
  FUN_400f311c(param_3,param_4,auStack_65,param_5);
  FUN_400f0d70(param_1,auStack_65);
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
  }
  return;
}

