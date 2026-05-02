// Function : FUN_4011f630
// Address  : 0x4011f630
// Size     : 75 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4011f630(void)

{
  (*(code *)&SUB_40092a70)();
  (*(code *)&SUB_40092a98)(0x3ffbdc68,0xffffffff);
  _DAT_3ffc6728 = _DAT_3ffc6728 + 1;
  if (_DAT_3ffc6728 == 1) {
    memw();
    _DAT_3ff4880c = _DAT_3ff4880c | 0xc0000;
    memw();
  }
  memw();
  (*(code *)&SUB_40092a70)();
  (*(code *)&SUB_40092bec)(0x3ffbdc68);
  return;
}

