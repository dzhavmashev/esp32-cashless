// Function : FUN_400e5324
// Address  : 0x400e5324
// Size     : 134 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e5324(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_400f0780(0x3ffc5490,"ssfully");
  FUN_400f0780(0x3ffc5490,"rtTask");
  FUN_400f0be8(auStack_34,"ates...");
  FUN_400e4a64(param_1,1,auStack_34);
  FUN_400f0a50(auStack_34);
  FUN_400e4b9c(param_1,7);
  uVar2 = FUN_400f1a9c();
  *(undefined4 *)(param_1 + 0x1fc) = uVar2;
  iVar1 = _DAT_3ffc5708;
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
    FUN_400f0a50(auStack_34);
    thunk_FUN_401710d8(iVar1);
  }
  return;
}

