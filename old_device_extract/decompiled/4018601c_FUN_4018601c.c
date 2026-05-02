// Function : FUN_4018601c
// Address  : 0x4018601c
// Size     : 38 bytes


uint FUN_4018601c(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_2 < (uint)(*(int *)(param_1 + 4) << 5)) {
    uVar1 = *(uint *)(*(int *)(param_1 + 8) + (param_2 >> 5) * 4) >> (param_2 & 0x1f) & 1;
  }
  return uVar1;
}

