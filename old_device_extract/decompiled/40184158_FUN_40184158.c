// Function : FUN_40184158
// Address  : 0x40184158
// Size     : 29 bytes


void FUN_40184158(undefined4 *param_1)

{
  param_1[1] = *param_1;
  param_1[2] = param_1[3];
  *(undefined1 *)(param_1 + 4) = 0;
  *(byte *)(param_1 + 8) = *(byte *)(param_1 + 8) & 0x80;
  return;
}

