// Function : FUN_40185250
// Address  : 0x40185250
// Size     : 12 bytes


void FUN_40185250(int param_1)

{
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x1c0) = 0;
  }
  memw();
  return;
}

