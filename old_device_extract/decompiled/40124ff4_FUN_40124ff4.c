// Function : FUN_40124ff4
// Address  : 0x40124ff4
// Size     : 99 bytes


void FUN_40124ff4(int param_1)

{
  *(byte *)(param_1 + 0x19c) = *(byte *)(param_1 + 0x19c) | 1;
  memw();
  *(undefined4 *)(param_1 + 0x10) = 0;
  if (*(int *)(param_1 + 0x18) != 0) {
    *(byte *)(param_1 + 0x19c) = *(byte *)(param_1 + 0x19c) & 0xfe;
    memw();
  }
  *(undefined4 *)(param_1 + 0x11c) = 0;
  if (*(int *)(param_1 + 0x48) != 0) {
    *(int *)(*(int *)(param_1 + 4) + 0xc) = *(int *)(*(int *)(param_1 + 4) + 0xc) + -1;
  }
  *(undefined4 *)(param_1 + 0x48) = 0;
  if (*(int *)(param_1 + 0x1b4) == 1) {
    *(undefined4 *)(param_1 + 0x184) = 0;
  }
  *(undefined4 *)(param_1 + 0x120) = 1;
  memw();
  FUN_40124fb8(param_1);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  memw();
  return;
}

