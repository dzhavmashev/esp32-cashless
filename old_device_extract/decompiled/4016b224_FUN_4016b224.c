// Function : FUN_4016b224
// Address  : 0x4016b224
// Size     : 118 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016b224(void)

{
  (*(code *)&SUB_4008819c)();
  _DAT_3ff00024 = (*(code *)&SUB_40084594)(&DAT_3ff00024);
  _DAT_3ff00024 = _DAT_3ff00024 & 0xfffffffd;
  memw();
  _DAT_3ff000d0 = (*(code *)&SUB_40084594)(&DAT_3ff000d0);
  _DAT_3ff000d0 = _DAT_3ff000d0 | 3;
  memw();
  (*(code *)&SUB_40008534)(1);
  _DAT_3ff000d0 = (*(code *)&SUB_40084594)(&DAT_3ff000d0);
  _DAT_3ff000d0 = _DAT_3ff000d0 & 0xfffffffc;
  memw();
  _DAT_3ff48030 = (*(code *)&SUB_40084594)(&DAT_3ff48030);
  _DAT_3ff48030 = _DAT_3ff48030 & 0x27ffffff;
  memw();
  (*(code *)&SUB_40008534)(1);
  (*(code *)&SUB_4008a288)(1);
  return;
}

