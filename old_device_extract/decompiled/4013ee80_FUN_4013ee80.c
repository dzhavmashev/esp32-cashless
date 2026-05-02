// Function : FUN_4013ee80
// Address  : 0x4013ee80
// Size     : 2080 bytes


void FUN_4013ee80(int param_1,byte *param_2)

{
  uint *puVar1;
  int *piVar2;
  int *piVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint *puStack_150;
  uint *puStack_14c;
  int iStack_148;
  uint local_140 [4];
  uint uStack_130;
  uint uStack_12c;
  uint uStack_128;
  uint uStack_124;
  uint local_120 [72];
  
  puStack_150 = (uint *)(param_1 + 8);
  puStack_14c = local_140;
  local_140[0] = *puStack_150;
  local_120[0] = (uint)*param_2 << 0x18 | (uint)param_2[1] << 0x10 | (uint)param_2[3] |
                 (uint)param_2[2] << 8;
  piVar3 = &DAT_3f42265c;
  puVar4 = local_120;
  do {
    iVar5 = ((uint)(CONCAT44(uStack_130,uStack_130) >> 6) ^
             (uint)(CONCAT44(uStack_130,uStack_130) >> 0xb) ^
            (uint)(CONCAT44(uStack_130,uStack_130) >> 0x19)) + *piVar3 + *puVar4 +
            ((uStack_128 ^ uStack_12c) & uStack_130 ^ uStack_128) + uStack_124;
    uVar7 = local_140[3] + iVar5;
    uVar6 = ((uint)(CONCAT44(local_140[0],local_140[0]) >> 2) ^
             (uint)(CONCAT44(local_140[0],local_140[0]) >> 0xd) ^
            (uint)(CONCAT44(local_140[0],local_140[0]) >> 0x16)) +
            ((local_140[0] | local_140[1]) & local_140[2] | local_140[0] & local_140[1]) + iVar5;
    iVar5 = piVar3[1] + puVar4[1] + uStack_128 + ((uStack_130 ^ uStack_12c) & uVar7 ^ uStack_12c) +
            ((uint)(CONCAT44(uVar7,uVar7) >> 6) ^ (uint)(CONCAT44(uVar7,uVar7) >> 0xb) ^
            (uint)(CONCAT44(uVar7,uVar7) >> 0x19));
    uVar10 = ((uint)(CONCAT44(uVar6,uVar6) >> 2) ^ (uint)(CONCAT44(uVar6,uVar6) >> 0xd) ^
             (uint)(CONCAT44(uVar6,uVar6) >> 0x16)) +
             ((uVar6 | local_140[0]) & local_140[1] | uVar6 & local_140[0]) + iVar5;
    uVar8 = local_140[2] + iVar5;
    iVar5 = piVar3[2] + puVar4[2] + uStack_12c + ((uVar7 ^ uStack_130) & uVar8 ^ uStack_130) +
            ((uint)(CONCAT44(uVar8,uVar8) >> 6) ^ (uint)(CONCAT44(uVar8,uVar8) >> 0xb) ^
            (uint)(CONCAT44(uVar8,uVar8) >> 0x19));
    uVar12 = ((uint)(CONCAT44(uVar10,uVar10) >> 2) ^ (uint)(CONCAT44(uVar10,uVar10) >> 0xd) ^
             (uint)(CONCAT44(uVar10,uVar10) >> 0x16)) +
             ((uVar6 | uVar10) & local_140[0] | uVar6 & uVar10) + iVar5;
    uVar9 = local_140[1] + iVar5;
    iVar5 = piVar3[3] + puVar4[3] + uStack_130 + ((uVar7 ^ uVar8) & uVar9 ^ uVar7) +
            ((uint)(CONCAT44(uVar9,uVar9) >> 6) ^ (uint)(CONCAT44(uVar9,uVar9) >> 0xb) ^
            (uint)(CONCAT44(uVar9,uVar9) >> 0x19));
    uVar11 = ((uint)(CONCAT44(uVar12,uVar12) >> 2) ^ (uint)(CONCAT44(uVar12,uVar12) >> 0xd) ^
             (uint)(CONCAT44(uVar12,uVar12) >> 0x16)) +
             ((uVar10 | uVar12) & uVar6 | uVar10 & uVar12) + iVar5;
    local_140[0] = local_140[0] + iVar5;
    iVar5 = piVar3[4] + puVar4[4] + uVar7 + ((uVar8 ^ uVar9) & local_140[0] ^ uVar8) +
            ((uint)(CONCAT44(local_140[0],local_140[0]) >> 6) ^
             (uint)(CONCAT44(local_140[0],local_140[0]) >> 0xb) ^
            (uint)(CONCAT44(local_140[0],local_140[0]) >> 0x19));
    local_140[3] = ((uint)(CONCAT44(uVar11,uVar11) >> 2) ^ (uint)(CONCAT44(uVar11,uVar11) >> 0xd) ^
                   (uint)(CONCAT44(uVar11,uVar11) >> 0x16)) +
                   ((uVar12 | uVar11) & uVar10 | uVar12 & uVar11) + iVar5;
    uStack_124 = uVar6 + iVar5;
    iVar5 = piVar3[5] + puVar4[5] + uVar8 + ((uVar9 ^ local_140[0]) & uStack_124 ^ uVar9) +
            ((uint)(CONCAT44(uStack_124,uStack_124) >> 6) ^
             (uint)(CONCAT44(uStack_124,uStack_124) >> 0xb) ^
            (uint)(CONCAT44(uStack_124,uStack_124) >> 0x19));
    local_140[2] = ((uint)(CONCAT44(local_140[3],local_140[3]) >> 2) ^
                    (uint)(CONCAT44(local_140[3],local_140[3]) >> 0xd) ^
                   (uint)(CONCAT44(local_140[3],local_140[3]) >> 0x16)) +
                   ((uVar11 | local_140[3]) & uVar12 | uVar11 & local_140[3]) + iVar5;
    uStack_128 = uVar10 + iVar5;
    iVar5 = piVar3[6] + puVar4[6] + uVar9 +
            ((local_140[0] ^ uStack_124) & uStack_128 ^ local_140[0]) +
            ((uint)(CONCAT44(uStack_128,uStack_128) >> 6) ^
             (uint)(CONCAT44(uStack_128,uStack_128) >> 0xb) ^
            (uint)(CONCAT44(uStack_128,uStack_128) >> 0x19));
    local_140[1] = ((uint)(CONCAT44(local_140[2],local_140[2]) >> 2) ^
                    (uint)(CONCAT44(local_140[2],local_140[2]) >> 0xd) ^
                   (uint)(CONCAT44(local_140[2],local_140[2]) >> 0x16)) +
                   ((local_140[3] | local_140[2]) & uVar11 | local_140[3] & local_140[2]) + iVar5;
    uStack_12c = uVar12 + iVar5;
    puVar1 = puVar4 + 7;
    puVar4 = puVar4 + 8;
    piVar2 = piVar3 + 7;
    piVar3 = piVar3 + 8;
    iVar5 = *piVar2 + *puVar1 + local_140[0] + ((uStack_124 ^ uStack_128) & uStack_12c ^ uStack_124)
            + ((uint)(CONCAT44(uStack_12c,uStack_12c) >> 6) ^
               (uint)(CONCAT44(uStack_12c,uStack_12c) >> 0xb) ^
              (uint)(CONCAT44(uStack_12c,uStack_12c) >> 0x19));
    uStack_130 = uVar11 + iVar5;
    local_140[0] = ((uint)(CONCAT44(local_140[1],local_140[1]) >> 2) ^
                    (uint)(CONCAT44(local_140[1],local_140[1]) >> 0xd) ^
                   (uint)(CONCAT44(local_140[1],local_140[1]) >> 0x16)) +
                   ((local_140[2] | local_140[1]) & local_140[3] | local_140[2] & local_140[1]) +
                   iVar5;
  } while (piVar3 != &DAT_3f42269c);
  iStack_148 = 6;
  puVar4 = local_120;
  do {
    uVar6 = puVar4[0xe];
    uVar7 = puVar4[1];
    uVar6 = ((uint)(CONCAT44(uVar6,uVar6) >> 0x11) ^ (uint)(CONCAT44(uVar6,uVar6) >> 0x13) ^
            uVar6 >> 10) + puVar4[9] + *puVar4 +
            ((uint)(CONCAT44(uVar7,uVar7) >> 7) ^ (uint)(CONCAT44(uVar7,uVar7) >> 0x12) ^ uVar7 >> 3
            );
    puVar4[0x10] = uVar6;
    uVar9 = puVar4[0xf];
    uVar8 = puVar4[2];
    uVar7 = ((uint)(CONCAT44(uVar9,uVar9) >> 0x11) ^ (uint)(CONCAT44(uVar9,uVar9) >> 0x13) ^
            uVar9 >> 10) + uVar7 + puVar4[10] +
            ((uint)(CONCAT44(uVar8,uVar8) >> 7) ^ (uint)(CONCAT44(uVar8,uVar8) >> 0x12) ^ uVar8 >> 3
            );
    uVar9 = puVar4[3];
    uVar8 = ((uint)(CONCAT44(uVar6,uVar6) >> 0x11) ^ (uint)(CONCAT44(uVar6,uVar6) >> 0x13) ^
            uVar6 >> 10) + uVar8 + puVar4[0xb] +
            ((uint)(CONCAT44(uVar9,uVar9) >> 7) ^ (uint)(CONCAT44(uVar9,uVar9) >> 0x12) ^ uVar9 >> 3
            );
    uVar11 = puVar4[4];
    puVar4[0x11] = uVar7;
    uVar7 = ((uint)(CONCAT44(uVar7,uVar7) >> 0x11) ^ (uint)(CONCAT44(uVar7,uVar7) >> 0x13) ^
            uVar7 >> 10) + uVar9 + puVar4[0xc] +
            ((uint)(CONCAT44(uVar11,uVar11) >> 7) ^ (uint)(CONCAT44(uVar11,uVar11) >> 0x12) ^
            uVar11 >> 3);
    puVar4[0x12] = uVar8;
    uVar10 = puVar4[5];
    uVar8 = ((uint)(CONCAT44(uVar8,uVar8) >> 0x11) ^ (uint)(CONCAT44(uVar8,uVar8) >> 0x13) ^
            uVar8 >> 10) + uVar11 + puVar4[0xd] +
            ((uint)(CONCAT44(uVar10,uVar10) >> 7) ^ (uint)(CONCAT44(uVar10,uVar10) >> 0x12) ^
            uVar10 >> 3);
    puVar4[0x13] = uVar7;
    uVar9 = puVar4[6];
    uVar7 = ((uint)(CONCAT44(uVar7,uVar7) >> 0x11) ^ (uint)(CONCAT44(uVar7,uVar7) >> 0x13) ^
            uVar7 >> 10) + puVar4[0xe] + uVar10 +
            ((uint)(CONCAT44(uVar9,uVar9) >> 7) ^ (uint)(CONCAT44(uVar9,uVar9) >> 0x12) ^ uVar9 >> 3
            );
    puVar4[0x14] = uVar8;
    uVar10 = puVar4[7];
    puVar4[0x16] = ((uint)(CONCAT44(uVar8,uVar8) >> 0x11) ^ (uint)(CONCAT44(uVar8,uVar8) >> 0x13) ^
                   uVar8 >> 10) + puVar4[0xf] + uVar9 +
                   ((uint)(CONCAT44(uVar10,uVar10) >> 7) ^ (uint)(CONCAT44(uVar10,uVar10) >> 0x12) ^
                   uVar10 >> 3);
    puVar4[0x15] = uVar7;
    uVar8 = puVar4[8];
    puVar4[0x17] = ((uint)(CONCAT44(uVar7,uVar7) >> 0x11) ^ (uint)(CONCAT44(uVar7,uVar7) >> 0x13) ^
                   uVar7 >> 10) + uVar6 + uVar10 +
                   ((uint)(CONCAT44(uVar8,uVar8) >> 7) ^ (uint)(CONCAT44(uVar8,uVar8) >> 0x12) ^
                   uVar8 >> 3);
    iStack_148 = iStack_148 + -1;
    puVar4 = puVar4 + 8;
  } while (iStack_148 != 0);
  do {
    uVar6 = *puStack_14c;
    puStack_14c = puStack_14c + 1;
    *puStack_150 = *puStack_150 + uVar6;
    puStack_150 = puStack_150 + 1;
  } while ((uint *)(param_1 + 0x28) != puStack_150);
  memw();
  return;
}

