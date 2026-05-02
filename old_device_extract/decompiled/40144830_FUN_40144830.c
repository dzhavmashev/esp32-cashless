// Function : FUN_40144830
// Address  : 0x40144830
// Size     : 2292 bytes


int FUN_40144830(undefined4 *param_1,byte *param_2,int param_3,int param_4,code *param_5,
                undefined4 param_6)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  uint *puVar5;
  byte *pbVar6;
  undefined4 *puVar7;
  byte *pbVar8;
  byte *pbVar9;
  undefined4 *puVar10;
  byte *pbVar11;
  uint *puVar12;
  int iVar13;
  undefined4 *puVar14;
  undefined1 *puVar15;
  byte *pbStack_c4;
  undefined4 *puStack_c0;
  int iStack_a0;
  byte *local_9c;
  int iStack_98;
  int iStack_94;
  uint uStack_90;
  int iStack_8c;
  uint uStack_88;
  int iStack_84;
  int iStack_80;
  undefined4 uStack_7c;
  int iStack_78;
  int iStack_74;
  undefined4 uStack_70;
  undefined1 auStack_6c [4];
  int iStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  int iStack_5c;
  byte *pbStack_58;
  uint uStack_54;
  uint uStack_50;
  byte *pbStack_4c;
  undefined1 *puStack_48;
  undefined1 uStack_44;
  undefined1 *puStack_40;
  
  puStack_c0 = (undefined4 *)0x0;
  puVar14 = param_1;
  do {
    puVar10 = puVar14;
    if (puVar10[7] == 0) goto LAB_4014486e;
    puVar14 = (undefined4 *)puVar10[0x55];
    puStack_c0 = puVar10;
  } while ((undefined4 *)puVar10[0x55] != (undefined4 *)0x0);
  memw();
  iVar2 = FUN_4013ae30(1,0x158);
  puVar10[0x55] = iVar2;
  if (iVar2 == 0) {
    return -0x2880;
  }
  memw();
  FUN_4014471c();
  puVar10 = (undefined4 *)puVar10[0x55];
LAB_4014486e:
  memw();
  (*(code *)&SUB_4008b530)(&iStack_84,0,0xc);
  (*(code *)&SUB_4008b530)(&iStack_78,0,0xc);
  (*(code *)&SUB_4008b530)(auStack_6c,0,0xc);
  if ((puVar10 == (undefined4 *)0x0) || (param_2 == (byte *)0x0)) {
    iVar2 = -0x2800;
    goto LAB_401448cc;
  }
  memw();
  iStack_a0 = param_3;
  local_9c = param_2;
  iVar2 = FUN_40141738(&local_9c,param_2 + param_3,&iStack_a0);
  if (iVar2 != 0) {
    FUN_40144730(puVar10);
    iVar2 = -0x2180;
    goto LAB_401448cc;
  }
  pbStack_c4 = local_9c + iStack_a0;
  puVar10[2] = (int)pbStack_c4 - (int)param_2;
  if (param_4 == 0) {
    puVar10[3] = param_2;
    *puVar10 = 0;
    memw();
  }
  else {
    memw();
    local_9c = (byte *)FUN_4013ae30(1);
    puVar10[3] = local_9c;
    if (local_9c == (byte *)0x0) {
      iVar2 = -0x2880;
      local_9c = (byte *)0x0;
      goto LAB_401448cc;
    }
    memw();
    (*(code *)&SUB_4008b3d0)(local_9c,param_2,puVar10[2]);
    *puVar10 = 1;
    pbStack_c4 = local_9c + puVar10[2];
    local_9c = local_9c + (puVar10[2] - iStack_a0);
  }
  puVar10[6] = local_9c;
  memw();
  iVar2 = FUN_40141738(&local_9c,pbStack_c4,&iStack_a0);
  if (iVar2 != 0) {
    FUN_40144730(puVar10);
LAB_40144952:
    iVar2 = iVar2 + -0x2180;
    if (iVar2 == 0) {
      return 0;
    }
    goto LAB_401448cc;
  }
  pbVar9 = local_9c + iStack_a0;
  puVar10[5] = (int)pbVar9 - puVar10[6];
  memw();
  iVar3 = FUN_40141738(&local_9c,pbVar9,&puStack_48,0xa0);
  if (iVar3 == 0) {
    pbVar4 = local_9c + (int)puStack_48;
    iVar3 = FUN_4014180c(&local_9c,pbVar4,puVar10 + 7);
    iVar2 = iVar3 + -0x2200;
    if (iVar3 != 0) goto LAB_401449fc;
    iVar2 = -0x2266;
    if (pbVar4 != local_9c) goto LAB_401449f1;
  }
  else {
    iVar2 = iVar3 + -0x2180;
    if (iVar3 == -0x62) {
      puVar10[7] = 0;
    }
    else {
LAB_401449fc:
      if (iVar2 != 0) goto LAB_401449f1;
    }
  }
  memw();
  iVar2 = FUN_4014377c(&local_9c,pbVar9,puVar10 + 8);
  if (iVar2 == 0) {
    iVar2 = FUN_401437e4(&local_9c,pbVar9,puVar10 + 0xb,&iStack_84);
    if (iVar2 == 0) {
      if (2 < (uint)puVar10[7]) {
        FUN_40144730(puVar10);
        iVar2 = -0x2580;
        goto LAB_401448cc;
      }
      puVar10[7] = puVar10[7] + 1;
      memw();
      iVar2 = FUN_40143d24(puVar10 + 0xb,&iStack_84,puVar10 + 0x52,puVar10 + 0x53,puVar10 + 0x54);
      if (iVar2 == 0) {
        puVar10[0x10] = local_9c;
        memw();
        iVar2 = FUN_40141738(&local_9c,pbVar9,&iStack_a0);
        if (iVar2 != 0) {
LAB_40144a40:
          FUN_40144730(puVar10);
          goto LAB_40144952;
        }
        iVar2 = FUN_401439e8(&local_9c,local_9c + iStack_a0,puVar10 + 0x14);
        if (iVar2 == 0) {
          puVar10[0xf] = (int)local_9c - puVar10[0x10];
          memw();
          iVar2 = FUN_40141738(&local_9c,pbVar9,&puStack_48,0x30);
          if (iVar2 == 0) {
            pbVar4 = local_9c + (int)puStack_48;
            iVar2 = FUN_40143b30(&local_9c,pbVar4,puVar10 + 0x24);
            if (((iVar2 == 0) && (iVar2 = FUN_40143b30(&local_9c,pbVar4,puVar10 + 0x2a), iVar2 == 0)
                ) && (iVar2 = -0x2466, pbVar4 == local_9c)) goto LAB_40144a89;
          }
          else {
            iVar2 = iVar2 + -0x2400;
            if (iVar2 == 0) {
LAB_40144a89:
              puVar10[0x13] = local_9c;
              memw();
              iVar2 = FUN_40141738(&local_9c,pbVar9,&iStack_a0);
              if (iVar2 != 0) goto LAB_40144a40;
              if ((iStack_a0 == 0) ||
                 (iVar2 = FUN_401439e8(&local_9c,local_9c + iStack_a0,puVar10 + 0x1c), iVar2 == 0))
              {
                puVar10[0x12] = (int)local_9c - puVar10[0x13];
                puVar10[0x32] = local_9c;
                memw();
                iVar2 = FUN_4013a9d8(&local_9c,pbVar9,puVar10 + 0x33);
                if (iVar2 == 0) {
                  puVar10[0x31] = (int)local_9c - puVar10[0x32];
                  if (puVar10[7] - 2 < 2) {
                    memw();
                    iVar2 = FUN_40143f18(&local_9c,pbVar9,puVar10 + 0x35,1);
                    if ((iVar2 != 0) ||
                       ((puVar10[7] - 2 < 2 &&
                        (iVar2 = FUN_40143f18(&local_9c,pbVar9,puVar10 + 0x38,2), iVar2 != 0))))
                    goto LAB_401449f1;
                  }
                  if (puVar10[7] == 3) {
                    if (pbVar9 == local_9c) goto LAB_401450b0;
                    iVar2 = FUN_40143d9c(&local_9c,pbVar9,puVar10 + 0x3b);
                    if (iVar2 == 0) {
                      pbVar4 = (byte *)(puVar10[0x3d] + puVar10[0x3c]);
LAB_40144b5e:
                      if (pbVar4 <= local_9c) {
                        if (pbVar4 != local_9c) {
                          memw();
                          goto LAB_40144e31;
                        }
                        goto LAB_40144bf6;
                      }
                      uStack_60 = 0;
                      iStack_5c = 0;
                      pbStack_58 = (byte *)0x0;
                      iStack_94 = 0;
                      uStack_90 = 0;
                      memw();
                      iVar2 = FUN_40141738(&local_9c,pbVar4,&iStack_98,0x30);
                      if (iVar2 != 0) {
LAB_40144bf3:
                        iVar2 = iVar2 + -0x2500;
                        if (iVar2 == 0) goto LAB_40144bf6;
                        goto LAB_401449f1;
                      }
                      pbVar11 = local_9c + iStack_98;
                      iVar2 = FUN_40141738(&local_9c,pbVar11,&iStack_5c,6);
                      if (iVar2 != 0) goto LAB_40144bf3;
                      uStack_60 = 6;
                      pbStack_58 = local_9c;
                      local_9c = local_9c + iStack_5c;
                      memw();
                      iVar2 = FUN_401417d8(&local_9c,pbVar11,&iStack_94);
                      if ((iVar2 != -0x62) && (iVar2 != 0)) goto LAB_40144bf3;
                      iVar2 = FUN_40141738(&local_9c,pbVar11,&iStack_98,4);
                      pbVar1 = local_9c;
                      if (iVar2 != 0) goto LAB_40144bf3;
                      pbVar8 = local_9c + iStack_98;
                      if (pbVar11 == pbVar8) {
                        memw();
                        iVar2 = FUN_401394a0(&uStack_60,&uStack_90);
                        if (iVar2 != 0) {
                          if (param_5 != (code *)0x0) {
                            iVar2 = (*param_5)(param_6,puVar10,&uStack_60,iStack_94,local_9c,pbVar8)
                            ;
                            if ((iVar2 != 0) && (iStack_94 != 0)) goto LAB_401449f1;
LAB_40144c90:
                            memw();
                            local_9c = pbVar8;
                            goto LAB_40144b5e;
                          }
                          local_9c = pbVar11;
                          if (iStack_94 != 0) goto LAB_40144c9d;
                          goto LAB_40144b5e;
                        }
                        puVar15 = (undefined1 *)(puVar10[0x46] & uStack_90);
                        if (puVar15 != (undefined1 *)0x0) {
LAB_40145146:
                          iVar2 = -0x2500;
                          goto LAB_401449f1;
                        }
                        puVar10[0x46] = puVar10[0x46] | uStack_90;
                        if (uStack_90 == 0x20) {
                          iVar2 = FUN_40141738(&local_9c,pbVar11,&iStack_8c,0x30);
                          if (iVar2 == 0) {
                            if (pbVar8 == local_9c + iStack_8c) {
                              puVar12 = puVar10 + 0x3e;
                              while (pbVar11 = local_9c, local_9c < pbVar8) {
                                (*(code *)&SUB_4008b530)(&puStack_48,0,0x28);
                                uStack_54 = (uint)*pbVar11;
                                local_9c = pbVar11 + 1;
                                memw();
                                iVar2 = FUN_40186734(&local_9c,pbVar8,&uStack_88);
                                if (iVar2 != 0) {
                                  iVar2 = iVar2 + -0x2500;
                                  goto LAB_40144e6d;
                                }
                                pbStack_4c = local_9c;
                                uStack_50 = uStack_88;
                                if ((uStack_54 & 0xc0) != 0x80) goto LAB_40144c9d;
                                memw();
                                iVar2 = FUN_40143fe8(&uStack_54,&puStack_48);
                                if ((iVar2 != 0) && (iVar2 != -0x2080)) {
                                  iVar3 = puVar10[0x41];
                                  while (iVar3 != 0) {
                                    iVar13 = *(int *)(iVar3 + 0xc);
                                    FUN_4013ae54(iVar3,0x10);
                                    FUN_4013ae44(iVar3);
                                    iVar3 = iVar13;
                                  }
                                  puVar10[0x41] = 0;
                                  memw();
                                  goto LAB_40144e6d;
                                }
                                puVar5 = puVar12;
                                if (puVar12[2] != 0) {
                                  if (puVar12[3] != 0) goto LAB_40145146;
                                  puVar5 = (uint *)FUN_4013ae30(1,0x10);
                                  puVar12[3] = (uint)puVar5;
                                  if (puVar5 != (uint *)0x0) goto LAB_40144efc;
                                  iVar2 = -0x256a;
                                  goto LAB_401449f1;
                                }
LAB_40144efc:
                                *puVar5 = uStack_54;
                                puVar5[1] = uStack_50;
                                puVar5[2] = (uint)pbStack_4c;
                                local_9c = local_9c + uStack_50;
                                memw();
                                puVar12 = puVar5;
                              }
                              puVar12[3] = 0;
                              if (pbVar8 != local_9c) goto LAB_40144e31;
                              goto LAB_40144b5e;
                            }
                            goto LAB_40144e31;
                          }
                        }
                        else if ((int)uStack_90 < 0x21) {
                          if (uStack_90 != 4) {
                            if (uStack_90 != 8) {
LAB_40144cd1:
                              if (iStack_94 == 0) goto LAB_40144c90;
                              iVar2 = -0x2080;
                              memw();
                              goto LAB_401449f1;
                            }
                            iVar2 = FUN_40141738(&local_9c,pbVar8,&puStack_48,0x30);
                            if (iVar2 == 0) {
                              if ((pbVar8 == local_9c + (int)puStack_48) &&
                                 (puStack_48 != (undefined1 *)0x0)) {
                                iVar2 = 0;
                                puVar14 = puVar10 + 0x42;
                                do {
                                  if (pbVar8 <= local_9c) {
                                    puVar14[3] = 0;
                                    if (pbVar8 == local_9c) goto LAB_40144f79;
                                    memw();
                                    break;
                                  }
                                  iVar3 = FUN_40141738(&local_9c,pbVar8,&puStack_48,0x30);
                                  if (iVar3 != 0) {
LAB_40144fec:
                                    iVar2 = iVar3 + -0x2500;
                                    goto LAB_40144f79;
                                  }
                                  pbVar6 = local_9c + (int)puStack_48;
                                  memw();
                                  iVar3 = FUN_40141738(&local_9c,pbVar6,&puStack_48,6);
                                  puVar15 = puStack_48;
                                  pbVar11 = local_9c;
                                  if (iVar3 != 0) goto LAB_40144fec;
                                  if (puStack_48 == &DAT_00000004) {
                                    memw();
                                    iVar3 = (*(code *)&SUB_4008b33c)(")\n",local_9c,4);
                                    if (iVar3 != 0) goto LAB_4014508d;
                                  }
                                  else {
LAB_4014508d:
                                    iVar2 = -0x2080;
                                  }
                                  puVar7 = puVar14;
                                  if (puVar14[2] != 0) {
                                    if (puVar14[3] != 0) {
                                      iVar2 = -0x2500;
                                      goto LAB_40144f7c;
                                    }
                                    puVar7 = (undefined4 *)FUN_4013ae30(1,0x10);
                                    puVar14[3] = puVar7;
                                    if (puVar7 == (undefined4 *)0x0) {
                                      iVar2 = -0x256a;
                                      goto LAB_40144f7c;
                                    }
                                  }
                                  *puVar7 = 6;
                                  puVar7[1] = puVar15;
                                  local_9c = local_9c + (int)puStack_48;
                                  puVar7[2] = pbVar11;
                                  if (local_9c < pbVar6) {
                                    memw();
                                    iVar3 = FUN_40141738(&local_9c,pbVar6,&puStack_48,0x30);
                                    if (iVar3 != 0) goto LAB_40144fec;
                                    local_9c = local_9c + (int)puStack_48;
                                  }
                                  puVar14 = puVar7;
                                } while (pbVar6 == local_9c);
                              }
                              iVar2 = -0x2566;
                              memw();
                            }
                            else {
                              iVar2 = iVar2 + -0x2500;
LAB_40144f79:
                              if (iVar2 == 0) goto LAB_40144b5e;
                            }
LAB_40144f7c:
                            if ((((iVar2 != -0x2080) || (param_5 == (code *)0x0)) ||
                                (iVar3 = (*param_5)(param_6,puVar10,&uStack_60,iStack_94,pbVar1,
                                                    pbVar8), iVar3 != 0)) &&
                               ((iStack_94 != 0 || (iVar2 != -0x2080)))) goto LAB_401449f1;
                            goto LAB_40144b5e;
                          }
                          uStack_44 = 0;
                          memw();
                          memw();
                          puStack_48 = puVar15;
                          puStack_40 = puVar15;
                          iVar2 = FUN_40141850(&local_9c,pbVar11,&puStack_48);
                          if (iVar2 == 0) {
                            if (puStack_48 == (undefined1 *)0x0) goto LAB_40144dac;
                            puVar10[0x49] = 0;
                            puVar15 = (undefined1 *)0x0;
                            while ((puVar15 < puStack_48 && (puVar15 < &DAT_00000004))) {
                              puVar10[0x49] =
                                   puVar10[0x49] |
                                   (uint)(byte)puStack_40[(int)puVar15] <<
                                   0x20 - (((uint)puVar15 & 3) * -8 + 0x20);
                              memw();
                              puVar15 = puVar15 + 1;
                            }
                            goto LAB_40144b5e;
                          }
                        }
                        else if (uStack_90 == 0x800) {
                          iVar2 = FUN_40141990(&local_9c,pbVar11,puVar10 + 0x4a,6);
                          if (iVar2 == 0) {
                            if (puVar10[0x4c] == 0) {
LAB_40144dac:
                              iVar2 = -0x2564;
                              goto LAB_401449f1;
                            }
                            goto LAB_40144b5e;
                          }
                        }
                        else if (uStack_90 == 0x10000) {
                          uStack_44 = 0;
                          memw();
                          memw();
                          puStack_48 = puVar15;
                          puStack_40 = puVar15;
                          iVar2 = FUN_40141850(&local_9c,pbVar11,&puStack_48);
                          if (iVar2 == 0) {
                            if (puStack_48 != (undefined1 *)0x1) goto LAB_40144dac;
                            *(undefined1 *)(puVar10 + 0x4e) = *puStack_40;
                            memw();
                            memw();
                            goto LAB_40144b5e;
                          }
                        }
                        else {
                          if (uStack_90 != 0x100) goto LAB_40144cd1;
                          puVar10[0x47] = 0;
                          puVar10[0x48] = 0;
                          memw();
                          iVar2 = FUN_40141738(&local_9c,pbVar8,&puStack_48,0x30);
                          if (iVar2 == 0) {
                            if (pbVar8 == local_9c) goto LAB_40144b5e;
                            iVar2 = FUN_401417d8(&local_9c,pbVar8,puVar10 + 0x47);
                            if (iVar2 != 0) {
                              if ((iVar2 != -0x62) ||
                                 (iVar2 = FUN_4014180c(&local_9c,pbVar8,puVar10 + 0x47), iVar2 != 0)
                                 ) goto LAB_40144d10;
                              if (puVar10[0x47] != 0) {
                                puVar10[0x47] = 1;
                              }
                            }
                            if (pbVar8 == local_9c) goto LAB_40144b5e;
                            memw();
                            iVar2 = FUN_4014180c(&local_9c,pbVar8,puVar10 + 0x48);
                            if (iVar2 == 0) {
                              if (pbVar8 != local_9c) goto LAB_40144e31;
                              if (puVar10[0x48] == 0x7fffffff) goto LAB_40144dac;
                              puVar10[0x48] = puVar10[0x48] + 1;
                              memw();
                              goto LAB_40144b5e;
                            }
                          }
                        }
LAB_40144d10:
                        iVar2 = iVar2 + -0x2500;
LAB_40144e6d:
                        if (iVar2 != 0) goto LAB_401449f1;
                        goto LAB_40144b5e;
                      }
LAB_40144e31:
                      iVar2 = -0x2566;
                      memw();
                    }
                  }
                  else {
LAB_40144bf6:
                    if (pbVar9 != local_9c) {
LAB_40144bfe:
                      FUN_40144730(puVar10);
                      iVar2 = -0x21e6;
                      goto LAB_401448cc;
                    }
LAB_401450b0:
                    iVar2 = FUN_401437e4(&local_9c,pbStack_c4,auStack_6c,&iStack_78);
                    if (iVar2 == 0) {
                      if ((((puVar10[0xc] != iStack_68) ||
                           (iVar2 = (*(code *)&SUB_4008b33c)(puVar10[0xd],uStack_64), iVar2 != 0))
                          || (iStack_84 != iStack_78)) ||
                         ((iStack_80 != iStack_74 ||
                          ((iStack_80 != 0 &&
                           (iVar2 = (*(code *)&SUB_4008b33c)(uStack_7c,uStack_70), iVar2 != 0))))))
                      {
                        FUN_40144730(puVar10);
                        iVar2 = -0x2680;
                        goto LAB_401448cc;
                      }
                      iVar2 = FUN_40143ce4(&local_9c,pbStack_c4,puVar10 + 0x4f);
                      if (iVar2 == 0) {
                        if (pbStack_c4 == local_9c) {
                          return 0;
                        }
                        goto LAB_40144bfe;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_401449f1:
  FUN_40144730(puVar10);
LAB_401448cc:
  if (puStack_c0 != (undefined4 *)0x0) {
    puStack_c0[0x55] = 0;
  }
  if (puVar10 != param_1) {
    memw();
    FUN_4013ae44(puVar10);
  }
  return iVar2;
LAB_40144c9d:
  iVar2 = -0x2562;
  memw();
  goto LAB_401449f1;
}

