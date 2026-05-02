// Function : FUN_4013fa98
// Address  : 0x4013fa98
// Size     : 3538 bytes


/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_4013fa98(int param_1,byte *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
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
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uStack_350;
  uint uStack_340;
  uint uStack_33c;
  int *piStack_324;
  uint *puStack_320;
  uint uStack_31c;
  uint uStack_314;
  uint uStack_310;
  uint uStack_30c;
  uint uStack_308;
  uint uStack_304;
  uint uStack_300;
  uint uStack_2fc;
  uint uStack_2f8;
  int iStack_2d4;
  uint uStack_2cc;
  uint uStack_2c8;
  uint uStack_2c4;
  int local_2a0 [2];
  uint local_298;
  uint uStack_294;
  uint uStack_258;
  int iStack_254;
  uint uStack_230;
  uint uStack_22c;
  uint uStack_220;
  int iStack_21c;
  
  piStack_324 = local_2a0;
  uVar12 = (uStack_22c << 0xd | uStack_230 >> 0x13) ^ (uStack_22c >> 0x1d | uStack_230 << 3) ^
           (uStack_22c << 0x1a | uStack_230 >> 6);
  uVar7 = uStack_258 +
          ((uint)param_2[7] | (uint)param_2[4] << 0x18 | (uint)param_2[5] << 0x10 |
          (uint)param_2[6] << 8);
  uVar8 = uVar12 + uVar7;
  uStack_220 = uVar8 + ((uStack_294 << 0x1f | local_298 >> 1) ^
                        (uStack_294 << 0x18 | local_298 >> 8) ^
                       (uStack_294 << 0x19 | local_298 >> 7));
  iStack_21c = (uint)(uStack_220 < uVar8) +
               (uint)(uVar8 < uVar12) +
               ((uStack_230 << 0xd | uStack_22c >> 0x13) ^ (uStack_230 >> 0x1d | uStack_22c << 3) ^
               uStack_22c >> 6) +
               (uint)(uVar7 < uStack_258) +
               iStack_254 +
               ((uint)*param_2 << 0x18 | (uint)param_2[1] << 0x10 | (uint)param_2[2] << 8 |
               (uint)param_2[3]) +
               ((local_298 << 0x1f | uStack_294 >> 1) ^ (local_298 << 0x18 | uStack_294 >> 8) ^
               uStack_294 >> 7);
  uVar12 = *(uint *)(param_1 + 0x10);
  uVar8 = *(uint *)(param_1 + 0x30);
  uVar13 = *(uint *)(param_1 + 0x18);
  uVar20 = *(uint *)(param_1 + 0x20);
  uVar25 = *(uint *)(param_1 + 0x28);
  uVar4 = *(uint *)(param_1 + 0x38);
  uVar14 = *(uint *)(param_1 + 0x40);
  uVar21 = *(uint *)(param_1 + 0x48);
  puStack_320 = &DAT_3f4227e0;
  iStack_2d4 = 10;
  uVar7 = uVar12;
  uStack_350 = *(uint *)(param_1 + 0x14);
  uStack_340 = uVar8;
  uStack_33c = *(uint *)(param_1 + 0x34);
  uStack_31c = uVar13;
  uStack_314 = *(uint *)(param_1 + 0x1c);
  uStack_310 = uVar4;
  uStack_30c = *(uint *)(param_1 + 0x3c);
  uStack_308 = uVar20;
  uStack_304 = uVar14;
  uStack_300 = *(uint *)(param_1 + 0x44);
  uStack_2fc = *(uint *)(param_1 + 0x24);
  uStack_2f8 = uVar25;
  uStack_2cc = *(uint *)(param_1 + 0x2c);
  uStack_2c8 = uVar21;
  uStack_2c4 = *(uint *)(param_1 + 0x4c);
  do {
    uVar1 = (uStack_33c << 0x12 | uStack_340 >> 0xe) ^ (uStack_33c << 0xe | uStack_340 >> 0x12) ^
            (uStack_33c >> 9 | uStack_340 << 0x17);
    uVar9 = *puStack_320 + *piStack_324;
    uVar10 = uVar1 + uVar9;
    uVar15 = uVar10 + ((uStack_310 ^ uStack_304) & uStack_340 ^ uStack_304);
    uStack_2c8 = uVar15 + uStack_2c8;
    uVar16 = uStack_2f8 + uStack_2c8;
    iVar5 = (uint)(uStack_2c8 < uVar15) +
            (uint)(uVar15 < uVar10) +
            (uint)(uVar10 < uVar1) +
            ((uStack_340 << 0x12 | uStack_33c >> 0xe) ^ (uStack_340 << 0xe | uStack_33c >> 0x12) ^
            (uStack_340 >> 9 | uStack_33c << 0x17)) +
            (uint)(uVar9 < *puStack_320) + puStack_320[1] + piStack_324[1] +
            ((uStack_30c ^ uStack_300) & uStack_33c ^ uStack_300) + uStack_2c4;
    uVar1 = (uint)(uVar16 < uStack_2f8) + uStack_2cc + iVar5;
    uVar9 = (uStack_350 << 4 | uVar7 >> 0x1c) ^ (uStack_350 >> 2 | uVar7 << 0x1e) ^
            (uStack_350 >> 7 | uVar7 << 0x19);
    uVar10 = uVar9 + ((uVar7 | uStack_31c) & uStack_308 | uVar7 & uStack_31c);
    uVar11 = uVar10 + uStack_2c8;
    uVar18 = (uint)(uVar11 < uVar10) +
             (uint)(uVar10 < uVar9) +
             ((uVar7 << 4 | uStack_350 >> 0x1c) ^ (uVar7 >> 2 | uStack_350 << 0x1e) ^
             (uVar7 >> 7 | uStack_350 << 0x19)) +
             ((uStack_350 | uStack_314) & uStack_2fc | uStack_350 & uStack_314) + iVar5;
    uVar9 = puStack_320[2] + piStack_324[2];
    uStack_304 = uVar9 + uStack_304;
    uVar15 = uStack_304 + ((uStack_340 ^ uStack_310) & uVar16 ^ uStack_310);
    uVar6 = uVar15 + ((uVar1 * 0x40000 | uVar16 >> 0xe) ^ (uVar1 * 0x4000 | uVar16 >> 0x12) ^
                     (uVar1 >> 9 | uVar16 * 0x800000));
    uVar10 = uStack_308 + uVar6;
    iVar5 = (uint)(uVar6 < uVar15) +
            (uint)(uVar15 < uStack_304) +
            (uint)(uStack_304 < uVar9) +
            (uint)(uVar9 < puStack_320[2]) + puStack_320[3] + piStack_324[3] + uStack_300 +
            ((uStack_33c ^ uStack_30c) & uVar1 ^ uStack_30c) +
            ((uVar16 * 0x40000 | uVar1 >> 0xe) ^ (uVar16 * 0x4000 | uVar1 >> 0x12) ^
            (uVar16 >> 9 | uVar1 * 0x800000));
    uVar9 = (uint)(uVar10 < uStack_308) + uStack_2fc + iVar5;
    uVar15 = (uVar18 * 0x10 | uVar11 >> 0x1c) ^ (uVar18 >> 2 | uVar11 * 0x40000000) ^
             (uVar18 >> 7 | uVar11 * 0x2000000);
    uVar3 = uVar15 + ((uVar7 | uVar11) & uStack_31c | uVar7 & uVar11);
    uVar6 = uVar3 + uVar6;
    uVar22 = (uint)(uVar6 < uVar3) +
             (uint)(uVar3 < uVar15) +
             ((uVar11 * 0x10 | uVar18 >> 0x1c) ^ (uVar11 >> 2 | uVar18 * 0x40000000) ^
             (uVar11 >> 7 | uVar18 * 0x2000000)) +
             ((uStack_350 | uVar18) & uStack_314 | uStack_350 & uVar18) + iVar5;
    uVar15 = puStack_320[4] + piStack_324[4];
    uStack_310 = uVar15 + uStack_310;
    uVar3 = uStack_310 + ((uStack_340 ^ uVar16) & uVar10 ^ uStack_340);
    uVar2 = uVar3 + ((uVar9 * 0x40000 | uVar10 >> 0xe) ^ (uVar9 * 0x4000 | uVar10 >> 0x12) ^
                    (uVar9 >> 9 | uVar10 * 0x800000));
    uVar26 = uStack_31c + uVar2;
    iVar5 = (uint)(uVar2 < uVar3) +
            (uint)(uVar3 < uStack_310) +
            (uint)(uStack_310 < uVar15) +
            (uint)(uVar15 < puStack_320[4]) + puStack_320[5] + piStack_324[5] + uStack_30c +
            ((uStack_33c ^ uVar1) & uVar9 ^ uStack_33c) +
            ((uVar10 * 0x40000 | uVar9 >> 0xe) ^ (uVar10 * 0x4000 | uVar9 >> 0x12) ^
            (uVar10 >> 9 | uVar9 * 0x800000));
    uVar15 = (uint)(uVar26 < uStack_31c) + uStack_314 + iVar5;
    uVar3 = (uVar22 * 0x10 | uVar6 >> 0x1c) ^ (uVar22 >> 2 | uVar6 * 0x40000000) ^
            (uVar22 >> 7 | uVar6 * 0x2000000);
    uVar17 = uVar3 + ((uVar11 | uVar6) & uVar7 | uVar11 & uVar6);
    uVar2 = uVar17 + uVar2;
    uVar23 = (uint)(uVar2 < uVar17) +
             (uint)(uVar17 < uVar3) +
             ((uVar6 * 0x10 | uVar22 >> 0x1c) ^ (uVar6 >> 2 | uVar22 * 0x40000000) ^
             (uVar6 >> 7 | uVar22 * 0x2000000)) + ((uVar18 | uVar22) & uStack_350 | uVar18 & uVar22)
             + iVar5;
    uVar3 = puStack_320[6] + piStack_324[6];
    uStack_340 = uVar3 + uStack_340;
    uVar17 = uStack_340 + ((uVar16 ^ uVar10) & uVar26 ^ uVar16);
    uVar24 = uVar17 + ((uVar15 * 0x40000 | uVar26 >> 0xe) ^ (uVar15 * 0x4000 | uVar26 >> 0x12) ^
                      (uVar15 >> 9 | uVar26 * 0x800000));
    iVar5 = (uint)(uVar24 < uVar17) +
            (uint)(uVar17 < uStack_340) +
            (uint)(uStack_340 < uVar3) +
            (uint)(uVar3 < puStack_320[6]) + puStack_320[7] + piStack_324[7] + uStack_33c +
            ((uVar1 ^ uVar9) & uVar15 ^ uVar1) +
            ((uVar26 * 0x40000 | uVar15 >> 0xe) ^ (uVar26 * 0x4000 | uVar15 >> 0x12) ^
            (uVar26 >> 9 | uVar15 * 0x800000));
    uVar3 = uVar7 + uVar24;
    uVar17 = (uint)(uVar3 < uVar7) + uStack_350 + iVar5;
    uVar7 = (uVar23 * 0x10 | uVar2 >> 0x1c) ^ (uVar23 >> 2 | uVar2 * 0x40000000) ^
            (uVar23 >> 7 | uVar2 * 0x2000000);
    uVar27 = uVar7 + ((uVar6 | uVar2) & uVar11 | uVar6 & uVar2);
    uVar24 = uVar27 + uVar24;
    uVar19 = (uint)(uVar24 < uVar27) +
             (uint)(uVar27 < uVar7) +
             ((uVar2 * 0x10 | uVar23 >> 0x1c) ^ (uVar2 >> 2 | uVar23 * 0x40000000) ^
             (uVar2 >> 7 | uVar23 * 0x2000000)) + ((uVar22 | uVar23) & uVar18 | uVar22 & uVar23) +
             iVar5;
    uVar7 = puStack_320[8] + piStack_324[8];
    uVar16 = uVar7 + uVar16;
    uVar27 = uVar16 + ((uVar10 ^ uVar26) & uVar3 ^ uVar10);
    uStack_2f8 = uVar27 + ((uVar17 * 0x40000 | uVar3 >> 0xe) ^ (uVar17 * 0x4000 | uVar3 >> 0x12) ^
                          (uVar17 >> 9 | uVar3 * 0x800000));
    uStack_2c8 = uVar11 + uStack_2f8;
    iVar5 = (uint)(uStack_2f8 < uVar27) +
            (uint)(uVar27 < uVar16) +
            (uint)(uVar16 < uVar7) +
            (uint)(uVar7 < puStack_320[8]) + puStack_320[9] + piStack_324[9] + uVar1 +
            ((uVar9 ^ uVar15) & uVar17 ^ uVar9) +
            ((uVar3 * 0x40000 | uVar17 >> 0xe) ^ (uVar3 * 0x4000 | uVar17 >> 0x12) ^
            (uVar3 >> 9 | uVar17 * 0x800000));
    uStack_2c4 = (uint)(uStack_2c8 < uVar11) + uVar18 + iVar5;
    uVar7 = (uVar19 * 0x10 | uVar24 >> 0x1c) ^ (uVar19 >> 2 | uVar24 * 0x40000000) ^
            (uVar19 >> 7 | uVar24 * 0x2000000);
    uVar1 = uVar7 + ((uVar2 | uVar24) & uVar6 | uVar2 & uVar24);
    uStack_2f8 = uVar1 + uStack_2f8;
    uStack_2cc = (uint)(uStack_2f8 < uVar1) +
                 (uint)(uVar1 < uVar7) +
                 ((uVar24 * 0x10 | uVar19 >> 0x1c) ^ (uVar24 >> 2 | uVar19 * 0x40000000) ^
                 (uVar24 >> 7 | uVar19 * 0x2000000)) +
                 ((uVar23 | uVar19) & uVar22 | uVar23 & uVar19) + iVar5;
    uVar7 = puStack_320[10] + piStack_324[10];
    uVar10 = uVar7 + uVar10;
    uVar1 = uVar10 + ((uVar26 ^ uVar3) & uStack_2c8 ^ uVar26);
    uStack_308 = uVar1 + ((uStack_2c4 * 0x40000 | uStack_2c8 >> 0xe) ^
                          (uStack_2c4 * 0x4000 | uStack_2c8 >> 0x12) ^
                         (uStack_2c4 >> 9 | uStack_2c8 * 0x800000));
    uStack_304 = uVar6 + uStack_308;
    iVar5 = (uint)(uStack_308 < uVar1) +
            (uint)(uVar1 < uVar10) +
            (uint)(uVar10 < uVar7) +
            (uint)(uVar7 < puStack_320[10]) + puStack_320[0xb] + piStack_324[0xb] + uVar9 +
            ((uVar15 ^ uVar17) & uStack_2c4 ^ uVar15) +
            ((uStack_2c8 * 0x40000 | uStack_2c4 >> 0xe) ^ (uStack_2c8 * 0x4000 | uStack_2c4 >> 0x12)
            ^ (uStack_2c8 >> 9 | uStack_2c4 * 0x800000));
    uStack_300 = (uint)(uStack_304 < uVar6) + uVar22 + iVar5;
    uVar7 = (uStack_2cc * 0x10 | uStack_2f8 >> 0x1c) ^ (uStack_2cc >> 2 | uStack_2f8 * 0x40000000) ^
            (uStack_2cc >> 7 | uStack_2f8 * 0x2000000);
    uVar1 = uVar7 + ((uVar24 | uStack_2f8) & uVar2 | uVar24 & uStack_2f8);
    uStack_308 = uVar1 + uStack_308;
    uStack_2fc = (uint)(uStack_308 < uVar1) +
                 (uint)(uVar1 < uVar7) +
                 ((uStack_2f8 * 0x10 | uStack_2cc >> 0x1c) ^
                  (uStack_2f8 >> 2 | uStack_2cc * 0x40000000) ^
                 (uStack_2f8 >> 7 | uStack_2cc * 0x2000000)) +
                 ((uVar19 | uStack_2cc) & uVar23 | uVar19 & uStack_2cc) + iVar5;
    uVar7 = puStack_320[0xc] + piStack_324[0xc];
    uVar26 = uVar7 + uVar26;
    uVar1 = uVar26 + ((uVar3 ^ uStack_2c8) & uStack_304 ^ uVar3);
    uStack_31c = uVar1 + ((uStack_300 * 0x40000 | uStack_304 >> 0xe) ^
                          (uStack_300 * 0x4000 | uStack_304 >> 0x12) ^
                         (uStack_300 >> 9 | uStack_304 * 0x800000));
    uStack_310 = uVar2 + uStack_31c;
    iVar5 = (uint)(uStack_31c < uVar1) +
            (uint)(uVar1 < uVar26) +
            (uint)(uVar26 < uVar7) +
            (uint)(uVar7 < puStack_320[0xc]) + puStack_320[0xd] + piStack_324[0xd] + uVar15 +
            ((uVar17 ^ uStack_2c4) & uStack_300 ^ uVar17) +
            ((uStack_304 * 0x40000 | uStack_300 >> 0xe) ^ (uStack_304 * 0x4000 | uStack_300 >> 0x12)
            ^ (uStack_304 >> 9 | uStack_300 * 0x800000));
    uStack_30c = (uint)(uStack_310 < uVar2) + uVar23 + iVar5;
    uVar7 = (uStack_2fc * 0x10 | uStack_308 >> 0x1c) ^ (uStack_2fc >> 2 | uStack_308 * 0x40000000) ^
            (uStack_2fc >> 7 | uStack_308 * 0x2000000);
    uVar1 = uVar7 + ((uStack_2f8 | uStack_308) & uVar24 | uStack_2f8 & uStack_308);
    uStack_31c = uVar1 + uStack_31c;
    uStack_314 = (uint)(uStack_31c < uVar1) +
                 (uint)(uVar1 < uVar7) +
                 ((uStack_308 * 0x10 | uStack_2fc >> 0x1c) ^
                  (uStack_308 >> 2 | uStack_2fc * 0x40000000) ^
                 (uStack_308 >> 7 | uStack_2fc * 0x2000000)) +
                 ((uStack_2cc | uStack_2fc) & uVar19 | uStack_2cc & uStack_2fc) + iVar5;
    uVar1 = puStack_320[0xe] + piStack_324[0xe];
    uVar3 = uVar1 + uVar3;
    uVar9 = uVar3 + ((uStack_2c8 ^ uStack_304) & uStack_310 ^ uStack_2c8);
    uVar7 = uVar9 + ((uStack_30c * 0x40000 | uStack_310 >> 0xe) ^
                     (uStack_30c * 0x4000 | uStack_310 >> 0x12) ^
                    (uStack_30c >> 9 | uStack_310 * 0x800000));
    iVar5 = (uint)(uVar7 < uVar9) +
            (uint)(uVar9 < uVar3) +
            (uint)(uVar3 < uVar1) +
            (uint)(uVar1 < puStack_320[0xe]) + puStack_320[0xf] + piStack_324[0xf] + uVar17 +
            ((uStack_2c4 ^ uStack_300) & uStack_30c ^ uStack_2c4) +
            ((uStack_310 * 0x40000 | uStack_30c >> 0xe) ^ (uStack_310 * 0x4000 | uStack_30c >> 0x12)
            ^ (uStack_310 >> 9 | uStack_30c * 0x800000));
    uStack_340 = uVar24 + uVar7;
    uStack_33c = (uint)(uStack_340 < uVar24) + uVar19 + iVar5;
    uVar1 = (uStack_314 * 0x10 | uStack_31c >> 0x1c) ^ (uStack_314 >> 2 | uStack_31c * 0x40000000) ^
            (uStack_314 >> 7 | uStack_31c * 0x2000000);
    uVar9 = uVar1 + ((uStack_308 | uStack_31c) & uStack_2f8 | uStack_308 & uStack_31c);
    uVar7 = uVar9 + uVar7;
    uStack_350 = (uint)(uVar7 < uVar9) +
                 (uint)(uVar9 < uVar1) +
                 ((uStack_31c * 0x10 | uStack_314 >> 0x1c) ^
                  (uStack_31c >> 2 | uStack_314 * 0x40000000) ^
                 (uStack_31c >> 7 | uStack_314 * 0x2000000)) +
                 ((uStack_2fc | uStack_314) & uStack_2cc | uStack_2fc & uStack_314) + iVar5;
    puStack_320 = puStack_320 + 0x10;
    piStack_324 = piStack_324 + 0x10;
    iStack_2d4 = iStack_2d4 + -1;
  } while (iStack_2d4 != 0);
  *(uint *)(param_1 + 0x10) = uVar12 + uVar7;
  *(uint *)(param_1 + 0x14) =
       (uint)(uVar12 + uVar7 < uVar12) + *(uint *)(param_1 + 0x14) + uStack_350;
  *(uint *)(param_1 + 0x18) = uVar13 + uStack_31c;
  *(uint *)(param_1 + 0x1c) =
       (uint)(uVar13 + uStack_31c < uVar13) + *(uint *)(param_1 + 0x1c) + uStack_314;
  *(uint *)(param_1 + 0x24) =
       (uint)(uVar20 + uStack_308 < uVar20) + *(uint *)(param_1 + 0x24) + uStack_2fc;
  *(uint *)(param_1 + 0x20) = uVar20 + uStack_308;
  *(uint *)(param_1 + 0x28) = uVar25 + uStack_2f8;
  *(uint *)(param_1 + 0x2c) =
       (uint)(uVar25 + uStack_2f8 < uVar25) + *(uint *)(param_1 + 0x2c) + uStack_2cc;
  *(uint *)(param_1 + 0x34) =
       (uint)(uVar8 + uStack_340 < uVar8) + *(uint *)(param_1 + 0x34) + uStack_33c;
  *(uint *)(param_1 + 0x30) = uVar8 + uStack_340;
  *(uint *)(param_1 + 0x3c) =
       (uint)(uVar4 + uStack_310 < uVar4) + *(uint *)(param_1 + 0x3c) + uStack_30c;
  *(uint *)(param_1 + 0x38) = uVar4 + uStack_310;
  *(uint *)(param_1 + 0x44) =
       (uint)(uVar14 + uStack_304 < uVar14) + *(uint *)(param_1 + 0x44) + uStack_300;
  *(uint *)(param_1 + 0x40) = uVar14 + uStack_304;
  *(uint *)(param_1 + 0x48) = uVar21 + uStack_2c8;
  *(uint *)(param_1 + 0x4c) =
       (uint)(uVar21 + uStack_2c8 < uVar21) + *(uint *)(param_1 + 0x4c) + uStack_2c4;
  memw();
  return;
}

