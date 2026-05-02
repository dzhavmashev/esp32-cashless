// Function : FUN_400f1084
// Address  : 0x400f1084
// Size     : 59 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400f1084(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined1 auStack_31 [13];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  func_0x4008d4fc(param_2,auStack_31,10);
  uVar1 = func_0x4008c024(auStack_31);
  uVar1 = FUN_400f0f40(param_1,auStack_31,uVar1);
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
  }
  return uVar1;
}

