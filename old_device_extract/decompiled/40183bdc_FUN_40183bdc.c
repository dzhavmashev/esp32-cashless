// Function : FUN_40183bdc
// Address  : 0x40183bdc
// Size     : 24 bytes


void FUN_40183bdc(int *param_1)

{
  *param_1 = (int)(param_1 + 10);
  param_1[1] = (int)(param_1 + 10);
  param_1[2] = (int)(param_1 + 0x8a);
  param_1[3] = (int)(param_1 + 0x8a);
  *(undefined1 *)(param_1 + 4) = 0;
  *(undefined1 *)(param_1 + 8) = 0;
  return;
}

