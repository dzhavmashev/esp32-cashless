// Function : FUN_400e6ab4
// Address  : 0x400e6ab4
// Size     : 330 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e6ab4(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  char *pcVar3;
  undefined1 auStack_54 [16];
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [16];
  undefined4 *puStack_24;
  
  memw();
  memw();
  puStack_24 = _DAT_3ffc5708;
  iVar1 = FUN_400e6a84(param_1);
  puVar2 = (undefined4 *)&DAT_3ffc5708;
  if (iVar1 == 0) {
    pcVar3 = (char *)0x3;
    goto LAB_400e6bb9;
  }
  FUN_400f0d4c(auStack_54,param_1 + 8);
  FUN_400f0d4c(auStack_44,param_1 + 0x28);
  FUN_400f0be8(auStack_34," in NVS");
  iVar1 = FUN_400f143c(auStack_54,auStack_34);
  FUN_400f0a50(auStack_34);
  if (iVar1 != -1) {
    FUN_400e6888(auStack_54," in NVS",&DAT_3f421885);
  }
  puVar2 = (undefined4 *)&DAT_3ffc5708;
  FUN_400f0be8(auStack_34," in NVS");
  iVar1 = FUN_400f143c(auStack_44,auStack_34);
  FUN_400f0a50(auStack_34);
  if (iVar1 != -1) {
    FUN_400e6888(auStack_44," in NVS",&DAT_3f421885);
  }
  iVar1 = FUN_400e6830(auStack_54,"ATE----------BEGIN CERTIFICATE-----");
  if ((iVar1 != 0) &&
     ((iVar1 = FUN_400e0438(auStack_54,"invalid"), iVar1 != 0 ||
      (iVar1 = FUN_400e0438(auStack_54,"E-----\n"), iVar1 != 0)))) {
    iVar1 = FUN_400e6830(auStack_44,"ATE----------BEGIN CERTIFICATE-----");
    pcVar3 = "invalid";
    goto LAB_400e6bcc;
  }
  pcVar3 = " NVS";
  do {
    FUN_400f0780(0x3ffc5490,pcVar3);
    pcVar3 = (char *)0x2;
    while( true ) {
      FUN_400f0a50(auStack_44);
      FUN_400f0a50(auStack_54);
LAB_400e6bb9:
      memw();
      memw();
      puVar2 = (undefined4 *)*puVar2;
      if (puStack_24 == puVar2) {
        return;
      }
      iVar1 = func_0x40082ecc();
LAB_400e6bcc:
      if ((iVar1 == 0) ||
         ((iVar1 = FUN_400e0438(auStack_44,pcVar3), iVar1 == 0 &&
          (iVar1 = FUN_400e0438(auStack_44,"E-----\n"), iVar1 == 0)))) break;
      pcVar3 = (char *)0x0;
    }
    pcVar3 = "TE-----";
  } while( true );
}

