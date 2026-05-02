// Function : FUN_400f0dd0
// Address  : 0x400f0dd0
// Size     : 58 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400f0dd0(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  undefined1 auStack_46 [34];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_400f0a18(param_1);
  func_0x4008afa4(param_2,auStack_46,param_3);
  FUN_400f0d70(param_1,auStack_46);
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
  }
  return;
}

