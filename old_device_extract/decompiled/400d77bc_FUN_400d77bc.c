// Function : FUN_400d77bc
// Address  : 0x400d77bc
// Size     : 1292 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400d77bc(int param_1)

{
  code *pcVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined *puVar6;
  undefined4 uVar7;
  char *pcVar8;
  undefined *puVar9;
  byte bStack_100;
  undefined1 uStack_ff;
  undefined1 uStack_fe;
  undefined1 auStack_f8 [24];
  undefined1 auStack_e0 [104];
  int aiStack_78 [2];
  code *pcStack_70;
  undefined1 *puStack_6c;
  int aiStack_68 [2];
  code *pcStack_60;
  undefined1 *puStack_5c;
  undefined1 auStack_58 [24];
  undefined1 auStack_40 [28];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_400f0780(0x3ffc5490,"mulator");
  FUN_400d909c(*(undefined4 *)(param_1 + 8));
  FUN_400f0780(0x3ffc5490,"l state");
  iVar3 = FUN_40183e94(*(undefined4 *)(param_1 + 8));
  iVar5 = 0x3ffc5490;
  if (iVar3 != 0) goto LAB_400d785a;
  do {
    iVar3 = FUN_40183e94(*(undefined4 *)(param_1 + 8));
    puVar6 = &DAT_3f401ac9;
    if (iVar3 == 0) {
      puVar6 = &DAT_3f401ace;
    }
    iVar3 = FUN_400d9a08(*(undefined4 *)(param_1 + 8));
    puVar9 = &DAT_3f401ac9;
    if (iVar3 == 0) {
      puVar9 = &DAT_3f401ace;
    }
    FUN_400f06a4(iVar5,"uration",puVar6,puVar9);
    FUN_400f0780(iVar5,"fig=%s\n");
    FUN_400d7d34(param_1,1);
    while( true ) {
      iVar5 = iStack_24;
      param_1 = _DAT_3ffc5708;
      memw();
      memw();
      if (iStack_24 == _DAT_3ffc5708) {
        return;
      }
      func_0x40082ecc();
LAB_400d785a:
      iVar3 = FUN_400d9a08(*(undefined4 *)(param_1 + 8));
      if (iVar3 == 0) break;
      FUN_400d9908(auStack_58,*(undefined4 *)(param_1 + 8));
      FUN_400f0780(iVar5,"eloaded");
      FUN_400f0be8(aiStack_68,"g state");
      uVar4 = FUN_400f10c0(aiStack_68,auStack_58);
      FUN_400f0768(iVar5,uVar4);
      FUN_400f0a50(aiStack_68);
      FUN_400f0be8(aiStack_68,"roker: ");
      uVar4 = FUN_400f10c0(aiStack_68,auStack_40);
      FUN_400f0768(iVar5,uVar4);
      FUN_400f0a50(aiStack_68);
      iVar3 = FUN_400daa6c(0x3ffc4218,auStack_58);
      pcVar8 = "ce ID: ";
      if (iVar3 == 0) goto LAB_400d7ba0;
      puStack_5c = (undefined1 *)0x400d6f24;
      pcStack_60 = (code *)&LAB_40183d64;
      aiStack_68[0] = param_1;
      FUN_400d73f0(0x3ffc4a28,aiStack_68);
      (*(code *)&LAB_40183a17_1)(aiStack_68);
      puStack_6c = &DAT_400d77a4;
      pcStack_70 = FUN_40183d7c;
      pcStack_60 = (code *)0x0;
      aiStack_78[0] = param_1;
      FUN_40183d7c(aiStack_68,aiStack_78,2);
      puStack_5c = puStack_6c;
      pcStack_60 = pcStack_70;
      FUN_400d73b8(aiStack_68,0x3ffc4a38);
      puVar2 = _DAT_3ffc4a44;
      pcVar1 = _DAT_3ffc4a40;
      _DAT_3ffc4a40 = pcStack_60;
      pcStack_60 = pcVar1;
      _DAT_3ffc4a44 = puStack_5c;
      puStack_5c = puVar2;
      (*(code *)&LAB_40183a17_1)(aiStack_68);
      (*(code *)&LAB_40183a17_1)(aiStack_78);
      FUN_400f0780(iVar5," client");
      iVar3 = FUN_400daf88(0x3ffc4218);
      if (iVar3 == 0) {
        FUN_400f0780(iVar5,"oker...");
        uVar4 = 3;
LAB_400d79bc:
        FUN_400d7d34(param_1,uVar4);
        FUN_400f0a50(auStack_40);
      }
      else {
        FUN_400d7378(&bStack_100,0x200,0);
        uVar4 = FUN_400d4db0(auStack_e0,"offline status",auStack_f8);
        FUN_400d6da8("ssfully",uVar4);
        FUN_400e6d7c(aiStack_78,*(undefined4 *)(param_1 + 0x1c));
        uVar4 = FUN_400d4db0(auStack_e0,"",auStack_f8);
        FUN_40183db8(aiStack_78,uVar4,auStack_f8);
        FUN_400f0a50(aiStack_78);
        uVar4 = FUN_400d4db0(auStack_e0,"loading firmware",auStack_f8);
        FUN_400d6da8("version",uVar4);
        iVar3 = (*(code *)&LAB_40183e8b_1)(*(undefined4 *)(param_1 + 8));
        pcVar8 = "g state";
        if (iVar3 != 1) {
          pcVar8 = "te";
        }
        uVar4 = FUN_400d4db0(auStack_e0,"eviceId",auStack_f8);
        FUN_400d6da8(pcVar8,uVar4);
        FUN_400f0be8(aiStack_68,&DAT_3f42161d);
        FUN_400d5948(auStack_e0,aiStack_68);
        FUN_400da510(0x3ffc4218,aiStack_68);
        FUN_400f0780(iVar5,"NECTING");
        FUN_400f0a50(aiStack_68);
        FUN_400d73a8(&bStack_100);
        FUN_400e0ef4(*(undefined4 *)(param_1 + 0x20));
        FUN_400e723c(*(undefined4 *)(param_1 + 0x24));
        FUN_400e7250(*(undefined4 *)(param_1 + 0x24),1);
        FUN_400f0780(iVar5," status");
        iVar3 = FUN_400e55bc(0x3ffc4ae8);
        if (iVar3 == 0) {
          FUN_400f0780(iVar5,"Manager");
        }
        FUN_400e7730(*(undefined4 *)(param_1 + 0x18),5);
        DAT_3ffc4a24 = 0;
        uVar4 = func_0x40091390();
        *(undefined4 *)(param_1 + 0x58) = uVar4;
        memw();
        *(undefined1 *)(param_1 + 0x54) = 1;
        func_0x40090934(0x400d8848," failed",0x2000,param_1,1,param_1 + 0x50,0);
        FUN_400f06a4(0x3ffc5490,"et_task");
        FUN_400f0780(0x3ffc5490,"Core 0\n");
        FUN_400d9c94(&bStack_100,*(undefined4 *)(param_1 + 8));
        FUN_400f06a4(0x3ffc5490,"troller",bStack_100,uStack_ff,uStack_fe);
        iVar3 = FUN_400dde10(&bStack_100);
        iVar5 = 0x3ffc5490;
        *(int *)(param_1 + 0x28) = iVar3;
        if (iVar3 == 0) {
          pcVar8 = "in: %d\n";
LAB_400d7ba0:
          FUN_400f0780(iVar5,pcVar8);
          uVar4 = 5;
          goto LAB_400d79bc;
        }
        puStack_6c = &LAB_400d735c;
        pcStack_70 = FUN_40183d94;
        pcStack_60 = (code *)0x0;
        aiStack_78[0] = param_1;
        FUN_40183d94(aiStack_68,aiStack_78,2);
        puStack_5c = puStack_6c;
        pcStack_60 = pcStack_70;
        FUN_400d73b8(aiStack_68,iVar3 + 4);
        uVar4 = *(undefined4 *)(iVar3 + 0xc);
        uVar7 = *(undefined4 *)(iVar3 + 0x10);
        *(code **)(iVar3 + 0xc) = pcStack_60;
        *(undefined1 **)(iVar3 + 0x10) = puStack_5c;
        pcStack_60 = (code *)uVar4;
        puStack_5c = (undefined1 *)uVar7;
        (*(code *)&LAB_40183a17_1)(aiStack_68);
        (*(code *)&LAB_40183a17_1)(aiStack_78);
        puStack_5c = (undefined1 *)0x400d6d84;
        pcStack_60 = (code *)&LAB_40183dac;
        FUN_400d73f0(*(int *)(param_1 + 0x28) + 0x14,aiStack_68);
        (*(code *)&LAB_40183a17_1)(aiStack_68);
        iVar3 = (**(code **)(**(int **)(param_1 + 0x28) + 8))(*(int **)(param_1 + 0x28),&bStack_100)
        ;
        iVar5 = 0x3ffc5490;
        pcVar8 = "troller";
        if (iVar3 == 0) goto LAB_400d7ba0;
        pcVar8 = "t_based";
        if (bStack_100 != 2) {
          if (bStack_100 < 3) {
            pcVar8 = "ecovery";
            if ((bStack_100 != 0) && (pcVar8 = "", bStack_100 != 1)) {
LAB_400d7c6e:
              pcVar8 = " OID is unknown";
            }
          }
          else {
            pcVar8 = "h_relay";
            if (((bStack_100 != 4) && (pcVar8 = "r_based", 3 < bStack_100)) &&
               (pcVar8 = "lay", bStack_100 != 5)) goto LAB_400d7c6e;
          }
        }
        FUN_400f06a4(0x3ffc5490,"troller",pcVar8);
        FUN_400f0780(0x3ffc5490,"de: %s\n");
        FUN_400f0a50(auStack_40);
      }
      FUN_400f0a50(auStack_58);
    }
  } while( true );
}

