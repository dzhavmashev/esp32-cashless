// Function : FUN_4018532c
// Address  : 0x4018532c
// Size     : 22 bytes


void FUN_4018532c(int param_1)

{
  *(byte *)(param_1 + 0xeb) = *(byte *)(param_1 + 0xeb) | 0x80;
  memw();
  memw();
  return;
}

