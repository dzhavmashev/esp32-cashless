// Function : FUN_400de254
// Address  : 0x400de254
// Size     : 166 bytes


void FUN_400de254(undefined4 *param_1)

{
  memw();
  param_1[10] = 0;
  memw();
  *(undefined2 *)(param_1 + 0xb) = 0;
  *param_1 = &DAT_3f406634;
  memw();
  *(undefined2 *)((int)param_1 + 0x2e) = 0;
  memw();
  param_1[0x13] = 0;
  param_1[9] = 0x3c1b1a;
  memw();
  *(undefined1 *)((int)param_1 + 0x97) = 0;
  param_1[0xc] = 1;
  memw();
  param_1[0x43] = 0;
  memw();
  param_1[0x44] = 0;
  param_1[0xe] = 0xff00;
  memw();
  param_1[0x45] = 0;
  param_1[0x2a] = 0;
  param_1[3] = 0;
  param_1[7] = 0;
  param_1[0xd] = 0;
  param_1[0x14] = 0;
  *(undefined2 *)(param_1 + 0x15) = 0;
  *(undefined1 *)((int)param_1 + 0x96) = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  *(undefined2 *)(param_1 + 0x29) = 0;
  memw();
  param_1[0x46] = 0;
  param_1[0x47] = 0;
  func_0x4008b538((int)param_1 + 0x56,0,0x40);
  func_0x4008b538(param_1 + 0x33,0,0x20);
  func_0x4008b538(param_1 + 0x3b,0,0x20);
  func_0x4008b538(param_1 + 0x2b,0,0x20);
  return;
}

