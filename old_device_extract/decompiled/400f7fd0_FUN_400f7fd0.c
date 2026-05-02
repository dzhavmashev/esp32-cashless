// Function : FUN_400f7fd0
// Address  : 0x400f7fd0
// Size     : 58 bytes


/* WARNING: Control flow encountered bad instruction data */

uint FUN_400f7fd0(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0x10;
  do {
    iVar1 = FUN_400f8eb4(0,iVar2,0);
    if (iVar1 == 0) {
      return iVar2 - 0x10U & 0xff;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x21);
  (*(code *)&SUB_40094c54)("_update/esp_ota_ops.c",0x17f,"rtition","!= NULL");
  cust0();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

