// Function : FUN_4014d0c0
// Address  : 0x4014d0c0
// Size     : 1394 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 FUN_4014d0c0(int param_1)

{
  undefined1 uVar1;
  uint uVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  ushort uVar6;
  ushort *puVar7;
  byte bVar8;
  int iVar9;
  undefined4 uVar10;
  uint *puVar11;
  undefined4 uVar12;
  char *pcVar13;
  undefined4 uVar14;
  uint uVar15;
  char *pcVar16;
  undefined1 local_50 [16];
  int iStack_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  uint uStack_30;
  ushort *puStack_2c;
  
  puVar7 = *(ushort **)(param_1 + 0x3c);
  local_50[0] = 0;
  memw();
  if (puVar7 == (ushort *)0x0) {
    memw();
    return 0;
  }
  DAT_3ffc89f0 = 3;
  DAT_3ffc89ee = '\x03';
  DAT_3ffc89ec = 3;
  DAT_3ffc89ed = 4;
  DAT_3ffc89f6 = 9;
  memw();
  uVar4 = (uint)*(byte *)((int)puVar7 + 1);
  if (uVar4 == 1) {
    pcVar16 = "rotocol version";
    uVar12 = 4;
    uVar10 = 8;
    uVar14 = 0x3f43362c;
    goto LAB_4014d10e;
  }
  if (puVar7[1] == 1) {
    uStack_3c = (uint)*(byte *)(_DAT_3ffbfc54 + 0x360);
    uStack_38 = (uint)*(byte *)(_DAT_3ffbfc54 + 0x361);
    uVar10 = 0x3f433606;
    if (uVar4 == 2) {
LAB_4014d1d0:
      FUN_40147fe4(1,8,4,uVar10);
      memw();
      iStack_40 = 1;
LAB_4014d618:
      if (uStack_3c == 0) {
        uVar3 = 0;
        puVar7 = (ushort *)0x1;
        uVar4 = 0;
      }
      else {
        if (uStack_38 != 0) {
LAB_4014d468:
          uVar10 = 0x3f434dd2;
          uVar14 = 3;
          uVar12 = 0x20;
          memw();
          goto LAB_4014d133;
        }
        puVar7 = (ushort *)0x1;
        uVar3 = 0;
        uVar4 = 0;
LAB_4014d475:
        if ((uVar4 & 0x80) != 0) {
          if (((byte)(DAT_3ffc89ee - 0xbU) < 2) || (DAT_3ffc89ee == '\x03')) {
            _DAT_3ffc89f4 = 1;
            memw();
            memw();
          }
          else {
            memw();
            uStack_34 = uVar4;
            puStack_2c = puVar7;
            FUN_40147fe4(1,0x20,2,0x3f4366ef);
            _DAT_3ffc89f4 = 0;
            memw();
            memw();
            puVar7 = puStack_2c;
            uVar4 = uStack_34;
          }
        }
      }
    }
    else {
      if (uVar4 - 3 < 3) {
        uVar12 = 4;
        pcVar16 = "input.c";
        uVar10 = 8;
        uVar14 = 0x3f4335f4;
        memw();
        goto LAB_4014d10e;
      }
      memw();
      puStack_2c = puVar7;
      uVar2 = FUN_4014c228(puVar7 + 2,local_50);
      if ((uVar2 & 0xffffffdf) == 0) {
        return 0;
      }
      DAT_3ffc89f0 = (undefined1)uVar2;
      memw();
      uVar10 = 0x3f4335e3;
      if (uVar4 == 6) goto LAB_4014d1d0;
      if (uVar4 == 7) {
        pcVar16 = "r suite";
        uVar12 = 4;
        uVar10 = 8;
        uVar14 = 0x3f4335d1;
        memw();
        goto LAB_4014d10e;
      }
      iVar5 = uVar4 - 8;
      uVar4 = (uint)puStack_2c[4];
      if (uVar4 == 0 && iVar5 == 0) {
        uVar10 = 0x3f4335b8;
        goto LAB_4014d1d0;
      }
      iVar9 = 0;
      if (uVar4 != 0) {
        iVar9 = 4;
      }
      pcVar16 = "e count";
      uVar14 = 0x3f4335a6;
      if (((uint)((iVar5 >> 0x1f) - iVar5) >> 0x1f & (uint)(iVar5 < iVar9)) != 0) {
LAB_4014d411:
        uVar12 = 4;
        uVar10 = 8;
LAB_4014d10e:
        memw();
        FUN_40147fe4(1,uVar10,uVar12,uVar14,pcVar16);
        return 0;
      }
      puVar7 = puStack_2c + 5;
      iStack_40 = 1;
      if (uVar4 != 0) {
        DAT_3ffc89ee = ' ';
        memw();
        memw();
        for (uVar2 = 0; ((iVar5 >> 0x1f) - iVar5 < 0 && (uVar2 < uVar4)); uVar2 = uVar2 + 1) {
          memw();
          uStack_30 = uVar4;
          puStack_2c = puVar7;
          uVar4 = FUN_4014c228(puVar7,local_50);
          if (uVar4 != 0x20) {
            memw();
            uStack_34 = uVar4;
            iVar9 = FUN_4014cf40();
            if (iVar9 != 0) {
              DAT_3ffc89ee = (char)uStack_34;
              memw();
            }
          }
          iVar5 = iVar5 + -4;
          puVar7 = puStack_2c + 2;
          uVar4 = uStack_30;
        }
        iStack_40 = 0;
      }
      if (DAT_3ffc89ee == ' ') {
        uVar10 = 0x3f433596;
        memw();
        goto LAB_4014d595;
      }
      if (iVar5 == 0) {
        uVar10 = 0x3f433585;
LAB_4014d2c2:
        FUN_40147fe4(1,8,4,uVar10);
        goto LAB_4014d618;
      }
      if (iVar5 == 1) {
        pcVar16 = "r suite";
        uVar10 = 0x3f433573;
        goto LAB_4014d3f9;
      }
      pcVar13 = (char *)(uint)*puVar7;
      iVar5 = iVar5 + -2;
      if (pcVar13 == (char *)0x0 && iVar5 == 0) {
        uVar10 = 0x3f43355a;
        goto LAB_4014d2c2;
      }
      iVar9 = 4;
      if (pcVar13 == (char *)0x0) {
        iVar9 = 0;
      }
      pcVar16 = "e count";
      uVar14 = 0x3f433548;
      if (((uint)((iVar5 >> 0x1f) - iVar5) >> 0x1f & (uint)(iVar5 < iVar9)) != 0) goto LAB_4014d411;
      puVar11 = (uint *)(puVar7 + 1);
      uVar3 = 0;
      if (pcVar13 == (char *)0x0) {
        if (iVar5 != 0) {
          puVar7 = (ushort *)0x1;
LAB_4014d38d:
          if (iVar5 == 1) {
            pcVar16 = "M suite";
            uVar10 = 0x3f433536;
            goto LAB_4014d3f9;
          }
          goto LAB_4014d3a0;
        }
        goto LAB_4014d618;
      }
      DAT_3ffc89ed = 0xe;
      memw();
      memw();
      pcVar16 = (char *)0x0;
      for (; 0 < iVar5; iVar5 = iVar5 + -4) {
        if (pcVar13 <= pcVar16) {
          puVar7 = (ushort *)0x0;
          goto LAB_4014d38d;
        }
        uVar4 = *puVar11;
        if (uVar4 == 0x2ac0f00) {
          iVar9 = 1;
LAB_4014d360:
          uVar6 = (&DAT_3f423b40)[iVar9];
        }
        else {
          if (0x2ac0f00 < uVar4) {
            if (uVar4 == 0x6ac0f00) {
              iVar9 = 5;
            }
            else if (uVar4 == 0x8ac0f00) {
              iVar9 = 7;
            }
            else {
              if (uVar4 != 0x5ac0f00) goto LAB_4014d36c;
              iVar9 = 4;
            }
            goto LAB_4014d360;
          }
          if ((uVar4 != 0xac0f00) && (iVar9 = 0, uVar4 == 0x1ac0f00)) goto LAB_4014d360;
LAB_4014d36c:
          uVar6 = 0;
        }
        uVar3 = uVar3 | uVar6;
        puVar11 = puVar11 + 1;
        pcVar16 = pcVar16 + 1;
      }
      puVar7 = (ushort *)0x0;
      if (iVar5 != 0) {
LAB_4014d3a0:
        uVar4 = (uint)(ushort)*puVar11;
        if (iVar5 != 2) {
          if (iVar5 == 3) {
            pcVar16 = "ite";
            uVar10 = 0x3f433524;
LAB_4014d3f9:
            FUN_40147fe4(1,8,4,uVar10,pcVar16);
            return 0;
          }
          uVar2 = (uint)*(ushort *)((int)puVar11 + 2);
          iVar5 = iVar5 + -4;
          uVar15 = (uint)(iVar5 < (int)(uVar2 * 0x10));
          if (((uint)((iVar5 >> 0x1f) - iVar5) >> 0x1f & uVar15) != 0) {
            pcVar16 = "D count";
            uVar10 = 0x3f433512;
            goto LAB_4014d3f9;
          }
          iVar5 = iVar5 + uVar2 * -0x10;
          if (iVar5 != 0) {
            if (iVar5 - 1U < 3) {
              pcVar16 = "ID list";
              uVar14 = 0x3f433500;
              goto LAB_4014d411;
            }
            memw();
            uStack_34 = uVar4;
            puStack_2c = puVar7;
            pcVar16 = (char *)FUN_4014c228(puVar11 + uVar2 * 4 + 1,local_50,uVar2 * 0x10,uVar15,
                                           pcVar16);
            if (((char *)0x1 < pcVar16 + -0xd) && (pcVar16 != &DAT_00000009)) {
              uVar14 = 0x3f436741;
              uVar12 = 2;
              uVar10 = 0x20;
              goto LAB_4014d10e;
            }
            DAT_3ffc89f6 = SUB41(pcVar16,0);
            memw();
            puVar7 = puStack_2c;
            uVar4 = uStack_34;
          }
        }
        if (uStack_3c == 0) {
          if ((uVar4 & 0x40) != 0) {
            return 0;
          }
          goto LAB_4014d4c7;
        }
        if ((uStack_38 == 0) || ((uVar4 & 0x80) != 0)) goto LAB_4014d475;
        goto LAB_4014d468;
      }
      puVar7 = (ushort *)0x0;
      uVar4 = 0;
      if (uStack_3c != 0) {
        puVar7 = (ushort *)0x0;
        uVar4 = 0;
        if (uStack_38 != 0) goto LAB_4014d468;
        goto LAB_4014d475;
      }
    }
LAB_4014d4c7:
    if ((uVar4 & 0x400) != 0) {
      *(undefined1 *)(param_1 + 0x7d) = 1;
      memw();
    }
    if ((uVar4 & 0x800) != 0) {
      *(undefined1 *)(param_1 + 0x7e) = 1;
      memw();
    }
    if (((uVar3 & 0x2000) == 0) || (_DAT_3ffc89a8 == 0)) {
      if ((uVar3 & 0x200) == 0) {
LAB_4014d521:
        if (((uVar3 & 0x400) == 0) || (_DAT_3ffc89a8 == 0)) {
          if (((uVar3 & 0x10) == 0) || (_DAT_3ffc89a8 == 0)) {
            bVar8 = 8;
            if ((uVar3 & 0x100) == 0) {
              if ((uVar3 & 0x20) == 0) goto LAB_4014d54e;
              bVar8 = 5;
            }
          }
          else {
            bVar8 = 4;
          }
        }
        else {
          bVar8 = 10;
        }
        goto LAB_4014d548;
      }
      memw();
      puStack_2c = puVar7;
      iVar5 = FUN_401594d4();
      puVar7 = puStack_2c;
      if ((iVar5 == 0) || (_DAT_3ffc89f4 == 0)) goto LAB_4014d521;
      DAT_3ffc89ed = 9;
      DAT_3ffc89ec = 6;
      memw();
      memw();
    }
    else {
      bVar8 = 0xd;
      memw();
LAB_4014d548:
      memw();
      DAT_3ffc89ed = bVar8;
    }
LAB_4014d54e:
    uVar4 = (uint)DAT_3ffc89ed;
    uVar10 = 0x3f4334f4;
    if (uVar4 != 0xe) {
      if (_DAT_3ffc89a8 == 0) {
        if ((uVar4 < 0xe) && ((0x2410U >> (uVar4 & 0x1f) & 1) == 1)) {
          uVar10 = 0x3f4334b3;
LAB_4014d595:
          FUN_40147fe4(1,8,4,uVar10);
          return 0;
        }
      }
      else if ((0xd < uVar4) || ((1 << (DAT_3ffc89ed & 0x1f) & 0x2410U) == 0)) {
        uVar10 = 0x3f4334d7;
        memw();
        goto LAB_4014d12d;
      }
      if ((iStack_40 == 0) && (puVar7 == (ushort *)0x0)) {
        DAT_3ffc89f3 = 1;
        memw();
      }
      else {
        FUN_40147fe4(1,8,4,0x3f43348d,puVar7,iStack_40);
        DAT_3ffc89f3 = 0;
        memw();
        memw();
      }
      if (uVar3 == 0x220) {
        uVar1 = 7;
        memw();
      }
      else if (uVar3 == 0x200) {
        uVar1 = 6;
      }
      else {
        if (_DAT_3ffc89a8 != 0) {
          if ((uVar3 & 0x2000) != 0) {
            uVar1 = 9;
            goto LAB_4014d602;
          }
          if ((uVar3 & 0x410) != 0) {
            uVar1 = 5;
            goto LAB_4014d602;
          }
        }
        uVar1 = 3;
      }
LAB_4014d602:
      *(undefined1 *)(param_1 + 0x7c) = uVar1;
      memw();
      memw();
      return 1;
    }
  }
  else {
    uVar10 = 0x3f433617;
  }
LAB_4014d12d:
  uVar14 = 4;
  uVar12 = 8;
LAB_4014d133:
  FUN_40147fe4(1,uVar12,uVar14,uVar10);
  return 0;
}

