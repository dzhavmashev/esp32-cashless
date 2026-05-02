// Function : FUN_40145d1c
// Address  : 0x40145d1c
// Size     : 44 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte * FUN_40145d1c(void)

{
  int iVar1;
  byte *pbVar2;
  
  iVar1 = FUN_40189d50();
  pbVar2 = (byte *)0x0;
  if (iVar1 == 0) {
    pbVar2 = (byte *)0x0;
    if (_DAT_3ffc78e4 != (byte *)0x0) {
      pbVar2 = (byte *)0x0;
      if ((uint)DAT_3ffc78e8 < (uint)*_DAT_3ffc78e4) {
        pbVar2 = _DAT_3ffc78e4 + (uint)DAT_3ffc78e8 * 4 + 2;
      }
    }
    FUN_40189d78();
  }
  return pbVar2;
}

