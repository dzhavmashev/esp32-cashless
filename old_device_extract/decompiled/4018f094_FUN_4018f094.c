// Function : FUN_4018f094
// Address  : 0x4018f094
// Size     : 130 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4018f094(void)

{
  uint uVar1;
  
  _DAT_3ff00024 = (*(code *)&SUB_40084594)(&DAT_3ff00024);
  _DAT_3ff00024 = _DAT_3ff00024 | 0x10000000;
  memw();
  _DAT_3ff00024 = (*(code *)&SUB_40084594)(&DAT_3ff00024);
  _DAT_3ff00024 = _DAT_3ff00024 & 0xfffffffd;
  memw();
  _DAT_3ff00024 = (*(code *)&SUB_40084594)(&DAT_3ff00024);
  _DAT_3ff00024 = _DAT_3ff00024 | 2;
  memw();
  _DAT_3ff00024 = (*(code *)&SUB_40084594)(&DAT_3ff00024);
  _DAT_3ff00024 = _DAT_3ff00024 & 0xfffffffd;
  memw();
  _DAT_3ff00024 = (*(code *)&SUB_40084594)(&DAT_3ff00024);
  _DAT_3ff00024 = _DAT_3ff00024 | 2;
  memw();
  _DAT_3ff00024 = (*(code *)&SUB_40084594)(&DAT_3ff00024);
  _DAT_3ff00024 = _DAT_3ff00024 & 0xfffffffd;
  memw();
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff00024);
  memw();
  _DAT_3ff00024 = uVar1 | 2;
  return;
}

