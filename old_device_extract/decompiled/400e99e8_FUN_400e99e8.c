// Function : FUN_400e99e8
// Address  : 0x400e99e8
// Size     : 102 bytes


void FUN_400e99e8(undefined4 *param_1)

{
  undefined4 uVar1;
  
  FUN_40172440(param_1);
  *param_1 = &DAT_3f4092c4;
  param_1[0xd] = 0xffffffff;
  param_1[0xc] = 0;
  *(undefined1 *)(param_1 + 8) = 0;
  param_1[0xe] = 30000;
  uVar1 = (*(code *)&LAB_40170217_1)(0x898);
  param_1[0xb] = uVar1;
  FUN_400ea040();
  *(undefined4 *)param_1[0xb] = 0xffffffff;
  *(undefined4 *)(param_1[0xb] + 0x894) = 120000;
  *(undefined1 *)(param_1 + 0xf) = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x17] = 0;
  param_1[0x15] = 0;
  *(undefined1 *)(param_1 + 0x16) = 0;
  return;
}

