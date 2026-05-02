// Function : FUN_4012d208
// Address  : 0x4012d208
// Size     : 862 bytes


undefined1 * FUN_4012d208(int *param_1)

{
  bool bVar1;
  uint uVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  code *pcVar5;
  char cVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  uint uVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  undefined4 uVar17;
  int iVar18;
  undefined4 uStack_28;
  undefined4 *puStack_24;
  
  cVar6 = *(char *)(param_1[0x11] + 4);
  if (cVar6 == '\x03') {
    cVar6 = *(char *)(*param_1 + 6);
  }
  uVar2 = *(uint *)(*(int *)(param_1[0x11] + 0x14) + 0x10);
  if (uVar2 == 7) {
LAB_4012d228:
    if (*(char *)(*param_1 + 4) != '\x01') {
LAB_4012d264:
      puVar3 = (undefined1 *)FUN_4012a960(param_1,1);
      if (puVar3 != (undefined1 *)0x0) goto LAB_4012d2c0;
      iVar8 = param_1[0x10];
      if (*(char *)(*param_1 + 4) != '\0') {
        iVar13 = 0xc;
        if (*(char *)(*param_1 + 5) != '\x01') {
          iVar13 = 4;
        }
        if ((((param_1[0x2a] == iVar13 + 3) && (param_1[0x20] == 0x16)) &&
            (*(char *)param_1[0x1e] == '\v')) &&
           (iVar13 = (*(code *)&SUB_4008b33c)((char *)param_1[0x1e] + iVar13,&DAT_3f41ab98,3),
           iVar13 == 0)) {
          *(undefined4 *)(iVar8 + 0x68) = 0x40;
          puVar3 = (undefined1 *)0xffff8b80;
          if (cVar6 != '\x01') goto LAB_4012d2c0;
          goto LAB_4012d256;
        }
      }
      FUN_4012bd70(iVar8 + 100);
      iVar8 = FUN_4013ae30(1,0x158);
      if (iVar8 == 0) {
        memw();
        FUN_4012a73c(param_1,2,0x50);
        puVar3 = (undefined1 *)0xffff8100;
        goto LAB_4012d2c0;
      }
      FUN_4014471c(iVar8);
      if (param_1[0x20] == 0x16) {
        if (*(char *)param_1[0x1e] == '\v') {
          iVar13 = 0xc;
          if (*(char *)(*param_1 + 5) != '\x01') {
            iVar13 = 4;
          }
          if (iVar13 + 6U <= (uint)param_1[0x2a]) {
            pcVar9 = (char *)param_1[0x1e] + iVar13;
            if (*pcVar9 == '\0') {
              uVar2 = iVar13 + 3;
              iVar13 = 0;
              if (param_1[0x2a] == CONCAT11(pcVar9[1],pcVar9[2]) + uVar2) {
                while (uVar14 = param_1[0x2a], uVar2 < uVar14) {
                  uVar7 = uVar2 + 3;
                  if (uVar14 < uVar7) goto LAB_4012d338;
                  pcVar9 = (char *)(param_1[0x1e] + uVar2);
                  if (((*pcVar9 != '\0') ||
                      (uVar10 = (uint)CONCAT11(pcVar9[1],pcVar9[2]), uVar10 < 0x80)) ||
                     (uVar2 = uVar7 + uVar10, uVar14 < uVar2)) goto LAB_4012d338;
                  if (((iVar13 == 0) && (*(char *)(*param_1 + 4) == '\0')) && (param_1[2] == 1)) {
                    iVar18 = param_1[0xf];
                    iVar15 = *(int *)(iVar18 + 100);
                    if ((iVar15 != 0) && (uVar10 == *(uint *)(iVar15 + 8))) {
                      memw();
                      iVar15 = (*(code *)&SUB_4008b33c)
                                         (*(undefined4 *)(iVar15 + 0xc),param_1[0x1e] + uVar7);
                      if (iVar15 == 0) {
                        FUN_4012bd70(iVar18 + 100);
                        goto LAB_4012d3d1;
                      }
                    }
                    uVar17 = 0x31;
                    goto LAB_4012d33b;
                  }
LAB_4012d3d1:
                  puVar4 = (undefined1 *)FUN_4014514c(iVar8,param_1[0x1e] + uVar7,uVar10);
                  if (puVar4 != (undefined1 *)0xffffd9d2) {
                    if ((int)puVar4 < -0x262d) {
                      uVar17 = 0x2a;
                      if (puVar4 == (undefined1 *)0xffffd780) {
                        uVar17 = 0x50;
                      }
                    }
                    else if (puVar4 == (undefined1 *)0xffffda80) {
                      uVar17 = 0x2b;
                    }
                    else {
                      if (puVar4 == (undefined1 *)0x0) goto LAB_4012d420;
                      uVar17 = 0x2a;
                    }
                    FUN_4012a73c(param_1,2,uVar17);
                    if (puVar4 != (undefined1 *)0x0) goto LAB_4012d304;
                    break;
                  }
LAB_4012d420:
                  iVar13 = iVar13 + 1;
                }
                if (cVar6 == '\0') {
LAB_4012d408:
                  *(int *)(param_1[0x10] + 100) = iVar8;
                  memw();
                  goto LAB_4012d256;
                }
                iVar15 = param_1[7];
                iVar13 = *param_1;
                if (iVar15 == 0) {
                  iVar15 = *(int *)(iVar13 + 0x68);
                  iVar18 = *(int *)(iVar13 + 0x6c);
                }
                else {
                  iVar18 = param_1[8];
                }
                bVar1 = true;
                iVar11 = param_1[0x11];
                iVar16 = *(int *)(iVar11 + 0x1ec);
                if (iVar16 == 0) {
                  iVar16 = *(int *)(iVar13 + 0xa4);
                  bVar1 = iVar16 != 0;
                  uVar17 = *(undefined4 *)(iVar13 + 0xa8);
                }
                else {
                  uVar17 = *(undefined4 *)(iVar11 + 0x1f0);
                }
                uVar12 = *(undefined4 *)(iVar11 + 0x14);
                memw();
                puVar4 = (undefined1 *)
                         FUN_401446f8(iVar8,iVar16,uVar17,*(undefined4 *)(iVar13 + 0x9c),
                                      param_1[0x3b],param_1[0x10] + 0x68,iVar15,iVar18,0);
                memw();
                iVar13 = FUN_401864ec((undefined4 *)(iVar8 + 0xcc),2);
                if (iVar13 != 0) {
                  puStack_24 = *(undefined4 **)(iVar8 + 0xd0);
                  uStack_28 = *(undefined4 *)(iVar8 + 0xcc);
                  memw();
                  iVar13 = FUN_40186520(&uStack_28);
                  if (2 < iVar13 - 2U) {
                    memw();
                    breakpoint(0x1000,0x4012d56d,1,0xf);
                    puVar3 = (undefined1 *)0xffff9a00;
                    if (*(int *)(iRam00000000 + 0x14) == 3) {
                      if (param_1 == (int *)&DAT_00000004) {
                        iVar8 = *(int *)(iRam00000000 + 0x44);
                        pcVar5 = (code *)&DAT_4012ba7c;
                      }
                      else if (param_1 == (int *)&DAT_00000005) {
                        iVar8 = *(int *)(iRam00000000 + 0x44);
                        pcVar5 = FUN_4012bb50;
                      }
                      else {
                        if (param_1 != (int *)0x2) goto LAB_4012d58e;
                        iVar8 = *(int *)(iRam00000000 + 0x44);
                        pcVar5 = (code *)&DAT_4012bc58;
                      }
                      puVar3 = (undefined1 *)0x0;
                      *(code **)(iVar8 + 0x1c) = pcVar5;
                    }
LAB_4012d58e:
                    memw();
                    return puVar3;
                  }
                  iVar13 = FUN_40185ad8(param_1,*puStack_24);
                  if ((iVar13 != 0) &&
                     (*(uint *)(param_1[0x10] + 0x68) = *(uint *)(param_1[0x10] + 0x68) | 0x10000,
                     puVar4 == (undefined1 *)0x0)) {
                    puVar4 = (undefined1 *)0xffff8600;
                  }
                }
                memw();
                iVar13 = FUN_4012d194(iVar8,uVar12,*(char *)(*param_1 + 4) == '\0',
                                      param_1[0x10] + 0x68);
                if ((iVar13 != 0) && (puVar4 == (undefined1 *)0x0)) {
                  puVar4 = (undefined1 *)0xffff8600;
                }
                if ((cVar6 == '\x01') &&
                   ((puVar4 == (undefined1 *)0xffffd900 || (puVar4 == (undefined1 *)0xffff8600)))) {
                  puVar4 = puVar3;
                }
                if ((bVar1) || (cVar6 != '\x02')) {
                  if (puVar4 == (undefined1 *)0x0) goto LAB_4012d408;
                }
                else {
                  puVar4 = (undefined1 *)0xffff8980;
                }
                uVar17 = 0x31;
                uVar2 = *(uint *)(param_1[0x10] + 0x68);
                if ((((((uVar2 & 0x100) == 0) && (uVar17 = 0x2a, (uVar2 & 4) == 0)) &&
                     (uVar17 = 0x2b, (uVar2 & 0x1b800) == 0)) &&
                    ((uVar17 = 0x2d, (uVar2 & 1) == 0 && (uVar17 = 0x2c, (uVar2 & 2) == 0)))) &&
                   (uVar17 = 0x30, (uVar2 >> 3 & 1) == 0)) {
                  uVar17 = 0x2e;
                }
                FUN_4012a73c(param_1,2,uVar17);
                goto LAB_4012d304;
              }
            }
          }
        }
LAB_4012d338:
        uVar17 = 0x32;
LAB_4012d33b:
        FUN_4012a73c(param_1,2,uVar17);
        puVar4 = (undefined1 *)0xffff8600;
      }
      else {
        FUN_4012a73c(param_1,2,10);
        puVar4 = &DAT_ffff8900;
      }
LAB_4012d304:
      puVar3 = puVar4;
      FUN_40144730(iVar8);
      FUN_4013ae44(iVar8);
      goto LAB_4012d2c0;
    }
    if (uVar2 != 7) {
      if (cVar6 != '\0') goto LAB_4012d264;
      *(undefined4 *)(param_1[0x10] + 0x68) = 0x80;
      memw();
    }
  }
  else if (uVar2 < 8) {
    if (uVar2 - 1 < 4) goto LAB_4012d228;
  }
  else if (uVar2 - 9 < 2) goto LAB_4012d228;
LAB_4012d256:
  param_1[1] = param_1[1] + 1;
  puVar3 = (undefined1 *)0x0;
  memw();
LAB_4012d2c0:
  memw();
  return puVar3;
}

