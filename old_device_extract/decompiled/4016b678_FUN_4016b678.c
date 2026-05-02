// Function : FUN_4016b678
// Address  : 0x4016b678
// Size     : 86 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016b678(void)

{
  DAT_3ffc7e6b = 1;
  memw();
  _DAT_3ff5c860 = (*(code *)&SUB_40084594)(&DAT_3ff5c860);
  _DAT_3ff5c860 = _DAT_3ff5c860 | 0x400;
  memw();
  _DAT_3ff5c860 = (*(code *)&SUB_40084594)(&DAT_3ff5c860);
  _DAT_3ff5c860 = _DAT_3ff5c860 | 0x800;
  memw();
  _DAT_3ff5c87c = (*(code *)&SUB_40084594)(&DAT_3ff5c87c);
  _DAT_3ff5c87c = _DAT_3ff5c87c | 0x800;
  memw();
  (*(code *)&SUB_40088a54)(1);
  return;
}

