// Function : FUN_401359d0
// Address  : 0x401359d0
// Size     : 1132 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401359d0(int param_1,byte *param_2,undefined4 param_3,int param_4,int param_5,
                 undefined1 *param_6)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  uint extraout_a3;
  byte *pbVar5;
  byte *pbVar6;
  undefined4 *puVar7;
  byte *pbVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  byte *in_t0;
  uint uStack_1e0;
  uint uStack_1dc;
  byte *pbStack_1d8;
  byte *pbStack_1d4;
  uint uStack_1d0;
  int iStack_1cc;
  undefined1 *puStack_1c4;
  undefined1 auStack_1c0 [12];
  undefined4 local_1b4 [9];
  undefined1 auStack_190 [101];
  byte abStack_12b [263];
  byte *pbStack_24;
  byte abStack_20 [32];
  
  memw();
  memw();
  pbStack_24 = _DAT_3ffc5708;
  memw();
  FUN_40138c04(auStack_190);
  iStack_1cc = param_5;
  puStack_1c4 = param_6;
  if (param_5 == 0) {
    iVar2 = FUN_40134e20(auStack_190,param_3,*(int *)(param_1 + 0x5c) + 7U >> 3);
    pbStack_1d4 = (byte *)0x0;
    pbVar5 = (byte *)0x0;
    pbVar6 = pbVar5;
    if (iVar2 != 0) goto LAB_40135ba9;
    puStack_1c4 = auStack_190;
    iStack_1cc = 0x40134e08;
  }
  memw();
  iVar2 = FUN_401860ec(param_4 + 0xc,param_1 + 0x34);
  pbStack_1d8 = (byte *)0x0;
  if (iVar2 == 0) {
    memw();
    iVar2 = FUN_401860ec(param_4,param_1 + 0x28);
    pbStack_1d8 = (byte *)(uint)(iVar2 == 0);
  }
  uStack_1d0 = 4;
  if (*(uint *)(param_1 + 0x5c) < 5) {
    uStack_1d0 = 2;
  }
  pbVar6 = (byte *)(uStack_1d0 - 1);
  uStack_1dc = 1 << 0x20 - (0x20 - ((uint)pbVar6 & 0x1f));
  pbStack_1d4 = (byte *)(uStack_1dc & 0xff);
  uStack_1e0 = ((*(uint *)(param_1 + 0x5c) - 1) + uStack_1d0) / uStack_1d0;
  if ((pbStack_1d8 == (byte *)0x0) || (pbVar5 = *(byte **)(param_1 + 0x74), pbVar5 == (byte *)0x0))
  {
    memw();
    pbVar5 = (byte *)FUN_4013ae30(uStack_1dc,0x24);
    iVar2 = -0x4d80;
    if (pbVar5 == (byte *)0x0) goto LAB_40135ba9;
    pbVar3 = (byte *)0x0;
    pbVar8 = pbVar5;
    do {
      memw();
      FUN_4013562c(pbVar8);
      pbVar3 = (byte *)((uint)(pbVar3 + 1) & 0xff);
      pbVar8 = pbVar8 + 0x24;
    } while (pbVar3 < pbStack_1d4);
    iVar2 = FUN_4013572c(pbVar5,param_4);
    if (iVar2 != 0) goto LAB_40135ba9;
    pbVar6 = (byte *)((int)pbVar6 * uStack_1e0);
    pbVar8 = (byte *)0x0;
    goto LAB_40135aba;
  }
  do {
    memw();
    FUN_40186008(auStack_1c0);
    FUN_40186008(local_1b4);
    iVar2 = FUN_4018601c(param_1 + 0x4c,0);
    if (iVar2 == 1) {
      iVar2 = FUN_4018601c(param_3,0);
      pbStack_1d8 = (byte *)(uint)(iVar2 == 0);
      memw();
      iVar2 = FUN_4013167c(auStack_1c0,param_3);
      if (((iVar2 == 0) && (iVar2 = FUN_40131d30(local_1b4,param_1 + 0x4c,param_3), iVar2 == 0)) &&
         (iVar2 = FUN_4013365c(auStack_1c0,local_1b4,pbStack_1d8), iVar2 == 0)) {
        (*(code *)&SUB_4008b530)(abStack_12b + 1,0,uStack_1e0 + 1);
        pbVar3 = abStack_12b + 1;
        uVar12 = 0;
        pbVar8 = pbVar3;
        while (uStack_1e0 != uVar12) {
          uVar10 = 0;
          uVar13 = uVar12;
          do {
            memw();
            iVar4 = FUN_4018601c(auStack_1c0,uVar13);
            uVar11 = uVar10 & 0x1f;
            uVar10 = uVar10 + 1;
            *pbVar8 = (byte)(iVar4 << 0x20 - (0x20 - uVar11)) | *pbVar8;
            memw();
            uVar13 = uVar13 + uStack_1e0;
          } while (uVar10 < uStack_1d0);
          uVar12 = uVar12 + 1;
          pbVar8 = pbVar8 + 1;
          memw();
        }
        uVar10 = 0;
        uVar13 = 1;
        while (uVar13 <= uVar12) {
          bVar1 = pbVar3[1];
          uVar11 = bVar1 ^ uVar10;
          pbVar6 = (byte *)((uint)*pbVar3 * ((uVar11 ^ 0xffffffff) & 1));
          pbVar3[1] = (byte)uVar11 ^ (byte)pbVar6;
          uVar10 = uVar11 & (uint)pbVar6 | bVar1 & uVar10;
          uVar13 = uVar13 + 1;
          *pbVar3 = (byte)(((uVar11 ^ 0xffffffff) & 1) << 7) | *pbVar3;
          memw();
          pbVar3 = pbVar3 + 1;
          memw();
        }
      }
      FUN_40131548(local_1b4);
      FUN_40131548(auStack_1c0);
      if (iVar2 == 0) {
        FUN_4013562c(local_1b4);
        pbVar6 = abStack_12b + 1;
        iVar2 = FUN_401352e4(param_1,param_2,pbVar5,uStack_1dc,pbVar6[uStack_1e0]);
        if (((iVar2 == 0) && (iVar2 = FUN_40131700(param_2 + 0x18,1), iVar2 == 0)) &&
           (iVar4 = FUN_40135034(param_1,param_2,iStack_1cc,puStack_1c4), iVar2 = iVar4, iVar4 == 0)
           ) {
          while (iVar2 = iVar4, uStack_1e0 != 0) {
            uStack_1e0 = uStack_1e0 - 1;
            memw();
            iVar2 = FUN_40135374(param_1,param_2,param_2);
            if (((iVar2 != 0) ||
                (iVar2 = FUN_401352e4(param_1,local_1b4,pbVar5,uStack_1dc,pbVar6[uStack_1e0]),
                iVar2 != 0)) ||
               (iVar2 = FUN_40135788(param_1,param_2,param_2,local_1b4), iVar2 != 0)) break;
          }
        }
        FUN_40135340(local_1b4);
        if (((iVar2 == 0) && (iVar2 = FUN_40134e84(param_1,param_2,pbStack_1d8), iVar2 == 0)) &&
           (iVar2 = FUN_40135034(param_1,param_2,iStack_1cc,puStack_1c4), iVar2 == 0)) {
          iVar2 = FUN_401350bc(param_1,param_2);
        }
      }
    }
    else {
      iVar2 = -0x4f80;
    }
LAB_40135ba9:
    do {
      do {
        do {
          FUN_40138f14(auStack_190);
          pbVar8 = *(byte **)(param_1 + 0x74);
          if ((pbVar8 != pbVar5) && (pbVar5 != (byte *)0x0)) {
            pbVar8 = pbVar5 + (int)pbStack_1d4 * 0x24;
            for (pbVar6 = pbVar5; pbVar6 != pbVar8; pbVar6 = pbVar6 + 0x24) {
              FUN_401356a8(pbVar6);
            }
            FUN_4013ae44(pbVar5);
          }
          pbVar3 = in_t0;
          if (iVar2 != 0) {
            FUN_401356a8(param_2);
            pbVar3 = in_t0;
          }
          pbVar5 = pbStack_24;
          param_2 = _DAT_3ffc5708;
          memw();
          memw();
          if (pbStack_24 == _DAT_3ffc5708) {
            return;
          }
          (*(code *)&SUB_40082ec4)();
          uVar12 = extraout_a3;
          in_t0 = pbVar3;
LAB_40135bfb:
          memw();
          iVar2 = FUN_4013572c(pbVar3,pbVar5 + (uVar12 >> 1 & 0x7f) * 0x24);
        } while (iVar2 != 0);
        while( true ) {
          iVar2 = FUN_40135374(param_1,pbVar3,pbVar3);
          if (iVar2 != 0) goto LAB_40135ba9;
          pbVar8 = pbVar8 + 1;
LAB_40135aba:
          if (pbVar8 == pbVar6) break;
          uVar12 = 1 << 0x20 - (0x20 - ((uint)pbVar8 / uStack_1e0 & 0x1f));
          pbVar3 = pbVar5 + (uVar12 & 0xff) * 0x24;
          if ((uint)pbVar8 % uStack_1e0 == 0) goto LAB_40135bfb;
        }
        puVar9 = local_1b4;
        iVar2 = 0;
        pbVar6 = (byte *)0x1;
        puVar7 = puVar9;
        do {
          *puVar7 = pbVar5 + (int)pbVar6 * 0x24;
          pbVar6 = (byte *)(((uint)pbVar6 & 0x7f) << 1);
          iVar2 = iVar2 + 1;
          puVar7 = puVar7 + 1;
        } while (pbVar6 < pbStack_1d4);
        pbVar6 = abStack_20;
        memw();
        iVar2 = FUN_40135144(param_1,local_1b4,iVar2);
      } while (iVar2 != 0);
      pbVar6 = (byte *)0x1;
      do {
        pbVar3 = pbVar5 + (int)pbVar6 * 0x48;
        pbVar8 = pbVar6;
        while (pbVar8 != (byte *)0x0) {
          pbVar3 = pbVar3 + -0x24;
          memw();
          iVar2 = FUN_40135788(param_1,pbVar3,pbVar5 + (int)(pbVar8 + -1) * 0x24,
                               pbVar5 + (int)pbVar6 * 0x24);
          pbVar8 = pbVar8 + -1;
          if (iVar2 != 0) goto LAB_40135ba9;
        }
        pbVar6 = (byte *)(((uint)pbVar6 & 0x7f) << 1);
        uVar12 = 0;
      } while (pbVar6 < pbStack_1d4);
      while (uVar12 = uVar12 + 1, uStack_1dc != uVar12) {
        *puVar9 = pbVar5 + uVar12 * 0x24;
        puVar9 = puVar9 + 1;
        memw();
      }
      iVar2 = FUN_40135144(param_1,local_1b4,uStack_1dc - 1);
    } while (iVar2 != 0);
    pbVar6 = pbStack_1d8;
    if (pbStack_1d8 != (byte *)0x0) {
      *(byte **)(param_1 + 0x74) = pbVar5;
      *(uint *)(param_1 + 0x78) = uStack_1dc;
    }
  } while( true );
}

