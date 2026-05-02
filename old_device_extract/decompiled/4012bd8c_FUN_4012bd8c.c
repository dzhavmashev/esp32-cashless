// Function : FUN_4012bd8c
// Address  : 0x4012bd8c
// Size     : 1130 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4012bd8c(int *param_1)

{
  char cVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  uint *puVar8;
  undefined1 *puVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  undefined1 *puVar13;
  code *pcVar14;
  uint *puVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  undefined4 uVar23;
  char *pcVar24;
  undefined1 *puStack_150;
  undefined1 *puStack_14c;
  undefined4 uStack_128;
  undefined1 auStack_124 [32];
  undefined1 auStack_104 [224];
  int *piStack_24;
  
  memw();
  piVar7 = (int *)param_1[5];
  memw();
  piStack_24 = _DAT_3ffc5708;
  iVar2 = param_1[0x11];
  if ((int)piVar7 < 3) {
    *(undefined4 *)(iVar2 + 0x24) = 0x4012b730;
    *(undefined **)(iVar2 + 0x1c) = &DAT_4012bc58;
    puVar9 = (undefined1 *)0x4012bba0;
    goto LAB_4012bdb7;
  }
  do {
    if ((*(int *)(*(int *)(iVar2 + 0x14) + 0xc) == 7) && (piVar7 == (int *)0x3)) {
      *(undefined1 **)(iVar2 + 0x24) = &LAB_4012b70b_1;
      *(code **)(iVar2 + 0x1c) = FUN_4012bb50;
      puVar9 = &LAB_4012bacc;
      memw();
LAB_4012bdb7:
      *(undefined1 **)(iVar2 + 0x20) = puVar9;
      uStack_128 = 0x40;
      iVar11 = param_1[0x10];
      if (*(char *)(iVar2 + 2) == '\0') {
        if (*(char *)(iVar2 + 6) == '\x01') {
          (**(code **)(iVar2 + 0x1c))(param_1,auStack_124,&uStack_128);
          puVar9 = auStack_124;
          pcVar24 = "inished";
        }
        else {
          puVar9 = (undefined1 *)(iVar2 + 0x470);
          pcVar24 = "xtended master secret";
        }
        memw();
        iVar11 = (**(code **)(iVar2 + 0x24))
                           (iVar2 + 0x4b0,*(undefined4 *)(iVar2 + 0x10),pcVar24,puVar9,uStack_128,
                            iVar11 + 0x34,0x30);
        if (iVar11 != 0) goto LAB_4012be84;
        FUN_4013ae54(iVar2 + 0x4b0,0x424);
      }
      iVar2 = param_1[0x11];
      (*(code *)&SUB_4008b3d0)(auStack_124,iVar2 + 0x470,0x40);
      (*(code *)&SUB_4008b3d0)(iVar2 + 0x470,auStack_104);
      (*(code *)&SUB_4008b3d0)(param_1[0x11] + 0x490,auStack_124,0x20);
      FUN_4013ae54(auStack_124,0x40);
      iVar2 = param_1[0x10];
      iVar17 = iVar2 + 0x34;
      iVar19 = param_1[0x11];
      uVar23 = *(undefined4 *)(iVar2 + 8);
      uVar16 = *(uint *)(iVar2 + 0x7c);
      iVar2 = *(int *)(iVar2 + 0x78);
      pcVar3 = *(code **)(iVar19 + 0x24);
      puVar8 = (uint *)param_1[0x15];
      uVar10 = param_1[5];
      cVar1 = *(char *)(*param_1 + 4);
      puVar8[0x13] = uVar16;
      puVar8[0x34] = uVar10;
      memw();
      iVar4 = FUN_4012d7a8(uVar23);
      if (((iVar4 == 0) || (iVar5 = FUN_40132c44(*(undefined4 *)(iVar4 + 8)), iVar5 == 0)) ||
         (iVar6 = FUN_40138f28(*(undefined4 *)(iVar4 + 0xc)), iVar6 == 0)) {
        iVar11 = -0x7100;
      }
      else {
        memw();
        iVar11 = (*pcVar3)(iVar17,0x30,"on",iVar19 + 0x470,0x40,auStack_124,0x100);
        if (iVar11 == 0) {
          uVar20 = *(uint *)(iVar5 + 8);
          uVar21 = *(uint *)(iVar5 + 4);
          if (((uVar21 & 0xfffffffd) == 8) || (uVar21 == 6)) {
            uVar18 = 0;
            puVar8[3] = 0;
            uVar16 = 0x10;
            if ((*(byte *)(iVar4 + 0x24) >> 1 & 1) != 0) {
              uVar16 = 8;
            }
            puVar8[4] = uVar16;
            uVar12 = 0xc;
            puVar8[1] = 0xc;
            if (uVar21 != 10) {
              uVar12 = 4;
            }
            uVar21 = (uVar16 + 0xc) - uVar12;
            puVar8[2] = uVar12;
LAB_4012bf7c:
            *puVar8 = uVar21;
            goto LAB_4012bf7e;
          }
          if ((uVar21 != 7) && (iVar11 = -0x6c00, uVar21 != 2)) goto LAB_4012be84;
          iVar11 = FUN_4013905c(puVar8 + 0xd,iVar6,1);
          if ((iVar11 == 0) && (iVar11 = FUN_4013905c(puVar8 + 0x10,iVar6,1), iVar11 == 0)) {
            uVar18 = FUN_401864c4(iVar6);
            if (iVar2 == 1) {
              puVar8[3] = 10;
              memw();
            }
            else {
              puVar8[3] = uVar18;
            }
            uVar12 = *(uint *)(iVar5 + 0x10);
            iVar2 = *(int *)(iVar5 + 4);
            puVar8[1] = uVar12;
            uVar21 = puVar8[3];
            if (iVar2 == 7) goto LAB_4012bf7c;
            uVar22 = uVar21 + *(uint *)(iVar5 + 0x18);
            if (uVar16 != 1) {
              uVar22 = uVar22 - uVar21 % *(uint *)(iVar5 + 0x18);
            }
            *puVar8 = uVar22;
            if (uVar10 < 2) {
LAB_4012bf7e:
              uVar20 = uVar20 >> 3;
              if (cVar1 == '\0') {
                puStack_14c = auStack_124 + uVar18 * 2;
                puStack_150 = auStack_124 + uVar20 + uVar18 * 2;
                puVar13 = auStack_124 + uVar18;
                uVar16 = puVar8[2];
                if (uVar16 == 0) {
                  uVar16 = puVar8[1];
                }
                memw();
                (*(code *)&SUB_4008b3d0)(puVar8 + 5,puStack_150 + uVar20,uVar16);
                (*(code *)&SUB_4008b3d0)(puVar8 + 9,puStack_150 + uVar20 + uVar16,uVar16);
                puVar9 = auStack_124;
              }
              else {
                if (cVar1 != '\x01') goto LAB_4012c10d;
                puStack_14c = auStack_124 + uVar20 + uVar18 * 2;
                puStack_150 = auStack_124 + uVar18 * 2;
                puVar9 = auStack_124 + uVar18;
                uVar16 = puVar8[2];
                if (uVar16 == 0) {
                  uVar16 = puVar8[1];
                }
                memw();
                (*(code *)&SUB_4008b3d0)(puVar8 + 9,puStack_14c + uVar20,uVar16);
                (*(code *)&SUB_4008b3d0)(puVar8 + 5,puStack_14c + uVar20 + uVar16,uVar16);
                puVar13 = auStack_124;
              }
              if (0 < (int)uVar10) {
                if (uVar18 != 0) {
                  memw();
                  iVar11 = FUN_40139270(puVar8 + 0xd,puVar9,uVar18);
                  if ((iVar11 != 0) ||
                     (iVar11 = FUN_40139270(puVar8 + 0x10,puVar13,uVar18), iVar11 != 0))
                  goto LAB_4012c110;
                }
                pcVar14 = *(code **)(*param_1 + 0x90);
                if (pcVar14 != (code *)0x0) {
                  memw();
                  (*pcVar14)(*(undefined4 *)(*param_1 + 0x98),iVar17,auStack_124,uVar18,uVar20,
                             uVar16);
                }
                pcVar14 = *(code **)(*param_1 + 0x94);
                if (pcVar14 != (code *)0x0) {
                  uVar23 = 2;
                  if (((pcVar3 != (code *)0x4012b730) &&
                      (uVar23 = 3, pcVar3 != (code *)&LAB_4012b70b_1)) &&
                     (uVar23 = 0, pcVar3 == FUN_4012b6e8)) {
                    uVar23 = 4;
                  }
                  memw();
                  (*pcVar14)(*(undefined4 *)(*param_1 + 0x98),iVar17,auStack_124,uVar18,uVar20,
                             uVar16,iVar19 + 0x490,iVar19 + 0x470,uVar23);
                }
                puVar15 = puVar8 + 0x14;
                iVar11 = FUN_40133068(puVar15,iVar5);
                if (iVar11 == 0) {
                  puVar8 = puVar8 + 0x24;
                  iVar11 = FUN_40133068(puVar8,iVar5);
                  if (((iVar11 == 0) &&
                      (iVar11 = FUN_40132cb4(puVar15,puStack_14c,*(undefined4 *)(iVar5 + 8),1),
                      iVar11 == 0)) &&
                     ((iVar11 = FUN_40132cb4(puVar8,puStack_150,*(undefined4 *)(iVar5 + 8)),
                      iVar11 == 0 &&
                      ((*(int *)(iVar5 + 4) == 2 && (iVar11 = FUN_40132fe8(puVar15,4), iVar11 == 0))
                      )))) {
                    iVar11 = FUN_40132fe8(puVar8,4);
                  }
                }
                goto LAB_4012c110;
              }
            }
            else if (uVar10 - 2 < 2) {
              *puVar8 = uVar12 + uVar22;
              memw();
              goto LAB_4012bf7e;
            }
LAB_4012c10d:
            iVar11 = -0x6c00;
          }
LAB_4012c110:
          memw();
          FUN_4013ae54(auStack_124,0x100);
          if (iVar11 == 0) {
            FUN_4013ae54(param_1[0x11] + 0x470,0x40);
          }
        }
      }
    }
    else {
      iVar11 = -0x6c00;
      if (piVar7 == (int *)0x3) {
        *(code **)(iVar2 + 0x24) = FUN_4012b6e8;
        *(undefined **)(iVar2 + 0x1c) = &DAT_4012ba7c;
        puVar9 = (undefined1 *)0x4012b9f8;
        memw();
        goto LAB_4012bdb7;
      }
    }
LAB_4012be84:
    iVar2 = iVar11;
    param_1 = piStack_24;
    piVar7 = _DAT_3ffc5708;
    memw();
    memw();
    if (piStack_24 == _DAT_3ffc5708) {
      return;
    }
    (*(code *)&SUB_40082ec4)();
  } while( true );
}

