// Function : FUN_401862c0
// Address  : 0x401862c0
// Size     : 25 bytes


uint FUN_401862c0(int param_1,int param_2,int param_3)

{
  return ((uint)(param_2 - param_3 | param_3 - param_1) >> 8 ^ 0xffffffff) & 0xff;
}

