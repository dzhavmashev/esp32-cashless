// Function : MDB_Expansion_ID
// Address  : 0x400de708
// Size     : 1627 bytes


void MDB_Expansion_ID(int param_1)

{
  char cVar1;
  byte bVar2;
  short sVar3;
  ushort uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  char cVar8;
  undefined1 uVar9;
  undefined2 uVar10;
  uint uVar11;
  undefined4 uVar12;
  byte bStack_23;
  short asStack_22 [17];
  
  cVar8 = '\0';
LAB_400de70d:
  while( true ) {
    bStack_23 = 0;
    uVar5 = FUN_400de634(param_1,&bStack_23);
    if ((uVar5 & 0x100) == 0) goto LAB_400de7b5;
    *(undefined1 *)(param_1 + 0x96) = 0;
    uVar11 = uVar5 & 7;
    if ((uVar5 & 0xf8) == 8) break;
    if ((uVar5 & 0xf8) != 0x30) goto LAB_400de7b5;
    memw();
    memw();
    *(int *)(param_1 + 0x110) = *(int *)(param_1 + 0x110) + 1;
    iVar6 = param_1 + uVar11 * 4;
    memw();
    memw();
    *(int *)(iVar6 + 0xec) = *(int *)(iVar6 + 0xec) + 1;
    if (uVar11 == 4) {
      sVar3 = FUN_400de634(param_1,&bStack_23);
      uVar4 = FUN_400de634(param_1,&bStack_23);
      *(ushort *)(param_1 + 0x52) = sVar3 << 8 | uVar4;
      sVar3 = FUN_400de634(param_1,&bStack_23);
      uVar4 = FUN_400de634(param_1,&bStack_23);
      *(ushort *)(param_1 + 0x54) = sVar3 << 8 | uVar4;
      bVar2 = FUN_400de634(param_1,0);
      if (bStack_23 == bVar2) {
        uVar12 = 2;
LAB_400debd3:
        memw();
        *(undefined4 *)(param_1 + 0x4c) = uVar12;
        goto LAB_400de7a7;
      }
    }
    else if (uVar11 < 5) {
      if (uVar11 == 2) {
LAB_400dec0c:
        FUN_400de634(param_1,&bStack_23);
LAB_400dec16:
        FUN_400de634(param_1,&bStack_23);
LAB_400dec1d:
        bVar2 = FUN_400de634(param_1,0);
        if (bStack_23 == bVar2) goto LAB_400de7a7;
      }
      else if (uVar11 < 3) {
        if (uVar11 == 1) {
          bVar2 = FUN_400de634(param_1,0);
          if (bStack_23 == bVar2) {
            memw();
            *(undefined4 *)(param_1 + 0x4c) = 1;
            *(undefined2 *)(param_1 + 0x56) = 0x1601;
            *(undefined4 *)(param_1 + 0x58) = 0x2640043;
            *(undefined4 *)(param_1 + 0x5c) = 0xc800;
            *(undefined4 *)(param_1 + 0x60) = 0x64320aff;
            *(undefined2 *)(param_1 + 100) = 0xff;
            *(undefined1 *)(param_1 + 0x66) = 0x7d;
            uVar9 = 0x11;
            goto LAB_400de87d;
          }
        }
        else {
LAB_400debb9:
          bVar2 = FUN_400de634(param_1,0);
          if (bStack_23 == bVar2) {
            *(undefined1 *)(param_1 + 0x50) = 1;
            uVar12 = 0;
            goto LAB_400debd3;
          }
        }
      }
      else {
        bVar2 = FUN_400de634(param_1,0);
        if (bStack_23 == bVar2) {
          if (*(char *)(param_1 + 0x50) == '\0') {
            if (*(char *)(param_1 + 0x51) != '\0') {
              *(char *)(param_1 + 0x51) = *(char *)(param_1 + 0x51) + -1;
              uVar9 = 9;
              goto LAB_400decb7;
            }
            goto LAB_400de7a7;
          }
          *(undefined2 *)(param_1 + 0x50) = 0x100;
          uVar10 = 0x906;
          goto LAB_400deca2;
        }
      }
    }
    else {
      if (uVar11 == 6) goto LAB_400ded0e;
      if (uVar11 < 6) goto LAB_400dec16;
      if (uVar11 != 7) goto LAB_400debb9;
      cVar1 = FUN_400de634(param_1,&bStack_23);
      if (cVar1 != '\0') {
        if (cVar1 != '\x01') goto LAB_400de9be;
        FUN_400de634(param_1,&bStack_23);
        FUN_400de634(param_1,&bStack_23);
        goto LAB_400dec0c;
      }
      bVar2 = FUN_400de634(param_1);
      if (bStack_23 == bVar2) {
        *(char *)(param_1 + 0x58) = '0';
        *(char *)(param_1 + 0x56) = 'x';
        *(char *)(param_1 + 0x57) = '%';
        func_0x4008b3d8(param_1 + 0x59,"0MDB   ",0xc);
        func_0x4008b3d8(param_1 + 0x65,&UNK_3f4065ed,0xc);
        *(undefined1 *)(param_1 + 0x71) = 0x10;
        *(undefined1 *)(param_1 + 0x72) = 0x51;
        uVar9 = 0x1d;
        goto LAB_400de87d;
      }
    }
  }
  memw();
  memw();
  *(int *)(param_1 + 0x110) = *(int *)(param_1 + 0x110) + 1;
  iVar6 = param_1 + uVar11 * 4;
  memw();
  memw();
  *(int *)(iVar6 + 0xcc) = *(int *)(iVar6 + 0xcc) + 1;
  if (uVar11 == 3) {
    bVar2 = FUN_400de634(param_1,0);
    if (bStack_23 == bVar2) {
      memw();
      if ((*(int *)(param_1 + 0x28) != 0) && (*(char *)(param_1 + 0x38) == '\0')) {
        memw();
        if (*(int *)(param_1 + 0x28) == 2) {
          if (*(char *)(param_1 + 0x39) != -1) {
            memw();
            *(undefined2 *)(param_1 + 0x3a) = 0;
            memw();
            *(int *)(param_1 + 0x114) = *(int *)(param_1 + 0x114) + 1;
            *(undefined1 *)(param_1 + 0x39) = 0xff;
          }
          memw();
          if (*(short *)(param_1 + 0x2c) != 0) {
            if (cVar8 == '\0') {
              memw();
              uVar5 = FUN_400de604(param_1,*(undefined2 *)(param_1 + 0x2c));
              if (uVar5 == 0xff) {
LAB_400de900:
                cVar8 = '\0';
              }
              else {
                bVar2 = 0x50;
                if (3 < uVar5) {
                  bVar2 = 0x40;
                }
                cVar8 = *(char *)(param_1 + uVar5 + 0x3c) + '\x01';
                *(char *)(param_1 + uVar5 + 0x3c) = cVar8;
                *(byte *)(param_1 + 0x56) = bVar2 | (byte)uVar5 & 0xf;
                *(char *)(param_1 + 0x57) = cVar8;
                sVar3 = *(short *)((int)&PTR_FUN_3f406658 + uVar5 * 2);
                *(undefined1 *)(param_1 + 0x96) = 2;
                memw();
                *(short *)(param_1 + 0x3a) = sVar3;
                memw();
                *(short *)(param_1 + 0x2c) = *(short *)(param_1 + 0x2c) - sVar3;
                *(byte *)(param_1 + 0x39) = (byte)uVar5;
                cVar8 = '\x05';
              }
            }
            else {
LAB_400de8e2:
              cVar8 = cVar8 + -1;
            }
          }
        }
        goto LAB_400de7a7;
      }
LAB_400ded75:
      *(undefined1 *)(param_1 + 0x38) = 0;
      uVar9 = 0xb;
LAB_400decb7:
      *(undefined1 *)(param_1 + 0x56) = uVar9;
      uVar9 = 1;
      goto LAB_400de87d;
    }
    goto LAB_400de70d;
  }
  if (3 < uVar11) {
    if (uVar11 == 5) goto LAB_400dec0c;
    if (uVar11 < 5) {
      sVar3 = FUN_400de634(param_1,&bStack_23);
      uVar4 = FUN_400de634(param_1,&bStack_23);
      *(ushort *)(param_1 + 0x30) = sVar3 << 8 | uVar4;
      sVar3 = FUN_400de634(param_1,&bStack_23);
      uVar4 = FUN_400de634(param_1,&bStack_23);
      *(ushort *)(param_1 + 0x32) = sVar3 << 8 | uVar4;
      bVar2 = FUN_400de634(param_1,0);
      if (bStack_23 == bVar2) {
        uVar12 = 2;
        goto LAB_400de82f;
      }
      goto LAB_400de70d;
    }
    if (uVar11 != 7) goto LAB_400de7a7;
    bVar2 = FUN_400de634(param_1,&bStack_23);
    if (bVar2 == 2) goto LAB_400dec16;
    if (bVar2 < 3) {
      if (bVar2 == 0) {
        bVar2 = FUN_400de634(param_1,0);
        if (bStack_23 == bVar2) {
          *(char *)(param_1 + 0x58) = '0';
          *(char *)(param_1 + 0x56) = 'x';
          *(char *)(param_1 + 0x57) = '%';
          func_0x4008b3d8(param_1 + 0x59,"lX\n",0xc);
          func_0x4008b3d8(param_1 + 0x65,"600351 ",0xc);
          *(undefined1 *)(param_1 + 0x71) = 1;
          *(undefined2 *)(param_1 + 0x72) = 0x27;
          *(undefined2 *)(param_1 + 0x74) = 0;
          *(undefined1 *)(param_1 + 0x76) = 5;
          uVar9 = 0x21;
          goto LAB_400de87d;
        }
        goto LAB_400de70d;
      }
      if (bVar2 != 1) {
LAB_400de9be:
        FUN_400de634(param_1,0);
        goto LAB_400de7a7;
      }
      uVar5 = FUN_400de634(param_1,&bStack_23);
      uVar11 = FUN_400de634(param_1,&bStack_23);
      uVar7 = FUN_400de634(param_1,&bStack_23);
      iVar6 = FUN_400de634(param_1,&bStack_23);
      bVar2 = FUN_400de634(param_1,0);
      if (bStack_23 != bVar2) goto LAB_400de70d;
      *(uint *)(param_1 + 0x34) =
           iVar6 << 0x18 | (uVar7 & 0xff) << 0x10 | uVar5 & 0xff | (uVar11 & 0xff) << 8;
    }
    else {
      if (bVar2 == 4) goto LAB_400dec1d;
      if (bVar2 < 4) {
        bVar2 = FUN_400de634(param_1,0);
        if (bStack_23 == bVar2) {
          *(undefined1 *)(param_1 + 0x56) = 0;
          uVar9 = 0x10;
          goto LAB_400de87d;
        }
        goto LAB_400de70d;
      }
      if (bVar2 != 5) goto LAB_400de9be;
      bVar2 = FUN_400de634(param_1,0);
      if (bStack_23 != bVar2) goto LAB_400de70d;
      memw();
      if ((*(int *)(param_1 + 0x28) == 0) || (*(char *)(param_1 + 0x38) != '\0')) goto LAB_400ded75;
      memw();
      if (*(int *)(param_1 + 0x28) == 2) {
        if (*(char *)(param_1 + 0x39) != -1) {
          memw();
          *(undefined2 *)(param_1 + 0x3a) = 0;
          memw();
          *(int *)(param_1 + 0x114) = *(int *)(param_1 + 0x114) + 1;
          *(undefined1 *)(param_1 + 0x39) = 0xff;
        }
        memw();
        if (*(short *)(param_1 + 0x2c) != 0) {
          if (cVar8 != '\0') goto LAB_400de8e2;
          memw();
          uVar5 = FUN_400de604(param_1,*(undefined2 *)(param_1 + 0x2c));
          if (uVar5 == 0xff) goto LAB_400de900;
          bVar2 = 0x50;
          if (3 < uVar5) {
            bVar2 = 0x40;
          }
          cVar8 = *(char *)(param_1 + uVar5 + 0x3c) + '\x01';
          *(char *)(param_1 + uVar5 + 0x3c) = cVar8;
          *(byte *)(param_1 + 0x56) = bVar2 | (byte)uVar5 & 0xf;
          *(char *)(param_1 + 0x57) = cVar8;
          sVar3 = *(short *)((int)&PTR_FUN_3f406658 + uVar5 * 2);
          *(undefined1 *)(param_1 + 0x96) = 2;
          memw();
          *(short *)(param_1 + 0x3a) = sVar3;
          memw();
          *(short *)(param_1 + 0x2c) = *(short *)(param_1 + 0x2c) - sVar3;
          *(byte *)(param_1 + 0x39) = (byte)uVar5;
          cVar8 = '\x05';
        }
      }
    }
    goto LAB_400de7a7;
  }
  if (uVar11 != 1) {
    if (uVar11 < 2) {
      bVar2 = FUN_400de634(param_1,0);
      if (bStack_23 == bVar2) {
        if (*(char *)(param_1 + 0x39) != -1) {
          memw();
          memw();
          *(short *)(param_1 + 0x2c) = *(short *)(param_1 + 0x2c) + *(short *)(param_1 + 0x3a);
          *(undefined1 *)(param_1 + 0x39) = 0xff;
          *(undefined2 *)(param_1 + 0x3a) = 0;
        }
        *(undefined1 *)(param_1 + 0x38) = 1;
        uVar12 = 0;
LAB_400de82f:
        memw();
        *(undefined4 *)(param_1 + 0x28) = uVar12;
        goto LAB_400de7a7;
      }
    }
    else {
      bVar2 = FUN_400de634(param_1,0);
      if (bStack_23 == bVar2) {
        *(undefined2 *)(param_1 + 0x56) = 0;
        *(undefined1 *)(param_1 + 0x58) = *(undefined1 *)(param_1 + 0x3c);
        uVar9 = 0x12;
        goto LAB_400de87d;
      }
    }
    goto LAB_400de70d;
  }
  bVar2 = FUN_400de634(param_1,0);
  if (bStack_23 != bVar2) goto LAB_400de70d;
  memw();
  *(undefined4 *)(param_1 + 0x28) = 1;
  *(undefined2 *)(param_1 + 0x56) = 0x1603;
  *(undefined4 *)(param_1 + 0x58) = 0x26443;
  *(undefined1 *)(param_1 + 0x5c) = 0xf;
  *(undefined1 *)(param_1 + 0x5d) = 0xac;
  uVar9 = 0x17;
  goto LAB_400de87d;
LAB_400ded0e:
  bVar2 = FUN_400de634(param_1,0);
  if (bStack_23 != bVar2) goto LAB_400de70d;
  uVar10 = 0;
LAB_400deca2:
  *(undefined2 *)(param_1 + 0x56) = uVar10;
  uVar9 = 2;
LAB_400de87d:
  *(undefined1 *)(param_1 + 0x96) = uVar9;
LAB_400de7a7:
  FUN_400de6b4(param_1,param_1 + 0x56,*(undefined1 *)(param_1 + 0x96));
LAB_400de7b5:
  iVar6 = func_0x4008fecc(*(undefined4 *)(param_1 + 0x9c),asStack_22,0);
  if (iVar6 == 1) {
    memw();
    memw();
    *(short *)(param_1 + 0x2c) = asStack_22[0] + *(short *)(param_1 + 0x2c);
    memw();
    memw();
    *(short *)(param_1 + 0x2e) = asStack_22[0] + *(short *)(param_1 + 0x2e);
  }
  goto LAB_400de70d;
}

