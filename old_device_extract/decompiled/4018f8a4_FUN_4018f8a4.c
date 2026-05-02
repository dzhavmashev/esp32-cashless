// Function : FUN_4018f8a4
// Address  : 0x4018f8a4
// Size     : 211 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4018f8a4(void)

{
  uint uVar1;
  
  (*(code *)&LAB_400fc90f_1)(1);
  _DAT_3ff48890 = (*(code *)&SUB_40084594)(&DAT_3ff48890);
  _DAT_3ff48890 = _DAT_3ff48890 | 0x8000000;
  memw();
  _DAT_3ff66010 = (*(code *)&SUB_40084594)(&DAT_3ff66010);
  _DAT_3ff66010 = _DAT_3ff66010 & 0xfffffffb;
  memw();
  _DAT_3ff48890 = (*(code *)&SUB_40084594)(&DAT_3ff48890);
  _DAT_3ff48890 = _DAT_3ff48890 & 0xefffffff;
  memw();
  _DAT_3ff48894 = (*(code *)&SUB_40084594)(&DAT_3ff48894);
  _DAT_3ff48894 = _DAT_3ff48894 | 0x80000000;
  memw();
  _DAT_3ff48894 = (*(code *)&SUB_40084594)(&DAT_3ff48894);
  _DAT_3ff48894 = _DAT_3ff48894 & 0x8007ffff;
  memw();
  _DAT_3ff4882c = (*(code *)&SUB_40084594)(&DAT_3ff4882c);
  _DAT_3ff4882c = _DAT_3ff4882c | 0xc;
  memw();
  _DAT_3ff48838 = (*(code *)&SUB_40084594)(&DAT_3ff48838);
  _DAT_3ff48838 = _DAT_3ff48838 & 0x3fffffff;
  memw();
  _DAT_3ff48838 = (*(code *)&SUB_40084594)(&DAT_3ff48838);
  _DAT_3ff48838 = _DAT_3ff48838 & 0xfffffffc;
  memw();
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff4882c);
  memw();
  _DAT_3ff4882c = uVar1 & 0xffffff1f | 0x80;
  return;
}

