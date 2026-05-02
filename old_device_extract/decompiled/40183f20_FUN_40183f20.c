// Function : FUN_40183f20
// Address  : 0x40183f20
// Size     : 24 bytes


void FUN_40183f20(undefined4 param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *(byte *)(param_2 + 2) = *(byte *)(param_2 + 2) & 0x80 | 8;
    *param_2 = param_1;
    param_2[1] = 0;
  }
  return;
}

