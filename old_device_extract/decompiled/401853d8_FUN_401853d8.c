// Function : FUN_401853d8
// Address  : 0x401853d8
// Size     : 18 bytes


void FUN_401853d8(int param_1,undefined4 param_2)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 0x3c) == 1)) {
    *(undefined4 *)(param_1 + 0x44) = param_2;
  }
  memw();
  return;
}

