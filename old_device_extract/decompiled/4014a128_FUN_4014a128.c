// Function : FUN_4014a128
// Address  : 0x4014a128
// Size     : 59 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4014a128(uint param_1)

{
  if (DAT_3ffc8a38 == 0) {
    (**(code **)(_DAT_3ffc1a34 + 0xf4))(0x3ffc8a3c,&LAB_4014a2fc);
  }
  DAT_3ffc8a38 = (byte)(1 << 0x20 - (0x20 - (param_1 & 0x1f))) | DAT_3ffc8a38;
  memw();
  memw();
  return 0;
}

