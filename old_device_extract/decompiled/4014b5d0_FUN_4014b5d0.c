// Function : FUN_4014b5d0
// Address  : 0x4014b5d0
// Size     : 163 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4014b5d0(void)

{
  int iVar1;
  uint uVar2;
  
  if ((((*_DAT_3ffbfc54 & 0xfffffffd) == 1) && (_DAT_3ffc8800 != 0)) &&
     (iVar1 = *(int *)(_DAT_3ffc8800 + 0xe4), iVar1 != 0)) {
    if (*(char *)(iVar1 + 0xac) == '\x01') {
      if ((byte)(*(char *)(iVar1 + 0xab) - 1U) < 9) {
        return 1;
      }
    }
    else if ((*(char *)(iVar1 + 0xac) == '\x02') && ((byte)(*(char *)(iVar1 + 0xab) - 5U) < 9)) {
      return 1;
    }
  }
  if ((*_DAT_3ffbfc54 - 2 < 2) && (_DAT_3ffc8804 != 0)) {
    uVar2 = 1;
    do {
      if (_DAT_3ffbfc54[0x3f6] < uVar2) {
        return 0;
      }
      iVar1 = *(int *)(uVar2 * 4 + _DAT_3ffc8804 + 0xec);
      if ((iVar1 != 0) && (*(short *)(iVar1 + 0x26) != 0)) {
        if (*(char *)(iVar1 + 0xac) == '\x01') {
          if ((byte)(*(char *)(iVar1 + 0xab) - 1U) < 9) {
            return 1;
          }
        }
        else if ((*(char *)(iVar1 + 0xac) == '\x02') && ((byte)(*(char *)(iVar1 + 0xab) - 5U) < 9))
        {
          return 1;
        }
      }
      uVar2 = uVar2 + 1 & 0xff;
    } while( true );
  }
  return 0;
}

