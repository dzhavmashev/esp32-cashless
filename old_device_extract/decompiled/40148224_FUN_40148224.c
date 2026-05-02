// Function : FUN_40148224
// Address  : 0x40148224
// Size     : 61 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40148224(void)

{
  if (DAT_3ffc795c != '\0') {
    if (_DAT_3ffc7970 != 0) {
      FUN_4015fb44();
      _DAT_3ffc7970 = 0;
    }
    if (_DAT_3ffc7974 != 0) {
      memw();
      FUN_4015fb44();
      _DAT_3ffc7974 = 0;
    }
    DAT_3ffc795c = '\0';
    memw();
  }
  memw();
  return;
}

