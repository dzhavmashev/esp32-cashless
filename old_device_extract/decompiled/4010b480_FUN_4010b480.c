// Function : FUN_4010b480
// Address  : 0x4010b480
// Size     : 42 bytes


void FUN_4010b480(int param_1)

{
  if ((param_1 != 0) && ((*(byte *)(param_1 + 0xeb) & 1) == 0)) {
    *(byte *)(param_1 + 0xeb) = *(byte *)(param_1 + 0xeb) | 1;
    memw();
    memw();
    FUN_4010b1a0(param_1,3);
    FUN_40185508(param_1);
  }
  return;
}

