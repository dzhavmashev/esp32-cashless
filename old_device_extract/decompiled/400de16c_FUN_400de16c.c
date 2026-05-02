// Function : FUN_400de16c
// Address  : 0x400de16c
// Size     : 118 bytes


void FUN_400de16c(int param_1)

{
  if (*(char *)(param_1 + 0xa4) != '\0') {
    FUN_400f06a4(0x3ffc5490,"D: %s)\n","de: %d\n");
    FUN_400f4310(*(undefined1 *)(param_1 + 0x24));
    FUN_400f3e44(*(undefined1 *)(param_1 + 0x24));
    if (*(int *)(param_1 + 0x98) != 0) {
      func_0x40091740();
      *(undefined4 *)(param_1 + 0x98) = 0;
    }
    if (*(int *)(param_1 + 0x11c) != 0) {
      func_0x40091740();
      *(undefined4 *)(param_1 + 0x11c) = 0;
    }
    if (*(int *)(param_1 + 0x9c) != 0) {
      func_0x400902dc();
      *(undefined4 *)(param_1 + 0x9c) = 0;
    }
    if (*(int *)(param_1 + 0xa0) != 0) {
      func_0x400902dc();
      *(undefined4 *)(param_1 + 0xa0) = 0;
    }
    memw();
    *(undefined4 *)(param_1 + 0x28) = 0;
    memw();
    *(undefined4 *)(param_1 + 0x4c) = 0;
    *(undefined1 *)(param_1 + 0xa4) = 0;
    FUN_400f06a4(0x3ffc5490,"ulator\n","de: %d\n");
  }
  return;
}

