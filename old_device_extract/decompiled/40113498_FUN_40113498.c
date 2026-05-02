// Function : FUN_40113498
// Address  : 0x40113498
// Size     : 712 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void FUN_40113498(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  char cVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined2 *puVar11;
  int *piVar12;
  int iVar13;
  int *piVar14;
  int *piVar15;
  int *piVar16;
  int *piVar17;
  uint uVar18;
  uint uVar19;
  undefined4 uVar20;
  char *pcVar21;
  
  if (param_1 != 0) goto LAB_401134b0;
  pcVar21 = "d netif";
  uVar20 = 0xcf;
  do {
    while( true ) {
      (*(code *)&SUB_40094c54)("lid pcb",uVar20,"l_match",pcVar21);
LAB_401134b0:
      if (param_2 != 0) break;
      pcVar21 = "id pbuf";
      uVar20 = 0xd0;
    }
    if (*(ushort *)(param_1 + 10) < 8) goto LAB_401134c6;
    iVar13 = 0;
    puVar11 = *(undefined2 **)(param_1 + 4);
    if (DAT_3ffc83f8 != '\x06') {
      iVar13 = FUN_4018549c(_DAT_3ffc83e4,_DAT_3ffc83b8);
    }
    uVar7 = FUN_40185290(*puVar11);
    uVar8 = FUN_40185290(puVar11[1]);
    piVar12 = _DAT_3ffc8424;
    uVar19 = _DAT_3ffc83e4;
    cVar6 = DAT_3ffc83e0;
    cVar5 = DAT_3ffc83dc;
    iVar4 = _DAT_3ffc83d8;
    iVar3 = _DAT_3ffc83d4;
    iVar2 = _DAT_3ffc83d0;
    iVar10 = _DAT_3ffc83cc;
    piVar14 = (int *)0x0;
    piVar15 = _DAT_3ffc8424;
    piVar17 = (int *)0x0;
    while (piVar16 = piVar15, piVar16 != (int *)0x0) {
      if (*(ushort *)((int)piVar16 + 0x3a) == uVar8) {
        memw();
        iVar9 = FUN_401133a0(piVar16,param_2,iVar13);
        if (iVar9 != 0) {
          piVar15 = piVar14;
          if (((*(byte *)(piVar16 + 0xe) & 4) == 0) && (piVar15 = piVar16, piVar14 != (int *)0x0)) {
            if ((iVar13 == 0) || (uVar19 != 0xffffffff)) {
              bVar1 = true;
              if ((char)piVar16[5] == '\x06') {
                if ((((*piVar16 == 0) && (piVar16[1] == 0)) && (piVar16[2] == 0)) &&
                   (piVar16[3] == 0)) {
                  bVar1 = false;
                }
              }
              else {
                bVar1 = *piVar16 != 0;
              }
              piVar15 = piVar14;
              if (bVar1) {
                piVar15 = piVar16;
              }
            }
            else if ((((char)piVar14[5] != '\0') ||
                     (piVar15 = piVar14, *piVar14 != *(int *)(param_2 + 4))) &&
                    ((piVar15 = piVar14, (char)piVar16[5] == '\0' &&
                     (*piVar16 == *(int *)(param_2 + 4))))) {
              piVar15 = piVar16;
            }
          }
          piVar14 = piVar15;
          if (*(ushort *)(piVar16 + 0xf) == uVar7) {
            iVar9 = piVar16[6];
            if ((char)piVar16[0xb] == '\x06') {
              if (((iVar9 == 0) && (((piVar16[7] == 0 && (piVar16[8] == 0)) && (piVar16[9] == 0))))
                 || (((cVar6 == '\x06' && (iVar10 == iVar9)) &&
                     (((piVar16[7] == iVar2 && ((piVar16[8] == iVar3 && (piVar16[9] == iVar4)))) &&
                      ((char)piVar16[10] == cVar5)))))) {
LAB_4011362c:
                if (piVar17 != (int *)0x0) {
                  piVar17[0xd] = piVar16[0xd];
                  piVar16[0xd] = (int)piVar12;
                  _DAT_3ffc8424 = piVar16;
                }
                goto LAB_4011363c;
              }
            }
            else if ((iVar9 == 0) || ((cVar6 == (char)piVar16[0xb] && (iVar10 == iVar9))))
            goto LAB_4011362c;
          }
        }
      }
      piVar17 = piVar16;
      piVar15 = (int *)piVar16[0xd];
    }
    piVar16 = piVar14;
    if (piVar14 == (int *)0x0) {
      if (_DAT_3ffc83c4 == 0) {
LAB_4011353b:
        uVar19 = (uint)(*(uint *)(param_2 + 4) == _DAT_3ffc83e4);
      }
      else {
        memw();
        uVar19 = FUN_4010b8c0(param_2,&DAT_3ffc83e4);
        uVar19 = (uVar19 ^ 0xffffffff) >> 7 & 1;
        if (_DAT_3ffc83c4 == 0) goto LAB_4011353b;
      }
      if (uVar19 == 0) {
        memw();
        goto LAB_401134c6;
      }
    }
LAB_4011363c:
    memw();
    iVar10 = FUN_4010ba9c(param_1,8);
    if (iVar10 == 0) break;
    pcVar21 = "d netif";
    uVar20 = 0x170;
  } while( true );
  if (piVar16 == (int *)0x0) {
    if (iVar13 == 0) {
      if (DAT_3ffc83f8 == '\x06') {
        uVar19 = 0xff;
        iVar13 = -0xff;
      }
      else {
        uVar19 = 0xf0;
        iVar13 = -0xe0;
      }
      if ((_DAT_3ffc83e4 & uVar19) + iVar13 != 0) {
        FUN_4010baf0(param_1,(int)(short)(_DAT_3ffc83c8 + 8));
        if (_DAT_3ffc83c4 == 0) {
          FUN_40116068(param_1,3);
        }
        else {
          FUN_40117248(param_1,4);
        }
      }
    }
    goto LAB_401134c6;
  }
  if ((*(byte *)((int)piVar16 + 0x31) & 4) != 0) {
    piVar12 = _DAT_3ffc8424;
    if (iVar13 == 0) {
      if (DAT_3ffc83f8 == '\x06') {
        uVar19 = 0xff;
        uVar18 = 0xff;
      }
      else {
        uVar19 = 0xf0;
        uVar18 = 0xe0;
      }
      if ((_DAT_3ffc83e4 & uVar19) != uVar18) goto LAB_40113681;
    }
    for (; piVar12 != (int *)0x0; piVar12 = (int *)piVar12[0xd]) {
      if ((((piVar12 != piVar16) && (*(ushort *)((int)piVar12 + 0x3a) == uVar8)) &&
          (iVar10 = FUN_401133a0(piVar12,param_2,iVar13), iVar10 != 0)) &&
         ((piVar12[0x12] != 0 && (iVar10 = FUN_4010c10c(0,0x182,param_1), iVar10 != 0)))) {
        (*(code *)piVar12[0x12])(piVar12[0x13],piVar12,iVar10,&DAT_3ffc83cc,uVar7);
      }
    }
  }
LAB_40113681:
  if ((code *)piVar16[0x12] != (code *)0x0) {
    (*(code *)piVar16[0x12])(piVar16[0x13],piVar16,param_1,&DAT_3ffc83cc,uVar7);
    return;
  }
LAB_401134c6:
  FUN_4010bb10(param_1);
  return;
}

