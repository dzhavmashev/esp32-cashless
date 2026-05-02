// Function : FUN_4013d9ec
// Address  : 0x4013d9ec
// Size     : 4547 bytes


undefined4 FUN_4013d9ec(int param_1,byte *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  
  iVar22 = 0;
  if (*(int *)(param_1 + 0x5c) == 0) {
    memw();
    iVar22 = FUN_40143650();
    if (iVar22 == 0) {
      *(undefined4 *)(param_1 + 0x5c) = 2;
      memw();
    }
    else {
      *(undefined4 *)(param_1 + 0x5c) = 1;
    }
  }
  if (*(int *)(param_1 + 0x5c) == 1) {
    memw();
    FUN_401436e4(0,param_2,iVar22);
    if (param_3 != 0) {
      FUN_401436b0(0,param_1 + 8);
    }
  }
  else {
    uVar1 = (uint)*param_2 << 0x18 | (uint)param_2[1] << 0x10 | (uint)param_2[3] |
            (uint)param_2[2] << 8;
    uVar2 = (uint)param_2[4] << 0x18 | (uint)param_2[5] << 0x10 | (uint)param_2[7] |
            (uint)param_2[6] << 8;
    uVar3 = (uint)param_2[8] << 0x18 | (uint)param_2[9] << 0x10 | (uint)param_2[0xb] |
            (uint)param_2[10] << 8;
    uVar28 = (uint)param_2[0xc] << 0x18 | (uint)param_2[0xd] << 0x10 | (uint)param_2[0xf] |
             (uint)param_2[0xe] << 8;
    uVar15 = (uint)param_2[0x10] << 0x18 | (uint)param_2[0x11] << 0x10 | (uint)param_2[0x13] |
             (uint)param_2[0x12] << 8;
    uVar5 = (uint)param_2[0x14] << 0x18 | (uint)param_2[0x15] << 0x10 | (uint)param_2[0x17] |
            (uint)param_2[0x16] << 8;
    uVar6 = (uint)param_2[0x18] << 0x18 | (uint)param_2[0x19] << 0x10 | (uint)param_2[0x1b] |
            (uint)param_2[0x1a] << 8;
    uVar7 = (uint)param_2[0x1c] << 0x18 | (uint)param_2[0x1d] << 0x10 | (uint)param_2[0x1f] |
            (uint)param_2[0x1e] << 8;
    uVar16 = (uint)param_2[0x20] << 0x18 | (uint)param_2[0x21] << 0x10 | (uint)param_2[0x23] |
             (uint)param_2[0x22] << 8;
    uVar8 = (uint)param_2[0x24] << 0x18 | (uint)param_2[0x25] << 0x10 | (uint)param_2[0x27] |
            (uint)param_2[0x26] << 8;
    uVar9 = (uint)param_2[0x28] << 0x18 | (uint)param_2[0x29] << 0x10 | (uint)param_2[0x2b] |
            (uint)param_2[0x2a] << 8;
    uVar10 = (uint)param_2[0x2c] << 0x18 | (uint)param_2[0x2d] << 0x10 | (uint)param_2[0x2f] |
             (uint)param_2[0x2e] << 8;
    uVar11 = (uint)param_2[0x30] << 0x18 | (uint)param_2[0x31] << 0x10 | (uint)param_2[0x33] |
             (uint)param_2[0x32] << 8;
    uVar12 = (uint)param_2[0x34] << 0x18 | (uint)param_2[0x35] << 0x10 | (uint)param_2[0x37] |
             (uint)param_2[0x36] << 8;
    uVar13 = (uint)param_2[0x38] << 0x18 | (uint)param_2[0x39] << 0x10 | (uint)param_2[0x3b] |
             (uint)param_2[0x3a] << 8;
    uVar4 = (uint)param_2[0x3c] << 0x18 | (uint)param_2[0x3d] << 0x10 | (uint)param_2[0x3f] |
            (uint)param_2[0x3e] << 8;
    uVar18 = *(uint *)(param_1 + 0x14);
    uVar17 = *(uint *)(param_1 + 0x10);
    uVar29 = *(uint *)(param_1 + 0xc);
    uVar26 = *(uint *)(param_1 + 8);
    uVar23 = (uint)(CONCAT44(uVar29,uVar29) >> 2);
    uVar14 = uVar1 + ((uVar17 ^ uVar18) & uVar29 ^ uVar18) +
                     (int)(CONCAT44(uVar26,uVar26) >> 0x1b) + *(int *)(param_1 + 0x18) + 0x5a827999;
    uVar20 = (int)(CONCAT44(uVar14,uVar14) >> 0x1b) +
             ((uVar17 ^ uVar23) & uVar26 ^ uVar17) + uVar18 + 0x5a827999 + uVar2;
    uVar21 = (uint)(CONCAT44(uVar26,uVar26) >> 2);
    uVar24 = (uint)(CONCAT44(uVar14,uVar14) >> 2);
    uVar27 = (int)(CONCAT44(uVar20,uVar20) >> 0x1b) +
             ((uVar23 ^ uVar21) & uVar14 ^ uVar23) + uVar17 + 0x5a827999 + uVar3;
    uVar14 = (uint)(CONCAT44(uVar20,uVar20) >> 2);
    uVar25 = (int)(CONCAT44(uVar27,uVar27) >> 0x1b) +
             ((uVar21 ^ uVar24) & uVar20 ^ uVar21) + uVar23 + 0x5a827999 + uVar28;
    uVar23 = (uint)(CONCAT44(uVar27,uVar27) >> 2);
    uVar27 = (int)(CONCAT44(uVar25,uVar25) >> 0x1b) +
             ((uVar24 ^ uVar14) & uVar27 ^ uVar24) + uVar21 + 0x5a827999 + uVar15;
    uVar21 = (uint)(CONCAT44(uVar25,uVar25) >> 2);
    uVar20 = (uint)(CONCAT44(uVar27,uVar27) >> 2);
    uVar25 = (int)(CONCAT44(uVar27,uVar27) >> 0x1b) +
             ((uVar14 ^ uVar23) & uVar25 ^ uVar14) + uVar5 + 0x5a827999 + uVar24;
    uVar27 = (int)(CONCAT44(uVar25,uVar25) >> 0x1b) +
             ((uVar23 ^ uVar21) & uVar27 ^ uVar23) + uVar6 + 0x5a827999 + uVar14;
    uVar24 = (uint)(CONCAT44(uVar25,uVar25) >> 2);
    uVar14 = (int)(CONCAT44(uVar27,uVar27) >> 0x1b) +
             ((uVar21 ^ uVar20) & uVar25 ^ uVar21) + uVar7 + 0x5a827999 + uVar23;
    uVar23 = (uint)(CONCAT44(uVar27,uVar27) >> 2);
    uVar27 = (int)(CONCAT44(uVar14,uVar14) >> 0x1b) +
             ((uVar20 ^ uVar24) & uVar27 ^ uVar20) + uVar16 + 0x5a827999 + uVar21;
    uVar21 = (uint)(CONCAT44(uVar14,uVar14) >> 2);
    uVar20 = (int)(CONCAT44(uVar27,uVar27) >> 0x1b) +
             ((uVar24 ^ uVar23) & uVar14 ^ uVar24) + uVar8 + 0x5a827999 + uVar20;
    uVar14 = (uint)(CONCAT44(uVar27,uVar27) >> 2);
    uVar25 = (int)(CONCAT44(uVar20,uVar20) >> 0x1b) +
             ((uVar23 ^ uVar21) & uVar27 ^ uVar23) + uVar9 + 0x5a827999 + uVar24;
    uVar24 = (uint)(CONCAT44(uVar20,uVar20) >> 2);
    uVar27 = (int)(CONCAT44(uVar25,uVar25) >> 0x1b) +
             ((uVar21 ^ uVar14) & uVar20 ^ uVar21) + uVar10 + 0x5a827999 + uVar23;
    uVar23 = (uint)(CONCAT44(uVar25,uVar25) >> 2);
    uVar20 = (uint)(CONCAT44(uVar27,uVar27) >> 2);
    uVar25 = (int)(CONCAT44(uVar27,uVar27) >> 0x1b) +
             ((uVar14 ^ uVar24) & uVar25 ^ uVar14) + uVar11 + 0x5a827999 + uVar21;
    uVar14 = (int)(CONCAT44(uVar25,uVar25) >> 0x1b) +
             ((uVar24 ^ uVar23) & uVar27 ^ uVar24) + uVar12 + 0x5a827999 + uVar14;
    uVar21 = (uint)(CONCAT44(uVar25,uVar25) >> 2);
    uVar27 = (int)(CONCAT44(uVar14,uVar14) >> 0x1b) +
             ((uVar23 ^ uVar20) & uVar25 ^ uVar23) + uVar13 + 0x5a827999 + uVar24;
    uVar25 = (int)(CONCAT44(uVar27,uVar27) >> 0x1b) +
             ((uVar20 ^ uVar21) & uVar14 ^ uVar20) + uVar4 + 0x5a827999 + uVar23;
    uVar23 = (uint)(CONCAT44(uVar14,uVar14) >> 2);
    uVar24 = uVar1 ^ uVar3 ^ uVar16 ^ uVar12;
    uVar24 = (uint)(CONCAT44(uVar24,uVar24) >> 0x1f);
    uVar19 = (int)(CONCAT44(uVar25,uVar25) >> 0x1b) +
             ((uVar21 ^ uVar23) & uVar27 ^ uVar21) + uVar24 + 0x5a827999 + uVar20;
    uVar14 = uVar2 ^ uVar28 ^ uVar8 ^ uVar13;
    uVar14 = (uint)(CONCAT44(uVar14,uVar14) >> 0x1f);
    uVar20 = (uint)(CONCAT44(uVar27,uVar27) >> 2);
    uVar27 = (int)(CONCAT44(uVar19,uVar19) >> 0x1b) +
             ((uVar23 ^ uVar20) & uVar25 ^ uVar23) + uVar14 + 0x5a827999 + uVar21;
    uVar21 = (uint)(CONCAT44(uVar25,uVar25) >> 2);
    uVar1 = uVar3 ^ uVar15 ^ uVar9 ^ uVar4;
    uVar1 = (uint)(CONCAT44(uVar1,uVar1) >> 0x1f);
    uVar25 = (int)(CONCAT44(uVar27,uVar27) >> 0x1b) +
             ((uVar20 ^ uVar21) & uVar19 ^ uVar20) + uVar1 + 0x5a827999 + uVar23;
    uVar23 = (uint)(CONCAT44(uVar19,uVar19) >> 2);
    uVar2 = (uint)(CONCAT44(uVar27,uVar27) >> 2);
    uVar3 = uVar28 ^ uVar5 ^ uVar10 ^ uVar24;
    uVar3 = (uint)(CONCAT44(uVar3,uVar3) >> 0x1f);
    uVar19 = (int)(CONCAT44(uVar25,uVar25) >> 0x1b) +
             ((uVar21 ^ uVar23) & uVar27 ^ uVar21) + uVar3 + 0x5a827999 + uVar20;
    uVar20 = uVar15 ^ uVar6 ^ uVar11 ^ uVar14;
    uVar20 = (uint)(CONCAT44(uVar20,uVar20) >> 0x1f);
    uVar27 = (uint)(CONCAT44(uVar25,uVar25) >> 2);
    uVar15 = (int)(CONCAT44(uVar19,uVar19) >> 0x1b) +
             (uVar23 ^ uVar2 ^ uVar25) + uVar20 + 0x6ed9eba1 + uVar21;
    uVar21 = (uint)(CONCAT44(uVar19,uVar19) >> 2);
    uVar5 = uVar5 ^ uVar7 ^ uVar12 ^ uVar1;
    uVar5 = (uint)(CONCAT44(uVar5,uVar5) >> 0x1f);
    uVar25 = (int)(CONCAT44(uVar15,uVar15) >> 0x1b) +
             (uVar2 ^ uVar27 ^ uVar19) + uVar5 + 0x6ed9eba1 + uVar23;
    uVar23 = (uint)(CONCAT44(uVar15,uVar15) >> 2);
    uVar6 = uVar6 ^ uVar16 ^ uVar13 ^ uVar3;
    uVar6 = (uint)(CONCAT44(uVar6,uVar6) >> 0x1f);
    uVar19 = (int)(CONCAT44(uVar25,uVar25) >> 0x1b) +
             (uVar27 ^ uVar21 ^ uVar15) + uVar6 + 0x6ed9eba1 + uVar2;
    uVar2 = uVar7 ^ uVar8 ^ uVar4 ^ uVar20;
    uVar2 = (uint)(CONCAT44(uVar2,uVar2) >> 0x1f);
    uVar15 = (int)(CONCAT44(uVar19,uVar19) >> 0x1b) +
             (uVar21 ^ uVar23 ^ uVar25) + uVar2 + 0x6ed9eba1 + uVar27;
    uVar27 = (uint)(CONCAT44(uVar25,uVar25) >> 2);
    uVar7 = uVar16 ^ uVar9 ^ uVar24 ^ uVar5;
    uVar7 = (uint)(CONCAT44(uVar7,uVar7) >> 0x1f);
    uVar16 = (int)(CONCAT44(uVar15,uVar15) >> 0x1b) +
             (uVar23 ^ uVar27 ^ uVar19) + uVar7 + 0x6ed9eba1 + uVar21;
    uVar21 = (uint)(CONCAT44(uVar19,uVar19) >> 2);
    uVar8 = uVar8 ^ uVar10 ^ uVar14 ^ uVar6;
    uVar8 = (uint)(CONCAT44(uVar8,uVar8) >> 0x1f);
    uVar25 = (uint)(CONCAT44(uVar15,uVar15) >> 2);
    uVar15 = (int)(CONCAT44(uVar16,uVar16) >> 0x1b) +
             (uVar27 ^ uVar21 ^ uVar15) + uVar8 + 0x6ed9eba1 + uVar23;
    uVar23 = uVar9 ^ uVar11 ^ uVar1 ^ uVar2;
    uVar23 = (uint)(CONCAT44(uVar23,uVar23) >> 0x1f);
    uVar28 = (int)(CONCAT44(uVar15,uVar15) >> 0x1b) +
             (uVar21 ^ uVar25 ^ uVar16) + uVar23 + 0x6ed9eba1 + uVar27;
    uVar27 = (uint)(CONCAT44(uVar16,uVar16) >> 2);
    uVar9 = uVar10 ^ uVar12 ^ uVar3 ^ uVar7;
    uVar9 = (uint)(CONCAT44(uVar9,uVar9) >> 0x1f);
    uVar19 = (int)(CONCAT44(uVar28,uVar28) >> 0x1b) +
             (uVar25 ^ uVar27 ^ uVar15) + uVar9 + 0x6ed9eba1 + uVar21;
    uVar21 = (uint)(CONCAT44(uVar15,uVar15) >> 2);
    uVar10 = uVar11 ^ uVar13 ^ uVar20 ^ uVar8;
    uVar10 = (uint)(CONCAT44(uVar10,uVar10) >> 0x1f);
    uVar15 = (int)(CONCAT44(uVar19,uVar19) >> 0x1b) +
             (uVar27 ^ uVar21 ^ uVar28) + uVar10 + 0x6ed9eba1 + uVar25;
    uVar25 = (uint)(CONCAT44(uVar28,uVar28) >> 2);
    uVar11 = uVar12 ^ uVar4 ^ uVar5 ^ uVar23;
    uVar11 = (uint)(CONCAT44(uVar11,uVar11) >> 0x1f);
    uVar16 = (int)(CONCAT44(uVar15,uVar15) >> 0x1b) +
             (uVar21 ^ uVar25 ^ uVar19) + uVar11 + 0x6ed9eba1 + uVar27;
    uVar27 = (uint)(CONCAT44(uVar19,uVar19) >> 2);
    uVar12 = uVar13 ^ uVar24 ^ uVar6 ^ uVar9;
    uVar12 = (uint)(CONCAT44(uVar12,uVar12) >> 0x1f);
    uVar13 = (uint)(CONCAT44(uVar15,uVar15) >> 2);
    uVar15 = (int)(CONCAT44(uVar16,uVar16) >> 0x1b) +
             (uVar25 ^ uVar27 ^ uVar15) + uVar12 + 0x6ed9eba1 + uVar21;
    uVar21 = uVar4 ^ uVar14 ^ uVar2 ^ uVar10;
    uVar21 = (uint)(CONCAT44(uVar21,uVar21) >> 0x1f);
    uVar4 = (int)(CONCAT44(uVar15,uVar15) >> 0x1b) +
            (uVar27 ^ uVar13 ^ uVar16) + uVar21 + 0x6ed9eba1 + uVar25;
    uVar25 = (uint)(CONCAT44(uVar16,uVar16) >> 2);
    uVar24 = uVar24 ^ uVar1 ^ uVar7 ^ uVar11;
    uVar24 = (uint)(CONCAT44(uVar24,uVar24) >> 0x1f);
    uVar19 = (int)(CONCAT44(uVar4,uVar4) >> 0x1b) +
             (uVar13 ^ uVar25 ^ uVar15) + uVar24 + 0x6ed9eba1 + uVar27;
    uVar27 = (uint)(CONCAT44(uVar15,uVar15) >> 2);
    uVar14 = uVar14 ^ uVar3 ^ uVar8 ^ uVar12;
    uVar14 = (uint)(CONCAT44(uVar14,uVar14) >> 0x1f);
    uVar16 = (int)(CONCAT44(uVar19,uVar19) >> 0x1b) +
             (uVar25 ^ uVar27 ^ uVar4) + uVar14 + 0x6ed9eba1 + uVar13;
    uVar13 = (uint)(CONCAT44(uVar4,uVar4) >> 2);
    uVar4 = (uint)(CONCAT44(uVar19,uVar19) >> 2);
    uVar1 = uVar1 ^ uVar20 ^ uVar23 ^ uVar21;
    uVar1 = (uint)(CONCAT44(uVar1,uVar1) >> 0x1f);
    uVar15 = (int)(CONCAT44(uVar16,uVar16) >> 0x1b) +
             (uVar27 ^ uVar13 ^ uVar19) + uVar1 + 0x6ed9eba1 + uVar25;
    uVar3 = uVar3 ^ uVar5 ^ uVar9 ^ uVar24;
    uVar3 = (uint)(CONCAT44(uVar3,uVar3) >> 0x1f);
    uVar19 = (int)(CONCAT44(uVar15,uVar15) >> 0x1b) +
             (uVar13 ^ uVar4 ^ uVar16) + uVar3 + 0x6ed9eba1 + uVar27;
    uVar27 = (uint)(CONCAT44(uVar16,uVar16) >> 2);
    uVar20 = uVar20 ^ uVar6 ^ uVar10 ^ uVar14;
    uVar20 = (uint)(CONCAT44(uVar20,uVar20) >> 0x1f);
    uVar25 = uVar5 ^ uVar2 ^ uVar11 ^ uVar1;
    uVar16 = (int)(CONCAT44(uVar19,uVar19) >> 0x1b) +
             (uVar4 ^ uVar27 ^ uVar15) + uVar20 + 0x6ed9eba1 + uVar13;
    uVar5 = (uint)(CONCAT44(uVar15,uVar15) >> 2);
    uVar25 = (uint)(CONCAT44(uVar25,uVar25) >> 0x1f);
    uVar28 = (int)(CONCAT44(uVar16,uVar16) >> 0x1b) +
             (uVar27 ^ uVar5 ^ uVar19) + uVar25 + 0x6ed9eba1 + uVar4;
    uVar13 = (uint)(CONCAT44(uVar19,uVar19) >> 2);
    uVar4 = (uint)(CONCAT44(uVar16,uVar16) >> 2);
    uVar6 = uVar6 ^ uVar7 ^ uVar12 ^ uVar3;
    uVar6 = (uint)(CONCAT44(uVar6,uVar6) >> 0x1f);
    uVar15 = (int)(CONCAT44(uVar28,uVar28) >> 0x1b) +
             (uVar5 ^ uVar13 ^ uVar16) + uVar6 + 0x6ed9eba1 + uVar27;
    uVar2 = uVar2 ^ uVar8 ^ uVar21 ^ uVar20;
    uVar2 = (uint)(CONCAT44(uVar2,uVar2) >> 0x1f);
    uVar27 = (uint)(CONCAT44(uVar28,uVar28) >> 2);
    uVar16 = (int)(CONCAT44(uVar15,uVar15) >> 0x1b) +
             (uVar13 ^ uVar4 ^ uVar28) + uVar2 + 0x6ed9eba1 + uVar5;
    uVar5 = uVar7 ^ uVar23 ^ uVar24 ^ uVar25;
    uVar5 = (uint)(CONCAT44(uVar5,uVar5) >> 0x1f);
    uVar19 = ((uVar15 | uVar27) & uVar4 | uVar15 & uVar27) +
             uVar5 + 0x8f1bbcdc + uVar13 + (int)(CONCAT44(uVar16,uVar16) >> 0x1b);
    uVar7 = (uint)(CONCAT44(uVar15,uVar15) >> 2);
    uVar8 = uVar8 ^ uVar9 ^ uVar14 ^ uVar6;
    uVar8 = (uint)(CONCAT44(uVar8,uVar8) >> 0x1f);
    uVar15 = (int)(CONCAT44(uVar19,uVar19) >> 0x1b) +
             ((uVar16 | uVar7) & uVar27 | uVar16 & uVar7) + uVar8 + 0x8f1bbcdc + uVar4;
    uVar13 = (uint)(CONCAT44(uVar16,uVar16) >> 2);
    uVar23 = uVar23 ^ uVar10 ^ uVar1 ^ uVar2;
    uVar23 = (uint)(CONCAT44(uVar23,uVar23) >> 0x1f);
    uVar28 = ((uVar19 | uVar13) & uVar7 | uVar19 & uVar13) +
             uVar23 + 0x8f1bbcdc + uVar27 + (int)(CONCAT44(uVar15,uVar15) >> 0x1b);
    uVar27 = (uint)(CONCAT44(uVar19,uVar19) >> 2);
    uVar4 = (uint)(CONCAT44(uVar15,uVar15) >> 2);
    uVar9 = uVar9 ^ uVar11 ^ uVar3 ^ uVar5;
    uVar9 = (uint)(CONCAT44(uVar9,uVar9) >> 0x1f);
    uVar15 = (int)(CONCAT44(uVar28,uVar28) >> 0x1b) +
             ((uVar15 | uVar27) & uVar13 | uVar15 & uVar27) + uVar9 + 0x8f1bbcdc + uVar7;
    uVar7 = uVar10 ^ uVar12 ^ uVar20 ^ uVar8;
    uVar7 = (uint)(CONCAT44(uVar7,uVar7) >> 0x1f);
    uVar16 = ((uVar28 | uVar4) & uVar27 | uVar28 & uVar4) +
             uVar7 + 0x8f1bbcdc + uVar13 + (int)(CONCAT44(uVar15,uVar15) >> 0x1b);
    uVar10 = (uint)(CONCAT44(uVar28,uVar28) >> 2);
    uVar13 = (uint)(CONCAT44(uVar15,uVar15) >> 2);
    uVar11 = uVar11 ^ uVar21 ^ uVar25 ^ uVar23;
    uVar11 = (uint)(CONCAT44(uVar11,uVar11) >> 0x1f);
    uVar19 = (int)(CONCAT44(uVar16,uVar16) >> 0x1b) +
             ((uVar15 | uVar10) & uVar4 | uVar15 & uVar10) + uVar11 + 0x8f1bbcdc + uVar27;
    uVar27 = uVar12 ^ uVar24 ^ uVar6 ^ uVar9;
    uVar27 = (uint)(CONCAT44(uVar27,uVar27) >> 0x1f);
    uVar12 = (uint)(CONCAT44(uVar16,uVar16) >> 2);
    uVar15 = ((uVar16 | uVar13) & uVar10 | uVar16 & uVar13) +
             uVar27 + 0x8f1bbcdc + uVar4 + (int)(CONCAT44(uVar19,uVar19) >> 0x1b);
    uVar21 = uVar21 ^ uVar14 ^ uVar2 ^ uVar7;
    uVar21 = (uint)(CONCAT44(uVar21,uVar21) >> 0x1f);
    uVar16 = (int)(CONCAT44(uVar15,uVar15) >> 0x1b) +
             ((uVar19 | uVar12) & uVar13 | uVar19 & uVar12) + uVar21 + 0x8f1bbcdc + uVar10;
    uVar10 = (uint)(CONCAT44(uVar19,uVar19) >> 2);
    uVar24 = uVar24 ^ uVar1 ^ uVar5 ^ uVar11;
    uVar24 = (uint)(CONCAT44(uVar24,uVar24) >> 0x1f);
    uVar4 = (uint)(CONCAT44(uVar15,uVar15) >> 2);
    uVar15 = ((uVar15 | uVar10) & uVar12 | uVar15 & uVar10) +
             uVar24 + 0x8f1bbcdc + uVar13 + (int)(CONCAT44(uVar16,uVar16) >> 0x1b);
    uVar14 = uVar14 ^ uVar3 ^ uVar8 ^ uVar27;
    uVar14 = (uint)(CONCAT44(uVar14,uVar14) >> 0x1f);
    uVar13 = (uint)(CONCAT44(uVar16,uVar16) >> 2);
    uVar16 = (int)(CONCAT44(uVar15,uVar15) >> 0x1b) +
             ((uVar16 | uVar4) & uVar10 | uVar16 & uVar4) + uVar14 + 0x8f1bbcdc + uVar12;
    uVar1 = uVar1 ^ uVar20 ^ uVar23 ^ uVar21;
    uVar1 = (uint)(CONCAT44(uVar1,uVar1) >> 0x1f);
    uVar19 = ((uVar15 | uVar13) & uVar4 | uVar15 & uVar13) +
             uVar1 + 0x8f1bbcdc + uVar10 + (int)(CONCAT44(uVar16,uVar16) >> 0x1b);
    uVar10 = (uint)(CONCAT44(uVar15,uVar15) >> 2);
    uVar12 = (uint)(CONCAT44(uVar16,uVar16) >> 2);
    uVar3 = uVar3 ^ uVar25 ^ uVar9 ^ uVar24;
    uVar3 = (uint)(CONCAT44(uVar3,uVar3) >> 0x1f);
    uVar4 = (int)(CONCAT44(uVar19,uVar19) >> 0x1b) +
            ((uVar16 | uVar10) & uVar13 | uVar16 & uVar10) + uVar3 + 0x8f1bbcdc + uVar4;
    uVar20 = uVar20 ^ uVar6 ^ uVar7 ^ uVar14;
    uVar20 = (uint)(CONCAT44(uVar20,uVar20) >> 0x1f);
    uVar15 = ((uVar19 | uVar12) & uVar10 | uVar19 & uVar12) +
             uVar20 + 0x8f1bbcdc + uVar13 + (int)(CONCAT44(uVar4,uVar4) >> 0x1b);
    uVar13 = (uint)(CONCAT44(uVar19,uVar19) >> 2);
    uVar25 = uVar25 ^ uVar2 ^ uVar11 ^ uVar1;
    uVar25 = (uint)(CONCAT44(uVar25,uVar25) >> 0x1f);
    uVar19 = (int)(CONCAT44(uVar15,uVar15) >> 0x1b) +
             ((uVar4 | uVar13) & uVar12 | uVar4 & uVar13) + uVar25 + 0x8f1bbcdc + uVar10;
    uVar10 = (uint)(CONCAT44(uVar4,uVar4) >> 2);
    uVar6 = uVar6 ^ uVar5 ^ uVar27 ^ uVar3;
    uVar6 = (uint)(CONCAT44(uVar6,uVar6) >> 0x1f);
    uVar16 = ((uVar15 | uVar10) & uVar13 | uVar15 & uVar10) +
             uVar6 + 0x8f1bbcdc + uVar12 + (int)(CONCAT44(uVar19,uVar19) >> 0x1b);
    uVar12 = (uint)(CONCAT44(uVar15,uVar15) >> 2);
    uVar2 = uVar2 ^ uVar8 ^ uVar21 ^ uVar20;
    uVar2 = (uint)(CONCAT44(uVar2,uVar2) >> 0x1f);
    uVar4 = (uint)(CONCAT44(uVar19,uVar19) >> 2);
    uVar13 = (int)(CONCAT44(uVar16,uVar16) >> 0x1b) +
             ((uVar19 | uVar12) & uVar10 | uVar19 & uVar12) + uVar2 + 0x8f1bbcdc + uVar13;
    uVar5 = uVar5 ^ uVar23 ^ uVar24 ^ uVar25;
    uVar5 = (uint)(CONCAT44(uVar5,uVar5) >> 0x1f);
    uVar15 = ((uVar16 | uVar4) & uVar12 | uVar16 & uVar4) +
             uVar5 + 0x8f1bbcdc + uVar10 + (int)(CONCAT44(uVar13,uVar13) >> 0x1b);
    uVar10 = (uint)(CONCAT44(uVar16,uVar16) >> 2);
    uVar8 = uVar8 ^ uVar9 ^ uVar14 ^ uVar6;
    uVar8 = (uint)(CONCAT44(uVar8,uVar8) >> 0x1f);
    uVar16 = (int)(CONCAT44(uVar15,uVar15) >> 0x1b) +
             ((uVar13 | uVar10) & uVar4 | uVar13 & uVar10) + uVar8 + 0x8f1bbcdc + uVar12;
    uVar12 = (uint)(CONCAT44(uVar13,uVar13) >> 2);
    uVar23 = uVar23 ^ uVar7 ^ uVar1 ^ uVar2;
    uVar23 = (uint)(CONCAT44(uVar23,uVar23) >> 0x1f);
    uVar13 = (uint)(CONCAT44(uVar15,uVar15) >> 2);
    uVar15 = ((uVar15 | uVar12) & uVar10 | uVar15 & uVar12) +
             uVar23 + 0x8f1bbcdc + uVar4 + (int)(CONCAT44(uVar16,uVar16) >> 0x1b);
    uVar9 = uVar9 ^ uVar11 ^ uVar3 ^ uVar5;
    uVar9 = (uint)(CONCAT44(uVar9,uVar9) >> 0x1f);
    uVar4 = (uint)(CONCAT44(uVar16,uVar16) >> 2);
    uVar19 = (int)(CONCAT44(uVar15,uVar15) >> 0x1b) +
             ((uVar16 | uVar13) & uVar12 | uVar16 & uVar13) + uVar9 + 0x8f1bbcdc + uVar10;
    uVar10 = (uint)(CONCAT44(uVar15,uVar15) >> 2);
    uVar7 = uVar7 ^ uVar27 ^ uVar20 ^ uVar8;
    uVar7 = (uint)(CONCAT44(uVar7,uVar7) >> 0x1f);
    uVar15 = (int)(CONCAT44(uVar19,uVar19) >> 0x1b) +
             (uVar13 ^ uVar4 ^ uVar15) + uVar7 + 0xca62c1d6 + uVar12;
    uVar11 = uVar11 ^ uVar21 ^ uVar25 ^ uVar23;
    uVar11 = (uint)(CONCAT44(uVar11,uVar11) >> 0x1f);
    uVar16 = (int)(CONCAT44(uVar15,uVar15) >> 0x1b) +
             (uVar4 ^ uVar10 ^ uVar19) + uVar11 + 0xca62c1d6 + uVar13;
    uVar12 = (uint)(CONCAT44(uVar19,uVar19) >> 2);
    uVar13 = (uint)(CONCAT44(uVar15,uVar15) >> 2);
    uVar27 = uVar27 ^ uVar24 ^ uVar6 ^ uVar9;
    uVar27 = (uint)(CONCAT44(uVar27,uVar27) >> 0x1f);
    uVar15 = (int)(CONCAT44(uVar16,uVar16) >> 0x1b) +
             (uVar10 ^ uVar12 ^ uVar15) + uVar27 + 0xca62c1d6 + uVar4;
    uVar4 = (uint)(CONCAT44(uVar16,uVar16) >> 2);
    uVar21 = uVar21 ^ uVar14 ^ uVar2 ^ uVar7;
    uVar21 = (uint)(CONCAT44(uVar21,uVar21) >> 0x1f);
    uVar16 = (int)(CONCAT44(uVar15,uVar15) >> 0x1b) +
             (uVar12 ^ uVar13 ^ uVar16) + uVar21 + 0xca62c1d6 + uVar10;
    uVar24 = uVar24 ^ uVar1 ^ uVar5 ^ uVar11;
    uVar24 = (uint)(CONCAT44(uVar24,uVar24) >> 0x1f);
    uVar10 = (uint)(CONCAT44(uVar15,uVar15) >> 2);
    uVar15 = (int)(CONCAT44(uVar16,uVar16) >> 0x1b) +
             (uVar13 ^ uVar4 ^ uVar15) + uVar24 + 0xca62c1d6 + uVar12;
    uVar14 = uVar14 ^ uVar3 ^ uVar8 ^ uVar27;
    uVar14 = (uint)(CONCAT44(uVar14,uVar14) >> 0x1f);
    uVar12 = (uint)(CONCAT44(uVar16,uVar16) >> 2);
    uVar19 = (int)(CONCAT44(uVar15,uVar15) >> 0x1b) +
             (uVar4 ^ uVar10 ^ uVar16) + uVar14 + 0xca62c1d6 + uVar13;
    uVar1 = uVar1 ^ uVar20 ^ uVar23 ^ uVar21;
    uVar1 = (uint)(CONCAT44(uVar1,uVar1) >> 0x1f);
    uVar13 = (uint)(CONCAT44(uVar15,uVar15) >> 2);
    uVar3 = uVar3 ^ uVar25 ^ uVar9 ^ uVar24;
    uVar3 = (uint)(CONCAT44(uVar3,uVar3) >> 0x1f);
    uVar16 = (int)(CONCAT44(uVar19,uVar19) >> 0x1b) +
             (uVar10 ^ uVar12 ^ uVar15) + uVar1 + 0xca62c1d6 + uVar4;
    uVar15 = (int)(CONCAT44(uVar16,uVar16) >> 0x1b) +
             (uVar12 ^ uVar13 ^ uVar19) + uVar3 + 0xca62c1d6 + uVar10;
    uVar10 = (uint)(CONCAT44(uVar19,uVar19) >> 2);
    uVar4 = (uint)(CONCAT44(uVar16,uVar16) >> 2);
    uVar20 = uVar20 ^ uVar6 ^ uVar7 ^ uVar14;
    uVar20 = (uint)(CONCAT44(uVar20,uVar20) >> 0x1f);
    uVar16 = (int)(CONCAT44(uVar15,uVar15) >> 0x1b) +
             (uVar13 ^ uVar10 ^ uVar16) + uVar20 + 0xca62c1d6 + uVar12;
    uVar12 = (uint)(CONCAT44(uVar15,uVar15) >> 2);
    uVar25 = uVar25 ^ uVar2 ^ uVar11 ^ uVar1;
    uVar25 = (uint)(CONCAT44(uVar25,uVar25) >> 0x1f);
    uVar15 = (int)(CONCAT44(uVar16,uVar16) >> 0x1b) +
             (uVar10 ^ uVar4 ^ uVar15) + uVar25 + 0xca62c1d6 + uVar13;
    uVar6 = uVar6 ^ uVar5 ^ uVar27 ^ uVar3;
    uVar6 = (uint)(CONCAT44(uVar6,uVar6) >> 0x1f);
    uVar13 = (uint)(CONCAT44(uVar16,uVar16) >> 2);
    uVar19 = (int)(CONCAT44(uVar15,uVar15) >> 0x1b) +
             (uVar4 ^ uVar12 ^ uVar16) + uVar6 + 0xca62c1d6 + uVar10;
    uVar2 = uVar2 ^ uVar8 ^ uVar21 ^ uVar20;
    uVar2 = (uint)(CONCAT44(uVar2,uVar2) >> 0x1f);
    uVar10 = (uint)(CONCAT44(uVar15,uVar15) >> 2);
    uVar16 = (int)(CONCAT44(uVar19,uVar19) >> 0x1b) +
             (uVar12 ^ uVar13 ^ uVar15) + uVar2 + 0xca62c1d6 + uVar4;
    uVar5 = uVar5 ^ uVar23 ^ uVar24 ^ uVar25;
    uVar5 = (uint)(CONCAT44(uVar5,uVar5) >> 0x1f);
    uVar15 = (int)(CONCAT44(uVar16,uVar16) >> 0x1b) +
             (uVar13 ^ uVar10 ^ uVar19) + uVar5 + 0xca62c1d6 + uVar12;
    uVar12 = (uint)(CONCAT44(uVar19,uVar19) >> 2);
    uVar4 = (uint)(CONCAT44(uVar16,uVar16) >> 2);
    uVar8 = uVar8 ^ uVar9 ^ uVar14 ^ uVar6;
    uVar8 = (uint)(CONCAT44(uVar8,uVar8) >> 0x1f);
    uVar16 = (int)(CONCAT44(uVar15,uVar15) >> 0x1b) +
             (uVar10 ^ uVar12 ^ uVar16) + uVar8 + 0xca62c1d6 + uVar13;
    uVar23 = uVar23 ^ uVar7 ^ uVar1 ^ uVar2;
    uVar23 = (uint)(CONCAT44(uVar23,uVar23) >> 0x1f);
    uVar13 = (int)(CONCAT44(uVar16,uVar16) >> 0x1b) +
             (uVar12 ^ uVar4 ^ uVar15) + uVar23 + 0xca62c1d6 + uVar10;
    uVar1 = (uint)(CONCAT44(uVar15,uVar15) >> 2);
    uVar5 = uVar9 ^ uVar11 ^ uVar3 ^ uVar5;
    uVar3 = (uint)(CONCAT44(uVar5,uVar5) >> 0x1f);
    uVar10 = (int)(CONCAT44(uVar13,uVar13) >> 0x1b) +
             (uVar4 ^ uVar1 ^ uVar16) + uVar3 + 0xca62c1d6 + uVar12;
    uVar5 = (uint)(CONCAT44(uVar16,uVar16) >> 2);
    uVar9 = (uint)(CONCAT44(uVar13,uVar13) >> 2);
    uVar8 = uVar7 ^ uVar27 ^ uVar20 ^ uVar8;
    uVar20 = (uint)(CONCAT44(uVar8,uVar8) >> 0x1f);
    uVar8 = (int)(CONCAT44(uVar10,uVar10) >> 0x1b) +
            (uVar1 ^ uVar5 ^ uVar13) + uVar20 + 0xca62c1d6 + uVar4;
    uVar23 = uVar11 ^ uVar21 ^ uVar25 ^ uVar23;
    uVar7 = (int)(CONCAT44(uVar8,uVar8) >> 0x1b) +
            (int)(CONCAT44(uVar23,uVar23) >> 0x1f) + -0x359d3e2a + uVar1 + (uVar5 ^ uVar9 ^ uVar10);
    uVar23 = (uint)(CONCAT44(uVar10,uVar10) >> 2);
    uVar1 = (uint)(CONCAT44(uVar8,uVar8) >> 2);
    uVar3 = uVar27 ^ uVar24 ^ uVar6 ^ uVar3;
    uVar20 = uVar21 ^ uVar14 ^ uVar2 ^ uVar20;
    iVar22 = (int)(CONCAT44(uVar7,uVar7) >> 0x1b) +
             (int)(CONCAT44(uVar3,uVar3) >> 0x1f) + -0x359d3e2a + uVar5 + (uVar9 ^ uVar23 ^ uVar8);
    *(uint *)(param_1 + 0xc) = uVar29 + iVar22;
    *(uint *)(param_1 + 0x10) = (int)(CONCAT44(uVar7,uVar7) >> 2) + uVar17;
    *(uint *)(param_1 + 8) =
         (int)(CONCAT44(uVar20,uVar20) >> 0x1f) + uVar26 + 0xca62c1d6 + uVar9 +
         (uVar23 ^ uVar1 ^ uVar7) + (int)(CONCAT44(iVar22,iVar22) >> 0x1b);
    *(uint *)(param_1 + 0x14) = uVar18 + uVar1;
    *(uint *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + uVar23;
    memw();
  }
  return 0;
}

