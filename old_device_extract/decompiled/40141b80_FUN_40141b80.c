// Function : FUN_40141b80
// Address  : 0x40141b80
// Size     : 1466 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40141b80(undefined4 *param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  undefined4 *puVar6;
  byte *pbVar7;
  byte *pbVar8;
  int iVar9;
  char *pcVar10;
  undefined *puVar11;
  uint *puVar12;
  uint uVar13;
  undefined8 uVar14;
  int iStack_134;
  undefined4 local_124;
  undefined4 uStack_120;
  undefined1 auStack_11c [8];
  undefined1 auStack_114 [8];
  undefined1 auStack_10c [8];
  undefined1 auStack_104 [8];
  undefined1 auStack_fc [8];
  uint local_f4;
  uint uStack_f0;
  uint uStack_ec;
  uint uStack_e8;
  uint uStack_e4;
  uint uStack_e0;
  uint uStack_dc;
  uint uStack_d8;
  uint local_d4;
  uint uStack_d0;
  uint uStack_cc;
  uint uStack_c8;
  uint uStack_c4;
  uint uStack_c0;
  uint uStack_bc;
  uint uStack_b8;
  uint local_b4;
  uint uStack_b0;
  uint uStack_ac;
  uint uStack_a8;
  uint auStack_a4 [16];
  byte local_64 [16];
  byte bStack_54;
  byte bStack_4c;
  uint uStack_24;
  
  memw();
  memw();
  uStack_24 = _DAT_3ffc5708;
  memw();
  (*(code *)&SUB_4008b530)(local_64,0,0x40);
  puVar6 = param_1 + 1;
  uVar14 = (*(code *)&SUB_4008b530)(puVar6,0,0x110);
  if ((param_3 != 0xc0) && (param_3 != 0x100)) {
    uVar3 = 0xffffffdc;
    if (param_3 != 0x80) goto LAB_40141f4e;
    *param_1 = 3;
    iVar5 = 0;
    goto LAB_40141bd9;
  }
  while( true ) {
    iVar5 = 1;
    *param_1 = 4;
    memw();
LAB_40141bd9:
    uVar2 = 0;
    while (param_3 >> 3 != uVar2) {
      pbVar7 = local_64 + uVar2;
      pbVar8 = (byte *)(param_2 + uVar2);
      uVar2 = uVar2 + 1;
      *pbVar7 = *pbVar8;
      memw();
      memw();
    }
    if (param_3 == 0xc0) {
      bStack_4c = bStack_54 ^ 0xff;
      memw();
      memw();
    }
    local_124 = 0x15e3adf4;
    uStack_120 = 0x77c7809e;
    memw();
    (*(code *)&SUB_4008b530)(&local_f4,0,0x40);
    local_f4 = (uint)local_64[0] << 0x18 | (uint)local_64[1] << 0x10 | (uint)local_64[3] |
               (uint)local_64[2] << 8;
    local_d4 = uStack_e4 ^ local_f4;
    uStack_d0 = uStack_e0 ^ uStack_f0;
    uStack_cc = uStack_dc ^ uStack_ec;
    uStack_c8 = uStack_e8 ^ uStack_d8;
    memw();
    FUN_40141aa4(&local_d4,&local_124,&uStack_cc);
    FUN_40141aa4(&uStack_cc,auStack_11c,&local_d4);
    local_d4 = local_d4 ^ local_f4;
    memw();
    FUN_40141aa4(&local_d4,auStack_114,&uStack_cc);
    FUN_40141aa4(&uStack_cc,auStack_10c,&local_d4);
    if (0x80 < param_3) {
      uStack_c4 = uStack_e4 ^ local_d4;
      uStack_c0 = uStack_e0 ^ uStack_d0;
      uStack_bc = uStack_dc ^ uStack_cc;
      uStack_b8 = uStack_d8 ^ uStack_c8;
      memw();
      FUN_40141aa4(&uStack_c4,auStack_104,&uStack_bc);
      FUN_40141aa4(&uStack_bc,auStack_fc,&uStack_c4);
    }
    iVar9 = iVar5 * 0x10;
    pcVar10 = &DAT_3f422c70 + iVar9;
    puVar12 = &local_b4;
    if (*pcVar10 != '\0') {
      auStack_a4[0] = local_f4 << 0xf ^ uStack_f0 >> 0x11;
      auStack_a4[1] = uStack_f0 << 0xf ^ uStack_ec >> 0x11;
      auStack_a4[2] = uStack_ec << 0xf ^ uStack_e8 >> 0x11;
      auStack_a4[3] = uStack_e8 << 0xf ^ local_f4 >> 0x11;
    }
    iVar1 = iVar5 * 0x50;
    if ((char)(&DAT_3f422bd0)[iVar1] != -1) {
      puVar6[(char)(&DAT_3f422bd0)[iVar1]] = local_f4;
    }
    if (0x80 < param_3) {
      if ((&UNK_3f422c74)[iVar9] != '\0') {
        auStack_a4[0] = uStack_e4 << 0xf ^ uStack_e0 >> 0x11;
        auStack_a4[1] = uStack_e0 << 0xf ^ uStack_dc >> 0x11;
        auStack_a4[2] = uStack_dc << 0xf ^ uStack_d8 >> 0x11;
        auStack_a4[3] = uStack_d8 << 0xf ^ uStack_e4 >> 0x11;
      }
      if ((char)(&UNK_3f422be4)[iVar1] != -1) {
        puVar6[(char)(&UNK_3f422be4)[iVar1]] = uStack_e4;
      }
      memw();
    }
    local_b4 = local_d4;
    uStack_b0 = uStack_d0;
    uStack_ac = uStack_cc;
    iStack_134 = 4;
    uStack_a8 = uStack_c8;
    uVar2 = 0xf;
    pcVar4 = pcVar10;
    do {
      if (pcVar4[8] != '\0') {
        uVar13 = 0x20 - (uVar2 & 0x1f);
        puVar12[4] = local_d4 << 0x20 - (0x20 - (uVar2 & 0x1f)) ^ uStack_d0 >> (uVar13 & 0x1f);
        puVar12[5] = uStack_d0 << 0x20 - (0x20 - (uVar2 & 0x1f)) ^ uStack_cc >> (uVar13 & 0x1f);
        puVar12[6] = uStack_cc << 0x20 - (0x20 - (uVar2 & 0x1f)) ^ uStack_c8 >> (uVar13 & 0x1f);
        puVar12[7] = uStack_c8 << 0x20 - (0x20 - (uVar2 & 0x1f)) ^ local_d4 >> (uVar13 & 0x1f);
      }
      pcVar4 = pcVar4 + 1;
      uVar2 = uVar2 + 0xf;
      puVar12 = puVar12 + 4;
      iStack_134 = iStack_134 + -1;
    } while (iStack_134 != 0);
    if ((char)(&UNK_3f422bf8)[iVar1] != -1) {
      puVar6[(char)(&UNK_3f422bf8)[iVar1]] = local_d4;
    }
    puVar11 = &UNK_3f422bd1 + iVar1;
    if (0x80 < param_3) {
      local_b4 = uStack_c4;
      uStack_b0 = uStack_c0;
      uStack_ac = uStack_bc;
      uStack_a8 = uStack_b8;
      if ((&UNK_3f422c7c)[iVar9] != '\0') {
        auStack_a4[0] = uStack_c4 << 0xf ^ uStack_c0 >> 0x11;
        auStack_a4[1] = uStack_c0 << 0xf ^ uStack_bc >> 0x11;
        auStack_a4[2] = uStack_bc << 0xf ^ uStack_b8 >> 0x11;
        auStack_a4[3] = uStack_b8 << 0xf ^ uStack_c4 >> 0x11;
      }
      pcVar10 = &UNK_3f422c71 + iVar9;
      puVar11 = (undefined *)0x1e;
      if ((char)(&UNK_3f422c0c)[iVar1] != -1) {
        puVar6[(char)(&UNK_3f422c0c)[iVar1]] = uStack_c4;
      }
      memw();
    }
    uVar14 = CONCAT44(puVar11,pcVar10);
    if ((char)(&DAT_3f422ba8)[iVar5 * 0x14] != -1) {
      param_1[iVar5 * 0xc + 0x21] = puVar6[(char)(&DAT_3f422ba8)[iVar5 * 0x14]];
    }
    uVar3 = 0;
LAB_40141f4e:
    param_3 = uStack_24;
    param_2 = _DAT_3ffc5708;
    memw();
    memw();
    if (uStack_24 == _DAT_3ffc5708) break;
    memw();
    (*(code *)&SUB_40082ec4)((int)uVar14,(int)((ulonglong)uVar14 >> 0x20));
  }
  return uVar3;
}

