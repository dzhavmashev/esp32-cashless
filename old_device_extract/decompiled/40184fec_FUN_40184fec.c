// Function : FUN_40184fec
// Address  : 0x40184fec
// Size     : 34 bytes


uint FUN_40184fec(byte *param_1)

{
  return (uint)*param_1 << 0x18 | (uint)param_1[3] | (uint)param_1[1] << 0x10 |
         (uint)param_1[2] << 8;
}

