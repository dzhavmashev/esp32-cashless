// Function : FUN_400d9de4
// Address  : 0x400d9de4
// Size     : 27 bytes


void FUN_400d9de4(int param_1)

{
  if (*(char *)(param_1 + 0x10) != '\0') {
    *(undefined1 *)(param_1 + 0x10) = 0;
    FUN_400f0780(0x3ffc5490,"lt: %s\n");
  }
  return;
}

