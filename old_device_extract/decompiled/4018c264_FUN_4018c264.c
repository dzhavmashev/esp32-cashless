// Function : FUN_4018c264
// Address  : 0x4018c264
// Size     : 186 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4018c264(void)

{
  undefined8 uVar1;
  ulonglong uVar2;
  undefined4 uVar3;
  int iVar4;
  
  _DAT_3ffca228 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
  uVar2 = (ulonglong)_DAT_3ffca228 >> 0x20;
  uVar3 = (undefined4)_DAT_3ffca228;
  memw();
  FUN_4018c018();
  if (DAT_3ffca1e5 == '\0') {
    (**(code **)(_DAT_3ffc1a34 + 0xec))(0x3ffca27c);
    (**(code **)(_DAT_3ffc1a34 + 0xec))(0x3ffca2cc);
    DAT_3ffca1f0 = 1;
    memw();
    memw();
    memw();
    _DAT_3ff73cb8 = _DAT_3ff73cb8 & 0xfff1ffff;
    memw();
    return;
  }
  DAT_3ffca1e9 = 1;
  memw();
  memw();
  FUN_4018bd48(&DAT_3ffca1d8);
  if (DAT_3ffca1d9 == '\x02') {
    FUN_4018bdc0();
    _DAT_3ffc7c20 = _DAT_3ffc7c20 + 1;
    DAT_3ffca1ea = 0;
    memw();
  }
  _DAT_3ffca1f4 = _DAT_3ffca1f4 + 1;
  memw();
  _DAT_3ffc7c10 = _DAT_3ffc7c10 + 1;
  memw();
  FUN_40161c2c(uVar3,(int)uVar2);
  FUN_40161378();
  iVar4 = FUN_401619a0();
  uVar1 = _DAT_3ffca228;
  if (iVar4 == 0) {
    FUN_40161844();
    FUN_401617f4();
    uVar1 = _DAT_3ffca228;
  }
  _DAT_3ffca22c = (undefined4)((ulonglong)uVar1 >> 0x20);
  _DAT_3ffca228 = (undefined4)uVar1;
  return;
}

