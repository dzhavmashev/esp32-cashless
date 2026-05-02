// Function : FUN_4018572c
// Address  : 0x4018572c
// Size     : 18 bytes


int FUN_4018572c(uint param_1)

{
  return (int)((param_1 ^ 0xffffffff) & param_1 - 1) >> 0x1f;
}

