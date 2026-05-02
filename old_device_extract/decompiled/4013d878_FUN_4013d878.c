// Function : FUN_4013d878
// Address  : 0x4013d878
// Size     : 77 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4013d878(undefined4 param_1,undefined4 param_2,int param_3)

{
  FUN_401866ec(0x3ff02600,param_1,param_3);
  FUN_401866ec((param_3 + 0xffc0880) * 4,param_2,param_3);
  memw();
  _DAT_3ff02800 = 0;
  memw();
  _DAT_3ff0280c = ((uint)(param_3 << 1) >> 4) + 7;
  memw();
  _DAT_3ff02814 = 1;
  memw();
  _DAT_3ff02810 = 1;
  memw();
  return;
}

