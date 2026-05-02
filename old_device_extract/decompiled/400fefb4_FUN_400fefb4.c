// Function : FUN_400fefb4
// Address  : 0x400fefb4
// Size     : 1056 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_400fefb4(uint param_1,undefined1 *param_2,undefined1 *param_3,undefined1 *param_4,
                int *param_5)

{
  byte bVar1;
  byte bVar2;
  undefined4 *puVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  undefined4 *puVar10;
  int iVar11;
  char cVar12;
  uint uVar13;
  byte *pbVar14;
  code *pcStack_58;
  int iStack_44;
  int iStack_38;
  
  memw();
  puVar3 = (undefined4 *)(*(code *)&SUB_4009164c)();
  iVar4 = _DAT_3ffc5804;
  if (param_1 < 0x41) {
    memw();
    pcVar5 = (char *)(*(code *)&SUB_40094dd8)(_DAT_3ffc5804,0x1c);
    if (pcVar5 == (char *)0x0) {
LAB_400ff034:
      *puVar3 = 0xc;
      memw();
    }
    else {
      puVar10 = (undefined4 *)0x0;
      uVar6 = 0;
      iStack_44 = 0x3ffbdd4c;
      iStack_38 = 0x3ffbdd4c;
      pcStack_58 = (code *)0x0;
      while (param_1 != uVar6) {
        (*(code *)&SUB_40086460)(0x3ffc5800);
        pbVar14 = (byte *)(uVar6 * 3 + 0x3ffbdd4c);
        bVar1 = *pbVar14;
        iVar11 = (int)*(char *)(iStack_38 + 1);
        bVar2 = *(byte *)(iStack_38 + 2);
        uVar13 = (uint)bVar2;
        memw();
        iVar7 = (*(code *)&LAB_40184def_1)(uVar6,param_4);
        if (iVar7 != 0) {
          *pbVar14 = bVar1 | 4;
          memw();
        }
        memw();
        (*(code *)&SUB_400864a0)(0x3ffc5800);
        if (-1 < iVar11) {
          if ((bVar1 & 1) == 0) {
            pcVar9 = pcVar5 + iVar11 * 0x1c;
            iVar7 = (*(code *)&LAB_40184def_1)(uVar6,param_2);
            if (iVar7 != 0) {
              *pcVar9 = '\x01';
              memw();
              if (uVar13 < 0x40) {
                *(uint *)(pcVar9 + (uint)(bVar2 >> 5) * 4 + 4) =
                     *(uint *)(pcVar9 + (uint)(bVar2 >> 5) * 4 + 4) |
                     1 << 0x20 - (0x20 - (uVar13 & 0x1f));
              }
              *(uint *)(param_2 + (uVar6 >> 5) * 4) =
                   *(uint *)(param_2 + (uVar6 >> 5) * 4) &
                   (uint)(0xfffffffefffffffe >> 0x20 - (uVar6 & 0x1f));
            }
            memw();
            iVar7 = (*(code *)&LAB_40184def_1)(uVar6,param_3);
            if (iVar7 != 0) {
              *pcVar9 = '\x01';
              memw();
              if (uVar13 < 0x40) {
                *(uint *)(pcVar9 + (uint)(bVar2 >> 5) * 4 + 0xc) =
                     *(uint *)(pcVar9 + (uint)(bVar2 >> 5) * 4 + 0xc) |
                     1 << 0x20 - (0x20 - (uVar13 & 0x1f));
              }
              *(uint *)(param_3 + (uVar6 >> 5) * 4) =
                   *(uint *)(param_3 + (uVar6 >> 5) * 4) &
                   (uint)(0xfffffffefffffffe >> 0x20 - (uVar6 & 0x1f));
            }
            memw();
            iVar7 = (*(code *)&LAB_40184def_1)(uVar6,param_4);
            if (iVar7 != 0) {
              *pcVar9 = '\x01';
              memw();
              if (uVar13 < 0x40) {
                *(uint *)(pcVar9 + (uint)(bVar2 >> 5) * 4 + 0x14) =
                     *(uint *)(pcVar9 + (uint)(bVar2 >> 5) * 4 + 0x14) |
                     1 << 0x20 - (0x20 - (uVar13 & 0x1f));
              }
              *(uint *)(param_4 + (uVar6 >> 5) * 4) =
                   *(uint *)(param_4 + (uVar6 >> 5) * 4) &
                   (uint)(0xfffffffefffffffe >> 0x20 - (uVar6 & 0x1f));
              memw();
            }
          }
          else if ((pcStack_58 == (code *)0x0) &&
                  (((iVar7 = (*(code *)&LAB_40184def_1)(uVar6,param_2), iVar7 != 0 ||
                    (iVar7 = (*(code *)&LAB_40184def_1)(uVar6,param_3), iVar7 != 0)) ||
                   (iVar7 = (*(code *)&LAB_40184def_1)(uVar6,param_4), iVar7 != 0)))) {
            iVar7 = *(int *)(iVar11 * 4 + 0x3ffc5808);
            pcStack_58 = *(code **)(iVar7 + 0x90);
            memw();
            puVar10 = (undefined4 *)(**(code **)(iVar7 + 0x9c))();
          }
        }
        uVar6 = uVar6 + 1;
        iStack_38 = iStack_38 + 3;
        memw();
      }
      cVar12 = '\0';
      if (pcStack_58 == (code *)0x0) {
        memw();
        puVar10 = (undefined4 *)(*(code *)&SUB_4008f990)(1,0,3);
        cVar12 = '\x01';
        if (puVar10 == (undefined4 *)0x0) {
          (*(code *)&SUB_40094d80)(pcVar5);
          goto LAB_400ff034;
        }
      }
      iVar7 = (*(code *)&SUB_40094dd8)(iVar4,4);
      iVar11 = 0;
      pcVar9 = pcVar5;
      if (iVar7 != 0) {
        for (; iVar4 != iVar11; iVar11 = iVar11 + 1) {
          iVar8 = FUN_400fea78(iVar11);
          if (((iVar8 != 0) && (*(code **)(iVar8 + 0x8c) != (code *)0x0)) && (*pcVar9 != '\0')) {
            memw();
            memw();
            iVar8 = (**(code **)(iVar8 + 0x8c))
                              (param_1,pcVar9 + 4,pcVar9 + 0xc,pcVar9 + 0x14,cVar12,puVar10,
                               iVar7 + iVar11 * 4);
            if (iVar8 != 0) {
              if (iVar8 != 0x106) {
                FUN_400feabc(iVar11,pcVar5,iVar7);
              }
              FUN_400fe75c(pcVar5,iVar4,param_2,param_3,param_4);
              if ((puVar10 != (undefined4 *)0x0) && (cVar12 != '\0')) {
                (*(code *)&SUB_400902d4)(puVar10);
              }
              (*(code *)&SUB_40094d80)(pcVar5);
              (*(code *)&SUB_40094d80)(iVar7);
              *puVar3 = 4;
              memw();
              goto LAB_400fefd7;
            }
          }
          pcVar9 = pcVar9 + 0x1c;
        }
        if (pcStack_58 == (code *)0x0) {
          if (param_2 != (undefined1 *)0x0) {
            *param_2 = 0;
            memw();
          }
          if (param_3 != (undefined1 *)0x0) {
            *param_3 = 0;
            memw();
          }
          if (param_4 != (undefined1 *)0x0) {
            *param_4 = 0;
            memw();
          }
          iVar4 = -1;
          if (param_5 != (int *)0x0) {
            iVar4 = *param_5 * 1000 + param_5[1] / 1000 + 1;
          }
          memw();
          (*(code *)&SUB_40090010)(puVar10,iVar4);
          iVar4 = 0;
        }
        else {
          iVar4 = (*pcStack_58)(param_1,param_2,param_3,param_4,param_5);
        }
        FUN_400feabc(iVar11,pcVar5,iVar7);
        if (-1 < iVar4) {
          iVar11 = FUN_400fe75c(pcVar5,iVar11,param_2,param_3,param_4);
          iVar4 = iVar4 + iVar11;
        }
        if (puVar10 != (undefined4 *)0x0) {
          if (cVar12 == '\0') {
            if (pcStack_58 != (code *)0x0) {
              (*(code *)&SUB_40090010)(*puVar10,0);
            }
          }
          else {
            (*(code *)&SUB_400902d4)(puVar10);
          }
        }
        (*(code *)&SUB_40086460)(0x3ffc5800);
        uVar6 = 0;
        while (param_1 != uVar6) {
          pbVar14 = (byte *)(uVar6 * 3 + 0x3ffbdd4c);
          if ((*pbVar14 & 2) != 0) {
            (*(code *)&SUB_4008b530)(pbVar14,0,3);
            *(undefined1 *)(iStack_44 + 1) = 0xff;
            *(undefined1 *)(iStack_44 + 2) = 0xff;
            memw();
          }
          uVar6 = uVar6 + 1;
          iStack_44 = iStack_44 + 3;
          memw();
        }
        (*(code *)&SUB_400864a0)(0x3ffc5800);
        (*(code *)&SUB_40094d80)(pcVar5);
        (*(code *)&SUB_40094d80)(iVar7);
        goto LAB_400fefd9;
      }
      (*(code *)&SUB_40094d80)(pcVar5);
      *puVar3 = 0xc;
      memw();
    }
  }
  else {
    *puVar3 = 0x16;
  }
LAB_400fefd7:
  iVar4 = -1;
LAB_400fefd9:
  memw();
  return iVar4;
}

