// Function : FUN_401512c4
// Address  : 0x401512c4
// Size     : 85 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_401512c4(void)

{
  int iVar1;
  
  iVar1 = _DAT_3ffbfc54;
  if ((((0xe < *(byte *)(_DAT_3ffbfc54 + 0x48b)) ||
       (0xd < (byte)(*(char *)(_DAT_3ffbfc54 + 0x48c) - 1U))) ||
      (*(byte *)(_DAT_3ffbfc54 + 0x48b) == 0)) || (1 < *(uint *)(_DAT_3ffbfc54 + 0x490))) {
    *(undefined1 *)(_DAT_3ffbfc54 + 0x488) = 0x43;
    *(undefined1 *)(iVar1 + 0x489) = 0x4e;
    *(undefined1 *)(iVar1 + 0x48a) = 0x20;
    *(undefined1 *)(iVar1 + 0x48b) = 1;
    *(undefined1 *)(iVar1 + 0x48c) = 0xd;
    *(undefined1 *)(iVar1 + 0x48d) = 0x14;
    memw();
    *(undefined4 *)(iVar1 + 0x490) = 0;
  }
  memw();
  return 0;
}

