// Function : FUN_400f572c
// Address  : 0x400f572c
// Size     : 86 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400f572c(void)

{
  (*(code *)&SUB_40092a70)();
  (*(code *)&SUB_40092a98)(0x3ffbdc58,0xffffffff);
  _DAT_3ff000cc = (*(code *)&SUB_40084594)(&DAT_3ff000cc);
  _DAT_3ff000cc = _DAT_3ff000cc | 0x406;
  memw();
  memw();
  _DAT_3ff000d0 = (*(code *)&SUB_40084594)(&DAT_3ff000d0);
  memw();
  memw();
  (*(code *)&SUB_40092a70)();
  (*(code *)&SUB_40092bec)(0x3ffbdc58);
  return;
}

