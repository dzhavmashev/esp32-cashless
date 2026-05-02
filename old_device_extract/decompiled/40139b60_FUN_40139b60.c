// Function : FUN_40139b60
// Address  : 0x40139b60
// Size     : 41 bytes


undefined * FUN_40139b60(uint param_1)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = &DAT_3f422370;
  if (param_1 != 2) {
    if (param_1 < 3) {
      iVar2 = param_1 - 1;
      puVar1 = &DAT_3f4223a0;
    }
    else {
      if (param_1 == 3) {
        return &DAT_3f422340;
      }
      iVar2 = param_1 - 4;
      puVar1 = &DAT_3f422310;
    }
    if (iVar2 != 0) {
      puVar1 = (undefined *)0x0;
    }
  }
  return puVar1;
}

