// Function : FUN_401239bc
// Address  : 0x401239bc
// Size     : 56 bytes


bool FUN_401239bc(void)

{
  int iVar1;
  bool bVar2;
  
  memw();
  iVar1 = FUN_401041bc(0,0x40123860,0x40123998,FUN_40123818,0x40123840,0x40123874,&DAT_40123880);
  bVar2 = false;
  if (iVar1 != 0) {
    iVar1 = FUN_4015a594(0x40104494);
    bVar2 = iVar1 == 0;
  }
  return bVar2;
}

