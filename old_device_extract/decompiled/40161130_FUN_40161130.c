// Function : FUN_40161130
// Address  : 0x40161130
// Size     : 28 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40161130(void)

{
  if (_DAT_3ffca214 + 1 != 0) {
    _DAT_3ffca214 = _DAT_3ffca214 + 1;
    memw();
    return;
  }
  _DAT_3ffca214 = _DAT_3ffca214 + 2;
  memw();
  return;
}

