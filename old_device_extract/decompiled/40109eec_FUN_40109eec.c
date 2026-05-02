// Function : FUN_40109eec
// Address  : 0x40109eec
// Size     : 38 bytes


uint FUN_40109eec(uint param_1)

{
  return param_1 << 0x18 | param_1 >> 0x18 | (param_1 & 0xff00) << 8 | param_1 >> 8 & 0xff00;
}

