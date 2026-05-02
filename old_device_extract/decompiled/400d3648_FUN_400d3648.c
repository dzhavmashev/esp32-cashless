// Function : FUN_400d3648
// Address  : 0x400d3648
// Size     : 73 bytes


int FUN_400d3648(void)

{
  int iVar1;
  int iVar2;
  
  FUN_400f0780(0x3ffc5490," memory");
  iVar1 = FUN_40183e94(0x3ffc4090);
  if (iVar1 == 0) {
    FUN_400f0780(0x3ffc5490,"ivation");
    iVar1 = 1;
  }
  else {
    iVar2 = FUN_400d9a08(0x3ffc4090);
    if (iVar2 == 0) {
      FUN_400f0780(0x3ffc5490,"uration");
    }
    else {
      FUN_400f0780(0x3ffc5490," needed");
      iVar1 = 0;
    }
  }
  return iVar1;
}

