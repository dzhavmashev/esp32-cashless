// Function : FUN_400f44f0
// Address  : 0x400f44f0
// Size     : 97 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400f44f0(int param_1,int param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)(*_DAT_3ffbdc30 + (param_2 + 0x4c) * 4);
  memw();
  memw();
  *puVar1 = *puVar1 & 0xffffff7f;
  puVar1 = *(uint **)(&DAT_3f413ee8 + param_1 * 4);
  if (puVar1 + -0xffc0000 < (uint *)0x13ffd) {
    memw();
    (*(code *)&SUB_40094c54)("ude/hal/gpio_ll.h",0x272,"13FFC))","stalled");
  }
  memw();
  memw();
  *puVar1 = *puVar1 | 0x200;
  memw();
  return;
}

