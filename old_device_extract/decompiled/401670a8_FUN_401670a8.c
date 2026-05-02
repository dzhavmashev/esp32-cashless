// Function : FUN_401670a8
// Address  : 0x401670a8
// Size     : 231 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401670a8(int param_1)

{
  if (param_1 == 0) {
    memw();
    _DAT_3ff7505c = _DAT_3ff7505c & 0x3dffffff;
    memw();
    memw();
    FUN_401652b8();
    memw();
    _DAT_3ff75060 = param_1;
    memw();
    _DAT_3ff75064 = param_1;
    memw();
    memw();
    _DAT_3ff75010 = _DAT_3ff75010 | 0x80;
    memw();
    memw();
    _DAT_3ff7505c = _DAT_3ff7505c | 0xc2000000;
    memw();
    return;
  }
  if (param_1 != 1) {
    return;
  }
  memw();
  memw();
  memw();
  _DAT_3ff75024 = 0;
  memw();
  _DAT_3ff75028 = 0;
  memw();
  memw();
  memw();
  memw();
  _DAT_3ff75020 = _DAT_3ff75020 & 0x7fffffff | 0x80000000;
  memw();
  memw();
  memw();
  _DAT_3ff75060 = 0;
  memw();
  _DAT_3ff75064 = 0;
  memw();
  memw();
  _DAT_3ff75010 = _DAT_3ff75010 | 0xc0;
  memw();
  memw();
  _DAT_3ff7505c = _DAT_3ff7505c & 0x7fffffff | 0x80000000;
  memw();
  return;
}

