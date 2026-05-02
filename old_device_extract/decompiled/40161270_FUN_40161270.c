// Function : FUN_40161270
// Address  : 0x40161270
// Size     : 94 bytes


/* WARNING: Removing unreachable block (ram,0x401612aa) */
/* WARNING: Removing unreachable block (ram,0x401612b2) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_40161270(char param_1)

{
  bool bVar1;
  
  if (((DAT_3ffc1a44 != '\0') && (memw(), DAT_3ffc1a3c == '\0')) && (_DAT_3ffc1a40 != 0)) {
    if (DAT_3ffca1d9 != '\0') {
      memw();
    }
    return DAT_3ffca1d9 == '\0';
  }
  bVar1 = true;
  if ((DAT_3ffca1d9 != '\0') && (DAT_3ffca1da == param_1)) {
    bVar1 = false;
  }
  return bVar1;
}

