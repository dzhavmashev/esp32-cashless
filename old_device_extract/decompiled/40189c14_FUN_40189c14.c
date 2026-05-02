// Function : FUN_40189c14
// Address  : 0x40189c14
// Size     : 35 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_40189c14(void)

{
  uint uVar1;
  
  memw();
  uVar1 = 0;
  if ((_DAT_6001c860 & 0xc00) == 0xc00) {
    memw();
    uVar1 = _DAT_6001c87c >> 0xb & 1;
  }
  return uVar1;
}

