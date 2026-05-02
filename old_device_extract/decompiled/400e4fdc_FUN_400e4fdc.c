// Function : FUN_400e4fdc
// Address  : 0x400e4fdc
// Size     : 760 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e4fdc(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined1 *param_5,
                 undefined1 *param_6)

{
  int iVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  undefined1 *puVar5;
  uint uVar6;
  undefined1 *puVar7;
  undefined4 uVar8;
  char *pcVar9;
  uint in_t0;
  undefined8 uVar10;
  int iStack_118;
  undefined1 auStack_108 [16];
  undefined1 auStack_f8 [32];
  undefined1 auStack_d8 [64];
  undefined1 uStack_98;
  undefined1 auStack_94 [112];
  int iStack_24;
  undefined1 auStack_20 [32];
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_400f0780(0x3ffc5490,"m error");
  iVar1 = FUN_400ed7f4(0x3ffc5340,0);
  if (iVar1 == 0) {
    FUN_400f0be8(auStack_94,"ware...");
    FUN_400e4a64(param_1,6,auStack_94);
  }
  else {
    param_4 = param_1 + 0x8c;
    iVar4 = FUN_400da468(param_4);
    puVar5 = (undefined1 *)0x3ffc5490;
    if (iVar4 != 0) {
      pcVar9 = " PASSED";
      goto LAB_400e52c0;
    }
    FUN_400f0780(0x3ffc5490," failed");
    iStack_118 = FUN_400f80b4(0);
    if (iStack_118 != 0) {
      FUN_400f06a4(0x3ffc5490,"rtition",iStack_118 + 0x14,*(undefined4 *)(param_1 + 0x9c));
      param_6 = (undefined1 *)(*(code *)&LAB_40170346_2)(0x4000);
      FUN_4013f784(auStack_94);
      FUN_4013f86c(auStack_94,0);
      puVar5 = (undefined1 *)0x3ffc5490;
      iVar4 = 0;
      param_5 = (undefined1 *)0x0;
      goto LAB_400e50c4;
    }
    FUN_400f0be8(auStack_94,"hash...");
    FUN_400e4a64(param_1,0xb,auStack_94);
  }
  puVar5 = auStack_94;
LAB_400e507e:
  FUN_400f0a50(puVar5);
LAB_400e515e:
  uVar8 = 7;
  uVar6 = in_t0;
  do {
    FUN_400e4b9c(param_1,uVar8);
    iVar4 = iStack_24;
    param_1 = _DAT_3ffc5708;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) {
      return;
    }
    func_0x40082ecc();
    puVar5 = &DAT_3ffc5708;
    in_t0 = uVar6;
    do {
      FUN_4013f894(auStack_94,param_6,uVar6);
      param_5 = param_5 + uVar6;
      iVar2 = FUN_400f1a9c();
      if (1000 < (uint)(iVar2 - *(int *)(param_1 + 0x58))) {
        fVar3 = (float)FUN_40187018((float)param_5 / 1.0,(float)*(uint *)(param_1 + 0x9c) / 1.0);
        uVar10 = (*(code *)&SUB_40002c34)(fVar3 * 100.0);
        FUN_400f06a4(puVar5,"ition: ",(int)uVar10,(int)((ulonglong)uVar10 >> 0x20));
        uVar8 = FUN_400f1a9c();
        *(undefined4 *)(param_1 + 0x58) = uVar8;
      }
LAB_400e50c4:
      if (*(undefined1 **)(param_1 + 0x9c) <= param_5) goto LAB_400e5148;
      uVar6 = (int)*(undefined1 **)(param_1 + 0x9c) - (int)param_5;
      if (0x3fff < uVar6) {
        uVar6 = 0x4000;
      }
      iVar2 = FUN_400f90c0(iStack_118,param_5,param_6,uVar6);
    } while (iVar2 == 0);
    FUN_400f0be8(auStack_d8,"bytes)\n");
    FUN_400f0dd0(auStack_f8,iVar2,10);
    uVar8 = FUN_400f10c0(auStack_d8,auStack_f8);
    FUN_400e4a64(param_1,0xb,uVar8);
    FUN_400f0a50(auStack_f8);
    param_5 = auStack_20;
    FUN_400f0a50(auStack_d8);
    iVar4 = iVar1;
LAB_400e5148:
    FUN_4016fffc(param_6);
    if (iVar4 != 0) break;
    FUN_4013fa88(auStack_94,auStack_f8);
    FUN_4013f798(auStack_94);
    param_6 = auStack_d8;
    iVar4 = 0;
    do {
      puVar7 = auStack_f8 + iVar4;
      iVar4 = iVar4 + 1;
      FUN_4017435c(param_6,"%02x%02x%02x",*puVar7);
      param_6 = param_6 + 2;
    } while (iVar4 != 0x20);
    uStack_98 = 0;
    FUN_400f0be8(auStack_108,auStack_d8);
    iVar4 = FUN_400f122c(param_4,auStack_108);
    FUN_400f0a50(auStack_108);
    param_5 = (undefined1 *)0xffffff18;
    pcVar9 = "ismatch";
    if (iVar4 == 0) {
      FUN_400f06a4(puVar5,"%.1f%%\n");
      if ((*(byte *)(param_1 + 0x9b) & 0x80) == 0) {
        param_4 = *(int *)(param_1 + 0x8c);
      }
      FUN_400f06a4(puVar5,"match!\n",param_4);
      FUN_400f06a4(puVar5,"ed: %s\n",auStack_d8);
      FUN_400f0be8(auStack_108,"    %s\n");
      FUN_400e4a64(param_1,6,auStack_108);
      param_5 = (undefined1 *)0xffffff18;
      puVar5 = auStack_108;
      goto LAB_400e507e;
    }
LAB_400e52c0:
    FUN_400f0780(puVar5,pcVar9);
    FUN_400f0780(puVar5,"ication");
    uVar8 = 5;
    uVar6 = in_t0;
  } while( true );
  FUN_4013f798(auStack_94);
  goto LAB_400e515e;
}

