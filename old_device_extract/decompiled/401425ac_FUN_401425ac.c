// Function : FUN_401425ac
// Address  : 0x401425ac
// Size     : 980 bytes


/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_401425ac(undefined4 param_1,int param_2,uint param_3,undefined4 param_4,uint param_5,
                 int param_6,byte *param_7,byte *param_8,byte *param_9,byte *param_10,uint param_11)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  undefined4 uVar5;
  byte *pbVar6;
  byte bVar7;
  byte *pbVar8;
  int iVar9;
  byte *pbVar10;
  int iVar11;
  byte *pbVar12;
  byte *pbStack_7c;
  byte *pbStack_78;
  undefined1 auStack_58 [4];
  byte local_54 [15];
  byte abStack_45 [17];
  byte abStack_34 [15];
  byte bStack_25;
  uint uStack_24;
  
  pbStack_7c = param_8;
  memw();
  memw();
  uStack_24 = _DAT_3ffc5708;
  uVar2 = param_11 - 2;
  pbStack_78 = param_9;
  pbVar8 = param_10;
  if (((uVar2 != 0) && (param_11 < 0x11)) &&
     (pbVar8 = (byte *)(param_11 & 1), pbVar8 == (byte *)0x0)) goto LAB_40142610;
LAB_401425ee:
  uVar2 = 0xfffffff3;
LAB_401425f0:
  do {
    param_3 = uStack_24;
    memw();
    memw();
    if (uStack_24 == _DAT_3ffc5708) {
      return;
    }
    memw();
    (*(code *)&SUB_40082ec4)();
LAB_40142610:
    if ((6 < param_5 - 7) || ((byte *)0xfeff < param_7)) goto LAB_401425ee;
    bVar7 = 0x40;
    if (param_7 == (byte *)0x0) {
      bVar7 = (byte)pbVar8;
    }
    bVar1 = 0xe - (char)param_5;
    pbVar10 = (byte *)(0xf - (param_5 & 0xff) & 0xff);
    local_54[0] = (byte)((uVar2 >> 1) << 3) | bVar7 | bVar1;
    pbVar8 = local_54;
    memw();
    memw();
    (*(code *)&SUB_4008b3d0)(local_54 + 1,param_4,param_5);
    pbVar6 = pbVar8;
    uVar2 = param_3;
    do {
      pbVar3 = pbVar6 + -1;
      pbVar6[0xf] = (byte)uVar2;
      memw();
      uVar2 = uVar2 >> 8;
      pbVar6 = pbVar3;
    } while ((byte *)((int)pbVar8 - (int)pbVar3 & 0xffU) < pbVar10);
    if (uVar2 != 0) goto LAB_401425ee;
    memw();
    (*(code *)&SUB_4008b530)(abStack_45 + 1,0,0x10);
    pbVar8 = abStack_45;
    iVar9 = 0x10;
    iVar11 = 0;
    do {
      pbVar8 = pbVar8 + 1;
      pbVar6 = local_54 + iVar11;
      iVar11 = iVar11 + 1;
      *pbVar8 = *pbVar6 ^ *pbVar8;
      memw();
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    memw();
    uVar2 = FUN_40132d58(param_1,abStack_45 + 1,0x10,abStack_45 + 1,auStack_58);
    pbVar8 = (byte *)0x0;
  } while (uVar2 != 0);
  if (param_7 != (byte *)0x0) {
    (*(code *)&SUB_4008b530)(local_54 + 2,0,0xe);
    pbVar8 = (byte *)((uint)(param_7 < &DAT_0000000e) * (int)param_7 +
                     (uint)(param_7 >= &DAT_0000000e) * 0xe);
    local_54[0] = (byte)((uint)param_7 >> 8);
    local_54[1] = (byte)param_7;
    memw();
    memw();
    (*(code *)&SUB_4008b3d0)(local_54 + 2,param_6,pbVar8);
    abStack_45[1] = local_54[0] ^ abStack_45[1];
    memw();
    memw();
    uVar2 = FUN_40132d58(param_1,abStack_45 + 1,0x10,abStack_45 + 1,auStack_58);
    if (uVar2 != 0) goto LAB_401425f0;
    uVar4 = (int)param_7 - (int)pbVar8;
    pbVar8 = pbVar8 + param_6;
    for (; uVar4 != 0; uVar4 = uVar4 - (int)param_7) {
      param_7 = (byte *)((uVar4 < 0x10) * uVar4 + (uint)(uVar4 >= 0x10) * 0x10);
      uVar5 = (*(code *)&SUB_4008b530)(local_54,0,0x10);
      pbVar6 = (byte *)(*(code *)&SUB_4008b3d0)(uVar5,pbVar8,param_7);
      abStack_45[1] = *pbVar6 ^ abStack_45[1];
      memw();
      memw();
      uVar2 = FUN_40132d58(param_1,abStack_45 + 1,0x10,abStack_45 + 1,auStack_58);
      if (uVar2 != 0) goto LAB_401425f0;
      pbVar8 = pbVar8 + (int)param_7;
    }
  }
  memw();
  memw();
  abStack_34[0] = bVar1;
  (*(code *)&SUB_4008b3d0)(abStack_34 + 1,param_4,param_5);
  (*(code *)&SUB_4008b530)(abStack_34 + param_5 + 1,0,pbVar10);
  bStack_25 = 1;
  memw();
LAB_40142706:
  if (param_3 != 0) {
    param_7 = (byte *)((param_3 < 0x10) * param_3 + (uint)(param_3 >= 0x10) * 0x10);
    if (param_2 == 0) {
      (*(code *)&SUB_4008b530)(local_54,0,0x10);
      (*(code *)&SUB_4008b3d0)(local_54,pbStack_7c,param_7);
      abStack_45[1] = local_54[0] ^ abStack_45[1];
      memw();
      memw();
      uVar2 = FUN_40132d58(param_1,abStack_45 + 1,0x10,abStack_45 + 1,auStack_58);
      pbVar8 = &DAT_00000010;
      if (uVar2 != 0) goto LAB_401425f0;
    }
    uVar2 = FUN_40132d58(param_1,abStack_34,0x10,local_54,auStack_58);
    pbVar8 = &DAT_00000010;
    if (uVar2 != 0) goto LAB_401425f0;
    pbVar8 = (byte *)0x0;
    while (pbVar8 < param_7) {
      pbVar3 = pbVar8 + (int)pbStack_78;
      pbVar6 = pbVar8 + (int)pbStack_7c;
      pbVar12 = local_54 + (int)pbVar8;
      pbVar8 = (byte *)((uint)(pbVar8 + 1) & 0xff);
      *pbVar3 = *pbVar6 ^ *pbVar12;
      memw();
      memw();
    }
    if (param_2 == 1) {
      (*(code *)&SUB_4008b530)(local_54,0,0x10);
      (*(code *)&SUB_4008b3d0)(local_54,pbStack_78,param_7);
      abStack_45[1] = local_54[0] ^ abStack_45[1];
      memw();
      memw();
      uVar2 = FUN_40132d58(param_1,abStack_45 + 1,0x10,abStack_45 + 1,auStack_58);
      pbVar8 = &DAT_00000010;
      if (uVar2 != 0) goto LAB_401425f0;
    }
    param_3 = param_3 - (int)param_7;
    pbStack_78 = pbStack_78 + (int)param_7;
    pbStack_7c = pbStack_7c + (int)param_7;
    pbVar8 = abStack_34;
    do {
      bVar7 = pbVar8[0xf];
      pbVar8[0xf] = bVar7 + 1;
      memw();
      if ((byte)(bVar7 + 1) != 0) goto LAB_40142706;
      pbVar8 = pbVar8 + -1;
    } while ((byte *)((int)abStack_34 - (int)pbVar8 & 0xffU) < pbVar10);
    memw();
    goto LAB_40142706;
  }
  pbVar8 = abStack_34;
  do {
    pbVar8[0xf] = 0;
    memw();
    pbVar8 = pbVar8 + -1;
  } while ((byte *)((int)abStack_34 - (int)pbVar8 & 0xffU) < pbVar10);
  memw();
  uVar2 = FUN_40132d58(param_1,abStack_34,0x10,local_54,auStack_58);
  pbVar8 = (byte *)0x0;
  param_7 = pbVar10;
  if (uVar2 == 0) {
    pbVar8 = (byte *)(uint)abStack_45[1];
    abStack_45[1] = local_54[0] ^ abStack_45[1];
    memw();
    param_7 = abStack_45 + 2;
    memw();
    (*(code *)&SUB_4008b3d0)(param_10,abStack_45 + 1,param_11);
  }
  goto LAB_401425f0;
}

