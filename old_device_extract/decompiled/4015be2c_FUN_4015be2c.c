// Function : FUN_4015be2c
// Address  : 0x4015be2c
// Size     : 85 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4015be2c(void)

{
  undefined4 uVar1;
  
  uVar1 = 0x3f434bd6;
  if ((_DAT_3ffc8a2c & 1) != 0) {
    if (_DAT_3ffc8800 == 0) {
      uVar1 = 0x3f434bb8;
    }
    else {
      if (*(int *)(_DAT_3ffc8800 + 0x98) != 5) {
        FUN_40147fe4(1,8,4,0x3f434b93);
        return 0;
      }
      if (*(int *)(_DAT_3ffc8800 + 0xe4) != 0) {
        return 1;
      }
      uVar1 = 0x3f434b6d;
    }
  }
  FUN_40147fe4(1,8,4,uVar1);
  return 0;
}

