// Function : FUN_40161c2c
// Address  : 0x40161c2c
// Size     : 195 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40161c2c(int param_1,int param_2)

{
  int iVar1;
  
  (**(code **)(_DAT_3ffc1a34 + 0xec))(0x3ffca2cc);
  DAT_3ffca1f0 = 1;
  memw();
  memw();
  iVar1 = (**(code **)(_DAT_3ffc1a34 + 0x194))();
  if (iVar1 != 0) {
    if (DAT_3ffca1e6 == '\0') {
      _DAT_3ffca244 = 1;
      _DAT_3ffca240 = _DAT_3ffca204 + param_1;
      if (_DAT_3ffca204 <= _DAT_3ffca240) {
        _DAT_3ffca244 = 0;
      }
    }
    else {
      iVar1 = (**(code **)(_DAT_3ffc1a34 + 0x1c0))();
      _DAT_3ffca244 = 1;
      _DAT_3ffca240 = iVar1 * _DAT_3ffca204 + param_1;
      if (iVar1 * _DAT_3ffca204 <= _DAT_3ffca240) {
        _DAT_3ffca244 = 0;
      }
    }
    _DAT_3ffca244 = _DAT_3ffca244 + param_2;
    if (DAT_3ffca1e6 != '\0') {
      memw();
      (**(code **)(_DAT_3ffc1a34 + 0x1b8))(_DAT_3ffca204 / 100);
      FUN_40161bf8();
      (**(code **)(_DAT_3ffc1a34 + 0x19c))(0,0,_DAT_3ffca20c);
    }
  }
  _DAT_3ffca218 = 0;
  memw();
  _DAT_3ff73cb8 = _DAT_3ff73cb8 & 0xfff1ffff;
  memw();
  if (((DAT_3ffca1f1 != '\0') && (DAT_3ffca1e6 != '\0')) && (DAT_3ffca1e7 == '\0')) {
    DAT_3ffca1f1 = DAT_3ffca1e7;
    memw();
    memw();
    FUN_4016179c();
  }
  return;
}

