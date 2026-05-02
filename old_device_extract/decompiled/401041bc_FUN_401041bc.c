// Function : FUN_401041bc
// Address  : 0x401041bc
// Size     : 109 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_401041bc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  uint uVar1;
  
  _DAT_3ffc81f8 = param_7;
  DAT_3ffc8150 = 0;
  DAT_3ffc811c = 1;
  memw();
  _DAT_3ffc8140 = 0;
  _DAT_3ffc8114 = 0;
  memw();
  _DAT_3ffc81e4 = param_2;
  _DAT_3ffc81e8 = param_3;
  _DAT_3ffc81ec = param_4;
  _DAT_3ffc81f0 = param_5;
  _DAT_3ffc81f4 = param_6;
  uVar1 = FUN_4015a404(0);
  DAT_3ffc8238 = (byte)(uVar1 >> 10) & 1;
  DAT_3ffc8239 = (byte)(uVar1 >> 0xb) & 1;
  memw();
  memw();
  FUN_40103538(2);
  _DAT_3ffc80ac = FUN_40106858(0x40102df0,0x3ffc7ef0,0x3ffc7ef0);
  memw();
  return _DAT_3ffc80ac != 0;
}

