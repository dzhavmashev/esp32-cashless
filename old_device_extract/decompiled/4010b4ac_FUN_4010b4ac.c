// Function : FUN_4010b4ac
// Address  : 0x4010b4ac
// Size     : 43 bytes


void FUN_4010b4ac(int param_1)

{
  byte bVar1;
  
  if ((param_1 != 0) && (bVar1 = *(byte *)(param_1 + 0xeb), (bVar1 & 1) != 0)) {
    *(byte *)(param_1 + 0xeb) = bVar1 & 0xfe;
    memw();
    if ((bVar1 & 8) != 0) {
      memw();
      FUN_40115910(param_1);
    }
    FUN_4011a900(param_1);
  }
  return;
}

