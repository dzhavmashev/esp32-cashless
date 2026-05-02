// Function : FUN_400da1f8
// Address  : 0x400da1f8
// Size     : 155 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400da1f8(int param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 uStack_38;
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_400f0780(0x3ffc5490,"on type");
  FUN_400f0be8(auStack_34,"on lost");
  if (*(int *)(param_1 + 0x10) == 1) {
    pcVar2 = "Unknown";
  }
  else {
    if (*(int *)(param_1 + 0x10) != 2) goto LAB_400da228;
    pcVar2 = "nnected";
  }
  FUN_400f0d70(auStack_34,pcVar2);
LAB_400da228:
  if (*(int *)(param_1 + 100) != 0) {
    uStack_38 = *(undefined4 *)(param_1 + 0x10);
    (**(code **)(param_1 + 0x68))(param_1 + 0x5c,&uStack_38,auStack_34);
  }
  FUN_400d9fe0(param_1,0);
  *(undefined1 *)(param_1 + 0x1c) = 0;
  FUN_400f0a50(auStack_34);
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

