// Function : FUN_4010ca60
// Address  : 0x4010ca60
// Size     : 29 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4010ca60(void)

{
  ushort uVar1;
  
  uVar1 = (*(code *)&SUB_400842fc)();
  _DAT_3ffbe0cc = (uVar1 & 0x3fff) + 0xc000;
  memw();
  memw();
  return;
}

