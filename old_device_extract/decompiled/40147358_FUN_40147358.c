// Function : FUN_40147358
// Address  : 0x40147358
// Size     : 69 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40147358(void)

{
  (**(code **)(_DAT_3ffc1a34 + 0x54))(_DAT_3ffc799c);
  if (_DAT_3ffc8874 != 0) {
    (**(code **)(_DAT_3ffc1a34 + 0xb0))();
    _DAT_3ffc8874 = 0;
  }
  DAT_3ffc8a04 = 1;
  memw();
  memw();
  (**(code **)(_DAT_3ffc1a34 + 0x58))(_DAT_3ffc799c);
  return 0;
}

