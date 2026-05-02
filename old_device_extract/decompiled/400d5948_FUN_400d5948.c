// Function : FUN_400d5948
// Address  : 0x400d5948
// Size     : 115 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400d5948(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 auStack_74 [9];
  undefined4 uStack_50;
  undefined1 auStack_4c [40];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  uStack_50 = 0;
  auStack_74[0] = param_2;
  func_0x4008b3d8(auStack_4c,auStack_74,0x28);
  uVar1 = FUN_400d58a8(param_1,auStack_4c);
  FUN_400d3f28(auStack_4c);
  FUN_400d3f28(auStack_74);
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
    FUN_400d3f28(auStack_4c);
    FUN_400d3f28(auStack_74);
    thunk_FUN_401710d8(uVar1);
  }
  return;
}

