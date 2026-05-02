// Function : FUN_4010112c
// Address  : 0x4010112c
// Size     : 232 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4010112c(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  char *pcVar6;
  undefined1 auStack_38 [4];
  undefined1 auStack_34 [16];
  undefined4 *puStack_24;
  
  memw();
  memw();
  puStack_24 = _DAT_3ffc5708;
  memw();
  iVar2 = FUN_40100574();
  puVar5 = (undefined4 *)&DAT_3ffc5708;
  if (iVar2 == 0) goto LAB_40101176;
  uVar3 = (*(code *)&SUB_40094b80)();
  puVar5 = (undefined4 *)&DAT_3ffc5708;
  pcVar6 = "t (%x)\n";
LAB_40101159:
  do {
    FUN_4012113c(1,&PTR_s_STA_DEF_3f40e714,pcVar6,uVar3,&PTR_s_STA_DEF_3f40e714);
    iVar2 = -1;
    do {
      do {
        memw();
        memw();
        puVar5 = (undefined4 *)*puVar5;
        if (puStack_24 == puVar5) {
          return;
        }
        (*(code *)&SUB_40082ec4)();
LAB_40101176:
        iVar4 = FUN_4011b0cc(4);
        if (iVar4 == 0) {
          FUN_4011e57c(auStack_34,0x10);
          uVar3 = (*(code *)&SUB_40094b80)();
          FUN_4011ab34(uVar3,auStack_34);
          cVar1 = FUN_4011ad40(auStack_38,iVar2);
          if (cVar1 != '\0') {
            uVar3 = (*(code *)&SUB_40094b80)();
            pcVar6 = "failed\n";
            goto LAB_40101159;
          }
          FUN_40109e9c(0x4010075c,auStack_38);
          FUN_4011ade8(auStack_38,iVar2);
          FUN_4011ae30(auStack_38);
        }
        if (_DAT_3ffc5860 == 0) {
          cVar1 = FUN_4011ad40();
          if (cVar1 != '\0') {
            uVar3 = (*(code *)&SUB_40094b80)();
            pcVar6 = "aphore\n";
            goto LAB_40101159;
          }
        }
      } while (_DAT_3ffc585c != 0);
      cVar1 = FUN_4011ad40(&DAT_3ffc585c,1);
    } while (cVar1 == '\0');
    uVar3 = (*(code *)&SUB_40094b80)();
    pcVar6 = "t fail\n";
  } while( true );
}

