// Function : FUN_401071f4
// Address  : 0x401071f4
// Size     : 60 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401071f4(void)

{
  int iVar1;
  char *pcStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  pcStack_2c = "DEF";
  uStack_28 = 0;
  uStack_24 = _DAT_3ffbde88;
  memw();
  iVar1 = FUN_40101278(&pcStack_2c);
  if (iVar1 == 0) {
    (*(code *)&SUB_40094c54)("ifi/src/wifi_default.c",0x13f,"ifi_sta","invalid netif");
  }
  FUN_401071e0();
  FUN_401071b4();
  return;
}

