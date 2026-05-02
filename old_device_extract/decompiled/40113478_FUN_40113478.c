// Function : FUN_40113478
// Address  : 0x40113478
// Size     : 29 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40113478(void)

{
  ushort uVar1;
  
  uVar1 = (*(code *)&SUB_400842fc)();
  _DAT_3ffbe0ce = (uVar1 & 0x3fff) + 0xc000;
  memw();
  memw();
  return;
}

