// Function : FUN_4013d950
// Address  : 0x4013d950
// Size     : 151 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4013d950(undefined4 param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = 0;
  while (uVar1 != param_3) {
    memw();
    *(undefined4 *)(uVar1 * 4 + 0x3ff02000) = 0xffffffff;
    uVar1 = uVar1 + 1;
    memw();
  }
  _DAT_3ff0280c = (param_3 >> 4) - 1;
  memw();
  _DAT_3ff02800 = 1;
  memw();
  memw();
  FUN_401866ec(0x3ff02600,param_1,param_3);
  uVar1 = 1;
  memw();
  _DAT_3ff02200 = 1;
  while (uVar1 < param_3) {
    memw();
    *(undefined4 *)(&DAT_3ff02200 + uVar1 * 4) = 0;
    uVar1 = uVar1 + 1;
    memw();
  }
  memw();
  _DAT_3ff02814 = 1;
  memw();
  _DAT_3ff02810 = 1;
  memw();
  FUN_4013d79c();
  FUN_401866ec(0x3ff02600,param_2,param_3);
  memw();
  _DAT_3ff02814 = 1;
  memw();
  _DAT_3ff02810 = 1;
  memw();
  return;
}

