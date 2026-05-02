// Function : FUN_40169ea0
// Address  : 0x40169ea0
// Size     : 43 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40169ea0(void)

{
  if ((_DAT_3ffca4c8 & 0x1000) == 0) {
    FUN_40168ed0();
  }
  if ((_DAT_3ffca4c8 & 0x800) == 0) {
    FUN_40168f80();
  }
  FUN_4016db04();
  if (DAT_3ffc7e68 == '\0') {
    (*(code *)&SUB_4008879c)();
  }
  return;
}

