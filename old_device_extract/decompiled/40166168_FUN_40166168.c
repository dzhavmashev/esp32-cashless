// Function : FUN_40166168
// Address  : 0x40166168
// Size     : 62 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [12] FUN_40166168(uint *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined1 auVar1 [12];
  
  memw();
  if ((_DAT_3ff73250 & 0x80000000) != 0) {
    memw();
    *param_1 = _DAT_3ff7325c >> 0x14;
    memw();
    *param_2 = _DAT_3ff73268;
    memw();
    *param_3 = _DAT_3ff7326c;
  }
  auVar1._0_4_ = param_1 + 1;
  auVar1._4_4_ = param_2 + 1;
  auVar1._8_4_ = param_3 + 1;
  memw();
  return auVar1;
}

