// Function : FUN_4016b0bc
// Address  : 0x4016b0bc
// Size     : 143 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016b0bc(void)

{
  uint uVar1;
  
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff4e0c4);
  _DAT_3ff4e0c4 = uVar1 & 0xfff0ffff | 0x20000;
  memw();
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff4e0c4);
  _DAT_3ff4e0c4 = uVar1 & 0xff0fffff | 0x400000;
  memw();
  _DAT_3ff4e0c4 = (*(code *)&SUB_40084594)(&DAT_3ff4e0c4);
  _DAT_3ff4e0c4 = _DAT_3ff4e0c4 | 0x1000000;
  memw();
  _DAT_3ff4e0c4 = (*(code *)&SUB_40084594)(&DAT_3ff4e0c4);
  _DAT_3ff4e0c4 = _DAT_3ff4e0c4 | 0x40000000;
  memw();
  _DAT_3ff4e0c4 = (*(code *)&SUB_40084594)(&DAT_3ff4e0c4);
  _DAT_3ff4e0c4 = _DAT_3ff4e0c4 & 0xdfffffff;
  memw();
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff4e0c4);
  memw();
  _DAT_3ff4e0c4 = uVar1 & 0xffff83ff | 0x2c00;
  return;
}

