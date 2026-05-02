// Function : FUN_4012ca94
// Address  : 0x4012ca94
// Size     : 54 bytes


void FUN_4012ca94(int param_1)

{
  FUN_4012ca14(param_1);
  FUN_4013ae44(*(undefined4 *)(param_1 + 0x44));
  *(undefined4 *)(param_1 + 0x44) = 0;
  if (*(int *)(param_1 + 0x50) != 0) {
    memw();
    FUN_40129d74();
    FUN_4013ae44(*(undefined4 *)(param_1 + 0x50));
  }
  *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(param_1 + 0x54) = 0;
  memw();
  return;
}

