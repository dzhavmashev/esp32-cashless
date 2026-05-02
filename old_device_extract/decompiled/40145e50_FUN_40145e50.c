// Function : FUN_40145e50
// Address  : 0x40145e50
// Size     : 176 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40145e50(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  _DAT_3ffc1a20 = 0;
  _DAT_3ffc1a1c = 0;
  _DAT_3ffc1a24 = 0;
  memw();
  _DAT_3ffc1a14 = (**(code **)(_DAT_3ffc17c4 + 4))();
  if (_DAT_3ffc1a14 == 0) {
    memw();
    uVar1 = (**(code **)(_DAT_3ffc17c4 + 0x4c))();
    uVar2 = 0x3ffc19dc;
  }
  else {
    _DAT_3ffc1a10 = (**(code **)(_DAT_3ffc17c4 + 4))();
    if (_DAT_3ffc1a10 == 0) {
      uVar1 = (**(code **)(_DAT_3ffc17c4 + 0x4c))();
      uVar2 = 0x3ffc19ba;
    }
    else {
      _DAT_3ffc1a28 = 0;
      _DAT_3ffc1a2c = 0;
      memw();
      _DAT_3ffc1a18 = (**(code **)(_DAT_3ffc17c4 + 0x34))(0x390);
      if (_DAT_3ffc1a18 != 0) {
        memw();
        return 0;
      }
      uVar1 = (**(code **)(_DAT_3ffc17c4 + 0x4c))();
      uVar2 = 0x3ffc1998;
    }
  }
  FUN_40168698(uVar2,uVar1);
  if (_DAT_3ffc1a14 != 0) {
    (**(code **)(_DAT_3ffc17c4 + 8))();
    _DAT_3ffc1a14 = 0;
  }
  if (_DAT_3ffc1a10 != 0) {
    memw();
    (**(code **)(_DAT_3ffc17c4 + 8))();
    _DAT_3ffc1a10 = 0;
  }
  memw();
  return 0x101;
}

