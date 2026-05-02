// Function : FUN_4016a87c
// Address  : 0x4016a87c
// Size     : 184 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016a87c(void)

{
  if ((_DAT_3ffca4c8 & 0x10000) == 0) {
    (**(code **)(_DAT_3ffc7e64 + 0x30))();
    _DAT_3ffca4c8 = _DAT_3ffca4c8 | 0x10000;
  }
  FUN_4016cd2c();
  if ((_DAT_3ffca4c8 & 0x80000) == 0) {
    (**(code **)(_DAT_3ffc7e64 + 0x114))(0x3ffca4d4,_DAT_3ffc073c,_DAT_3ffc073e);
    _DAT_3ffca4c8 = _DAT_3ffca4c8 | 0x80000;
  }
  FUN_4016d1c4();
  FUN_4016de60(0);
  FUN_4016da5c(1);
  FUN_4016a6c8();
  if ((DAT_3ffc7e6d == '\0') || (DAT_3ffc7e6f == '\0')) {
    (*(code *)&SUB_400883c0)(_DAT_3ffc073c,_DAT_3ffc073e);
    (*(code *)&SUB_40088a54)(0);
    FUN_40169ea0();
  }
  FUN_4016eeac();
  FUN_4016a4b0(0x985,3);
  FUN_4016a7a4();
  (*(code *)&SUB_4008a288)(0);
  FUN_4018f390();
  _DAT_3ffca516 = 0xfe80;
  _DAT_3ffca57a = 0xfe80;
  memw();
  FUN_4016f968(0xb,0);
  return;
}

