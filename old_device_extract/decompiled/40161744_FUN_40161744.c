// Function : FUN_40161744
// Address  : 0x40161744
// Size     : 86 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40161744(void)

{
  int iVar1;
  
  iVar1 = FUN_4018c018();
  if (iVar1 != 0) {
    DAT_3ffca1d9 = 1;
    memw();
    if (((DAT_3ffc1a44 != '\0') && (memw(), DAT_3ffc1a3c == '\0')) && (_DAT_3ffc1a40 != 0)) {
      memw();
      (*_DAT_3ffc7a30)(1,&DAT_3ffca1ec,&DAT_3ffca1eb);
      return;
    }
    if (DAT_3ffca1ec == '\0') {
      FUN_401613ec(1);
    }
  }
  return;
}

