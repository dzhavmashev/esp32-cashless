// Function : FUN_400f21e8
// Address  : 0x400f21e8
// Size     : 27 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400f21e8(int param_1)

{
  _DAT_3ffc5538 = 0xffffffff;
  if ((param_1 != 0) && (*(byte *)(param_1 + 4) < 3)) {
    _DAT_3ffc5538 = (uint)*(byte *)(param_1 + 4);
  }
  FUN_400f21bc();
  return;
}

