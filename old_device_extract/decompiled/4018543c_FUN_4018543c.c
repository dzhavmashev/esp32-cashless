// Function : FUN_4018543c
// Address  : 0x4018543c
// Size     : 17 bytes


void FUN_4018543c(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 200) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 200) + 0x54) = param_2;
  }
  memw();
  return;
}

