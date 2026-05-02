// Function : FUN_400f4554
// Address  : 0x400f4554
// Size     : 141 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400f4554(uint param_1,uint param_2,uint param_3)

{
  uint *puVar1;
  
  puVar1 = (uint *)(*_DAT_3ffbdc30 + ((param_1 & 0xff) + 0x14c) * 4);
  memw();
  memw();
  *puVar1 = *puVar1 & 0xfffffbff;
  memw();
  memw();
  *puVar1 = *puVar1 & 0xfffff7ff | (param_3 & 1) << 0xb;
  puVar1 = *(uint **)(&DAT_3f413ee8 + (param_1 & 0xff) * 4);
  if (puVar1 + -0xffc0000 < (uint *)0x13ffd) {
    memw();
    (*(code *)&SUB_40094c54)("ude/hal/gpio_ll.h",0x27d,"service","t->num)");
  }
  memw();
  memw();
  *puVar1 = (param_2 & 7) << 0xc | *puVar1 & 0xffff8fff;
  memw();
  return;
}

