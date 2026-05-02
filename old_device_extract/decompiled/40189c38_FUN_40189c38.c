// Function : FUN_40189c38
// Address  : 0x40189c38
// Size     : 28 bytes


uint FUN_40189c38(uint param_1)

{
  memw();
  return *(uint *)((param_1 & 0xff) * -0x3c + 0x3ff74270) >> 0x19 & 1;
}

