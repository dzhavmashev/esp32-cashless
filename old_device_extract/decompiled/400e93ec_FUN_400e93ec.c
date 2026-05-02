// Function : FUN_400e93ec
// Address  : 0x400e93ec
// Size     : 381 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400e93ec(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  undefined *puStack_d0;
  undefined4 uStack_cc;
  undefined *puStack_c8;
  undefined4 uStack_c4;
  undefined *puStack_c0;
  undefined4 uStack_bc;
  undefined *puStack_b8;
  undefined4 uStack_b4;
  undefined1 auStack_b0 [140];
  undefined4 *puStack_24;
  
  memw();
  memw();
  puStack_24 = _DAT_3ffc5708;
  iVar1 = FUN_400e8448(&DAT_3ffc516c,1);
  puVar4 = (undefined4 *)&DAT_3ffc5708;
  if (iVar1 != 0) goto LAB_400e9455;
  uVar7 = func_0x40085c04();
  uVar2 = FUN_401847ec("face_ip");
  uVar3 = (*(code *)&SUB_4000cff8)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),1000,0);
  puVar4 = (undefined4 *)&DAT_3ffc5708;
  pcVar5 = "iled!\r\n";
  uVar6 = 299;
LAB_400e943a:
  FUN_4012105c(pcVar5,uVar3,uVar2,uVar6,"connect");
  do {
    uVar2 = 4;
    while( true ) {
      memw();
      memw();
      puVar4 = (undefined4 *)*puVar4;
      if (puStack_24 == puVar4) {
        return uVar2;
      }
      func_0x40082ecc();
LAB_400e9455:
      iVar1 = FUN_40146ec4(0,auStack_b0);
      if ((iVar1 != 0) || (iVar1 = FUN_40146e58(0,auStack_b0), iVar1 != 0)) {
        uVar7 = func_0x40085c04();
        uVar2 = FUN_401847ec("face_ip");
        uVar3 = (*(code *)&SUB_4000cff8)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),1000,0);
        uVar6 = 0x131;
        pcVar5 = "iled!\r\n";
        goto LAB_400e943a;
      }
      if (DAT_3ffc51cc == '\0') {
        puStack_d0 = &DAT_3f40a508;
        uStack_cc = _DAT_3ffc54e0;
        puStack_c8 = &DAT_3f40a508;
        uStack_c4 = _DAT_3ffc54e0;
        puStack_c0 = &DAT_3f40a508;
        uStack_bc = _DAT_3ffc54e0;
        puStack_b8 = &DAT_3f40a508;
        uStack_b4 = _DAT_3ffc54e0;
        iVar1 = FUN_400e852c(0,&puStack_d0,&puStack_c8,&puStack_c0,&puStack_b8);
        if (iVar1 != 0) {
          uVar7 = func_0x40085c04();
          uVar2 = FUN_401847ec("face_ip");
          uVar3 = (*(code *)&SUB_4000cff8)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),1000,0);
          uVar6 = 0x136;
          pcVar5 = "ailed\r\n";
          goto LAB_400e943a;
        }
      }
      iVar1 = FUN_400e90d8();
      if ((iVar1 != 3) && (iVar1 = FUN_40146a1c(), iVar1 != 0)) break;
      uVar2 = FUN_400e90d8();
    }
    uVar7 = func_0x40085c04();
    uVar2 = FUN_401847ec("face_ip");
    uVar3 = (*(code *)&SUB_4000cff8)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),1000,0);
    FUN_4012105c("iled!\r\n",uVar3,uVar2,0x13d,"connect",iVar1);
  } while( true );
}

