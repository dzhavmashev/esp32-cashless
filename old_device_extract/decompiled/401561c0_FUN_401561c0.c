// Function : FUN_401561c0
// Address  : 0x401561c0
// Size     : 79 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401561c0(void)

{
  FUN_40147fe4(1,8,4,0x3f4339c5);
  (**(code **)(_DAT_3ffc1a34 + 0x54))(_DAT_3ffc799c);
  while (_DAT_3ffc8920 != (int *)0x0) {
    _DAT_3ffc8920 = (int *)*_DAT_3ffc8920;
    if (_DAT_3ffc8920 == (int *)0x0) {
      _DAT_3ffc8924 = &DAT_3ffc8920;
    }
    memw();
    FUN_4015617c();
  }
  (**(code **)(_DAT_3ffc1a34 + 0x58))(_DAT_3ffc799c);
  return;
}

