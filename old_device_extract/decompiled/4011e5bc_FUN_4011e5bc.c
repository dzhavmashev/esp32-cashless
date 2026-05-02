// Function : FUN_4011e5bc
// Address  : 0x4011e5bc
// Size     : 33 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint * FUN_4011e5bc(uint param_1,uint param_2)

{
  uint *puVar1;
  
  for (puVar1 = _DAT_3ffc66e0;
      (puVar1 != (uint *)0x0 &&
      (((*puVar1 >> 0x10 & 1) != param_2 || ((*puVar1 >> 0x11 & 0x1f) != param_1))));
      puVar1 = (uint *)puVar1[2]) {
  }
  return puVar1;
}

