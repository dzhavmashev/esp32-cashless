// Function : FUN_40123344
// Address  : 0x40123344
// Size     : 78 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40123344(void)

{
  (*(code *)&SUB_40086460)(0x3ffc17c0);
  _DAT_3ffc17bc = _DAT_3ffc17bc + -1;
  if (_DAT_3ffc17bc == 0) {
    memw();
    _DAT_3ff48088 = _DAT_3ff48088 | 0x10000000;
    memw();
    memw();
    _DAT_3ff48084 = _DAT_3ff48084 | 0x20000;
    memw();
  }
  memw();
  (*(code *)&SUB_400864a0)(0x3ffc17c0);
  return;
}

