// Function : FUN_4016da5c
// Address  : 0x4016da5c
// Size     : 152 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016da5c(undefined1 param_1)

{
  if ((_DAT_3ffca4c8 & 0x100000) == 0) {
    FUN_4016bc68();
    FUN_4016d8e0(6,param_1);
    FUN_4016d8e0(1,param_1);
    FUN_4016d8e0(0xb,param_1);
    _DAT_3ffca4d2 = _DAT_3ffca4d0;
    memw();
    DAT_3ffca53a = DAT_3ffca534;
    memw();
    (**(code **)(_DAT_3ffc7e64 + 0x124))();
    _DAT_3ffca586 = _DAT_3ffc073e;
    _DAT_3ffca584 = _DAT_3ffc073c;
    _DAT_3ffca4c8 = _DAT_3ffca4c8 | 0x100000;
    DAT_3ffca519 = 0xe;
    memw();
    return;
  }
  _DAT_3ffc073c = _DAT_3ffca584;
  _DAT_3ffc073e = _DAT_3ffca586;
  memw();
  return;
}

