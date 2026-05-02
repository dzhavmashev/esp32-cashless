// Function : FUN_4016e2bc
// Address  : 0x4016e2bc
// Size     : 79 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016e2bc(void)

{
  uint uVar1;
  
  (**(code **)(_DAT_3ffc7e64 + 0xf8))(1,(int)_DAT_3ffc7e92);
  _DAT_3ff5c400 = (*(code *)&SUB_40084594)(&DAT_3ff5c400);
  _DAT_3ff5c400 = _DAT_3ff5c400 & 0xfff8ffff;
  memw();
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff4e054);
  memw();
  _DAT_3ff4e054 = uVar1 & 0xffffff00 | 200;
  return;
}

