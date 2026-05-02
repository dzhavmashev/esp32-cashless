// Function : FUN_40161150
// Address  : 0x40161150
// Size     : 31 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40161150(void)

{
  if (_DAT_3ffca218 + 1 != 0) {
    _DAT_3ffca218 = _DAT_3ffca218 + 1;
    memw();
    return;
  }
  _DAT_3ffca218 = _DAT_3ffca218 + 2;
  memw();
  return;
}

