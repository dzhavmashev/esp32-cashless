// Function : FUN_4018f390
// Address  : 0x4018f390
// Size     : 187 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4018f390(void)

{
  uint uVar1;
  
  func_0x401cf41c();
  _DAT_3ffc073c = _DAT_3ffca584;
  _DAT_3ffc073e = _DAT_3ffca586;
  memw();
  FUN_4018ec38();
  FUN_4018ef70();
  FUN_4018ed5c();
  _DAT_3ff5d040 = (*pcRam4018f394)(&DAT_3ff5d040);
  _DAT_3ff5d040 = _DAT_3ff5d040 | 0x80000000;
  memw();
  memw();
  _DAT_3ff5d03c = &DAT_401800aa;
  FUN_4018f094();
  FUN_4018f808(1);
  (**(code **)(_DAT_3ffc7e64 + 0x1a4))();
  (**(code **)(_DAT_3ffc7e64 + 0x78))();
  uVar1 = (*pcRam4018f394)(&DAT_3ff5c030);
  _DAT_3ff5c030 = uVar1 & 0xfffc07ff | 0x1a000;
  memw();
  memw();
  _DAT_3ff5c11c = 0xe000;
  memw();
  _DAT_3ff5c120 = _FUN_4018f390;
  FUN_4018f2d0();
  FUN_4018f158(1);
  return;
}

