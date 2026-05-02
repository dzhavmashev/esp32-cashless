// Function : FUN_40169f00
// Address  : 0x40169f00
// Size     : 112 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40169f00(void)

{
  uint uVar1;
  
  _DAT_60033cb8 = (*(code *)&SUB_40084594)(&DAT_60033cb8);
  _DAT_60033cb8 = _DAT_60033cb8 | 0x8000;
  memw();
  while (uVar1 = (*(code *)&SUB_40084594)(&DAT_60033cb8), (uVar1 & 0x6000) != 0) {
    (*(code *)&SUB_40008534)(2);
  }
  _DAT_60033cb8 = (*(code *)&SUB_40084594)(&DAT_60033cb8);
  _DAT_60033cb8 = _DAT_60033cb8 | 0x7ff8000;
  memw();
  while (uVar1 = (*(code *)&SUB_40084594)(&DAT_60033cb8), (uVar1 & 0x6000) != 0) {
    (*(code *)&SUB_40008534)(2);
  }
  (**(code **)(_DAT_3ffc7e64 + 8))();
  return;
}

