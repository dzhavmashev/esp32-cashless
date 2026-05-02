// Function : FUN_40145d84
// Address  : 0x40145d84
// Size     : 66 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40145d84(void)

{
  undefined4 uVar1;
  
  if (_DAT_3ffc78f4 == 0) {
    _DAT_3ffc78f4 = (**(code **)(_DAT_3ffc17c4 + 0x18))(1);
    if (_DAT_3ffc78f4 == 0) {
      memw();
      uVar1 = (**(code **)(_DAT_3ffc17c4 + 0x4c))();
      FUN_40168698(0x3ffc1921,uVar1);
      return 0x101;
    }
  }
  _DAT_3ffc78e4 = 0x3ffbfc1e;
  memw();
  return 0;
}

