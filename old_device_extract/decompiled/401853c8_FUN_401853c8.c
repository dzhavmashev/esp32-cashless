// Function : FUN_401853c8
// Address  : 0x401853c8
// Size     : 13 bytes


void FUN_401853c8(int param_1,undefined4 param_2)

{
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x38) = param_2;
  }
  memw();
  return;
}

