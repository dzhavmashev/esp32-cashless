// Function : FUN_401629ac
// Address  : 0x401629ac
// Size     : 57 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_401629ac(void)

{
  if (_DAT_3ffc7bf8 != 0) {
    (**(code **)(_DAT_3ffc1a34 + 0x98))();
    _DAT_3ffc7bf8 = 0;
  }
  if (_DAT_3ffc7be8 != 0) {
    memw();
    (**(code **)(_DAT_3ffc1a34 + 0x180))();
    _DAT_3ffc7be8 = 0;
  }
  memw();
  return 0;
}

