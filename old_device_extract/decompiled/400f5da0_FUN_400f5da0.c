// Function : FUN_400f5da0
// Address  : 0x400f5da0
// Size     : 1998 bytes


void FUN_400f5da0(byte *param_1)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  uint uVar14;
  uint local_50;
  int iStack_4c;
  undefined4 uStack_48;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  uint uStack_28;
  byte bStack_24;
  
  uVar6 = (uint)*param_1;
  iVar7 = uVar6 * 0x10;
  piVar10 = (int *)(iVar7 + 0x3ffbdc78);
  local_50 = 0;
  iStack_4c = 0;
  iVar5 = iVar7 + 0x3ffbdc7c;
LAB_400f5dbe:
  do {
    while( true ) {
      iVar11 = *piVar10;
      memw();
      uVar9 = *(uint *)(iVar11 + 8);
      if (uVar9 == 0) {
        if (iStack_4c == 1) {
          (*(code *)&SUB_40085da0)(0);
        }
        return;
      }
      uStack_2c = 8;
      if ((uVar9 & 2) == 0) break;
      memw();
      (*(code *)&SUB_40092a98)(iVar5,0xffffffff);
      memw();
      memw();
      *(uint *)(*piVar10 + 0xc) = *(uint *)(*piVar10 + 0xc) & 0xfffffffd;
      memw();
      (*(code *)&SUB_40092bec)(iVar5);
      iVar11 = *piVar10;
      memw();
      *(undefined4 *)(iVar11 + 0x10) = 2;
      if (param_1[0xce] == 0) {
        if (param_1[0xb8] != 0) {
          if (*(int *)(param_1 + 0xb4) != 0) goto LAB_400f5e38;
          uVar13 = *(undefined4 *)(param_1 + 0xe8);
          param_1[0xb8] = 0;
          memw();
          goto LAB_400f5e27;
        }
        if (*(int *)(param_1 + 0xb4) != 0) {
LAB_400f5e38:
          memw();
          uStack_44 = *(uint *)(iVar11 + 0x1c);
          memw();
          memw();
          uVar9 = 0x80 - (uStack_44 >> 0x10 & 0xff);
          bVar3 = true;
          bVar2 = false;
LAB_400f5e55:
          if (uVar9 != 0) {
            if (((*(int *)(param_1 + 0xc4) != 0) && (*(int *)(param_1 + 0xbc) != 0)) &&
               (*(int *)(param_1 + 200) != 0)) goto LAB_400f5efd;
            piVar4 = (int *)(*(code *)&SUB_4008ed58)(*(undefined4 *)(param_1 + 0xdc),&uStack_48);
            *(int **)(param_1 + 0xc0) = piVar4;
            if (piVar4 != (int *)0x0) goto code_r0x400f5ec3;
          }
          if (bVar2) {
            memw();
            *(undefined4 *)(*(int *)(iVar7 + 0x3ffbdc78) + 0x10) = 2;
            memw();
            (*(code *)&SUB_40092a98)(iVar5,0xffffffff);
            iVar11 = *(int *)(iVar7 + 0x3ffbdc78);
            memw();
            memw();
            *(uint *)(iVar11 + 0xc) = *(uint *)(iVar11 + 0xc) | 2;
            goto LAB_400f5e89;
          }
          goto LAB_400f5e94;
        }
      }
    }
    if ((uVar9 & 0x40101) != 0) {
      if (DAT_3ffc5584 == '\x01') {
        uVar9 = uVar9 | 0x40000;
        DAT_3ffc5584 = '\0';
        memw();
      }
      uVar14 = uVar9 & 0x40000;
      if (param_1[0x1c] != 0) {
        memw();
        (*(code *)&SUB_40092a98)(iVar5,0xffffffff);
        iVar11 = *(int *)(iVar7 + 0x3ffbdc78);
        memw();
        memw();
        *(uint *)(iVar11 + 0xc) = *(uint *)(iVar11 + 0xc) & 0xfffffefe;
        memw();
        (*(code *)&SUB_40092bec)(iVar5);
        iVar11 = *(int *)(iVar7 + 0x3ffbdc78);
        memw();
        *(undefined4 *)(iVar11 + 0x10) = 0x101;
        if (uVar14 == 0) goto LAB_400f5e94;
        memw();
        *(undefined4 *)(iVar11 + 0x10) = 0x40000;
        uStack_2c = 7;
        uStack_28 = local_50;
        DAT_3ffc5584 = '\x01';
        memw();
        goto LAB_400f6291;
      }
      memw();
      uStack_3c = *(uint *)(iVar11 + 0x1c);
      memw();
      memw();
      memw();
      uStack_40 = *(uint *)(iVar11 + 0x60);
      memw();
      memw();
      memw();
      if ((uStack_40 >> 2 & 0x7ff) < (uStack_40 >> 0xd & 0x7ff)) {
        memw();
        memw();
        local_50 = (uStack_40 >> 0xd & 0x7ff) - (uStack_40 >> 2 & 0x7ff);
      }
      else {
        memw();
        memw();
        if ((uStack_40 >> 0xd & 0x7ff) < (uStack_40 >> 2 & 0x7ff)) {
          memw();
          memw();
          local_50 = ((uStack_40 >> 0xd & 0x7ff) + 0x80) - (uStack_40 >> 2 & 0x7ff);
        }
        else {
          local_50 = 0;
          if ((uStack_3c & 0xff) != 0) {
            local_50 = 0x80;
          }
        }
      }
      if ((*(char *)(*(int *)(uVar6 * 4 + 0x3ffc5588) + 0x11) != '\0') && ((uVar9 & 0x100) == 0)) {
        local_50 = local_50 - 1;
      }
      memw();
      FUN_400fe438(piVar10,param_1 + 0x1d,&local_50);
      iVar11 = *(int *)(iVar7 + 0x3ffbdc78);
      memw();
      uStack_38 = *(uint *)(iVar11 + 0x54);
      memw();
      memw();
      memw();
      uStack_34 = *(uint *)(iVar11 + 0x54);
      memw();
      memw();
      uVar8 = uStack_34 >> 8 & 0xff;
      if (uVar14 == 0) {
        bStack_24 = (byte)(uVar9 >> 8) & 1;
        memw();
        memw();
        *(undefined4 *)(iVar11 + 0x10) = 0x101;
        uStack_28 = local_50;
        memw();
        uStack_2c = uVar14;
        (*(code *)&SUB_40092a98)(0x3ffbdc70,0xffffffff);
        if (*(code **)(param_1 + 0xd0) != (code *)0x0) {
          (**(code **)(param_1 + 0xd0))(uVar6,0,&iStack_4c);
        }
        (*(code *)&SUB_40092bec)(0x3ffbdc70);
        uVar9 = 0xffffffff;
      }
      else {
        memw();
        *(undefined4 *)(iVar11 + 0x10) = 0x40000;
        iVar11 = 0;
        uStack_2c = 7;
        uStack_28 = local_50;
        uVar1 = local_50;
        do {
          uVar9 = uVar1 - 1;
          if ((int)uVar9 < 0) break;
          iVar11 = iVar11 + 1;
          if ((uint)param_1[uVar1 + 0x1c] != (uStack_38 & 0xff)) {
            iVar11 = 0;
          }
          uVar1 = uVar9;
        } while (iVar11 < (int)uVar8);
      }
      param_1[0x9d] = (byte)local_50;
      memw();
      memw();
      iVar11 = (*(code *)&SUB_4008ec74)
                         (*(undefined4 *)(param_1 + 0xd8),param_1 + 0x1d,local_50 & 0xff,&iStack_4c)
      ;
      if (iVar11 == 0) {
        param_1[0x1c] = 1;
        memw();
        memw();
        (*(code *)&SUB_40092a98)(iVar5,0xffffffff);
        memw();
        memw();
        *(uint *)(*(int *)(iVar7 + 0x3ffbdc78) + 0xc) =
             *(uint *)(*(int *)(iVar7 + 0x3ffbdc78) + 0xc) & 0xfffffefe;
        memw();
        (*(code *)&SUB_40092bec)(iVar5);
        if (uStack_2c == 7) {
          (*(code *)&SUB_40092a98)(iVar5,0xffffffff);
          iVar11 = *(int *)(param_1 + 0x14);
          if ((int)local_50 < (int)uVar8) {
            iVar12 = iVar11 - (uVar8 - local_50);
          }
          else {
            iVar12 = uVar9 + iVar11;
            if ((int)uVar9 < 0) {
              iVar12 = (uint)param_1[0x9d] + iVar11;
            }
          }
          FUN_400f5bfc(uVar6,iVar12);
          (*(code *)&SUB_40092bec)(iVar5);
          if (*(int *)(param_1 + 0xd4) != 0) {
            (*(code *)&SUB_4008fcf8)(*(int *)(param_1 + 0xd4),&uStack_2c,&iStack_4c,0);
          }
        }
        uStack_2c = 2;
        goto LAB_400f6152;
      }
      (*(code *)&SUB_40092a98)(iVar5,0xffffffff);
      if (uVar14 != 0) {
        if ((int)local_50 < (int)uVar8) {
          uVar9 = -(uVar8 - local_50);
        }
        else if ((int)uVar9 < 0) goto LAB_400f621c;
        FUN_400f5bfc(uVar6,*(int *)(param_1 + 0x14) + uVar9);
      }
LAB_400f621c:
      *(uint *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + (uint)param_1[0x9d];
      memw();
LAB_400f5e89:
      memw();
      (*(code *)&SUB_40092bec)(iVar5);
      goto LAB_400f5e94;
    }
    if ((uVar9 & 0x10) != 0) {
      (*(code *)&SUB_40092a98)(iVar5,0xffffffff);
      FUN_400fe324(piVar10);
      (*(code *)&SUB_40092bec)(iVar5);
      (*(code *)&SUB_40092a98)(0x3ffbdc70,0xffffffff);
      if (*(code **)(param_1 + 0xd0) != (code *)0x0) {
        (**(code **)(param_1 + 0xd0))(uVar6,2,&iStack_4c);
      }
      (*(code *)&SUB_40092bec)(0x3ffbdc70);
      memw();
      *(undefined4 *)(*(int *)(iVar7 + 0x3ffbdc78) + 0x10) = 0x10;
      uStack_2c = 3;
      memw();
LAB_400f6152:
      memw();
      goto LAB_400f6291;
    }
    if ((uVar9 & 0x80) != 0) {
      memw();
      *(undefined4 *)(iVar11 + 0x10) = 0x80;
      uStack_2c = 1;
      memw();
      goto LAB_400f6152;
    }
    if ((uVar9 & 8) != 0) {
      (*(code *)&SUB_40092a98)(0x3ffbdc70,0xffffffff);
      if (*(code **)(param_1 + 0xd0) != (code *)0x0) {
        (**(code **)(param_1 + 0xd0))(uVar6,2,&iStack_4c);
      }
      (*(code *)&SUB_40092bec)(0x3ffbdc70);
      memw();
      *(undefined4 *)(*(int *)(iVar7 + 0x3ffbdc78) + 0x10) = 8;
      uStack_2c = 4;
      memw();
      goto LAB_400f6152;
    }
    if ((uVar9 & 4) != 0) {
      (*(code *)&SUB_40092a98)(0x3ffbdc70,0xffffffff);
      if (*(code **)(param_1 + 0xd0) != (code *)0x0) {
        (**(code **)(param_1 + 0xd0))(uVar6,2,&iStack_4c);
      }
      (*(code *)&SUB_40092bec)(0x3ffbdc70);
      memw();
      *(undefined4 *)(*(int *)(iVar7 + 0x3ffbdc78) + 0x10) = 4;
      uStack_2c = 5;
      memw();
      goto LAB_400f6152;
    }
    if ((uVar9 & 0x1000) != 0) {
      memw();
      (*(code *)&SUB_40092a98)(iVar5,0xffffffff);
      FUN_400fe380(piVar10,0);
      iVar11 = *piVar10;
      memw();
      memw();
      *(uint *)(iVar11 + 0xc) = *(uint *)(iVar11 + 0xc) & 0xffffefff;
      if (param_1[0xcc] == 1) {
        memw();
        memw();
        *(uint *)(iVar11 + 0xc) = *(uint *)(iVar11 + 0xc) | 2;
      }
      memw();
      (*(code *)&SUB_40092bec)(iVar5);
      memw();
      *(undefined4 *)(*(int *)(iVar7 + 0x3ffbdc78) + 0x10) = 0x1000;
      if (param_1[0xcc] != 1) {
        uVar13 = *(undefined4 *)(param_1 + 0xf0);
        goto LAB_400f5e27;
      }
      param_1[0xcc] = 0;
      param_1[0xce] = 0;
      memw();
      memw();
      goto LAB_400f5e94;
    }
    if ((uVar9 & 0x2000) != 0) {
      (*(code *)&SUB_40092a98)(iVar5,0xffffffff);
      memw();
      memw();
      *(uint *)(*piVar10 + 0xc) = *(uint *)(*piVar10 + 0xc) & 0xffffdfff;
      memw();
      (*(code *)&SUB_40092bec)(iVar5);
      memw();
      *(undefined4 *)(*piVar10 + 0x10) = 0x2000;
      memw();
      goto LAB_400f5e94;
    }
    if ((uVar9 & 0x40000) != 0) {
      uStack_2c = 7;
      memw();
      *(undefined4 *)(iVar11 + 0x10) = 0x40000;
      memw();
      goto LAB_400f6152;
    }
    if ((uVar9 & 0x38000) == 0) {
      if ((uVar9 & 0x4000) != 0) {
        iVar12 = uVar6 * 4;
        if (*(int *)(*(int *)(iVar12 + 0x3ffc5588) + 0xc) == 1) break;
        goto LAB_400f64d2;
      }
      memw();
      *(uint *)(iVar11 + 0x10) = uVar9;
      memw();
    }
    else {
      (*(code *)&SUB_40092a98)(iVar5,0xffffffff);
      FUN_400fe324(piVar10);
      *(undefined1 *)(*(int *)(uVar6 * 4 + 0x3ffc5588) + 0x10) = 1;
      memw();
      memw();
      (*(code *)&SUB_40092bec)(iVar5);
      memw();
      *(undefined4 *)(*(int *)(iVar7 + 0x3ffbdc78) + 0x10) = 0x38000;
      uStack_2c = 8;
      memw();
    }
  } while( true );
  memw();
  uStack_30 = *(uint *)(iVar11 + 0x1c);
  memw();
  memw();
  if ((uStack_30 >> 0x10 & 0xff) == 0) {
    memw();
    if ((uStack_30 >> 0x18 & 0xf) == 0) {
LAB_400f64d2:
      memw();
      *(undefined4 *)(iVar11 + 0x10) = 0x4000;
      memw();
      (*(code *)&SUB_40092a98)(iVar5,0xffffffff);
      iVar11 = *(int *)(iVar7 + 0x3ffbdc78);
      memw();
      memw();
      *(uint *)(iVar11 + 0xc) = *(uint *)(iVar11 + 0xc) & 0xffffbfff;
      if (*(int *)(*(int *)(iVar12 + 0x3ffc5588) + 0xc) == 1) {
        memw();
        FUN_400fe324(piVar10);
        iVar11 = *(int *)(iVar7 + 0x3ffbdc78);
        memw();
        memw();
        *(uint *)(iVar11 + 0x20) = *(uint *)(iVar11 + 0x20) | 0x40;
      }
      memw();
      (*(code *)&SUB_40092bec)(iVar5);
      uVar13 = *(undefined4 *)(*(int *)(iVar12 + 0x3ffc5588) + 0xec);
LAB_400f5e27:
      memw();
      (*(code *)&SUB_4008fde8)(uVar13,&iStack_4c);
LAB_400f5e94:
      if (uStack_2c != 8) {
LAB_400f6291:
        if (*(int *)(param_1 + 0xd4) != 0) {
          memw();
          (*(code *)&SUB_4008fcf8)(*(int *)(param_1 + 0xd4),&uStack_2c,&iStack_4c,0);
        }
      }
    }
    else {
      memw();
    }
  }
  goto LAB_400f5dbe;
code_r0x400f5ec3:
  if (*(int *)(param_1 + 0xc4) == 0) {
    param_1[0xbc] = 0;
    param_1[0xbd] = 0;
    param_1[0xbe] = 0;
    param_1[0xbf] = 0;
    *(int *)(param_1 + 0xc4) = piVar4[2];
    if (*piVar4 == 6) {
      param_1[0xcc] = 1;
      memw();
      param_1[0xcd] = (byte)piVar4[1];
      memw();
    }
    memw();
    (*(code *)&SUB_4008ee3c)(*(undefined4 *)(param_1 + 0xdc),piVar4,&iStack_4c);
  }
  else if (*(int *)(param_1 + 0xbc) == 0) {
    *(int **)(param_1 + 0xbc) = piVar4;
    *(undefined4 *)(param_1 + 200) = uStack_48;
    memw();
    bVar2 = bVar3;
  }
  if (*(int *)(param_1 + 0xc4) != 0) {
LAB_400f5efd:
    if ((*(int *)(param_1 + 0xbc) != 0) && (uVar14 = *(uint *)(param_1 + 200), uVar14 != 0)) {
      iVar11 = FUN_400f5d20(uVar6,*(int *)(param_1 + 0xbc),
                            (uVar14 < uVar9) * uVar14 + (uVar14 >= uVar9) * uVar9);
      uVar9 = uVar9 - iVar11;
      iVar12 = *(int *)(param_1 + 200);
      *(int *)(param_1 + 0xbc) = *(int *)(param_1 + 0xbc) + iVar11;
      *(int *)(param_1 + 0xc4) = *(int *)(param_1 + 0xc4) - iVar11;
      *(int *)(param_1 + 200) = iVar12 - iVar11;
      bVar2 = bVar3;
      if (iVar12 - iVar11 == 0) {
        memw();
        (*(code *)&SUB_4008ee3c)
                  (*(undefined4 *)(param_1 + 0xdc),*(undefined4 *)(param_1 + 0xc0),&iStack_4c);
        param_1[0xc0] = 0;
        param_1[0xc1] = 0;
        param_1[0xc2] = 0;
        param_1[0xc3] = 0;
        param_1[0xbc] = 0;
        param_1[0xbd] = 0;
        param_1[0xbe] = 0;
        param_1[0xbf] = 0;
        if ((*(int *)(param_1 + 0xc4) == 0) && (param_1[0xcc] == 1)) {
          memw();
          *(undefined4 *)(*(int *)(iVar7 + 0x3ffbdc78) + 0x10) = 0x1000;
          memw();
          (*(code *)&SUB_40092a98)(iVar5,0xffffffff);
          FUN_400fe380(piVar10,param_1[0xcd]);
          iVar11 = *(int *)(iVar7 + 0x3ffbdc78);
          memw();
          memw();
          *(uint *)(iVar11 + 0xc) = *(uint *)(iVar11 + 0xc) | 0x1000;
          memw();
          (*(code *)&SUB_40092bec)(iVar5);
          param_1[0xce] = 1;
          memw();
          memw();
          bVar2 = false;
        }
      }
    }
  }
  goto LAB_400f5e55;
}

