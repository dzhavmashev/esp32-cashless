// Function : FUN_400ee930
// Address  : 0x400ee930
// Size     : 196 bytes


void FUN_400ee930(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  FUN_400f0be8(param_1 + 3,&DAT_3f42161d);
  *(undefined2 *)(param_1 + 7) = 0;
  *(undefined2 *)(param_1 + 10) = 0;
  param_1[8] = 5000;
  *(undefined1 *)(param_1 + 9) = 1;
  *(undefined2 *)((int)param_1 + 0x26) = 5000;
  FUN_400f0be8(param_1 + 0xb,&DAT_3f42161d);
  FUN_400f0be8(param_1 + 0xf,&DAT_3f42161d);
  FUN_400f0be8(param_1 + 0x13,&DAT_3f42161d);
  FUN_400f0be8(param_1 + 0x17,"lient\r\n");
  FUN_400f0be8(param_1 + 0x1b,&DAT_3f42161d);
  FUN_400f0be8(param_1 + 0x1f,"PClient");
  param_1[0x26] = 0xffffffff;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  *(undefined1 *)(param_1 + 0x27) = 0;
  param_1[0x28] = 0;
  *(undefined2 *)(param_1 + 0x29) = 10;
  FUN_400f0be8(param_1 + 0x2a,&DAT_3f42161d);
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  return;
}

