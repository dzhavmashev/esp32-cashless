// Function : FUN_4018413c
// Address  : 0x4018413c
// Size     : 20 bytes


void FUN_4018413c(undefined4 *param_1)

{
  *(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) & 0x80 | 0x20;
  *param_1 = 0;
  param_1[1] = 0;
  return;
}

