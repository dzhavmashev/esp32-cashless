// Function : FUN_400dc564
// Address  : 0x400dc564
// Size     : 34 bytes


void FUN_400dc564(int param_1)

{
  *(undefined1 *)(param_1 + 0x5a) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  if (*(char *)(param_1 + 0x70) != '\0') {
    FUN_400dc3c8(param_1);
  }
  *(undefined1 *)(param_1 + 100) = 0;
  return;
}

