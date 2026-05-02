// Function : FUN_400df0fc
// Address  : 0x400df0fc
// Size     : 130 bytes


void FUN_400df0fc(undefined4 *param_1)

{
  memw();
  *(undefined1 *)(param_1 + 0x1f) = 0;
  *param_1 = &DAT_3f406860;
  memw();
  *(undefined1 *)((int)param_1 + 0x7d) = 0;
  *(undefined1 *)((int)param_1 + 0x26) = 0x10;
  memw();
  param_1[0x20] = 0;
  memw();
  param_1[0x21] = 0;
  param_1[0xf] = 0xffff0201;
  memw();
  *(undefined1 *)(param_1 + 0x22) = 0;
  memw();
  param_1[0x3c] = 0;
  param_1[3] = 0;
  param_1[7] = 0;
  *(undefined2 *)(param_1 + 9) = 0x1b1a;
  param_1[0xb] = 0;
  *(undefined1 *)(param_1 + 0xc) = 0;
  *(undefined2 *)((int)param_1 + 0x32) = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  *(undefined1 *)(param_1 + 0x1b) = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  memw();
  *(undefined2 *)(param_1 + 0x3d) = 0;
  func_0x4008b538(param_1 + 0x12,0,0x24);
  func_0x4008b538((int)param_1 + 0x89,0,100);
  return;
}

