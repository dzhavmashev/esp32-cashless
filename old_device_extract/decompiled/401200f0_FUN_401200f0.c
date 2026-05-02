// Function : FUN_401200f0
// Address  : 0x401200f0
// Size     : 1090 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401200f0(undefined4 param_1,int param_2,int param_3,uint param_4)

{
  byte bVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 extraout_a3;
  undefined4 extraout_a3_00;
  undefined4 extraout_a3_01;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint *puVar12;
  char *pcVar13;
  int iVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  ushort uStack_26;
  uint auStack_24 [9];
  
  if (_DAT_3ffc6d24 == 0) {
    uVar3 = (*(code *)&SUB_40094b80)();
    FUN_4012113c(1,"nager.c"," pdTRUE",uVar3,"nager.c");
    return;
  }
  uVar15 = (*(code *)&SUB_40090010)(_DAT_3ffc6d24,0xffffffff);
  uVar16 = CONCAT44((int)((ulonglong)uVar15 >> 0x20),1);
  if ((int)uVar15 == 1) goto LAB_40120131;
  pcVar13 = "t loop\n";
  uVar3 = 0x328;
LAB_40120128:
  do {
    while( true ) {
      uVar16 = (*(code *)&SUB_40094c54)("ing/src/manager.c",uVar3,"op_task",pcVar13);
LAB_40120131:
      iVar4 = _DAT_3ffc6d20;
      uVar3 = (undefined4)((ulonglong)uVar16 >> 0x20);
      uVar9 = (uint)uVar16;
      if (_DAT_3ffc6d20 != 0) break;
      iVar4 = (*(code *)&SUB_4008fab8)(_DAT_3ffc6d24,0,0,0);
      if (iVar4 == 1) {
        return;
      }
      uVar3 = 0x32e;
      pcVar13 = "release";
    }
    if (*(int *)(_DAT_3ffc6d20 + 0x2c) == 2) {
      uVar10 = 0;
      if (_DAT_3ffbdea0 == param_2) {
        uVar10 = uVar9;
      }
      if ((uVar10 & 0xff) != 0) {
        if (param_3 != 1) {
          uVar9 = 0;
        }
        if (((uVar9 & 0xff) != 0) && (*(char *)(_DAT_3ffc6d20 + 0x70) != '\0')) {
          uVar9 = (uint)*(ushort *)(_DAT_3ffc6d20 + 0x72);
          iVar7 = _DAT_3ffc6d20 + uVar9 * 4;
          uStack_26 = 0;
          memw();
          if (*(int *)(iVar7 + 0x90) != 0) {
            memw();
            (*(code *)&SUB_40094d80)();
            *(undefined4 *)(iVar7 + 0x90) = 0;
            *(undefined2 *)(iVar4 + (uVar9 + 0x38) * 2 + 4) = 0;
            memw();
          }
          memw();
          uVar16 = FUN_40146d2c(&uStack_26);
          iVar4 = _DAT_3ffc6d20;
          uVar3 = (undefined4)((ulonglong)uVar16 >> 0x20);
          if ((int)uVar16 == 0) {
            uVar10 = (uint)uStack_26;
            iVar7 = 0;
            if (uVar10 != 0) {
              iVar11 = (uVar10 < 0x10) * uVar10 + (uint)(uVar10 >= 0x10) * 0x10;
              auStack_24[0] = CONCAT22(auStack_24[0]._2_2_,(short)iVar11);
              memw();
              memw();
              iVar11 = (*(code *)&SUB_40094dd8)(iVar11,0x50);
              *(int *)(iVar4 + (uVar9 + 0x24) * 4) = iVar11;
              if (iVar11 == 0) {
                memw();
                uVar3 = (*(code *)&SUB_40094b80)();
                FUN_4012113c(1,"nager.c","ed APs\n",uVar3,"nager.c");
                FUN_40146e0c();
                uVar3 = extraout_a3_00;
                goto LAB_40120236;
              }
              iVar11 = FUN_40146d84(auStack_24,iVar11);
              iVar4 = _DAT_3ffc6d20;
              if (iVar11 != 0) {
                uVar3 = (*(code *)&SUB_40094b80)();
                pcVar13 = "P list\n";
                goto LAB_401201e2;
              }
              uVar5 = auStack_24[0] & 0xffff;
              *(undefined2 *)(_DAT_3ffc6d20 + (uVar9 + 0x38) * 2 + 4) = (undefined2)auStack_24[0];
              memw();
              for (uVar10 = 0; uVar10 < uVar5; uVar10 = uVar10 + 1 & 0xff) {
              }
              iVar11 = 0xf - uVar5;
              while (((int)(((int)uVar5 >> 0x1f) - uVar5) < 0 && (-1 < iVar11))) {
                iVar6 = *(int *)(iVar4 + (iVar11 + 0x30) * 4 + 8);
                if (iVar6 == 0) {
LAB_4012034e:
                  iVar11 = iVar11 + -1;
                  memw();
                }
                else {
                  iVar14 = *(int *)(iVar4 + (uVar9 + 0x24) * 4) + uVar5 * 0x50 + -0x50;
                  iVar8 = iVar4 + (iVar11 + uVar5 + 0x30) * 4;
                  if (*(char *)(iVar6 + 0x2c) <= *(char *)(iVar14 + 0x2c)) {
                    *(int *)(iVar8 + 8) = iVar6;
                    goto LAB_4012034e;
                  }
                  uVar5 = uVar5 - 1;
                  *(int *)(iVar8 + 8) = iVar14;
                  memw();
                }
              }
              iVar6 = uVar5 * 0x50;
              uVar3 = 0xffffffb0;
              iVar11 = iVar4 + uVar5 * 4;
              while( true ) {
                iVar6 = iVar6 + -0x50;
                if (iVar6 == -0x50) break;
                *(int *)(iVar11 + 0xc4) = *(int *)(iVar4 + (uVar9 + 0x24) * 4) + iVar6;
                memw();
                iVar11 = iVar11 + -4;
              }
            }
          }
          else {
            uVar3 = (*(code *)&SUB_40094b80)();
            pcVar13 = "alized\n";
LAB_401201e2:
            FUN_4012113c(1,"nager.c",pcVar13,uVar3,"nager.c");
            uVar3 = extraout_a3;
LAB_40120236:
            iVar7 = -1;
          }
          iVar4 = _DAT_3ffc6d20;
          bVar1 = *(byte *)(_DAT_3ffc6d20 + 0x71);
          if (bVar1 == 0) {
            *(byte *)(_DAT_3ffc6d20 + 0x70) = bVar1;
            memw();
          }
          else {
            uVar9 = (*(ushort *)(_DAT_3ffc6d20 + 0x72) + 1) % 0xe;
            uVar3 = 1;
            *(short *)(_DAT_3ffc6d20 + 0x72) = (short)uVar9;
            memw();
            if ((iVar7 == 0) && (uVar9 != 0)) {
              if (uVar9 % (uint)bVar1 == 0) {
                (*(code *)&SUB_40091834)(0x78);
              }
              iVar4 = _DAT_3ffc6d20 + 0x108;
              *(char *)(_DAT_3ffc6d20 + 0x110) = (char)uVar9;
              memw();
              memw();
              uVar16 = FUN_40146be0(iVar4,0);
              uVar3 = (undefined4)((ulonglong)uVar16 >> 0x20);
              if ((int)uVar16 != 0) {
                uVar3 = (*(code *)&SUB_40094b80)();
                FUN_4012113c(1,"nager.c","ecords\n",uVar3,"nager.c");
                *(undefined1 *)(_DAT_3ffc6d20 + 0x70) = 0;
                memw();
                memw();
                uVar3 = extraout_a3_01;
              }
            }
            else {
              *(undefined1 *)(iVar4 + 0x70) = 0;
              memw();
              memw();
            }
          }
        }
      }
    }
    iVar4 = _DAT_3ffc6d20;
    if (*(uint *)(_DAT_3ffc6d20 + 0x2c) < 3) {
      memw();
      iVar4 = (*(code *)&SUB_4008fab8)(_DAT_3ffc6d24,0,0);
      if (iVar4 == 1) {
        return;
      }
      uVar3 = 0x33c;
      pcVar13 = "release";
      goto LAB_40120128;
    }
    bVar2 = _DAT_3ffbdea0 != param_2;
    if ((param_3 != 2) || (bVar2)) {
      if ((_DAT_3ffbde84 == param_2) && (param_3 == 0)) {
        *(undefined4 *)(_DAT_3ffc6d20 + 0x4c) = 1;
        *(undefined4 *)(iVar4 + 0x2c) = 5;
        if (*(char *)(iVar4 + 0x66) == '\0') {
          memw();
          (*(code *)&SUB_40085910)(*(undefined4 *)(iVar4 + 0x44),uVar3,30000000,0);
        }
        puVar12 = (uint *)0x0;
        uVar3 = 4;
LAB_40120461:
        FUN_4012004c(uVar3,puVar12);
      }
      else {
        param_2 = 1;
        if ((param_3 == 5) && (!bVar2)) {
          uVar3 = (*(code *)&SUB_40094b80)();
          FUN_4012113c(1,"nager.c","t scan\n",uVar3,"nager.c");
          *(undefined4 *)(_DAT_3ffc6d20 + 0x4c) = 2;
          memw();
          uVar3 = (*(code *)&SUB_40094b80)();
          FUN_4012113c(1,"nager.c","nected\n",uVar3,"nager.c",*(undefined1 *)(param_4 + 0x27));
          param_4 = (uint)*(byte *)(param_4 + 0x27);
          if (param_4 < 0x10) {
            if ((param_4 < 0xe) && (param_4 != 2)) {
LAB_4012050a:
              *(undefined4 *)(_DAT_3ffc6d20 + 0x4c) = 0;
              memw();
              param_3 = 0;
              FUN_40146a1c();
            }
            else {
LAB_401204bd:
              uVar3 = (*(code *)&SUB_40094b80)();
              FUN_4012113c(1,"nager.c","n : %d\n",uVar3,"nager.c");
              param_3 = 0;
              *(undefined4 *)(_DAT_3ffc6d20 + 0x50) = 0;
            }
          }
          else {
            if ((param_4 == 0xca) || (param_4 == 0xcc)) goto LAB_401204bd;
            if (param_4 != 0xc9) goto LAB_4012050a;
            uVar3 = (*(code *)&SUB_40094b80)();
            FUN_4012113c(1,"nager.c"," Error\n",uVar3,"nager.c");
            param_3 = _DAT_3ffc6d20;
            *(undefined4 *)(_DAT_3ffc6d20 + 0x50) = 1;
            memw();
          }
          iVar4 = _DAT_3ffc6d20;
          param_2 = *(int *)(_DAT_3ffc6d20 + 0x4c);
          if (param_2 == 2) {
            puVar12 = auStack_24;
            *(undefined4 *)(_DAT_3ffc6d20 + 0x2c) = 4;
            uVar3 = 3;
            auStack_24[0] = *(uint *)(iVar4 + 0x50);
            memw();
            goto LAB_40120461;
          }
        }
      }
    }
    else {
      *(undefined4 *)(_DAT_3ffc6d20 + 0x4c) = 0;
    }
    memw();
    iVar4 = (*(code *)&SUB_4008fab8)(_DAT_3ffc6d24,0,0);
    if (iVar4 == 1) {
      return;
    }
    uVar3 = 0x37e;
    pcVar13 = "release";
  } while( true );
}

