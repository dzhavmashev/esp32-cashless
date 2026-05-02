// Function : FUN_401291f4
// Address  : 0x401291f4
// Size     : 42 bytes


void FUN_401291f4(int param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 0x22c) != 0)) {
    *(int *)(param_1 + 500) = *(int *)(param_1 + 500) - *(int *)(param_1 + 0x230);
    memw();
    FUN_4013ae44();
    *(undefined4 *)(param_1 + 0x22c) = 0;
  }
  memw();
  return;
}

