// Function : FUN_400dc5a0
// Address  : 0x400dc5a0
// Size     : 154 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400dc5a0(int param_1)

{
  int iVar1;
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  if (*(int *)(param_1 + 0x48) != 0) {
    func_0x4009246c(*(int *)(param_1 + 0x48),3,0,0);
  }
  memw();
  *(undefined1 *)(param_1 + 0x6f) = 0;
  *(undefined1 *)(param_1 + 0x30) = 0;
  *(undefined1 *)(param_1 + 0x70) = 0;
  FUN_400dc43c(param_1);
  FUN_400f0be8(auStack_34,"ev_act_estop");
  FUN_400dc0a0(param_1,auStack_34);
  FUN_400f0a50(auStack_34);
  *(undefined4 *)(param_1 + 0x38) = 0;
  iVar1 = *(int *)(param_1 + 0x3c);
  if (iVar1 != *(int *)(param_1 + 0x40)) {
    FUN_400dc588(iVar1);
    *(int *)(param_1 + 0x40) = iVar1;
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

