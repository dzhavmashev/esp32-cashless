// Function : FUN_4018ed5c
// Address  : 0x4018ed5c
// Size     : 423 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4018ed5c(void)

{
  uint uVar1;
  
  _DAT_3ff5c004 = (*(code *)&SUB_40084594)(&DAT_3ff5c004);
  _DAT_3ff5c004 = _DAT_3ff5c004 & 0xfffeffff;
  memw();
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff5c0a4);
  _DAT_3ff5c0a4 = uVar1 & 0xffffc07f | 0x1e00;
  memw();
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff5c0a4);
  _DAT_3ff5c0a4 = uVar1 & 0xffffff80 | 0x3c;
  memw();
  memw();
  _DAT_3ff5c0c4 = 0x6450403f;
  memw();
  _DAT_3ff5c030 = 0x3c1a4d5;
  memw();
  _DAT_3ff5c094 = 0x1b8dd03;
  memw();
  _DAT_3ff5c02c = 0x324048fe;
  _DAT_3ff5c02c = (*(code *)&SUB_40084594)(&DAT_3ff5c02c);
  _DAT_3ff5c02c = _DAT_3ff5c02c | 0x800000;
  memw();
  _DAT_3ff5c02c = (*(code *)&SUB_40084594)(&DAT_3ff5c02c);
  _DAT_3ff5c02c = _DAT_3ff5c02c & 0xff7fffff;
  memw();
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff5c018);
  _DAT_3ff5c018 = uVar1 & 0xfffffff8 | 4;
  memw();
  _DAT_3ff5c018 = (*(code *)&SUB_40084594)(&DAT_3ff5c018);
  _DAT_3ff5c018 = _DAT_3ff5c018 | 0x40000000;
  memw();
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff5c01c);
  _DAT_3ff5c01c = uVar1 & 0xffffff00 | 0xbf;
  memw();
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff5c028);
  _DAT_3ff5c028 = uVar1 & 0xfffffe00 | 0x1ba;
  memw();
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff5c0f8);
  _DAT_3ff5c0f8 = uVar1 & 0xfffc01ff | 0x37400;
  memw();
  _DAT_3ff5c038 = (*(code *)&SUB_40084594)(&DAT_3ff5c038);
  _DAT_3ff5c038 = _DAT_3ff5c038 & 0xf7ffffff;
  memw();
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff5c088);
  _DAT_3ff5c088 = uVar1 & 0xffffff00 | 5;
  memw();
  _DAT_3ff5c104 = (*(code *)&SUB_40084594)(&DAT_3ff5c104);
  _DAT_3ff5c104 = _DAT_3ff5c104 & 0xffff7fff;
  memw();
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff5c07c);
  memw();
  _DAT_3ff5c07c = uVar1 & 0xff00ffff | 0x9c0000;
  return;
}

