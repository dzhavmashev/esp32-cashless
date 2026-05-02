// Function : FUN_400f0650
// Address  : 0x400f0650
// Size     : 50 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400f0650(undefined4 param_1,undefined4 param_2)

{
  undefined1 auStack_45 [33];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_400f0630(param_2,auStack_45);
  FUN_400f0be8(param_1,auStack_45);
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
  }
  return;
}

