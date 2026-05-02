// Function : FUN_4012b9c8
// Address  : 0x4012b9c8
// Size     : 53 bytes


void FUN_4012b9c8(int param_1)

{
  if (*(int *)(param_1 + 0xcc) != 0) {
    FUN_4013ae54(*(int *)(param_1 + 0xcc),*(undefined4 *)(param_1 + 0xd0));
    FUN_4013ae44(*(undefined4 *)(param_1 + 0xcc));
    *(undefined4 *)(param_1 + 0xcc) = 0;
    *(undefined4 *)(param_1 + 0xd0) = 0;
  }
  if (*(int *)(param_1 + 0xd4) != 0) {
    memw();
    FUN_4013ae44();
    *(undefined4 *)(param_1 + 0xd4) = 0;
    *(undefined4 *)(param_1 + 0xd8) = 0;
  }
  memw();
  return;
}

