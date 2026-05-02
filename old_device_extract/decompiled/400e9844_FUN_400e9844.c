// Function : FUN_400e9844
// Address  : 0x400e9844
// Size     : 45 bytes


void FUN_400e9844(int param_1)

{
  if (-1 < **(int **)(param_1 + 0x2c)) {
    (*(code *)&SUB_40001778)();
    **(undefined4 **)(param_1 + 0x2c) = 0xffffffff;
    *(undefined1 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x34) = 0xffffffff;
  }
  FUN_400ea9dc(*(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(param_1 + 0x40),
               *(undefined4 *)(param_1 + 0x44),*(undefined4 *)(param_1 + 0x48));
  return;
}

