// Function : FUN_40137814
// Address  : 0x40137814
// Size     : 220 bytes


int FUN_40137814(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint auStack_24 [9];
  
  auStack_24[0] = 0;
  memw();
  iVar1 = FUN_40131574(param_1,0xc);
  if (iVar1 == 0) {
    iVar2 = *(int *)(param_1 + 8);
    puVar3 = (undefined4 *)(iVar2 + 0x18);
    iVar4 = *(int *)(param_1 + 4);
    FUN_401863f0(iVar2,puVar3,auStack_24);
    FUN_401863f0(iVar2,*(int *)(param_1 + 8) + 0x28,auStack_24);
    iVar5 = iVar2 + 8;
    uVar6 = auStack_24[0] + *(int *)(iVar2 + 8);
    *(uint *)(iVar2 + 8) = uVar6;
    uVar7 = (uint)(uVar6 < auStack_24[0]);
    uVar6 = uVar7 + *(int *)(iVar2 + 0xc);
    *(uint *)(iVar2 + 0xc) = uVar6;
    auStack_24[0] = (uint)(uVar6 < uVar7);
    memw();
    FUN_401863f0(iVar5,*(int *)(param_1 + 8) + 0x18,auStack_24);
    FUN_401863f0(iVar5,*(int *)(param_1 + 8) + 0x20,auStack_24);
    FUN_401863f0(iVar5,*(int *)(param_1 + 8) + 0x28,auStack_24);
    uVar6 = auStack_24[0] + *(int *)(iVar2 + 0x10);
    *(uint *)(iVar2 + 0x10) = uVar6;
    uVar7 = (uint)(uVar6 < auStack_24[0]);
    uVar6 = uVar7 + *(int *)(iVar2 + 0x14);
    *(uint *)(iVar2 + 0x14) = uVar6;
    auStack_24[0] = (uint)(uVar6 < uVar7);
    memw();
    FUN_401863f0(iVar2 + 0x10,*(int *)(param_1 + 8) + 0x20,auStack_24);
    FUN_401863f0(iVar2 + 0x10,*(int *)(param_1 + 8) + 0x28,auStack_24);
    *(uint *)(iVar2 + 0x18) = auStack_24[0];
    while (puVar3 = puVar3 + 1, puVar3 < (undefined4 *)(iVar2 + iVar4 * 4)) {
      *puVar3 = 0;
      memw();
    }
  }
  memw();
  return iVar1;
}

