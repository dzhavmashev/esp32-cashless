// Function : FUN_40138f28
// Address  : 0x40138f28
// Size     : 55 bytes


undefined * FUN_40138f28(uint param_1)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = &DAT_3f4213c4;
  if (param_1 != 5) {
    if (param_1 < 6) {
      if (param_1 == 3) {
        return &DAT_3f4213dc;
      }
      iVar2 = param_1 - 4;
      puVar1 = &DAT_3f4213d0;
    }
    else {
      if (param_1 == 7) {
        return &DAT_3f4213ac;
      }
      if (param_1 < 7) {
        return &DAT_3f4213b8;
      }
      iVar2 = param_1 - 8;
      puVar1 = &DAT_3f4213a0;
    }
    if (iVar2 != 0) {
      puVar1 = (undefined *)0x0;
    }
  }
  return puVar1;
}

