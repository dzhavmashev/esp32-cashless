// Function : FUN_40189b7c
// Address  : 0x40189b7c
// Size     : 36 bytes


void FUN_40189b7c(uint param_1)

{
  uint *puVar1;
  
  puVar1 = (uint *)((0x7fee7a4 - (param_1 & 0xff)) * 8);
  memw();
  memw();
  *puVar1 = *puVar1 | 0xc0000000;
  memw();
  return;
}

