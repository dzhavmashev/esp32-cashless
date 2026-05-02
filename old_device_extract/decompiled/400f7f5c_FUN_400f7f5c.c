// Function : FUN_400f7f5c
// Address  : 0x400f7f5c
// Size     : 114 bytes


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_400f7f5c(void)

{
  int unaff_retaddr;
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  char *pcVar5;
  
  uVar3 = _DAT_3ffc5594;
  if (_DAT_3ffc5594 == 0) {
    uVar1 = FUN_400f9174(0x400f7f54);
    if (uVar1 != 0xffffffff) goto LAB_400f7f84;
    pcVar5 = "=0x%8x\n";
    uVar4 = 0x229;
    while( true ) {
      (*(code *)&SUB_40094c54)("_update/esp_ota_ops.c",uVar4,"rtition",pcVar5);
LAB_400f7f84:
      iVar2 = FUN_400f8e3c(0,0xff,0);
      if (iVar2 != 0) break;
      pcVar5 = "a_ops.c";
      uVar4 = 0x22e;
    }
    while( true ) {
      uVar3 = FUN_400f8e98(iVar2);
      if ((*(uint *)(uVar3 + 0xc) <= uVar1) &&
         (uVar1 < *(uint *)(uVar3 + 0xc) + *(int *)(uVar3 + 0x10))) break;
      iVar2 = FUN_400f8db8(iVar2);
      if (iVar2 == 0) {
        (*(code *)&SUB_40094bc8)();
        unaff_retaddr = uVar3 * 4 + unaff_retaddr;
        do {
          iVar2 = FUN_400f8eb4(uVar1,unaff_retaddr,uVar1);
          if (iVar2 == 0) {
            return unaff_retaddr - 0x10U & 0xff;
          }
          unaff_retaddr = unaff_retaddr + 1;
        } while (unaff_retaddr != 0x21);
        (*(code *)&SUB_40094c54)("_update/esp_ota_ops.c",0x17f,"rtition","!= NULL");
        cust0();
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
    }
    FUN_400f8e88();
  }
  memw();
  _DAT_3ffc5594 = uVar3;
  return uVar3;
}

