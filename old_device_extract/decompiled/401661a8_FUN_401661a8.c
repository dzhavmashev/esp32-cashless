// Function : FUN_401661a8
// Address  : 0x401661a8
// Size     : 103 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [12] FUN_401661a8(uint *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined1 auVar1 [12];
  
  memw();
  if ((_DAT_3ff73250 & 0x80000000) != 0) {
    memw();
    memw();
    memw();
    _DAT_3ff7325c = *param_1 & 0xfff | _DAT_3ff7325c & 0xfffff000;
    memw();
    _DAT_3ff73260 = *param_2;
    memw();
    _DAT_3ff73264 = *param_3;
    memw();
    memw();
    _DAT_3ff73250 = _DAT_3ff73250 & 0x7fffffff | 0x80000000;
    memw();
  }
  auVar1._0_4_ = param_1 + 1;
  auVar1._4_4_ = param_2 + 1;
  auVar1._8_4_ = param_3 + 1;
  memw();
  return auVar1;
}

