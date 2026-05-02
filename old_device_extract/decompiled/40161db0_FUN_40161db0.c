// Function : FUN_40161db0
// Address  : 0x40161db0
// Size     : 86 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40161db0(void)

{
  int iVar1;
  
  _DAT_3ffc7c24 = _DAT_3ffc7c24 + 1;
  if (((DAT_3ffca1e5 != '\0') && (DAT_3ffca1e6 != '\0')) && (DAT_3ffca1e7 == '\0')) {
    if (_DAT_3ffca1fc == 0) {
      if (_DAT_3ffca214 == 0) {
        FUN_401613ec();
      }
      else {
        _DAT_3ffca214 = _DAT_3ffca1fc;
        memw();
      }
LAB_40161df4:
      FUN_4018a8a8();
      return;
    }
    if (DAT_3ffca1d9 == '\0') {
      if ((DAT_3ffca1ea != '\0') || (iVar1 = FUN_40163758(1), iVar1 != 0)) goto LAB_40161df4;
      FUN_40161744();
    }
  }
  return;
}

