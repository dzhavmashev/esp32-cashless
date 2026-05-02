// Function : FUN_4018ec38
// Address  : 0x4018ec38
// Size     : 168 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4018ec38(void)

{
  uint uVar1;
  
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff5d000);
  _DAT_3ff5d000 = uVar1 & 0xe00007ff | 0xf7e8000;
  memw();
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff46048);
  _DAT_3ff46048 = uVar1 & 0xffff00ff | 0xa400;
  memw();
  _DAT_3ff5c400 = (*(code *)&SUB_40084594)(&DAT_3ff5c400);
  _DAT_3ff5c400 = _DAT_3ff5c400 & 0xfff8ffff;
  memw();
  _DAT_3ff450d0 = (*(code *)&SUB_40084594)(&DAT_3ff450d0);
  _DAT_3ff450d0 = _DAT_3ff450d0 & 0xbfffffff;
  memw();
  memw();
  _DAT_3ff450c4 = 1000000;
  memw();
  _DAT_3ff450c8 = 1000000;
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff4e054);
  _DAT_3ff4e054 = uVar1 & 0xffffff00 | 100;
  memw();
  FUN_4018ea50(0);
  return;
}

