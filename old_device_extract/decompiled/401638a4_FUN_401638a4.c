// Function : FUN_401638a4
// Address  : 0x401638a4
// Size     : 180 bytes


void FUN_401638a4(uint param_1)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  uint *puVar5;
  
  iVar3 = FUN_4018b928(0,5);
  if (iVar3 == 0) {
    FUN_40147fe4(6,0x40,2,0x3f43704c);
    return;
  }
  *(undefined2 *)(iVar3 + 0x16) = 0x18;
  memw();
  iVar1 = (param_1 & 0xff) * 0x24;
  puVar5 = (uint *)(iVar1 + 0x3ffc1acc);
  *(uint **)(iVar3 + 4) = puVar5;
  memw();
  memw();
  *puVar5 = *puVar5 & 0xfffff000 | 0x18;
  *(uint **)(iVar3 + 8) = puVar5;
  *(undefined2 *)(iVar3 + 0xc) = 1;
  memw();
  *(uint *)(*(int *)(iVar3 + 0x2c) + 4) =
       *(uint *)(*(int *)(iVar3 + 0x2c) + 4) & 0xffffff0f | (param_1 & 0xf) << 4;
  memw();
  uVar4 = FUN_40164fac(0);
  *(undefined4 *)(iVar3 + 0x24) = uVar4;
  memw();
  FUN_40189844(uVar4,*(undefined4 *)(iVar3 + 0x2c));
  FUN_40188920(iVar3);
  uVar2 = *(ushort *)(iVar3 + 0x16);
  *(undefined1 *)(iVar1 + 0x3ffc1adc) = 0x84;
  *(uint *)(iVar1 + 0x3ffc1ad8) = *(uint *)(iVar1 + 0x3ffc1ad8) & 0xffc80000 | uVar2 & 0xfff;
  *(undefined1 *)(iVar1 + 0x3ffc1add) = 0;
  memw();
  memw();
  return;
}

