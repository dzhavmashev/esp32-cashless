// Function : FUN_40102bc0
// Address  : 0x40102bc0
// Size     : 38 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40102bc0(void)

{
  undefined4 *puVar1;
  
  while (_DAT_3ffc5890 != 0) {
    puVar1 = (undefined4 *)(_DAT_3ffc5890 + 0x34);
    if ((code *)*puVar1 == (code *)0x0) {
      _DAT_3ffc5890 = *(int *)(_DAT_3ffc5890 + 0x3c);
      (*(code *)&SUB_40094d80)();
    }
    else {
      memw();
      _DAT_3ffc5890 = *(int *)(_DAT_3ffc5890 + 0x3c);
      (*(code *)*puVar1)();
    }
  }
  return;
}

