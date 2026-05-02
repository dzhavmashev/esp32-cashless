// Function : FUN_40112a70
// Address  : 0x40112a70
// Size     : 1410 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char FUN_40112a70(int *param_1)

{
  ushort uVar1;
  bool bVar2;
  int *piVar3;
  char cVar4;
  undefined2 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int *piVar10;
  int *piVar11;
  undefined1 uVar12;
  int *piVar13;
  int *piVar14;
  undefined4 uVar15;
  int iVar16;
  char *pcVar17;
  char *pcVar18;
  int iVar19;
  
  if (param_1 != (int *)0x0) goto LAB_40112a88;
  pcVar18 = "lid pcb";
  uVar15 = 0x4e1;
  pcVar17 = "segment";
LAB_40112a7f:
  while( true ) {
    (*(code *)&SUB_40094c54)("lid pcb",uVar15,pcVar17,pcVar18);
LAB_40112a88:
    if (param_1[0xf] != 1) break;
    pcVar18 = "lid pcb";
    uVar15 = 0x4e4;
    pcVar17 = "segment";
  }
  if (_DAT_3ffc8420 == param_1) goto LAB_40112c3c;
  piVar11 = (int *)param_1[0x26];
  if (piVar11 != (int *)0x0) {
    uVar8 = (uint)*(ushort *)(param_1 + 0x1d);
    piVar10 = param_1 + 6;
    uVar9 = (uint)*(ushort *)(param_1 + 0x23);
    memw();
    iVar6 = FUN_401101f4(param_1,param_1,piVar10);
    if (iVar6 == 0) {
      return -4;
    }
    if ((char)param_1[5] == '\x06') {
      bVar2 = false;
      if ((((*param_1 == 0) && (param_1[1] == 0)) && (param_1[2] == 0)) && (param_1[3] == 0)) {
        bVar2 = true;
      }
    }
    else {
      bVar2 = *param_1 == 0;
    }
    if (bVar2) {
      piVar14 = (int *)(iVar6 + 4);
      if (((char)param_1[0xb] == '\x06') &&
         (piVar14 = (int *)FUN_401174f8(iVar6,piVar10), piVar14 == (int *)0x0)) {
        return -4;
      }
      iVar7 = piVar14[5];
      *(char *)(param_1 + 5) = (char)iVar7;
      memw();
      if ((char)iVar7 == '\x06') {
        *param_1 = *piVar14;
        param_1[1] = piVar14[1];
        param_1[2] = piVar14[2];
        param_1[3] = piVar14[3];
        uVar12 = (undefined1)piVar14[4];
      }
      else {
        *param_1 = *piVar14;
        uVar12 = 0;
        param_1[3] = 0;
        param_1[2] = 0;
        param_1[1] = 0;
        memw();
      }
      *(undefined1 *)(param_1 + 4) = uVar12;
      memw();
    }
    uVar8 = (uVar8 < uVar9) * uVar8 + (uVar8 >= uVar9) * uVar9;
    memw();
    iVar7 = FUN_40109eec(*(undefined4 *)(piVar11[3] + 4));
    if (((uint)*(ushort *)(piVar11 + 2) - param_1[0x1c]) + iVar7 <= uVar8) {
      *(undefined1 *)((int)param_1 + 0xcd) = 0;
      memw();
      piVar13 = (int *)param_1[0x27];
      piVar14 = (int *)param_1[0x27];
      while (piVar3 = piVar13, piVar3 != (int *)0x0) {
        piVar14 = piVar3;
        piVar13 = (int *)*piVar3;
      }
      memw();
      do {
        memw();
        iVar7 = FUN_40109eec(*(undefined4 *)(piVar11[3] + 4));
        if (uVar8 < (iVar7 - param_1[0x1c]) + (uint)*(ushort *)(piVar11 + 2)) {
LAB_40112c20:
          if (param_1[0x26] == 0) goto LAB_40112c25;
          goto LAB_40112c2d;
        }
        uVar9 = FUN_40185290(*(undefined2 *)(piVar11[3] + 0xc));
        if ((uVar9 & 4) != 0) goto LAB_40112fe5;
        if ((((param_1[0x27] != 0) && ((*(ushort *)((int)param_1 + 0x46) & 0x44) == 0)) &&
            ((piVar13 = (int *)param_1[0x26], piVar13 == (int *)0x0 ||
             ((*piVar13 == 0 && (*(ushort *)(piVar13 + 2) < *(ushort *)((int)param_1 + 0x5e)))))))
           && (((short)param_1[0x24] != 0 &&
               ((*(ushort *)((int)param_1 + 0x92) < 0x11 &&
                ((*(ushort *)((int)param_1 + 0x46) & 0xa0) == 0)))))) goto LAB_40112c20;
        if (param_1[0xf] != 2) {
          uVar1 = *(ushort *)(piVar11[3] + 0xc);
          memw();
          uVar9 = FUN_40185290(0x10);
          uVar9 = (uint)uVar1 | uVar9 & 0xffff;
          iVar7 = piVar11[3];
          *(char *)(iVar7 + 0xc) = (char)uVar9;
          *(char *)(iVar7 + 0xd) = (char)(uVar9 >> 8);
          memw();
        }
        memw();
        iVar7 = FUN_401102b4(piVar11);
        if (iVar7 == 0) {
          iVar7 = piVar11[3];
          memw();
          uVar15 = FUN_40109eec(param_1[0x14]);
          *(char *)(iVar7 + 8) = (char)uVar15;
          *(char *)(iVar7 + 9) = (char)((uint)uVar15 >> 8);
          *(char *)(iVar7 + 10) = (char)((uint)uVar15 >> 0x10);
          *(char *)(iVar7 + 0xb) = (char)((uint)uVar15 >> 0x18);
          memw();
          iVar7 = piVar11[3];
          memw();
          uVar5 = FUN_40185290(*(undefined2 *)((int)param_1 + 0x56));
          *(char *)(iVar7 + 0xe) = (char)uVar5;
          *(char *)(iVar7 + 0xf) = (char)((ushort)uVar5 >> 8);
          memw();
          param_1[0x16] = param_1[0x14] + (uint)*(ushort *)((int)param_1 + 0x56);
          iVar7 = piVar11[3];
          iVar16 = iVar7 + 0x14;
          if ((*(byte *)((int)piVar11 + 10) & 1) != 0) {
            memw();
            uVar9 = FUN_4010cf7c(0x59c,iVar6,piVar10);
            uVar15 = FUN_40109eec(uVar9 | 0x2040000);
            iVar16 = iVar7 + 0x18;
            *(undefined4 *)(iVar7 + 0x14) = uVar15;
          }
          if ((short)param_1[0x17] < 0) {
            *(undefined2 *)(param_1 + 0x17) = 0;
            memw();
          }
          if (param_1[0x18] == 0) {
            iVar7 = piVar11[3];
            param_1[0x18] = _DAT_3ffc8414;
            memw();
            iVar7 = FUN_40109eec(*(undefined4 *)(iVar7 + 4));
            param_1[0x19] = iVar7;
          }
          iVar7 = piVar11[1];
          iVar19 = piVar11[3];
          uVar9 = iVar19 - *(int *)(iVar7 + 4);
          *(short *)(iVar7 + 10) = *(short *)(iVar7 + 10) - (short)uVar9;
          memw();
          uVar9 = (uint)*(ushort *)(iVar7 + 8) - (uVar9 & 0xffff);
          *(short *)(iVar7 + 8) = (short)uVar9;
          *(int *)(iVar7 + 4) = iVar19;
          *(undefined1 *)(iVar19 + 0x10) = 0;
          *(undefined1 *)(iVar19 + 0x11) = 0;
          memw();
          if (iVar16 != iVar19 + (*(byte *)((int)piVar11 + 10) & 1) * 4 + 0x14) {
            pcVar18 = "d here!";
            uVar15 = 0x61c;
            pcVar17 = "nt_busy";
            memw();
            goto LAB_40112a7f;
          }
          memw();
          uVar5 = FUN_4011dc38(iVar7,6,uVar9 & 0xffff,param_1,piVar10);
          *(char *)(iVar19 + 0x10) = (char)uVar5;
          *(char *)(iVar19 + 0x11) = (char)((ushort)uVar5 >> 8);
          memw();
          if ((char)param_1[0xb] == '\x06') {
            memw();
            cVar4 = FUN_40117f9c(piVar11[1],param_1,piVar10);
          }
          else {
            cVar4 = FUN_40116d00(piVar11[1],param_1,piVar10,*(undefined1 *)((int)param_1 + 0x33),
                                 *(undefined1 *)((int)param_1 + 0x32),6,iVar6);
          }
          if (cVar4 != '\0') {
            *(ushort *)((int)param_1 + 0x46) = *(ushort *)((int)param_1 + 0x46) | 0x80;
            memw();
            memw();
            return cVar4;
          }
        }
        param_1[0x26] = *piVar11;
        if (param_1[0xf] != 2) {
          *(ushort *)((int)param_1 + 0x46) = *(ushort *)((int)param_1 + 0x46) & 0xfffc;
          memw();
        }
        memw();
        iVar7 = FUN_40109eec(*(undefined4 *)(piVar11[3] + 4));
        uVar1 = *(ushort *)(piVar11 + 2);
        memw();
        uVar9 = FUN_40185290(*(undefined2 *)(piVar11[3] + 0xc));
        iVar7 = (uint)((uVar9 & 3) != 0) + iVar7 + (uint)uVar1;
        if (param_1[0x1f] - iVar7 < 0) {
          param_1[0x1f] = iVar7;
        }
        uVar1 = *(ushort *)(piVar11 + 2);
        memw();
        uVar9 = FUN_40185290(*(undefined2 *)(piVar11[3] + 0xc));
        if ((uint)((uVar9 & 3) != 0) + (uint)uVar1 == 0) {
          FUN_4010ce44(piVar11);
        }
        else {
          *piVar11 = 0;
          if (param_1[0x27] == 0) {
            param_1[0x27] = (int)piVar11;
          }
          else {
            iVar7 = FUN_40109eec(*(undefined4 *)(piVar11[3] + 4));
            memw();
            iVar16 = FUN_40109eec(*(undefined4 *)(piVar14[3] + 4));
            piVar13 = param_1 + 0x27;
            if (iVar7 - iVar16 < 0) {
              for (; *piVar13 != 0; piVar13 = (int *)*piVar13) {
                memw();
                iVar7 = FUN_40109eec(*(undefined4 *)(*(int *)(*piVar13 + 0xc) + 4));
                memw();
                iVar16 = FUN_40109eec(*(undefined4 *)(piVar11[3] + 4));
                if (-1 < iVar7 - iVar16) break;
              }
              *piVar11 = *piVar13;
              *piVar13 = (int)piVar11;
              goto LAB_40112f8b;
            }
            *piVar14 = (int)piVar11;
            memw();
          }
          memw();
          piVar14 = piVar11;
        }
LAB_40112f8b:
        piVar11 = (int *)param_1[0x26];
        if (piVar11 == (int *)0x0) {
LAB_40112c25:
          *(undefined2 *)(param_1 + 0x25) = 0;
          memw();
          goto LAB_40112c2d;
        }
      } while( true );
    }
    if (((*(ushort *)(param_1 + 0x23) == uVar8) && (param_1[0x27] == 0)) &&
       (*(char *)((int)param_1 + 0xcd) == '\0')) {
      *(undefined2 *)(param_1 + 0x33) = 0x100;
      *(undefined1 *)((int)param_1 + 0xce) = 0;
      memw();
      memw();
    }
  }
  if ((*(ushort *)((int)param_1 + 0x46) & 2) == 0) {
LAB_40112c2d:
    *(ushort *)((int)param_1 + 0x46) = *(ushort *)((int)param_1 + 0x46) & 0xff7f;
    memw();
LAB_40112c3c:
    cVar4 = '\0';
    memw();
  }
  else {
    cVar4 = FUN_40110c68(param_1);
  }
  return cVar4;
LAB_40112fe5:
  pcVar18 = "en-pcbs";
  uVar15 = 0x537;
  pcVar17 = "segment";
  goto LAB_40112a7f;
}

