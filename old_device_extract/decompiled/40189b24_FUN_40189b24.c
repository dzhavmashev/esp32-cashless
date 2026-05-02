// Function : FUN_40189b24
// Address  : 0x40189b24
// Size     : 87 bytes


undefined4 FUN_40189b24(int param_1)

{
  uint *puVar1;
  
  puVar1 = (uint *)((uint)*(byte *)(param_1 + 4) * -8 + 0x3ff73d1c);
  memw();
  memw();
  *puVar1 = (*(byte *)(param_1 + 5) & 0xf) << 0x18 | *puVar1 & 0xf0ffffff;
  puVar1 = (uint *)((uint)*(byte *)(param_1 + 4) * -8 + 0x3ff73d1c);
  memw();
  memw();
  *puVar1 = (*(ushort *)(param_1 + 6) & 0x3ff) << 0xc | *puVar1 & 0xffc00fff;
  memw();
  return 0;
}

