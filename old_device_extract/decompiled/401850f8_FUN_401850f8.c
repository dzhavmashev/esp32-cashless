// Function : FUN_401850f8
// Address  : 0x401850f8
// Size     : 34 bytes


uint FUN_401850f8(byte *param_1)

{
  return (uint)*param_1 << 0x18 | (uint)param_1[3] | (uint)param_1[1] << 0x10 |
         (uint)param_1[2] << 8;
}

