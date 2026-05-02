// Function : FUN_400f54fc
// Address  : 0x400f54fc
// Size     : 46 bytes


undefined1 * FUN_400f54fc(uint param_1)

{
  undefined1 *puVar1;
  
  if (param_1 < 0x1e) {
    puVar1 = &DAT_3ff000d0;
    if ((param_1 < 0x17) && (puVar1 = &DAT_3ff000c4, param_1 - 0x14 < 2)) {
      puVar1 = &DAT_3ff000d0;
    }
  }
  else {
    puVar1 = &DAT_3ff000c4;
    if (param_1 < 0x21) {
      puVar1 = &DAT_3ff00020;
    }
  }
  return puVar1;
}

