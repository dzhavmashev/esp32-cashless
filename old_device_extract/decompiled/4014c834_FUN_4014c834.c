// Function : FUN_4014c834
// Address  : 0x4014c834
// Size     : 1468 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_4014c834(int *param_1,int param_2,int *param_3,char param_4,undefined4 param_5)

{
  undefined1 uVar1;
  ushort uVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  byte bVar7;
  char *pcVar8;
  int iVar9;
  byte *pbVar10;
  int iVar11;
  undefined4 uVar12;
  char cVar13;
  int iVar14;
  undefined4 uVar15;
  
  if ((param_1 == (int *)0x0) || (*param_1 == 0)) {
    memw();
    FUN_40147fe4(1,0x800,1,"",&DAT_3f423a7d,0x20e);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  uVar2 = *(ushort *)(param_2 + 0x16);
  if (uVar2 < 0xc) {
    return 1;
  }
  iVar9 = *(int *)(*(int *)(param_2 + 4) + 4);
  iVar11 = iVar9 + 10;
  pbVar10 = (byte *)(iVar9 + 0x24);
  memw();
  (*(code *)&SUB_4008b530)(param_3,0,0x84);
  uVar15 = 2;
  *(undefined2 *)((int)param_3 + 10) = *(undefined2 *)(iVar9 + 0x20);
  memw();
  *(undefined2 *)((int)param_3 + 6) = *(undefined2 *)(iVar9 + 0x22);
  memw();
  *param_3 = iVar11;
  param_3[7] = iVar9 + 0x18;
  iVar9 = iVar9 + 0x18 + (uint)uVar2;
  uVar1 = *(undefined1 *)(*(int *)(param_2 + 0x2c) + 8);
  *(undefined1 *)((int)param_3 + 5) = uVar1;
  *(undefined1 *)(param_3 + 1) = uVar1;
  memw();
  param_3[5] = iVar9 - (int)pbVar10;
  uVar12 = 0;
  if (param_4 == '\0') {
    uVar15 = 0;
  }
  else {
    uVar12 = 2;
  }
  param_3[4] = (int)pbVar10;
  bVar4 = false;
  bVar3 = false;
  memw();
  do {
    iVar14 = iVar9 - (int)pbVar10;
    if (iVar14 < 2) {
      iVar9 = param_3[10];
      uVar5 = 2;
      if (iVar9 != 0) {
        uVar5 = 0;
        if (0xf < *(byte *)(iVar9 + 1)) {
          uVar5 = 2;
        }
        if ((param_3[0xb] != 0) &&
           ((int)(0xf - (uint)*(byte *)(iVar9 + 1)) < (int)(uint)*(byte *)(param_3[0xb] + 1))) {
          uVar5 = uVar5 | 4;
        }
      }
      if ((param_3[9] == 0) || (0x20 < *(byte *)(param_3[9] + 1))) {
        uVar5 = uVar5 | 8;
      }
      if ((param_3[8] != 0) && (*(byte *)(param_3[8] + 1) < 3)) {
        param_3[8] = 0;
      }
      if (((_DAT_3ffc8864 != 0) && (param_3[0x13] != 0)) && (*(byte *)(param_3[0x13] + 1) < 3)) {
        uVar5 = uVar5 | 0x80;
      }
      pcVar8 = (char *)param_3[0x11];
      if (pcVar8 != (char *)0x0) {
        bVar7 = 0x1e;
        if (*pcVar8 != -0x23) {
          bVar7 = 0x1a;
        }
        if ((byte)pcVar8[1] < bVar7) {
          param_3[0x11] = 0;
        }
      }
      pcVar8 = (char *)param_3[0x12];
      if (pcVar8 == (char *)0x0) {
        if (!bVar4) {
          return 0xffffffff;
        }
      }
      else {
        bVar7 = 0x1a;
        if (*pcVar8 != -0x23) {
          bVar7 = 0x16;
        }
        if ((byte)pcVar8[1] < bVar7) {
          param_3[0x12] = 0;
        }
        if (!bVar4) {
          pcVar8 = (char *)param_3[0x12];
          if (*pcVar8 == -0x23) {
            pcVar8 = pcVar8 + 4;
          }
          *(char *)(param_3 + 1) = pcVar8[2];
          memw();
          memw();
        }
      }
      if ((param_3[0x20] != 0) && ((iVar9 == 0 || (0x14 < *(byte *)(iVar9 + 1))))) {
        uVar5 = uVar5 | 0x100;
      }
      bVar7 = *(byte *)(param_3 + 1);
      uVar6 = FUN_40155040();
      if (uVar6 <= bVar7) {
        bVar7 = *(byte *)(param_3 + 1);
        uVar6 = FUN_40155000();
        if (bVar7 <= uVar6) {
          return uVar5;
        }
      }
      FUN_40147fe4(1,8,4,0x3f43363e,(char)param_3[1]);
      return 0xffffffff;
    }
    if (iVar14 <= (int)(pbVar10[1] + 1)) {
      return 1;
    }
    bVar7 = *pbVar10;
    if (bVar7 == 0x2d) {
LAB_4014cc24:
      param_3[0x11] = (int)pbVar10;
      memw();
    }
    else if (bVar7 < 0x2e) {
      if (bVar7 == 5) {
        param_3[6] = (int)pbVar10;
        if ((**(uint **)(param_2 + 0x2c) & 0x40000) == 0) {
          cVar13 = *(char *)(*(int *)(param_2 + 4) + 4);
        }
        else {
          cVar13 = (char)*(undefined4 *)(*(int *)(param_2 + 4) + 4) + '\x04';
          memw();
        }
        *(char *)(param_3 + 3) = (char)pbVar10 - cVar13;
        memw();
        memw();
      }
      else if (bVar7 < 6) {
        if (bVar7 == 1) {
          param_3[10] = (int)pbVar10;
          memw();
        }
        else if (bVar7 == 0) {
          if (!bVar3) {
            param_3[9] = (int)pbVar10;
            bVar3 = true;
            memw();
          }
        }
        else if (bVar7 == 3) {
          *(byte *)(param_3 + 1) = pbVar10[2];
          memw();
          bVar4 = true;
          memw();
        }
      }
      else if (bVar7 == 0x25) {
        param_3[0x13] = (int)pbVar10;
        memw();
      }
      else if (bVar7 == 0x2a) {
        if (pbVar10[1] == 1) {
          *(ushort *)(param_3 + 2) = pbVar10[2] | 0x100;
          memw();
          memw();
        }
      }
      else if (bVar7 == 7) {
        param_3[8] = (int)pbVar10;
        memw();
      }
    }
    else if (bVar7 == 0x44) {
      param_3[0xe] = (int)pbVar10;
      memw();
    }
    else if (bVar7 < 0x45) {
      if (bVar7 == 0x32) {
        param_3[0xb] = (int)pbVar10;
        memw();
      }
      else if (bVar7 == 0x3d) {
        param_3[0x12] = (int)pbVar10;
        memw();
      }
      else if (bVar7 == 0x30) {
        param_3[0xf] = (int)pbVar10;
        memw();
      }
    }
    else if (bVar7 == 0x7f) {
      param_3[0x1e] = (int)pbVar10;
      memw();
    }
    else if (bVar7 < 0x80) {
      if (bVar7 == 0x4a) {
        param_3[0x1d] = (int)pbVar10;
        memw();
      }
    }
    else {
      if (bVar7 != 0xdd) {
        if (bVar7 != 0xf4) goto LAB_4014cc60;
        param_3[0x20] = (int)pbVar10;
      }
      bVar7 = pbVar10[1];
      if (bVar7 < 4) goto LAB_4014cda4;
      if (*(int *)(pbVar10 + 2) == 0x1f25000) {
        memw();
        param_3[0xd] = (int)pbVar10;
        memw();
      }
      else {
        if (bVar7 < 6) {
LAB_4014ca90:
          if (*(int *)(pbVar10 + 2) == 0x4f25000) {
            param_3[0x14] = (int)pbVar10;
            memw();
            goto LAB_4014cc60;
          }
        }
        else if (*(int *)(pbVar10 + 2) == 0x2f25000) {
          if ((pbVar10[6] == 1) || (pbVar10[6] == 0)) {
            param_3[0x10] = (int)pbVar10;
            memw();
            goto LAB_4014cc60;
          }
        }
        else if (3 < bVar7) goto LAB_4014ca90;
LAB_4014cda4:
        if (((_DAT_3ffc8874 == 0) || (bVar7 < 4)) || (*(int *)(pbVar10 + 2) != 0x734fe18)) {
          if ((_DAT_3ffc8864 == 0) || (iVar14 = (*_DAT_3ffc79b0)(pbVar10,iVar11), iVar14 != 0)) {
            bVar7 = pbVar10[1];
            if (bVar7 < 4) {
LAB_4014cdc4:
              if ((*(uint *)(*param_1 + 0x158) & 0x10000000) == 0) {
                if (((3 < bVar7) && (*(int3 *)(pbVar10 + 2) != 0x34fe18)) &&
                   (_DAT_3ffc88b8 != (code *)0x0)) {
                  (*_DAT_3ffc88b8)(_DAT_3ffc88bc,uVar15,iVar11,pbVar10,param_5);
                }
              }
              else if (3 < bVar7) {
                if (*(int *)(pbVar10 + 2) == 0x334c9000) {
                  iVar14 = param_3[0x11];
                }
                else {
                  if (*(int *)(pbVar10 + 2) != 0x344c9000) goto LAB_4014cc60;
                  iVar14 = param_3[0x12];
                }
                if (iVar14 == 0) goto LAB_4014cc24;
              }
            }
            else if (*(int *)(pbVar10 + 2) != 0x334fe18) {
              if (*(int *)(pbVar10 + 2) != -0x22cb01e8) goto LAB_4014cdc4;
              if (_DAT_3ffc888c != (code *)0x0) {
                (*_DAT_3ffc888c)(uVar12,iVar11,pbVar10 + 7,pbVar10 + 10,bVar7 - 8,param_5);
              }
            }
          }
          else {
            iVar14 = (*_DAT_3ffc79f4)(pbVar10);
            if (iVar14 == 0) {
              iVar14 = (*_DAT_3ffc79fc)(pbVar10);
              if (iVar14 == 0) {
                iVar14 = (*_DAT_3ffc7a00)(pbVar10);
                if (iVar14 == 0) {
                  iVar14 = (*_DAT_3ffc7a04)(pbVar10);
                  if (iVar14 == 0) {
                    iVar14 = (*_DAT_3ffc7a08)(pbVar10);
                    if (iVar14 == 0) {
                      iVar14 = (*_DAT_3ffc7a0c)(pbVar10);
                      if (iVar14 == 0) {
                        iVar14 = (*_DAT_3ffc79f8)(pbVar10);
                        if (iVar14 == 0) {
                          iVar14 = (*_DAT_3ffc7a10)(pbVar10);
                          if (iVar14 != 0) {
                            param_3[0x1b] = (int)pbVar10;
                            memw();
                          }
                        }
                        else {
                          param_3[0x1a] = (int)pbVar10;
                          memw();
                        }
                      }
                      else {
                        param_3[0x19] = (int)pbVar10;
                        memw();
                      }
                    }
                    else {
                      param_3[0x18] = (int)pbVar10;
                      memw();
                    }
                  }
                  else {
                    param_3[0x17] = (int)pbVar10;
                    memw();
                  }
                }
                else {
                  param_3[0x16] = (int)pbVar10;
                  memw();
                }
              }
              else {
                param_3[9] = (int)(pbVar10 + 7);
                memw();
              }
            }
            else {
              param_3[0x15] = (int)pbVar10;
              memw();
            }
          }
        }
        else {
          *(undefined1 *)(param_3 + 0x1c) = 1;
          memw();
          memw();
        }
      }
    }
LAB_4014cc60:
    pbVar10 = pbVar10 + pbVar10[1] + 2;
  } while( true );
}

