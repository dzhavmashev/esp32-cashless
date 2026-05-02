// Function : FUN_4016eeac
// Address  : 0x4016eeac
// Size     : 93 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016eeac(void)

{
  uint uVar1;
  
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff4884c);
  _DAT_3ff4884c = uVar1 & 0xff00ffff | 0x20000;
  memw();
  _DAT_3ff4884c = (*(code *)&SUB_40084594)(&DAT_3ff4884c);
  _DAT_3ff4884c = _DAT_3ff4884c | 0x2000000;
  memw();
  _DAT_3ff4884c = (*(code *)&SUB_40084594)(&DAT_3ff4884c);
  _DAT_3ff4884c = _DAT_3ff4884c & 0xfeffffff;
  memw();
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff4884c);
  memw();
  _DAT_3ff4884c = uVar1 | 0x1000000;
  return;
}

