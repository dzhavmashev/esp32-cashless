// Function : FUN_400f57dc
// Address  : 0x400f57dc
// Size     : 32 bytes


uint FUN_400f57dc(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 < 0x28) {
    uVar1 = (*(uint *)(&DAT_3f414400 + param_1 * 4) ^ 0xffffffff) >> 0x1f;
  }
  return uVar1;
}

