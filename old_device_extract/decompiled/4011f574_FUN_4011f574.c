// Function : FUN_4011f574
// Address  : 0x4011f574
// Size     : 41 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_4011f574(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = _DAT_3ffc6720 >> 0x15 & 7;
  uVar2 = uVar1;
  if (uVar1 != 2) {
    if ((_DAT_3ffc6720 >> 0x10 & 0xff) == 0x26) {
      uVar2 = 2;
    }
    else if ((uVar1 != 1) && (uVar2 = 3, uVar1 == 0)) {
      uVar2 = 0;
    }
  }
  return uVar2;
}

