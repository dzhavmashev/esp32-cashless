// Function : FUN_400d3694
// Address  : 0x400d3694
// Size     : 75 bytes


int FUN_400d3694(void)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  
  FUN_400f0780(0x3ffc5490," needed");
  iVar1 = FUN_400e6a84(0x3ffc4d78);
  if (iVar1 == 0) {
    FUN_400f0780(0x3ffc5490,"ability");
    pcVar3 = "s found";
  }
  else {
    iVar2 = FUN_400e6ab4(0x3ffc4d78);
    pcVar3 = "ed: %d\n";
    if (iVar2 != 0) {
      FUN_400f06a4(0x3ffc5490,"or mTLS",iVar2);
      return 0;
    }
  }
  FUN_400f0780(0x3ffc5490,pcVar3);
  return iVar1;
}

