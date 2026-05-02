// Function : FUN_40163050
// Address  : 0x40163050
// Size     : 30 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40163050(uint param_1,undefined1 param_2)

{
  *(undefined1 *)(_DAT_3ffc0034 + (param_1 & 0xff) * 0x30 + 0x28) = param_2;
  memw();
  memw();
  return;
}

