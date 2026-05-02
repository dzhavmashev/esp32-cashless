// Function : FUN_4010b56c
// Address  : 0x4010b56c
// Size     : 50 bytes


void FUN_4010b56c(int param_1)

{
  if ((param_1 != 0) && ((*(byte *)(param_1 + 0xeb) & 4) == 0)) {
    *(byte *)(param_1 + 0xeb) = *(byte *)(param_1 + 0xeb) | 4;
    memw();
    memw();
    FUN_40115008(param_1);
    FUN_4010b1a0(param_1,3);
    FUN_40185508(param_1);
  }
  return;
}

