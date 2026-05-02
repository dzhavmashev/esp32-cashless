// Function : FUN_400dbee8
// Address  : 0x400dbee8
// Size     : 36 bytes


void FUN_400dbee8(int param_1)

{
  if (*(char *)(param_1 + 0x20) != '\0') {
    FUN_400e9570(&DAT_3ffc516c,0);
    *(undefined1 *)(param_1 + 0x20) = 0;
    FUN_400f0780(0x3ffc5490," failed");
  }
  return;
}

