// Function : FUN_4016179c
// Address  : 0x4016179c
// Size     : 82 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016179c(void)

{
  int iVar1;
  
  iVar1 = FUN_4018c018();
  if (iVar1 != 0) {
    DAT_3ffca1d9 = 1;
    memw();
    if (DAT_3ffc1a44 != '\0') {
      memw();
      if ((DAT_3ffc1a3c == '\0') && (_DAT_3ffc1a40 != 0)) {
        memw();
        (*_DAT_3ffc7a34)(0,&DAT_3ffca1ec,&DAT_3ffca1eb);
        return;
      }
    }
    if (DAT_3ffca1eb == '\0') {
      FUN_401613ec();
    }
  }
  return;
}

