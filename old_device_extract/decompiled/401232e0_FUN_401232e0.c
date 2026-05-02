// Function : FUN_401232e0
// Address  : 0x401232e0
// Size     : 99 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401232e0(void)

{
  (*(code *)&SUB_40086460)(0x3ffc75f4);
  DAT_3ffc75f0 = DAT_3ffc75f0 + -1;
  memw();
  if (DAT_3ffc75f0 == '\0') {
    if (_DAT_3ffc75e0 != 0) {
      memw();
      FUN_4016b754(1);
      DAT_3ffc75f1 = 1;
      memw();
    }
    memw();
    (*(code *)&SUB_4008888c)();
    _DAT_3ffc75d8 = (*(code *)&SUB_40085bfc)();
    memw();
    (*(code *)&SUB_40081744)();
  }
  (*(code *)&SUB_400864a0)(0x3ffc75f4);
  return;
}

