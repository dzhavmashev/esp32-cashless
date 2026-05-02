// Function : FUN_4011f9fc
// Address  : 0x4011f9fc
// Size     : 29 bytes


void FUN_4011f9fc(int param_1)

{
  if (*(int *)(param_1 + 4) == 0x12121212) {
    FUN_4011f8dc(*(undefined4 *)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 4) = 0;
  }
  memw();
  return;
}

