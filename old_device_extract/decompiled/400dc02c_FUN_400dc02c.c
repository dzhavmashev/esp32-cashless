// Function : FUN_400dc02c
// Address  : 0x400dc02c
// Size     : 116 bytes


void FUN_400dc02c(undefined4 *param_1)

{
  *param_1 = &DAT_3f405ae8;
  *(undefined2 *)(param_1 + 10) = 200;
  *(undefined2 *)(param_1 + 9) = 0x1001;
  param_1[0xb] = 0x40c00000;
  *(undefined2 *)(param_1 + 0x16) = 3000;
  param_1[0x1a] = 0x13882710;
  param_1[3] = 0;
  param_1[7] = 0;
  *(undefined1 *)((int)param_1 + 0x26) = 0;
  *(undefined1 *)(param_1 + 0xc) = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  *(undefined1 *)(param_1 + 0x14) = 0;
  param_1[0x15] = 0;
  *(undefined1 *)((int)param_1 + 0x5a) = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  *(undefined2 *)(param_1 + 0x19) = 0;
  *(undefined1 *)((int)param_1 + 0x66) = 0;
  *(undefined2 *)(param_1 + 0x1b) = 20000;
  *(undefined1 *)((int)param_1 + 0x6e) = 3;
  memw();
  *(undefined1 *)((int)param_1 + 0x6f) = 0;
  *(undefined1 *)(param_1 + 0x1c) = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  return;
}

