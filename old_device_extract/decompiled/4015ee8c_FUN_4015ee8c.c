// Function : FUN_4015ee8c
// Address  : 0x4015ee8c
// Size     : 131 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4015ee8c(int param_1,int param_2,byte param_3)

{
  int iVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = _DAT_3ffbfebc;
  puVar2 = (undefined1 *)(*(int *)(*(int *)(param_2 + 4) + 4) - _DAT_3ffbfebc);
  *(undefined1 **)(*(int *)(param_2 + 4) + 4) = puVar2;
  uVar4 = *(uint *)(param_1 + 0x98);
  *(short *)(param_2 + 0x16) = (short)iVar1 + *(short *)(param_2 + 0x16);
  memw();
  uVar3 = uVar4 + 1;
  *(uint *)(param_1 + 0x98) = uVar3;
  *(uint *)(param_1 + 0x9c) = (uint)(uVar3 < uVar4) + *(int *)(param_1 + 0x9c);
  *puVar2 = (char)uVar3;
  memw();
  puVar2[1] = (char)((uint)*(undefined4 *)(param_1 + 0x98) >> 8);
  puVar2[2] = 0;
  puVar2[3] = param_3 | 0x20;
  memw();
  puVar2[4] = (char)*(undefined2 *)(param_1 + 0x9a);
  memw();
  puVar2[5] = *(undefined1 *)(param_1 + 0x9b);
  memw();
  puVar2[6] = (char)*(undefined4 *)(param_1 + 0x9c);
  memw();
  puVar2[7] = (char)((uint)*(undefined4 *)(param_1 + 0x9c) >> 8);
  memw();
  memw();
  return 1;
}

