// Function : FUN_40163ab4
// Address  : 0x40163ab4
// Size     : 167 bytes


void FUN_40163ab4(int param_1)

{
  short sVar1;
  undefined4 uVar2;
  uint *puVar3;
  undefined4 *puVar4;
  
  puVar3 = *(uint **)(param_1 + 4);
  puVar4 = (undefined4 *)puVar3[1];
  sVar1 = *(short *)(param_1 + 0x14) + -4;
  uVar2 = *puVar4;
  *(short *)(param_1 + 0x14) = sVar1;
  *(ushort *)(param_1 + 0x16) = ((ushort)uVar2 & 0xfff) - sVar1;
  memw();
  memw();
  memw();
  *puVar3 = *puVar3 & 0xdfffffff;
  memw();
  memw();
  memw();
  *puVar3 = *puVar3 & 0xff000fff | ((*puVar3 >> 0xc & 0xfff) - 4 & 0xfff) << 0xc;
  puVar3[1] = (uint)(puVar4 + 1);
  *(undefined1 *)(*(int *)(param_1 + 0x2c) + 5) = 0;
  memw();
  *(undefined1 *)(*(int *)(param_1 + 0x2c) + 6) = 0;
  memw();
  *(undefined1 *)(*(int *)(param_1 + 0x2c) + 7) = 0;
  memw();
  **(uint **)(param_1 + 0x2c) = **(uint **)(param_1 + 0x2c) & 0xffb3feff;
  memw();
  FUN_40189844(*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_1 + 0x2c));
  FUN_40188920(param_1);
  memw();
  memw();
  **(uint **)(param_1 + 8) = **(uint **)(param_1 + 8) | 0x40000000;
  memw();
  return;
}

