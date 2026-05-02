// Function : FUN_40168994
// Address  : 0x40168994
// Size     : 44 bytes


int FUN_40168994(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (DAT_3ffc7e60 == '\0') {
    DAT_3ffc7e60 = '\x01';
    memw();
    memw();
    iVar1 = FUN_401688d0(0);
    iVar2 = 0;
    if (iVar1 != 0) {
      FUN_4016894c();
      iVar2 = iVar1;
    }
  }
  return iVar2;
}

