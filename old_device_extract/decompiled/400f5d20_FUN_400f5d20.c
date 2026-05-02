// Function : FUN_400f5d20
// Address  : 0x400f5d20
// Size     : 126 bytes


undefined4 FUN_400f5d20(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 auStack_24 [9];
  
  iVar1 = param_1 * 0x10;
  auStack_24[0] = 0;
  memw();
  (*(code *)&SUB_40092a70)();
  (*(code *)&SUB_40092a98)(iVar1 + 0x3ffbdc7c,0xffffffff);
  if (*(int *)(*(int *)(param_1 * 4 + 0x3ffc5588) + 0xc) == 1) {
    iVar2 = *(int *)(iVar1 + 0x3ffbdc78);
    memw();
    memw();
    *(uint *)(iVar2 + 0x20) = *(uint *)(iVar2 + 0x20) & 0xffffffbf;
    memw();
    *(undefined4 *)(iVar2 + 0x10) = 0x4000;
    memw();
    memw();
    *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) | 0x4000;
  }
  memw();
  FUN_400fe3dc(iVar1 + 0x3ffbdc78,param_2,param_3,auStack_24);
  (*(code *)&SUB_40092a70)();
  (*(code *)&SUB_40092bec)(iVar1 + 0x3ffbdc7c);
  return auStack_24[0];
}

