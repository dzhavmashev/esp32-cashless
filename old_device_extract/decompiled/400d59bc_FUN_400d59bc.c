// Function : FUN_400d59bc
// Address  : 0x400d59bc
// Size     : 1407 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400d59bc(int param_1,undefined4 param_2,int *param_3)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  int *piVar5;
  undefined4 ***pppuVar6;
  int iVar7;
  int *piVar8;
  undefined4 ***pppuVar9;
  undefined4 ****in_a12;
  undefined4 ****ppppuVar10;
  longlong lVar11;
  undefined8 uVar12;
  int iStack_494;
  undefined4 uStack_490;
  undefined8 uStack_48c;
  undefined4 ***pppuStack_484;
  undefined4 **ppuStack_480;
  char *pcStack_47c;
  undefined4 ***pppuStack_478;
  char *pcStack_474;
  undefined4 ***local_470 [3];
  byte bStack_461;
  undefined1 auStack_460 [16];
  undefined4 **appuStack_450 [6];
  undefined1 auStack_438 [1044];
  int *local_24;
  
  memw();
  memw();
  local_24 = _DAT_3ffc5708;
  pppuVar6 = appuStack_450;
  FUN_40183bb4(pppuVar6);
  iVar2 = FUN_400d54e4(pppuVar6,param_2);
  piVar5 = (int *)0x3ffc5490;
  if (iVar2 == 0) goto LAB_400d5aa9;
  FUN_400f0be8(auStack_460,"");
  FUN_400f0be8(local_470,*(undefined4 *)(iVar2 * 4 + 0x3ffbdb68));
  uVar3 = FUN_400f10c0(auStack_460,local_470);
  FUN_400f0d18(param_1 + 0x10,uVar3);
  FUN_400f0a50(local_470);
  FUN_400f0a50(auStack_460);
  FUN_400f0be8(auStack_460,"error: ");
  uVar3 = FUN_400f10c0(auStack_460,param_1 + 0x10);
  FUN_400f0768(0x3ffc5490,uVar3);
  FUN_400f0a50(auStack_460);
  do {
    param_1 = 0;
    while( true ) {
      param_3 = local_24;
      piVar5 = _DAT_3ffc5708;
      memw();
      memw();
      if (local_24 == _DAT_3ffc5708) {
        return;
      }
      func_0x40082ecc();
      pppuVar6 = (undefined4 ***)&DAT_3ffc5708;
LAB_400d5aa9:
      pppuVar9 = pppuVar6 + 6;
      iVar2 = FUN_400d4330(pppuVar9,"offline status");
      if (iVar2 == 0) break;
      pcStack_47c = "offline status";
      ppuStack_480 = pppuVar6;
      iVar2 = FUN_400d490c(&ppuStack_480,"lient: ");
      if (iVar2 != 0) break;
      iVar2 = FUN_400d4330(pppuVar9,"ailed: ");
      if (iVar2 == 0) {
        FUN_400f0d70(param_1 + 0x10,": ");
        FUN_400f0be8(auStack_460,"error: ");
        uVar3 = FUN_400f10c0(auStack_460,param_1 + 0x10);
        FUN_400f0768(piVar5,uVar3);
LAB_400d5d06:
        FUN_400f0a50(auStack_460);
        param_1 = 0;
      }
      else {
        pcVar4 = (char *)FUN_400d4330(pppuVar9,"ailed: ");
        if ((pcVar4 == (char *)0x0) || ((pcVar4[8] & 0x20U) == 0)) {
LAB_400d5ccc:
          FUN_400f0d70(param_1 + 0x10,"esponse");
          FUN_400f0be8(auStack_460,"error: ");
          uVar3 = FUN_400f10c0(auStack_460,param_1 + 0x10);
          FUN_400f0768(piVar5,uVar3);
          goto LAB_400d5d06;
        }
        iVar2 = FUN_400d431c(pcVar4,"ts");
        if (iVar2 == 0) goto LAB_400d5ccc;
        iVar2 = FUN_400d431c(pcVar4,"he same port");
        if (iVar2 == 0) goto LAB_400d5ccc;
        iVar2 = FUN_400d48f8(pcVar4,"ts");
        FUN_400f0be8(auStack_460,&DAT_3f42161d);
        uVar12 = uStack_48c;
        if (iVar2 == 0) {
LAB_400d5c8c:
          uStack_48c = uVar12;
          FUN_400d5948(iVar2,auStack_460);
        }
        else {
          uVar12 = (*(code *)&LAB_40183af3_1)(iVar2);
          pppuStack_484 = in_a12;
          if ((int)uVar12 == 0) goto LAB_400d5c8c;
          uStack_48c = uVar12;
          FUN_400f0d70(auStack_460,(int)uVar12);
        }
        FUN_400f0d60(param_3,auStack_460);
        FUN_400f0a50(auStack_460);
        iVar2 = FUN_400d48f8(pcVar4,"he same port");
        iVar7 = 0;
        if (iVar2 != 0) {
          iVar7 = FUN_400d4348();
        }
        param_3[4] = iVar7;
        piVar8 = param_3 + 6;
        FUN_400e6d7c(auStack_460,0x3ffc4d78);
        FUN_400f0d60(piVar8,auStack_460);
        FUN_400f0a50(auStack_460);
        iVar2 = (*(code *)&LAB_40183a7b_1)(piVar8);
        if (iVar2 == 0) {
          FUN_400f0d70(param_1 + 0x10,"ERROR - Failed to extract device ID from certificate");
          FUN_400f0be8(auStack_460,"error: ");
          uVar3 = FUN_400f10c0(auStack_460,param_1 + 0x10);
          FUN_400f0768(piVar5,uVar3);
          goto LAB_400d5d06;
        }
        pcStack_474 = "or port";
        uStack_490 = CONCAT31(uStack_490._1_3_,1);
        pcStack_47c = pcVar4;
        pppuStack_478 = appuStack_450;
        uVar1 = FUN_400d49c0(&ppuStack_480,&uStack_490);
        *(undefined1 *)(param_3 + 5) = uVar1;
        pcStack_474 = "use_tls";
        uStack_490 = 0x3c;
        pcStack_47c = pcVar4;
        pppuStack_478 = appuStack_450;
        iVar2 = FUN_400d4a48(&ppuStack_480,&uStack_490);
        param_3[10] = iVar2;
        pcStack_474 = "p_alive";
        uStack_490 = CONCAT31(uStack_490._1_3_,1);
        pcStack_47c = pcVar4;
        pppuStack_478 = appuStack_450;
        uVar1 = FUN_400d49c0(&ppuStack_480,&uStack_490);
        *(undefined1 *)(param_3 + 0xc) = uVar1;
        pcStack_474 = "session";
        uStack_490 = 300;
        pcStack_47c = pcVar4;
        pppuStack_478 = appuStack_450;
        iVar2 = FUN_400d4a48(&ppuStack_480,&uStack_490);
        param_3[0xb] = iVar2;
        FUN_400f0780(piVar5,"nterval");
        iStack_494 = (int)param_3;
        if ((*(byte *)((int)param_3 + 0xf) & 0x80) == 0) {
          iStack_494 = *param_3;
        }
        FUN_400f06a4(piVar5,"ul",iStack_494,param_3[4]);
        pcVar4 = "n error";
        if ((char)param_3[5] == '\0') {
          pcVar4 = "ror";
        }
        FUN_400f06a4(piVar5,"ssfully",pcVar4);
        FUN_400f0be8(auStack_460,"LS: %s\n");
        uVar3 = FUN_400f10c0(auStack_460,piVar8);
        uVar3 = FUN_400f10f0(uVar3,"evices/");
        FUN_400f0d4c(local_470,uVar3);
        FUN_400f0a50(auStack_460);
        ppppuVar10 = local_470;
        if ((bStack_461 & 0x80) == 0) {
          ppppuVar10 = (undefined4 ****)local_470[0];
        }
        FUN_400f06a4(piVar5,"ommands",ppppuVar10);
        FUN_400f0a50(local_470);
        FUN_400f0be8(auStack_460,"LS: %s\n");
        uVar3 = FUN_400f10c0(auStack_460,piVar8);
        uVar3 = FUN_400f10f0(uVar3,"ic: %s\n");
        FUN_400f0d4c(local_470,uVar3);
        FUN_400f0a50(auStack_460);
        in_a12 = local_470;
        if ((bStack_461 & 0x80) == 0) {
          in_a12 = (undefined4 ****)local_470[0];
        }
        FUN_400f06a4(piVar5,"/events");
        FUN_400f0a50(local_470);
        param_1 = 1;
      }
    }
    iVar2 = FUN_400d48f8(auStack_438,"all");
    if ((iVar2 == 0) || (1 < (byte)((*(byte *)(iVar2 + 8) & 0x7f) - 4))) {
      lVar11 = CONCAT44(pcStack_47c,"");
    }
    else {
      iVar2 = FUN_400d48f8(auStack_438,"all");
      lVar11 = ZEXT48(pcStack_47c) << 0x20;
      if (iVar2 != 0) {
        lVar11 = (*(code *)&LAB_40183af3_1)();
        ppuStack_480 = (undefined4 **)lVar11;
        pppuStack_478 = in_a12;
      }
    }
    pcStack_47c = (char *)((ulonglong)lVar11 >> 0x20);
    FUN_400f0be8(local_470,(int)lVar11);
    FUN_400f0be8(auStack_460,"success");
    uVar3 = FUN_400f10c0(auStack_460,local_470);
    FUN_400f0d18(param_1 + 0x10,uVar3);
    FUN_400f0a50(auStack_460);
    FUN_400f0be8(auStack_460,"error: ");
    uVar3 = FUN_400f10c0(auStack_460,param_1 + 0x10);
    FUN_400f0768(piVar5,uVar3);
    FUN_400f0a50(auStack_460);
    FUN_400f0a50(local_470);
  } while( true );
}

