// Function : FUN_400ef644
// Address  : 0x400ef644
// Size     : 1078 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400ef644(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined1 *puVar7;
  undefined1 auStack_94 [16];
  undefined1 auStack_84 [16];
  undefined1 auStack_74 [16];
  undefined1 auStack_64 [16];
  undefined1 auStack_54 [16];
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  iVar1 = (*(code *)&LAB_40184637_1)(param_1);
  if (iVar1 == 0) {
    param_1 = -4;
    goto LAB_400efa26;
  }
  *(undefined4 *)(param_1 + 0x98) = 0xffffffff;
  *(undefined1 *)(param_1 + 0x9c) = *(undefined1 *)(param_1 + 0x24);
  *(undefined4 *)(param_1 + 0x94) = 0;
  FUN_400f0be8(auStack_94,&DAT_3f42161d);
  *(undefined4 *)(param_1 + 0xb8) = 0;
  iVar2 = FUN_400f1a9c();
  FUN_400f0be8(auStack_84,&DAT_3f42161d);
  do {
    while( true ) {
      iVar3 = (*(code *)&LAB_40184637_1)(param_1);
      if (iVar3 == 0) {
        iVar1 = -5;
        goto LAB_400efa15;
      }
      iVar3 = (**(code **)(**(int **)(param_1 + 8) + 0x18))();
      if (iVar3 != 0) break;
      iVar3 = FUN_400f1a9c();
      if ((uint)*(ushort *)(param_1 + 0x26) < (uint)(iVar3 - iVar2)) {
        iVar1 = -0xb;
        goto LAB_400efa15;
      }
      FUN_400f1ab4(10);
    }
    FUN_400f08c0(auStack_74,*(undefined4 *)(param_1 + 8),10);
    FUN_400f17d0(auStack_74);
    iVar2 = FUN_400f1a9c();
    if (iVar1 == 0) {
      iVar1 = FUN_400f13f0(auStack_74,0x3a);
      if (iVar1 != 0) {
        uVar5 = FUN_400f13f0(auStack_74,0x3a);
        FUN_400f1520(auStack_64,auStack_74,0,uVar5);
        iVar1 = FUN_400f13f0(auStack_74,0x3a);
        FUN_400ed9cc(auStack_54,auStack_74,iVar1 + 1);
        FUN_400f17d0(auStack_54);
        FUN_400f0be8(auStack_34,"");
        iVar1 = FUN_400f122c(auStack_64,auStack_34);
        FUN_400f0a50(auStack_34);
        if (iVar1 != 0) {
          FUN_400f0d18(auStack_84,auStack_54);
        }
        FUN_400f0be8(auStack_34,"re");
        iVar1 = FUN_400f122c(auStack_64,auStack_34);
        FUN_400f0a50(auStack_34);
        if (iVar1 != 0) {
          uVar5 = FUN_400f1854(auStack_54);
          *(undefined4 *)(param_1 + 0x98) = uVar5;
        }
        if (*(char *)(param_1 + 0x9c) != '\0') {
          FUN_400f0be8(auStack_34,"tocol\r\n");
          iVar1 = FUN_400f122c(auStack_64,auStack_34);
          FUN_400f0a50(auStack_34);
          if (iVar1 != 0) {
            FUN_400f0be8(auStack_44,"p-alive");
            iVar1 = FUN_400f143c(auStack_54,auStack_44);
            uVar6 = 0;
            if (-1 < iVar1) {
              FUN_400f0be8(auStack_34,"ction: ");
              uVar6 = FUN_400f143c(auStack_54,auStack_34);
              uVar6 = uVar6 >> 0x1f;
              FUN_400f0a50(auStack_34);
            }
            FUN_400f0a50(auStack_44);
            if (uVar6 != 0) {
              *(undefined1 *)(param_1 + 0x9c) = 0;
            }
          }
        }
        FUN_400f0be8(auStack_34,"-Length");
        iVar1 = FUN_400f122c(auStack_64,auStack_34);
        FUN_400f0a50(auStack_34);
        if (iVar1 != 0) {
          FUN_400f0d18(auStack_94,auStack_54);
        }
        FUN_400f0be8(auStack_34,"ncoding");
        iVar1 = FUN_400f122c(auStack_64,auStack_34);
        FUN_400f0a50(auStack_34);
        if (iVar1 != 0) {
          FUN_400f0d18(param_1 + 0xa8,auStack_54);
        }
        FUN_400f0be8(auStack_34,"ocation");
        iVar1 = FUN_400f122c(auStack_64,auStack_34);
        FUN_400f0a50(auStack_34);
        if (iVar1 != 0) {
          FUN_400f0d4c(auStack_44,auStack_84);
          FUN_400f0d4c(auStack_34,auStack_54);
          FUN_400eeef0(param_1,auStack_44,auStack_34);
          FUN_400f0a50(auStack_34);
          FUN_400f0a50(auStack_44);
        }
        for (uVar6 = 0; uVar6 < *(uint *)(param_1 + 0x90); uVar6 = uVar6 + 1) {
          iVar1 = FUN_400f122c(*(int *)(param_1 + 0x8c) + uVar6 * 0x20,auStack_64);
          if (iVar1 != 0) {
            FUN_400f0d18(*(int *)(param_1 + 0x8c) + uVar6 * 0x20 + 0x10,auStack_54);
            break;
          }
        }
        FUN_400f0a50(auStack_54);
        puVar7 = auStack_64;
        goto LAB_400ef73f;
      }
    }
    else {
      if ((*(char *)(param_1 + 0x9c) != '\0') &&
         (iVar1 = FUN_400e6830(auStack_74,"zation"), iVar1 != 0)) {
        pcVar4 = (char *)FUN_400f1354(auStack_74,7);
        *(bool *)(param_1 + 0x9c) = *pcVar4 != '0';
      }
      iVar1 = FUN_400f13f0(auStack_74,0x20);
      uVar5 = FUN_400f13c0(auStack_74,0x20,iVar1 + 1);
      FUN_400f1520(auStack_34,auStack_74,iVar1 + 1,uVar5);
      uVar5 = FUN_400f1854(auStack_34);
      *(undefined4 *)(param_1 + 0x94) = uVar5;
      puVar7 = auStack_34;
LAB_400ef73f:
      FUN_400f0a50(puVar7);
    }
    iVar1 = FUN_400f11c0(auStack_74,&DAT_3f42161d);
    if (iVar1 != 0) {
      iVar1 = (*(code *)&LAB_40183a7b_1)(auStack_94);
      if (iVar1 == 0) goto LAB_400efa6d;
      FUN_400f0be8(auStack_34,"-Cookie");
      iVar1 = FUN_400f122c(auStack_94,auStack_34);
      FUN_400f0a50(auStack_34);
      if (iVar1 == 0) goto LAB_400efa44;
      uVar5 = 1;
      do {
        *(undefined4 *)(param_1 + 0xb8) = uVar5;
        iVar1 = *(int *)(param_1 + 0x94);
        if (iVar1 == 0) {
          iVar1 = -7;
        }
        do {
          FUN_400f0a50(auStack_74);
LAB_400efa15:
          FUN_400f0a50(auStack_84);
          FUN_400f0a50(auStack_94);
          param_1 = iVar1;
LAB_400efa26:
          memw();
          memw();
          if (iStack_24 == _DAT_3ffc5708) {
            return;
          }
          func_0x40082ecc();
LAB_400efa44:
          FUN_400f0be8(auStack_34,"chunked");
          iVar2 = FUN_400f122c(auStack_94,auStack_34);
          FUN_400f0a50(auStack_34);
          iVar1 = -9;
        } while (iVar2 == 0);
LAB_400efa6d:
        uVar5 = 0;
      } while( true );
    }
    FUN_400f0a50(auStack_74);
    iVar1 = 0;
  } while( true );
}

