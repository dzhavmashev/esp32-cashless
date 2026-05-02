// Function : FUN_4016b6d0
// Address  : 0x4016b6d0
// Size     : 86 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016b6d0(void)

{
  DAT_3ffc7e6b = 0;
  memw();
  _DAT_3ff5c860 = (*(code *)&SUB_40084594)(&DAT_3ff5c860);
  _DAT_3ff5c860 = _DAT_3ff5c860 & 0xfffffbff;
  memw();
  _DAT_3ff5c860 = (*(code *)&SUB_40084594)(&DAT_3ff5c860);
  _DAT_3ff5c860 = _DAT_3ff5c860 & 0xfffff7ff;
  memw();
  _DAT_3ff5c87c = (*(code *)&SUB_40084594)(&DAT_3ff5c87c);
  _DAT_3ff5c87c = _DAT_3ff5c87c & 0xfffff7ff;
  memw();
  (*(code *)&SUB_40088a54)(1);
  return;
}

