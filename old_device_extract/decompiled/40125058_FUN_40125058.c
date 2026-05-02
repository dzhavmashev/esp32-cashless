// Function : FUN_40125058
// Address  : 0x40125058
// Size     : 1021 bytes


undefined4 FUN_40125058(int *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  byte bVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  byte bVar7;
  
  if ((param_1 != (int *)0x0) && ((*(byte *)(param_1 + 0x67) & 2) == 0)) {
    *(byte *)(param_1 + 0x67) = *(byte *)(param_1 + 0x67) | 2;
    memw();
    do {
      bVar3 = *(byte *)(param_1 + 0x67);
      if ((bVar3 & 4) != 0) break;
      *(byte *)(param_1 + 0x67) = bVar3 & 0xfe;
      memw();
      *(uint *)(*(int *)*param_1 + 200) = bVar3 & 4;
      if (param_1[6] == 0) {
        if (param_1[10] != 0) goto LAB_401250d0;
        if (param_1[7] == 0) {
          if (param_1[8] == 0) {
            if (param_1[9] == 0) {
              if (param_1[0x62] != 0) {
                memw();
                iVar6 = FUN_40102858(param_1 + 0x13,0x20);
                if (iVar6 == 0) {
                  param_1[0xb] = 0;
                  goto LAB_401251c2;
                }
                bVar3 = 1;
                param_1[10] = 1;
                bVar7 = *(byte *)(param_1 + 0x67);
                memw();
                goto LAB_401250e1;
              }
              uVar5 = param_1[4];
              if (uVar5 == 5) goto LAB_401250d0;
              if (uVar5 < 6) {
                if (uVar5 == 2) goto LAB_401250c1;
                if (uVar5 < 3) {
                  if (uVar5 == 1) {
                    *(byte *)(param_1 + 0x67) = *(byte *)(param_1 + 0x67) | 1;
                    memw();
                    param_1[4] = 2;
                    param_1[7] = 0;
                    memw();
                  }
                }
                else {
                  if (uVar5 == 3) goto LAB_4012518e;
                  if ((uVar5 == 4) && ((param_1[0x6f] & 0xd42U) != 0)) {
                    *(byte *)(param_1 + 0x67) = *(byte *)(param_1 + 0x67) | 1;
                    memw();
                    param_1[4] = 6;
                    memw();
                    iVar6 = FUN_40124438(param_1 + 2,0);
                    if (iVar6 != 0) {
                      (*(code *)&SUB_4008b3d0)(param_1 + 0x23,iVar6,0x20);
                    }
                    param_1[0x6a] = 0;
                    memw();
                  }
                }
              }
              else if (uVar5 == 8) {
                if (param_1[0x11] == 0) {
                  if (((param_1[0xe] == 0) || (param_1[0x10] != 0)) || (param_1[0xf] == 0)) {
LAB_40125316:
                    if (param_1[0xd] != 0) {
LAB_401251c2:
                      memw();
                      FUN_40124c68(param_1);
                    }
                  }
                  else {
LAB_4012527c:
                    FUN_40124450(param_1);
                  }
                }
                else {
                  *(byte *)(param_1 + 0x67) = *(byte *)(param_1 + 0x67) | 1;
                  memw();
                  param_1[4] = 9;
                  param_1[0xb] = 0;
                  memw();
                }
              }
              else if (uVar5 < 9) {
                if (uVar5 == 6) {
                  iVar6 = FUN_40124438(param_1 + 2,0);
                  if (iVar6 != 0) goto LAB_401251c2;
                }
                else {
                  if (uVar5 != 7) goto LAB_40125125;
                  if (((param_1[0xe] != 0) && (param_1[0x10] == 0)) && (param_1[0xf] != 0))
                  goto LAB_4012527c;
                  if (param_1[0xb] < 5) goto LAB_40125316;
                }
LAB_401250d0:
                FUN_40124554(param_1);
              }
              else if (uVar5 == 9) {
LAB_401253a9:
                FUN_40124e4c(param_1);
              }
              else if (uVar5 == 10) {
                if ((*(byte *)(param_1 + 0x67) & 0x40) != 0) goto LAB_4012527c;
                if ((((param_1[0xe] == 0) || (param_1[0x10] != 0)) || (param_1[0xf] == 0)) ||
                   (param_1[0x11] == 0)) {
                  if (4 < param_1[0xb]) goto LAB_401250d0;
                  if (param_1[0xd] != 0) goto LAB_401253a9;
                }
                else {
                  *(byte *)(param_1 + 0x67) = *(byte *)(param_1 + 0x67) | 1;
                  memw();
                  param_1[4] = 0xb;
                  piVar4 = param_1 + 2;
                  param_1[0xe] = 0;
                  if (param_1[0x48] != 0) {
                    memw();
                    uVar1 = FUN_4018514c(param_1[0x6e]);
                    memw();
                    uVar2 = FUN_4018511c(param_1[0x6e]);
                    iVar6 = FUN_4015a608(uVar1,piVar4,0,param_1 + 0x39,uVar2);
                    if (iVar6 != 0) {
                      FUN_4015a5bc(piVar4,0xf);
                      goto LAB_40125125;
                    }
                    param_1[0x46] = 1;
                    if (*(int *)(*param_1 + 0x20) != 0) {
                      memw();
                      FUN_4018509c(&DAT_40125480,*param_1,param_1);
                      FUN_401850a4(*(undefined4 *)(*param_1 + 0x20),0,&DAT_40125480,*param_1,param_1
                                  );
                    }
                  }
                  if (param_1[0x6d] == 1) {
                    param_1[0x61] = 1;
                  }
                  else {
                    param_1[99] = 1;
                    memw();
                  }
                  memw();
                  FUN_4015a284(piVar4);
                }
              }
            }
            else {
LAB_4012518e:
              FUN_40124580(param_1);
            }
          }
          else {
            *(byte *)(param_1 + 0x67) = *(byte *)(param_1 + 0x67) | 1;
            memw();
            param_1[4] = 3;
            memw();
            (*(code *)&SUB_4008b530)(param_1 + 0x2b,0,0x68);
            param_1[0x45] = 0;
            param_1[8] = 0;
          }
        }
        else {
          bVar7 = 1;
          bVar3 = *(byte *)(param_1 + 0x67);
LAB_401250e1:
          *(byte *)(param_1 + 0x67) = bVar3 | bVar7;
          memw();
          param_1[4] = 2;
          param_1[7] = 0;
          memw();
        }
      }
      else {
LAB_401250c1:
        memw();
        FUN_40124ff4(param_1);
      }
LAB_40125125:
      bVar3 = *(byte *)(param_1 + 0x67);
      if ((bVar3 & 4) != 0) break;
      if ((param_1[6] == 0) && (param_1[100] == 0)) {
        uVar5 = param_1[5];
        if (uVar5 == 1) {
          if ((((param_1[0xe] == 0) || (param_1[0x10] != 0)) || (param_1[0xf] != 0)) ||
             (param_1[0x11] == 0)) {
            if (param_1[0xc] < 5) {
              iVar6 = param_1[0xd];
LAB_401253e9:
              if (iVar6 != 0) goto LAB_401253ec;
            }
            else {
              *(byte *)(param_1 + 0x67) = *(byte *)(param_1 + 0x67) | 1;
              memw();
              param_1[5] = 3;
              if (param_1[0x12] != 0) {
                *(int *)(param_1[1] + 0xc) = *(int *)(param_1[1] + 0xc) + -1;
              }
              param_1[0x12] = 0;
              param_1[10] = 1;
              memw();
            }
          }
          else {
            *(byte *)(param_1 + 0x67) = bVar3 | 1;
            memw();
            param_1[5] = 2;
            param_1[0xe] = 0;
            if (param_1[0x12] != 0) {
              *(int *)(param_1[1] + 0xc) = *(int *)(param_1[1] + 0xc) + -1;
            }
            param_1[0x12] = 0;
            param_1[0xc] = 0;
            param_1[99] = 1;
            memw();
          }
        }
        else if (uVar5 == 0) {
          if (param_1[0x12] == 0) {
            if (param_1[0x6d] == 1) {
              iVar6 = param_1[0x61];
              goto LAB_401253e9;
            }
          }
          else {
LAB_401253ec:
            FUN_40124d2c(param_1);
          }
        }
        else if (uVar5 < 4) {
          *(byte *)(param_1 + 0x67) = bVar3 | 1;
          memw();
          param_1[5] = 0;
          param_1[0xc] = 0;
          memw();
        }
      }
      else {
        *(byte *)(param_1 + 0x67) = *(byte *)(param_1 + 0x67) | 1;
        memw();
        param_1[5] = 0;
        if (param_1[6] != 0) {
          *(byte *)(param_1 + 0x67) = *(byte *)(param_1 + 0x67) & 0xfe;
          memw();
        }
        param_1[0xc] = 0;
        param_1[100] = 0;
      }
      if ((*(byte *)(param_1 + 0x67) & 4) != 0) break;
      memw();
      FUN_401245e4(*param_1,param_1[1]);
    } while (((*(byte *)(param_1 + 0x67) & 1) != 0) || (*(int *)(*(int *)*param_1 + 200) != 0));
    bVar3 = *(byte *)(param_1 + 0x67);
    *(byte *)(param_1 + 0x67) = bVar3 & 0xfd;
    memw();
    if ((bVar3 & 4) != 0) {
      memw();
      FUN_40124070(param_1);
      return 1;
    }
  }
  return 0;
}

