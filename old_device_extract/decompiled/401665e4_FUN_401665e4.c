// Function : FUN_401665e4
// Address  : 0x401665e4
// Size     : 160 bytes


undefined4 FUN_401665e4(int *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  uVar1 = *(uint *)(*param_1 + 4) & 0xfffff;
  uVar2 = uVar1 | 0x200000;
  puVar4 = *(uint **)(*param_1 + 0x2c);
  if ((((short)param_1[5] < 1) && ((*puVar4 & 0xc0) != 0x80)) &&
     (0xf < (byte)((char)puVar4[3] - 0x10U))) {
    uVar2 = uVar1 | 0x600000;
  }
  uVar1 = *puVar4;
  if (((uVar1 & 0x402) == 0) && ((uVar1 & 0x480000) != 0x400000)) {
    uVar3 = 0x3000000;
    if (((uVar1 & 0x100000) == 0) && (uVar3 = 0x2000000, (uVar1 & 0x80000) == 0)) {
      uVar3 = 0x1000000;
    }
    uVar2 = uVar2 | uVar3;
  }
  memw();
  *(uint *)((0x7fee7a4 - (uint)*(byte *)(param_1 + 1)) * 8) =
       uVar2 | (*puVar4 >> 8 & 1) << 0x1b | (*puVar4 >> 9 & 1) << 0x1c;
  memw();
  return 0;
}

