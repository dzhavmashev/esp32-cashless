// Function : FUN_40172c48
// Address  : 0x40172c48
// Size     : 2643 bytes


undefined8 FUN_40172c48(int param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_a3;
  undefined4 uVar3;
  int iVar4;
  undefined4 extraout_a3_00;
  undefined4 extraout_a3_01;
  undefined4 extraout_a3_02;
  undefined4 extraout_a3_03;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  ulonglong uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  longlong lVar22;
  int iStack_68;
  uint uStack_64;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  
  uVar16 = CONCAT44(param_2,param_1);
  uVar9 = param_4 & 0x7fffffff;
  iVar13 = 0;
  uVar14 = 0x3ff00000;
  if (uVar9 == 0 && param_3 == 0) goto LAB_401736a4;
  uVar5 = param_2 & 0x7fffffff;
  if (uVar5 < 0x7ff00001) {
    if ((uVar5 != 0x7ff00000) || (param_1 == 0)) {
      if ((0x7ff00000 < uVar9) || ((uVar9 == 0x7ff00000 && (param_3 != 0)))) goto LAB_40172c95;
      iVar8 = 0;
      if ((int)param_2 < 0) {
        if (0x433fffff < uVar9) {
          iVar8 = 2;
          goto LAB_40172d18;
        }
        if (uVar9 < 0x3ff00000) goto LAB_40172d18;
        iVar13 = ((int)uVar9 >> 0x14) + -0x3ff;
        if (0x14 < iVar13) {
          uVar14 = param_3 >> (0x34U - iVar13 & 0x1f);
          if (uVar14 << 0x20 - (0x20 - (0x34U - iVar13 & 0x1f)) == param_3) {
            iVar8 = 2 - (uVar14 & 1);
          }
          goto LAB_40172d18;
        }
        if (param_3 == 0) {
          uVar14 = (int)uVar9 >> (0x14U - iVar13 & 0x1f);
          if (uVar14 << 0x20 - (0x20 - (0x14U - iVar13 & 0x1f)) == uVar9) {
            iVar8 = 2 - (uVar14 & 1);
          }
          goto LAB_40172d5d;
        }
LAB_40172dac:
        uVar17 = FUN_40173814(param_1,param_2);
        uVar2 = (undefined4)((ulonglong)uVar17 >> 0x20);
        uVar12 = (undefined4)uVar17;
        uVar18 = CONCAT44(param_2,uVar12) & 0x7fffffffffffffff;
        if ((param_1 == 0) && (((param_2 & 0x3fffffff) == 0x3ff00000 || (uVar5 == 0)))) {
          if ((int)param_4 < 0) {
            uVar17 = (*(code *)&SUB_40002954)(0,0x3ff00000,uVar12,uVar2);
          }
          uVar14 = (uint)((ulonglong)uVar17 >> 0x20);
          iVar13 = (int)uVar17;
          if (-1 < (int)param_2) goto LAB_401736a4;
          if (uVar5 != 0x3ff00000 || iVar8 != 0) {
            if (iVar8 == 1) {
              uVar14 = uVar14 ^ 0x80000000;
            }
            goto LAB_401736a4;
          }
        }
        else {
          uVar17 = uVar16;
          if (iVar8 != 0 || -1 < (int)param_2) {
            if (uVar9 < 0x41e00001) {
              iVar13 = 0;
              if ((param_2 & 0x7ff00000) == 0) {
                uVar18 = (*(code *)&SUB_4006358c)(uVar12,uVar2,0,0x43400000);
                iVar13 = -0x35;
              }
              uVar14 = (uint)(uVar18 >> 0x20);
              uVar12 = (undefined4)uVar18;
              iVar13 = ((int)uVar14 >> 0x14) + -0x3ff + iVar13;
              uVar14 = uVar14 & 0xfffff;
              uVar9 = uVar14 | 0x3ff00000;
              iVar15 = 0;
              if ((0x3988e < uVar14) && (iVar15 = 1, 0xbb679 < uVar14)) {
                iVar13 = iVar13 + 1;
                uVar9 = uVar9 - 0x100000;
                iVar15 = 0;
              }
              iVar1 = iVar15 * 8;
              uVar6 = *(undefined4 *)(&DAT_3f425068 + iVar1);
              uVar7 = *(undefined4 *)(&DAT_3f42506c + iVar1);
              uVar16 = (*(code *)&SUB_400026e4)(uVar12,uVar9,uVar6,uVar7);
              uVar10 = (undefined4)((ulonglong)uVar16 >> 0x20);
              uVar17 = (*(code *)&SUB_40002590)(uVar6,uVar7,uVar12,uVar9);
              uVar17 = (*(code *)&SUB_40002954)
                                 (0,0x3ff00000,(int)uVar17,(int)((ulonglong)uVar17 >> 0x20));
              uVar11 = (undefined4)((ulonglong)uVar17 >> 0x20);
              uVar19 = (*(code *)&SUB_4006358c)((int)uVar16,uVar10,(int)uVar17,uVar11);
              uVar3 = (undefined4)((ulonglong)uVar19 >> 0x20);
              uVar2 = (undefined4)uVar19;
              iVar4 = ((int)uVar9 >> 1 | 0x20000000U) + 0x80000 + iVar15 * 0x40000;
              uVar19 = (*(code *)&SUB_4006358c)(0,uVar3,0,iVar4);
              uVar16 = (*(code *)&SUB_400026e4)
                                 ((int)uVar16,uVar10,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
              uVar19 = (*(code *)&SUB_400026e4)(0,iVar4,uVar6,uVar7);
              uVar19 = (*(code *)&SUB_400026e4)
                                 (uVar12,uVar9,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
              uVar19 = (*(code *)&SUB_4006358c)
                                 ((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),0,uVar3);
              uVar16 = (*(code *)&SUB_400026e4)
                                 ((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(int)uVar19,
                                  (int)((ulonglong)uVar19 >> 0x20));
              uVar16 = (*(code *)&SUB_4006358c)
                                 ((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(int)uVar17,uVar11);
              uVar10 = (undefined4)((ulonglong)uVar16 >> 0x20);
              uVar17 = (*(code *)&SUB_4006358c)(uVar2,uVar3);
              uVar11 = (undefined4)((ulonglong)uVar17 >> 0x20);
              uVar12 = (undefined4)uVar17;
              uVar17 = (*(code *)&SUB_4006358c)(uVar12,uVar11,0x4a454eef,0x3fca7e28);
              uVar17 = (*(code *)&SUB_40002590)
                                 ((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),0x93c9db65,0x3fcd864a
                                 );
              uVar17 = (*(code *)&SUB_4006358c)
                                 ((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar12,uVar11);
              uVar17 = (*(code *)&SUB_40002590)
                                 ((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),0xa91d4101,0x3fd17460
                                 );
              uVar17 = (*(code *)&SUB_4006358c)
                                 ((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar12,uVar11);
              uVar17 = (*(code *)&SUB_40002590)
                                 ((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),0x518f264d,0x3fd55555
                                 );
              uVar17 = (*(code *)&SUB_4006358c)
                                 ((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar12,uVar11);
              uVar17 = (*(code *)&SUB_40002590)
                                 ((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),0xdb6fabff,0x3fdb6db6
                                 );
              uVar17 = (*(code *)&SUB_4006358c)
                                 ((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar12,uVar11);
              uVar17 = (*(code *)&SUB_40002590)
                                 ((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),0x33333303,0x3fe33333
                                 );
              uVar19 = (*(code *)&SUB_4006358c)(uVar12,uVar11,uVar12,uVar11);
              uVar17 = (*(code *)&SUB_4006358c)
                                 ((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar19,
                                  (int)((ulonglong)uVar19 >> 0x20));
              uVar19 = (*(code *)&SUB_40002590)(uVar2,uVar3,0,uVar3);
              uVar19 = (*(code *)&SUB_4006358c)
                                 ((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar16,uVar10);
              uVar17 = (*(code *)&SUB_40002590)
                                 ((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar17,
                                  (int)((ulonglong)uVar17 >> 0x20));
              uVar12 = (undefined4)((ulonglong)uVar17 >> 0x20);
              uVar19 = (*(code *)&SUB_4006358c)(0,uVar3);
              uVar11 = (undefined4)((ulonglong)uVar19 >> 0x20);
              uVar20 = (*(code *)&SUB_40002590)((int)uVar19,uVar11,0,0x40080000);
              (*(code *)&SUB_40002590)
                        ((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),(int)uVar17,uVar12);
              uVar20 = (*(code *)&SUB_4006358c)(0,uVar3,0,extraout_a3_00);
              uVar6 = (undefined4)((ulonglong)uVar20 >> 0x20);
              uVar21 = (*(code *)&SUB_400026e4)(0,extraout_a3_00,0,0x40080000);
              uVar19 = (*(code *)&SUB_400026e4)
                                 ((int)uVar21,(int)((ulonglong)uVar21 >> 0x20),(int)uVar19,uVar11);
              uVar17 = (*(code *)&SUB_400026e4)
                                 ((int)uVar17,uVar12,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
              uVar17 = (*(code *)&SUB_4006358c)
                                 ((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar2,uVar3);
              uVar16 = (*(code *)&SUB_4006358c)((int)uVar16,uVar10,0,extraout_a3_00);
              uVar16 = (*(code *)&SUB_40002590)
                                 ((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar16,
                                  (int)((ulonglong)uVar16 >> 0x20));
              uVar12 = (undefined4)((ulonglong)uVar16 >> 0x20);
              (*(code *)&SUB_40002590)((int)uVar20,uVar6,(int)uVar16,uVar12);
              uVar17 = (*(code *)&SUB_4006358c)(0,extraout_a3_01,0xe0000000,0x3feec709);
              uVar2 = (undefined4)((ulonglong)uVar17 >> 0x20);
              uVar19 = (*(code *)&SUB_400026e4)(0,extraout_a3_01,(int)uVar20,uVar6);
              uVar16 = (*(code *)&SUB_400026e4)
                                 ((int)uVar16,uVar12,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
              uVar16 = (*(code *)&SUB_4006358c)
                                 ((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),0xdc3a03fd,0x3feec709
                                 );
              uVar19 = (*(code *)&SUB_4006358c)(0,extraout_a3_01,0x145b01f5,0xbe3e2fe0);
              uVar16 = (*(code *)&SUB_40002590)
                                 ((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(int)uVar19,
                                  (int)((ulonglong)uVar19 >> 0x20));
              uVar16 = (*(code *)&SUB_40002590)
                                 ((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),
                                  *(undefined4 *)(&DAT_3f425048 + iVar1),
                                  (&PTR_FUN_3f42504c)[iVar15 * 2]);
              uVar19 = (*(code *)&SUB_4000c944)(iVar13);
              uVar12 = (undefined4)((ulonglong)uVar19 >> 0x20);
              uVar10 = *(undefined4 *)(&DAT_3f425058 + iVar1);
              uVar11 = *(undefined4 *)(&DAT_3f42505c + iVar1);
              uVar20 = (*(code *)&SUB_40002590)
                                 ((int)uVar17,uVar2,(int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
              uVar20 = (*(code *)&SUB_40002590)
                                 ((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),uVar10,uVar11);
              (*(code *)&SUB_40002590)
                        ((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),(int)uVar19,uVar12);
              uVar19 = (*(code *)&SUB_400026e4)(0,extraout_a3_02,(int)uVar19,uVar12);
              uVar19 = (*(code *)&SUB_400026e4)
                                 ((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),uVar10,uVar11);
              uVar17 = (*(code *)&SUB_400026e4)
                                 ((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar17,uVar2);
              uStack_5c = extraout_a3_02;
LAB_40173317:
              uVar16 = (*(code *)&SUB_400026e4)
                                 ((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(int)uVar17,
                                  (int)((ulonglong)uVar17 >> 0x20));
              uStack_64 = 0x3ff00000;
              if (iVar8 == 1 && (int)param_2 < 0) {
                uStack_64 = 0xbff00000;
              }
              iStack_68 = 0;
              uVar17 = (*(code *)&SUB_400026e4)(param_3,param_4,0,param_4);
              uVar17 = (*(code *)&SUB_4006358c)
                                 ((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),0,uStack_5c);
              uVar16 = (*(code *)&SUB_4006358c)
                                 ((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),param_3,param_4);
              uVar16 = (*(code *)&SUB_40002590)
                                 ((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar16,
                                  (int)((ulonglong)uVar16 >> 0x20));
              uVar10 = (undefined4)((ulonglong)uVar16 >> 0x20);
              uVar12 = (undefined4)uVar16;
              uVar16 = (*(code *)&SUB_4006358c)(0,uStack_5c,0,param_4);
              uVar11 = (undefined4)((ulonglong)uVar16 >> 0x20);
              uVar2 = (undefined4)uVar16;
              lVar22 = (*(code *)&SUB_40002590)(uVar12,uVar10,uVar2,uVar11);
              uVar14 = (uint)((ulonglong)lVar22 >> 0x20);
              if (lVar22 < 0x4090000000000000) {
                if ((uVar14 & 0x7fffffff) < 0x4090cc00) {
LAB_40173465:
                  iVar13 = 0;
                  if (0x3fe00000 < (uVar14 & 0x7fffffff)) {
                    uVar14 = (0x100000 >> (((int)(uVar14 & 0x7fffffff) >> 0x14) + 2U & 0x1f)) +
                             uVar14;
                    uVar9 = (uVar14 >> 0x14 & 0x7ff) - 0x3ff;
                    iVar13 = (int)(uVar14 & 0xfffff | 0x100000) >> (0x14 - uVar9 & 0x1f);
                    if (lVar22 < 0) {
                      iVar13 = -iVar13;
                    }
                    uVar16 = (*(code *)&SUB_400026e4)
                                       (uVar2,uVar11,0,
                                        (0xfffff >> (uVar9 & 0x1f) ^ 0xffffffffU) & uVar14);
                  }
                  uStack_54 = (undefined4)((ulonglong)uVar16 >> 0x20);
                  uStack_58 = (undefined4)uVar16;
                  (*(code *)&SUB_40002590)(uStack_58,uStack_54,uVar12,uVar10);
                  uVar16 = (*(code *)&SUB_4006358c)(0,extraout_a3_03,0,0x3fe62e43);
                  uVar2 = (undefined4)((ulonglong)uVar16 >> 0x20);
                  uVar17 = (*(code *)&SUB_400026e4)(0,extraout_a3_03,uStack_58,uStack_54);
                  uVar17 = (*(code *)&SUB_400026e4)
                                     (uVar12,uVar10,(int)uVar17,(int)((ulonglong)uVar17 >> 0x20));
                  uVar17 = (*(code *)&SUB_4006358c)
                                     ((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),0xfefa39ef,
                                      0x3fe62e42);
                  uVar19 = (*(code *)&SUB_4006358c)(0,extraout_a3_03,0xca86c39,0xbe205c61);
                  uVar17 = (*(code *)&SUB_40002590)
                                     ((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar19,
                                      (int)((ulonglong)uVar19 >> 0x20));
                  uVar10 = (undefined4)((ulonglong)uVar17 >> 0x20);
                  uVar19 = (*(code *)&SUB_40002590)((int)uVar16,uVar2,(int)uVar17,uVar10);
                  uVar11 = (undefined4)((ulonglong)uVar19 >> 0x20);
                  uVar12 = (undefined4)uVar19;
                  uVar16 = (*(code *)&SUB_400026e4)(uVar12,uVar11,(int)uVar16,uVar2);
                  uVar16 = (*(code *)&SUB_400026e4)
                                     ((int)uVar17,uVar10,(int)uVar16,
                                      (int)((ulonglong)uVar16 >> 0x20));
                  uVar10 = (undefined4)((ulonglong)uVar16 >> 0x20);
                  uVar17 = (*(code *)&SUB_4006358c)(uVar12,uVar11,uVar12,uVar11);
                  uVar3 = (undefined4)((ulonglong)uVar17 >> 0x20);
                  uVar2 = (undefined4)uVar17;
                  uVar17 = (*(code *)&SUB_4006358c)(uVar2,uVar3,0x72bea4d0,0x3e663769);
                  uVar17 = (*(code *)&SUB_400026e4)
                                     ((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),0xc5d26bf1,
                                      0x3ebbbd41);
                  uVar17 = (*(code *)&SUB_4006358c)
                                     ((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar2,uVar3);
                  uVar17 = (*(code *)&SUB_40002590)
                                     ((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),0xaf25de2c,
                                      0x3f11566a);
                  uVar17 = (*(code *)&SUB_4006358c)
                                     ((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar2,uVar3);
                  uVar17 = (*(code *)&SUB_400026e4)
                                     ((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),0x16bebd93,
                                      0x3f66c16c);
                  uVar17 = (*(code *)&SUB_4006358c)
                                     ((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar2,uVar3);
                  uVar17 = (*(code *)&SUB_40002590)
                                     ((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),0x5555553e,
                                      0x3fc55555);
                  uVar17 = (*(code *)&SUB_4006358c)
                                     ((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar2,uVar3);
                  uVar17 = (*(code *)&SUB_400026e4)
                                     (uVar12,uVar11,(int)uVar17,(int)((ulonglong)uVar17 >> 0x20));
                  uVar2 = (undefined4)((ulonglong)uVar17 >> 0x20);
                  uVar19 = (*(code *)&SUB_4006358c)(uVar12,uVar11,(int)uVar17,uVar2);
                  uVar17 = (*(code *)&SUB_400026e4)((int)uVar17,uVar2,0,0x40000000);
                  uVar17 = (*(code *)&SUB_40002954)
                                     ((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar17,
                                      (int)((ulonglong)uVar17 >> 0x20));
                  uVar19 = (*(code *)&SUB_4006358c)(uVar12,uVar11,(int)uVar16,uVar10);
                  uVar16 = (*(code *)&SUB_40002590)
                                     ((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar16,
                                      uVar10);
                  uVar16 = (*(code *)&SUB_400026e4)
                                     ((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar16,
                                      (int)((ulonglong)uVar16 >> 0x20));
                  uVar16 = (*(code *)&SUB_400026e4)
                                     ((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar12,uVar11);
                  uVar17 = (*(code *)&SUB_400026e4)
                                     (0,0x3ff00000,(int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
                  iVar15 = (int)((ulonglong)uVar17 >> 0x20);
                  iVar8 = iVar13 * 0x100000 + iVar15;
                  uVar16 = CONCAT44(iVar8,(int)uVar17);
                  param_1 = iStack_68;
                  param_2 = uStack_64;
                  if (iVar8 >> 0x14 < 1) {
                    uVar16 = FUN_401739a0((int)uVar17,iVar15,iVar13);
                  }
                }
                else {
                  if (lVar22 == -0x3f6f340000000000) {
                    uVar17 = (*(code *)&SUB_400026e4)(0,0xc090cc00,uVar2,uVar11);
                    iVar13 = (*(code *)&SUB_40063768)
                                       ((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar12,uVar10);
                    if (iVar13 < 0) goto LAB_40173465;
                  }
                  uVar16 = (*(code *)&SUB_4006358c)(0,uStack_64,0xc2f8f359,0x1a56e1f);
                  param_1 = -0x3d070ca7;
                  param_2 = 0x1a56e1f;
                }
              }
              else {
                if (lVar22 == 0x4090000000000000) {
                  uVar17 = (*(code *)&SUB_40002590)(uVar12,uVar10,0x652b82fe,0x3c971547);
                  uVar19 = (*(code *)&SUB_400026e4)(0,0x40900000,uVar2,uVar11);
                  iVar13 = (*(code *)&SUB_400636dc)
                                     ((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar19,
                                      (int)((ulonglong)uVar19 >> 0x20));
                  if (iVar13 < 1) goto LAB_40173465;
                }
                uVar16 = (*(code *)&SUB_4006358c)(0,uStack_64,0x8800759c,0x7e37e43c);
                param_1 = -0x77ff8a64;
                param_2 = 0x7e37e43c;
              }
            }
            else {
              if (uVar9 < 0x43f00001) {
                if (0x3feffffe < uVar5) {
                  if (0x3ff00000 < uVar5) goto LAB_40172e82;
                  uVar16 = (*(code *)&SUB_400026e4)(uVar12,uVar2,0,0x3ff00000);
                  uVar2 = (undefined4)((ulonglong)uVar16 >> 0x20);
                  uVar12 = (undefined4)uVar16;
                  uVar17 = (*(code *)&SUB_4006358c)(uVar12,uVar2,0x60000000,0x3ff71547);
                  uVar10 = (undefined4)((ulonglong)uVar17 >> 0x20);
                  uVar16 = (*(code *)&SUB_4006358c)(uVar12,uVar2,0xf85ddf44,0x3e54ae0b);
                  uVar19 = (*(code *)&SUB_4006358c)(uVar12,uVar2,0,0x3fd00000);
                  uVar19 = (*(code *)&SUB_400026e4)
                                     (0x55555555,0x3fd55555,(int)uVar19,
                                      (int)((ulonglong)uVar19 >> 0x20));
                  uVar19 = (*(code *)&SUB_4006358c)
                                     ((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),uVar12,uVar2);
                  uVar19 = (*(code *)&SUB_400026e4)
                                     (0,0x3fe00000,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
                  uVar20 = (*(code *)&SUB_4006358c)(uVar12,uVar2,uVar12,uVar2);
                  uVar19 = (*(code *)&SUB_4006358c)
                                     ((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar20,
                                      (int)((ulonglong)uVar20 >> 0x20));
                  uVar19 = (*(code *)&SUB_4006358c)
                                     ((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),0x652b82fe,
                                      0x3ff71547);
                  uVar16 = (*(code *)&SUB_400026e4)
                                     ((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(int)uVar19,
                                      (int)((ulonglong)uVar19 >> 0x20));
                  (*(code *)&SUB_40002590)
                            ((int)uVar17,uVar10,(int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
                  uVar17 = (*(code *)&SUB_400026e4)(0,extraout_a3,(int)uVar17,uVar10);
                  uStack_5c = extraout_a3;
                  goto LAB_40173317;
                }
LAB_40172e61:
                if (-1 < (int)param_4) goto LAB_40172d44;
              }
              else {
                if (uVar5 < 0x3ff00000) goto LAB_40172e61;
LAB_40172e82:
                if ((int)param_4 < 1) goto LAB_40172d44;
              }
              param_1 = -0x77ff8a64;
              param_2 = 0x7e37e43c;
              uVar16 = 0x7e37e43c8800759c;
            }
LAB_4017369e:
            uVar16 = (*(code *)&SUB_4006358c)
                               ((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),param_1,param_2);
            iVar13 = (int)uVar16;
            uVar14 = (uint)((ulonglong)uVar16 >> 0x20);
            goto LAB_401736a4;
          }
        }
        uVar12 = (undefined4)((ulonglong)uVar17 >> 0x20);
        uVar17 = (*(code *)&SUB_400026e4)((int)uVar17,uVar12,(int)uVar17,uVar12);
        uVar16 = uVar17;
      }
      else {
LAB_40172d18:
        if (param_3 != 0) goto LAB_40172dac;
        if (uVar9 == 0x7ff00000) {
          iVar13 = 0;
          uVar14 = 0x3ff00000;
          if (uVar5 == 0x3ff00000 && param_1 == 0) goto LAB_401736a4;
          iVar13 = 0;
          if (uVar5 < 0x3ff00000) {
            if ((int)param_4 < 0) {
              uVar14 = param_4 ^ 0x80000000;
              goto LAB_401736a4;
            }
          }
          else {
            uVar14 = param_4;
            if (-1 < (int)param_4) goto LAB_401736a4;
          }
LAB_40172d44:
          iVar13 = 0;
          uVar14 = 0;
          goto LAB_401736a4;
        }
LAB_40172d5d:
        if (uVar9 != 0x3ff00000) {
          if (param_4 != 0x40000000) {
            if ((param_4 == 0x3fe00000) && ((int)(param_2 ^ 0xffffffff) < 0)) {
              uVar16 = FUN_401736ac(param_1,param_2);
              iVar13 = (int)uVar16;
              uVar14 = (uint)((ulonglong)uVar16 >> 0x20);
              goto LAB_401736a4;
            }
            goto LAB_40172dac;
          }
          goto LAB_4017369e;
        }
        iVar13 = param_1;
        uVar14 = param_2;
        if (-1 < (int)param_4) goto LAB_401736a4;
        uVar17 = 0x3ff0000000000000;
      }
      uVar16 = (*(code *)&SUB_40002954)
                         ((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar16,
                          (int)((ulonglong)uVar16 >> 0x20));
      iVar13 = (int)uVar16;
      uVar14 = (uint)((ulonglong)uVar16 >> 0x20);
      goto LAB_401736a4;
    }
  }
  else {
LAB_40172c95:
    iVar13 = 0;
    uVar14 = 0x3ff00000;
    if (param_2 == 0x3ff00000 && param_1 == 0) goto LAB_401736a4;
  }
  uVar16 = FUN_4017383c(&DAT_3f42161d);
  iVar13 = (int)uVar16;
  uVar14 = (uint)((ulonglong)uVar16 >> 0x20);
LAB_401736a4:
  return CONCAT44(uVar14,iVar13);
}

