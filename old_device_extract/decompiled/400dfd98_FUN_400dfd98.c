// Function : FUN_400dfd98
// Address  : 0x400dfd98
// Size     : 66 bytes


void FUN_400dfd98(undefined4 *param_1)

{
  param_1[3] = 0;
  param_1[7] = 0;
  *param_1 = &DAT_3f406cb0;
  *(undefined2 *)(param_1 + 9) = 0x1001;
  *(undefined1 *)((int)param_1 + 0x26) = 0;
  *(undefined2 *)(param_1 + 0x1e) = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  FUN_400f0be8(param_1 + 0x21,&DAT_3f42161d);
  param_1[0x26] = 0;
  param_1[0x25] = 0;
  *(undefined1 *)(param_1 + 0x27) = 0;
  return;
}

