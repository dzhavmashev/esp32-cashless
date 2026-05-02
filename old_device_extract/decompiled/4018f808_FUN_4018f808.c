// Function : FUN_4018f808
// Address  : 0x4018f808
// Size     : 54 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4018f808(void)

{
  uint uVar1;
  
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff5ccb8);
  _DAT_3ff5ccb8 = uVar1 & 0x1fffffff | 0x20000000;
  memw();
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff5c85c);
  memw();
  _DAT_3ff5c85c = uVar1 & 0xfffffff0;
  return;
}

