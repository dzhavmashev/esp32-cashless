// Function : FUN_4018dfb8
// Address  : 0x4018dfb8
// Size     : 40 bytes


uint FUN_4018dfb8(int param_1,uint param_2)

{
  if ((param_2 == 0) || (param_1 == 0)) {
    param_2 = 0;
  }
  else {
    param_2 = -((int)(0x80000000U >> (LZCOUNT(param_2) & 0x1fU)) /
               (int)(*(uint *)(param_1 + 0x10) >> 0xe & 0x3f)) & param_2;
  }
  return param_2;
}

