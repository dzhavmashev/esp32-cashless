// Function : FUN_400d3874
// Address  : 0x400d3874
// Size     : 114 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400d3874(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_400f0be8(auStack_34,"omplete");
  uVar2 = FUN_400f10c0(auStack_34,param_2);
  FUN_400f0768(0x3ffc5490,uVar2);
  FUN_400f0a50(auStack_34);
  if (*(int *)(param_1 + 0x48) != 0) {
    (**(code **)(param_1 + 0x4c))(param_1 + 0x40,param_2);
  }
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

