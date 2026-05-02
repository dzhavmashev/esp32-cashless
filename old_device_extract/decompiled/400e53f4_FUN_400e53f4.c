// Function : FUN_400e53f4
// Address  : 0x400e53f4
// Size     : 142 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e53f4(int param_1)

{
  int iVar1;
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_400f0780(0x3ffc5490,"updates");
  if (*(int *)(param_1 + 4) == 3) {
    FUN_400eda70(param_1 + 0xfc);
    FUN_400ed5d8(0x3ffc5340);
  }
  FUN_400e53ac(param_1);
  FUN_400f0be8(auStack_34,"date...");
  FUN_400e4a64(param_1,10,auStack_34);
  FUN_400f0a50(auStack_34);
  FUN_400e4b9c(param_1,7);
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

