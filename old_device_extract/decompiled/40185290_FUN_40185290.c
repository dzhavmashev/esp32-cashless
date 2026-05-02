// Function : FUN_40185290
// Address  : 0x40185290
// Size     : 12 bytes


uint FUN_40185290(uint param_1)

{
  return (param_1 & 0xff) << 8 | (param_1 & 0xffff) >> 8;
}

