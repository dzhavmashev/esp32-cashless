// Function : FUN_40129c30
// Address  : 0x40129c30
// Size     : 119 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40129c30(int param_1)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_2c [8];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  iVar1 = *(int *)(param_1 + 0x44);
  iVar2 = *(int *)(param_1 + 0x4c);
  if (iVar2 != *(int *)(iVar1 + 0x25c)) {
    *(int *)(param_1 + 0x4c) = *(int *)(iVar1 + 0x25c);
    *(int *)(iVar1 + 0x25c) = iVar2;
    memw();
    (*(code *)&SUB_4008b3d0)(auStack_2c,param_1 + 0xdc,8);
    (*(code *)&SUB_4008b3d0)(param_1 + 0xdc,iVar1 + 0x260,8);
    (*(code *)&SUB_4008b3d0)(iVar1 + 0x260,auStack_2c,8);
    FUN_40185840(param_1,*(undefined4 *)(param_1 + 0x4c));
  }
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    (*(code *)&SUB_40082ec4)();
  }
  return 0;
}

