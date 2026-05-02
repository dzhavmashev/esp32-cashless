// Function : FUN_40107230
// Address  : 0x40107230
// Size     : 60 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40107230(void)

{
  int iVar1;
  undefined **ppuStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  ppuStack_2c = &PTR_s_suite_3f40e6f0;
  uStack_28 = 0;
  uStack_24 = _DAT_3ffbde8c;
  memw();
  iVar1 = FUN_40101278(&ppuStack_2c);
  if (iVar1 == 0) {
    (*(code *)&SUB_40094c54)("ifi/src/wifi_default.c",0x14d,"fault.c","invalid netif");
  }
  FUN_401071cc();
  FUN_401071b4();
  return;
}

