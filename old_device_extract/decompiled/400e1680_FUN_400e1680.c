// Function : FUN_400e1680
// Address  : 0x400e1680
// Size     : 175 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e1680(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined1 auStack_48 [16];
  int iStack_38;
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  if (*(int *)(param_1 + 0x14) == 0) {
    uVar1 = (*(code *)&LAB_40170217_1)(0x30);
    FUN_400d7378(uVar1,0x1000,0);
    *(undefined4 *)(param_1 + 0x14) = uVar1;
  }
  iVar2 = *(int *)(param_1 + 0x14);
  FUN_400f0d4c(auStack_48,param_2);
  iStack_38 = iVar2 + 8;
  FUN_400f0d4c(auStack_34,auStack_48);
  FUN_400f0a50(auStack_48);
  iVar2 = iStack_38;
  uVar3 = FUN_400e13a4(auStack_34);
  uVar1 = FUN_400e145c(iVar2 + 0x18,(int)uVar3,(int)((ulonglong)uVar3 >> 0x20),iStack_38);
  FUN_400e0404(param_3,uVar1);
  FUN_400f0a50(auStack_34);
  iVar2 = _DAT_3ffc5708;
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
    FUN_400f0a50(auStack_48);
    thunk_FUN_401710d8(iVar2);
  }
  return;
}

