// Function : FUN_40169f78
// Address  : 0x40169f78
// Size     : 37 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40169f78(void)

{
  uint uVar1;
  
  (**(code **)(_DAT_3ffc7e64 + 0xc))();
  uVar1 = (*(code *)&SUB_40084594)(&DAT_60033cb8);
  memw();
  _DAT_60033cb8 = uVar1 & 0xf8007fff;
  return;
}

