// Function : FUN_4018f2d0
// Address  : 0x4018f2d0
// Size     : 138 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4018f2d0(void)

{
  uint uVar1;
  
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff5c0a0);
  _DAT_3ff5c0a0 = uVar1 & 0xff00ffff | 0x800000;
  memw();
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff5c01c);
  _DAT_3ff5c01c = uVar1 & 0xff00ffff | 0xc0000;
  memw();
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff5c094);
  _DAT_3ff5c094 = uVar1 & 0xffff01ff | 0xdc00;
  memw();
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff5c0f0);
  _DAT_3ff5c0f0 = uVar1 & 0xffffff00 | 0x80;
  memw();
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff5c0b8);
  memw();
  _DAT_3ff5c0b8 = uVar1 | 0x800;
  return;
}

