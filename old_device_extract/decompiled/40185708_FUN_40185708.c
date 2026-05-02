// Function : FUN_40185708
// Address  : 0x40185708
// Size     : 35 bytes


uint FUN_40185708(byte *param_1)

{
  return (uint)*param_1 << 0x18 | (uint)param_1[3] | (uint)param_1[1] << 0x10 |
         (uint)param_1[2] << 8;
}

