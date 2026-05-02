// Function : FUN_4018f158
// Address  : 0x4018f158
// Size     : 326 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4018f158(char param_1)

{
  uint uVar1;
  
  if (param_1 != '\0') {
    _DAT_3ff5c044 = (*(code *)&SUB_40084594)(&DAT_3ff5c044);
    _DAT_3ff5c044 = _DAT_3ff5c044 | 0x1ff0000;
    memw();
    uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff5c044);
    _DAT_3ff5c044 = uVar1 & 0xffffc0ff | 0x2100;
    memw();
    uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff5c124);
    _DAT_3ff5c124 = uVar1 & 0xffff03ff | 0x8400;
    memw();
    uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff5c124);
    _DAT_3ff5c124 = uVar1 & 0xfffffff0 | 3;
    memw();
    uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff5c804);
    _DAT_3ff5c804 = uVar1 & 0xffff0fff | 0x9000;
    memw();
    uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff5c104);
    memw();
    _DAT_3ff5c104 = uVar1 & 0xfffffe00 | 0x1e2;
    return;
  }
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff5c044);
  _DAT_3ff5c044 = uVar1 & 0xfe00ffff | 0x1fb0000;
  memw();
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff5c044);
  _DAT_3ff5c044 = uVar1 & 0xffffc0ff | 0x1800;
  memw();
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff5c124);
  _DAT_3ff5c124 = uVar1 & 0xffff03ff | 0x6000;
  memw();
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff5c124);
  _DAT_3ff5c124 = uVar1 & 0xfffffff0 | 4;
  memw();
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff5c804);
  _DAT_3ff5c804 = uVar1 & 0xffff0fff | 0x6000;
  memw();
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff5c104);
  memw();
  _DAT_3ff5c104 = uVar1 & 0xfffffe00 | 0x1d2;
  return;
}

