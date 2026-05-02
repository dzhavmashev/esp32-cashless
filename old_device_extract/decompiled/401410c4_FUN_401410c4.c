// Function : FUN_401410c4
// Address  : 0x401410c4
// Size     : 702 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401410c4(byte *param_1,int param_2,int param_3,uint param_4,uint param_5,uint param_6)

{
  undefined4 uVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  char *pcVar10;
  uint uVar11;
  uint *puVar12;
  uint *puVar13;
  uint in_t0;
  undefined8 uVar14;
  undefined1 auStack_34 [8];
  undefined8 uStack_2c;
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  pbVar2 = (byte *)0xffffffec;
  uVar5 = in_t0;
  uStack_2c = CONCAT44(uStack_2c._4_4_,(undefined4)uStack_2c);
  if (param_4 == 0) goto LAB_40141101;
  uStack_2c = CONCAT44(uStack_2c._4_4_,(undefined4)uStack_2c);
  if ((param_6 | param_4) >> 0x1d != 0) goto LAB_40141101;
  uVar5 = 0;
  if (param_1 != (byte *)0x0) goto LAB_4014111c;
  memw();
  uVar1 = (*(code *)&SUB_40094b80)();
  pcVar10 = "aes-gcm";
LAB_401410f8:
  FUN_4012113c(1,&DAT_3f422a60,pcVar10,uVar1,&DAT_3f422a60);
  pbVar2 = (byte *)0xffffffff;
  uVar5 = in_t0;
LAB_40141101:
  do {
    param_1 = pbVar2;
    param_3 = iStack_24;
    param_2 = _DAT_3ffc5708;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) {
      return;
    }
    (*(code *)&SUB_40082ec4)();
    param_6 = uVar5;
    in_t0 = uVar5;
LAB_4014111c:
    if (param_3 == 0) {
      uVar1 = (*(code *)&SUB_40094b80)();
      pcVar10 = "pplied\n";
      goto LAB_401410f8;
    }
    uVar7 = uVar5;
    if (param_6 != 0) {
      uVar7 = 1;
    }
    if (uVar7 != 0) {
      if (param_5 == 0) {
        uVar5 = 1;
      }
      if (uVar5 != 0) break;
    }
    memw();
    (*(code *)&SUB_4008b530)(param_1 + 0x10,0,0x10);
    param_1[0x150] = 0;
    param_1[0x151] = 0;
    param_1[0x152] = 0;
    param_1[0x153] = 0;
    *(int *)(param_1 + 0x140) = param_3;
    *(uint *)(param_1 + 0x144) = param_4;
    *(uint *)(param_1 + 0x158) = param_5;
    *(uint *)(param_1 + 0x148) = param_6;
    param_1[0x14c] = 0;
    param_1[0x14d] = 0;
    param_1[0x14e] = 0;
    param_1[0x14f] = 0;
    *(int *)(param_1 + 0x154) = param_2;
    uVar5 = in_t0;
    if (*(int *)(param_1 + 0x180) == 0) {
      (*(code *)&SUB_4008b530)(param_1,0,0x10);
      FUN_4013cf6c(param_1 + 0x15c,1,param_1,param_1);
      uVar5 = (uint)*param_1 << 0x18 | (uint)param_1[1] << 0x10 | (uint)param_1[3] |
              (uint)param_1[2] << 8;
      uVar4 = (uint)param_1[4] << 0x18 | (uint)param_1[5] << 0x10 | (uint)param_1[7] |
              (uint)param_1[6] << 8;
      uVar7 = (uint)param_1[8] << 0x18 | (uint)param_1[9] << 0x10 | (uint)param_1[0xb] |
              (uint)param_1[10] << 8;
      uVar3 = (uint)param_1[0xc] << 0x18 | (uint)param_1[0xd] << 0x10 | (uint)param_1[0xf] |
              (uint)param_1[0xe] << 8;
      *(uint *)(param_1 + 0x70) = uVar3;
      param_1[0xb4] = 0;
      param_1[0xb5] = 0;
      param_1[0xb6] = 0;
      param_1[0xb7] = 0;
      param_1[0x34] = 0;
      param_1[0x35] = 0;
      param_1[0x36] = 0;
      param_1[0x37] = 0;
      iVar6 = 3;
      *(uint *)(param_1 + 0x74) = uVar7;
      *(uint *)(param_1 + 0xf0) = uVar4;
      *(uint *)(param_1 + 0xf4) = uVar5;
      param_1[0xb0] = 0;
      param_1[0xb1] = 0;
      param_1[0xb2] = 0;
      param_1[0xb3] = 0;
      param_1[0x30] = 0;
      param_1[0x31] = 0;
      param_1[0x32] = 0;
      param_1[0x33] = 0;
      iVar9 = 4;
      do {
        uVar11 = uVar7 << 0x1f;
        uVar7 = uVar4 << 0x1f | uVar7 >> 1;
        uVar8 = uVar5 << 0x1f;
        uVar5 = (uVar3 & 1) * -0x1f000000 ^ uVar5 >> 1;
        uVar3 = uVar11 | uVar3 >> 1;
        uVar4 = uVar8 | uVar4 >> 1;
        *(uint *)(param_1 + iVar9 * 8 + 0x30) = uVar3;
        iVar6 = iVar6 + -1;
        *(uint *)(param_1 + iVar9 * 8 + 0x34) = uVar7;
        *(uint *)(param_1 + iVar9 * 8 + 0xb0) = uVar4;
        *(uint *)(param_1 + iVar9 * 8 + 0xb4) = uVar5;
        iVar9 = iVar9 >> 1;
      } while (iVar6 != 0);
      iVar9 = 3;
      iVar6 = 2;
      do {
        puVar12 = (uint *)(param_1 + iVar6 * 8 + 0x30);
        puVar13 = (uint *)(param_1 + iVar6 * 8 + 0xb0);
        param_5 = puVar12[1];
        param_4 = puVar13[1];
        uVar5 = *puVar12;
        puVar13[2] = *(uint *)(param_1 + 0xb8) ^ *puVar13;
        puVar13[3] = *(uint *)(param_1 + 0xbc) ^ param_4;
        puVar12[2] = *(uint *)(param_1 + 0x38) ^ uVar5;
        puVar12[3] = *(uint *)(param_1 + 0x3c) ^ param_5;
        iVar9 = iVar9 + -1;
        iVar6 = iVar6 << 1;
      } while (iVar9 != 0);
      memw();
      uVar5 = in_t0;
    }
    pbVar2 = param_1 + 0x20;
    param_1[0x180] = 1;
    param_1[0x181] = 0;
    param_1[0x182] = 0;
    param_1[0x183] = 0;
    memw();
    (*(code *)&SUB_4008b530)(pbVar2,0,0x10);
    (*(code *)&SUB_4008b530)(auStack_34,0,0x10);
    if (*(int *)(param_1 + 0x144) == 0xc) {
      (*(code *)&SUB_4008b3d0)(pbVar2,*(undefined4 *)(param_1 + 0x140));
      param_4 = (uint)param_1[0x2f];
      param_1[0x2f] = param_1[0x2f] | 1;
      memw();
    }
    else {
      FUN_40140fa8(param_1,*(undefined4 *)(param_1 + 0x140),*(int *)(param_1 + 0x144),pbVar2);
      uVar14 = (*(code *)&SUB_40064b08)(*(int *)(param_1 + 0x144) << 3,0);
      memw();
      uStack_2c = uVar14;
      FUN_40140fa8(param_1,auStack_34,0x10,pbVar2);
    }
    memw();
    (*(code *)&SUB_4008b3d0)(param_1 + 0x130,pbVar2,0x10);
    FUN_40140fa8(param_1,*(undefined4 *)(param_1 + 0x158),*(undefined4 *)(param_1 + 0x148),
                 param_1 + 0x10);
    pbVar2 = (byte *)0x0;
  } while( true );
  uVar1 = (*(code *)&SUB_40094b80)();
  pcVar10 = "pplied\n";
  goto LAB_401410f8;
}

