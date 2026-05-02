// Function : FUN_401602a4
// Address  : 0x401602a4
// Size     : 61 bytes


void FUN_401602a4(byte param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4)

{
  int iVar1;
  
  iVar1 = (uint)param_1 * 0x24;
  *(byte *)(iVar1 + 0x3ffc7b20) = param_1;
  *(undefined1 *)(iVar1 + 0x3ffc7b21) = param_2;
  *(undefined1 *)(iVar1 + 0x3ffc7b25) = param_3;
  *(undefined1 *)(iVar1 + 0x3ffc7b26) = param_4;
  *(undefined1 *)(iVar1 + 0x3ffc7b24) = param_3;
  *(undefined2 *)(iVar1 + 0x3ffc7b34) = 0;
  *(undefined1 *)(iVar1 + 0x3ffc7b27) = 0;
  *(undefined1 *)(iVar1 + 0x3ffc7b28) = 0;
  (&DAT_3ffc7b2e)[iVar1] = 0;
  memw();
  *(undefined4 *)(iVar1 + 0x3ffc7b38) = 0;
  *(undefined4 *)(iVar1 + 0x3ffc7b3c) = 0;
  memw();
  return;
}

