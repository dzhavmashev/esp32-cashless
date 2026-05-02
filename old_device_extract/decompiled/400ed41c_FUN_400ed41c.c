// Function : FUN_400ed41c
// Address  : 0x400ed41c
// Size     : 52 bytes


void FUN_400ed41c(int param_1)

{
  if (*(int *)(param_1 + 4) != 0) {
    FUN_4016fffc();
  }
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  if (*(uint *)(param_1 + 0xac) != 0xffffffff) {
    FUN_400f1a40(*(uint *)(param_1 + 0xac) & 0xff,*(char *)(param_1 + 0xb0) == '\0');
  }
  return;
}

