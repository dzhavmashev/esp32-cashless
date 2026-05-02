// Function : FUN_400dd37c
// Address  : 0x400dd37c
// Size     : 62 bytes


void FUN_400dd37c(undefined4 *param_1)

{
  *param_1 = &DAT_3f405d70;
  memw();
  *(undefined1 *)(param_1 + 0xf) = 0;
  param_1[9] = 0x3ffc4d68;
  memw();
  *(undefined1 *)((int)param_1 + 0x3d) = 0;
  param_1[0xc] = 0x3f800000;
  param_1[3] = 0;
  memw();
  param_1[0x29] = 0;
  param_1[7] = 0;
  *(undefined2 *)(param_1 + 10) = 0;
  param_1[0xb] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  memw();
  *(undefined1 *)((int)param_1 + 0x3e) = 0;
  return;
}

