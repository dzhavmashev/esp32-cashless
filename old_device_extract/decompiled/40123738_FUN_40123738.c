// Function : FUN_40123738
// Address  : 0x40123738
// Size     : 157 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40123738(void)

{
  (*(code *)&SUB_40086460)(0x3ffc75f4);
  if (DAT_3ffc75f0 == '\0') {
    _DAT_3ffc75e8 = (*(code *)&SUB_40085bfc)();
    if (_DAT_3ffc75d8 != 0) {
      if (_DAT_3ffc5898 != (code *)0x0) {
        memw();
        (*_DAT_3ffc5898)((int)_DAT_3ffc75e8 - _DAT_3ffc75d8);
      }
      _DAT_3ffc75d8 = 0;
    }
    memw();
    (*(code *)&SUB_400816fc)();
    if (DAT_3ffc75f2 == '\0') {
      FUN_40123674();
      DAT_3ffc75f2 = '\x01';
      memw();
    }
    else {
      FUN_4018f734();
      if ((DAT_3ffc75f1 != '\0') && (_DAT_3ffc75e0 != 0)) {
        FUN_4016b754(0);
      }
    }
    memw();
    (*(code *)&SUB_400952e4)();
  }
  DAT_3ffc75f0 = DAT_3ffc75f0 + '\x01';
  memw();
  memw();
  (*(code *)&SUB_400864a0)(0x3ffc75f4);
  return;
}

