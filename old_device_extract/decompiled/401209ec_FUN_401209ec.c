// Function : FUN_401209ec
// Address  : 0x401209ec
// Size     : 1630 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401209ec(uint param_1,undefined4 param_2,undefined4 param_3,byte *param_4,
                 undefined4 param_5,undefined4 param_6,int param_7,int param_8,int param_9)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  byte bVar9;
  int iVar10;
  undefined4 uVar11;
  uint uVar12;
  undefined1 uStack_b9;
  uint uStack_b8;
  undefined4 uStack_b4;
  int iStack_ac;
  int iStack_a8;
  int iStack_a4;
  uint uStack_a0;
  undefined4 uStack_9c;
  undefined8 uStack_98;
  undefined1 auStack_90 [16];
  byte *pbStack_80;
  undefined1 auStack_7c [64];
  undefined1 uStack_3c;
  undefined1 auStack_3b [23];
  int iStack_24;
  
  iVar10 = 0x105;
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  uStack_98 = CONCAT44(uStack_98._4_4_,(undefined4)uStack_98);
  if ((DAT_3ffc6d34 != '\0') &&
     (uStack_98 = CONCAT44(uStack_98._4_4_,(undefined4)uStack_98), (param_1 & _DAT_3ffc6d28) != 0))
  {
    memw();
    (*(code *)&SUB_4008b530)(&uStack_98,0,0x70);
    iStack_ac = param_7;
    iStack_a8 = param_8;
    iStack_a4 = param_9;
    memw();
    uStack_a0 = param_1;
    uStack_9c = param_2;
    uStack_98 = FUN_401211d8();
    memw();
    (*(code *)&SUB_4008bfd4)(auStack_90,param_3,0x10);
    uStack_3c = 0x40;
    memw();
    uStack_b9 = 0;
    memw();
    iVar10 = iStack_a4;
    iVar4 = iStack_a8;
    iVar5 = iStack_ac;
    pbStack_80 = param_4;
    goto LAB_40120a69;
  }
  do {
    iVar5 = iStack_24;
    iVar4 = _DAT_3ffc5708;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) {
      return;
    }
    (*(code *)&SUB_40082ec4)();
LAB_40120e84:
    iVar6 = iVar10 + 4;
    iVar3 = iVar4;
    if ((0x18 < iVar6) && (iVar3 = iVar5, iVar10 < 0x19)) {
      iVar6 = 0x24;
    }
    uStack_b8 = *(uint *)(iVar3 + iVar6 + -4);
    uVar11 = 6;
    memw();
LAB_40120d7d:
    memw();
    iVar10 = iVar6;
LAB_40120db8:
    memw();
    iVar3 = FUN_401209a8(auStack_7c,&uStack_b9,uVar11);
    while (iVar3 == 0) {
LAB_40120d29:
      do {
        do {
          param_4 = param_4 + 1;
LAB_40120a69:
          if (*param_4 == 0) goto LAB_40120e40;
        } while (*param_4 != 0x25);
        do {
          param_4 = param_4 + 1;
          if (0x10 < (byte)(*param_4 - 0x20)) break;
        } while ((1 << (*param_4 - 0x20 & 0x1f) & 0x12889U) != 0);
        memw();
        for (; (byte)(*param_4 - 0x30) < 10; param_4 = param_4 + 1) {
        }
        if (*param_4 == 0x2e) {
          do {
            param_4 = param_4 + 1;
          } while ((byte)(*param_4 - 0x30) < 10);
        }
        uVar7 = 0;
        uVar12 = 0;
        for (; bVar2 = *param_4, bVar2 != 0; param_4 = param_4 + 1) {
          if (bVar2 == 0x6a) {
            uVar8 = 5;
LAB_40120b58:
            uVar7 = uVar8;
            uVar12 = 8;
          }
          else if (bVar2 < 0x6b) {
            uVar8 = 8;
            if (bVar2 == 0x4c) goto LAB_40120b58;
            if (bVar2 != 0x68) break;
            bVar1 = uVar7 == 2;
            uVar7 = 2;
            uVar12 = 2;
            if (bVar1) {
              uVar7 = 1;
              uVar12 = 1;
            }
          }
          else {
            if (bVar2 == 0x74) {
              uVar7 = 6;
            }
            else if (bVar2 == 0x7a) {
              uVar7 = 7;
            }
            else {
              if (bVar2 != 0x6c) break;
              if (uVar7 == 3) {
                uVar8 = 4;
                goto LAB_40120b58;
              }
              uVar7 = 3;
            }
            uVar12 = 4;
          }
        }
        uStack_b8 = 0;
        uStack_b4 = 0;
        if (bVar2 == 100) {
LAB_40120cd1:
          if (uVar7 == 3) {
            iVar6 = iVar10 + 4;
            iVar3 = iVar4;
            if ((0x18 < iVar6) && (iVar3 = iVar5, iVar10 < 0x19)) {
              iVar6 = 0x24;
            }
            uStack_b8 = *(uint *)(iVar3 + iVar6 + -4);
            uVar11 = 3;
            iVar10 = iVar6;
            goto LAB_40120db8;
          }
          if (uVar7 < 4) {
            iVar6 = iVar10 + 4;
            if (uVar7 == 1) {
              iVar3 = iVar4;
              if ((0x18 < iVar6) && (iVar3 = iVar5, iVar10 < 0x19)) {
                iVar6 = 0x24;
              }
              uVar11 = 0;
              uStack_b8 = *(uint *)(iVar3 + iVar6 + -4) & 0xff;
              memw();
              goto LAB_40120d4d;
            }
            if (1 < uVar7) {
              iVar3 = iVar4;
              if ((0x18 < iVar6) && (iVar3 = iVar5, iVar10 < 0x19)) {
                iVar6 = 0x24;
              }
              uVar11 = 1;
              uStack_b8 = *(uint *)(iVar3 + iVar6 + -4) & 0xffff;
              memw();
              goto LAB_40120d7d;
            }
LAB_40120ce4:
            iVar6 = iVar10 + 4;
            iVar3 = iVar4;
            if ((0x18 < iVar6) && (iVar3 = iVar5, iVar10 < 0x19)) {
              iVar6 = 0x24;
            }
            uStack_b8 = *(uint *)(iVar3 + iVar6 + -4);
            uVar11 = 2;
LAB_40120d03:
            memw();
            iVar10 = iVar6;
            goto LAB_40120db8;
          }
          if (uVar7 == 5) {
            uVar7 = iVar10 + 7U & 0xfffffff8;
            iVar10 = uVar7 + 8;
            iVar3 = iVar4;
            if ((0x18 < iVar10) && (iVar3 = iVar5, (int)uVar7 < 0x19)) {
              iVar10 = 0x28;
            }
            uStack_b4 = *(undefined4 *)(iVar3 + iVar10 + -4);
            uVar11 = 5;
            uStack_b8 = *(uint *)(iVar3 + iVar10 + -8);
            goto LAB_40120e34;
          }
          if (uVar7 < 5) {
            uVar7 = iVar10 + 7U & 0xfffffff8;
            iVar10 = uVar7 + 8;
            iVar3 = iVar4;
            if ((0x18 < iVar10) && (iVar3 = iVar5, (int)uVar7 < 0x19)) {
              iVar10 = 0x28;
            }
            uStack_b4 = *(undefined4 *)(iVar3 + iVar10 + -4);
            uVar11 = 4;
            uStack_b8 = *(uint *)(iVar3 + iVar10 + -8);
LAB_40120def:
            memw();
            goto LAB_40120e34;
          }
          if (uVar7 == 6) goto LAB_40120e84;
          if (uVar7 == 7) goto LAB_40120ce4;
          goto LAB_40120d29;
        }
        if (100 < bVar2) {
          if (bVar2 < 0x71) {
            if (0x6e < bVar2) {
LAB_40120ea9:
              if (uVar7 == 3) {
                iVar6 = iVar10 + 4;
                iVar3 = iVar4;
                if ((0x18 < iVar6) && (iVar3 = iVar5, iVar10 < 0x19)) {
                  iVar6 = 0x24;
                }
                uStack_b8 = *(uint *)(iVar3 + iVar6 + -4);
                uVar11 = 10;
                memw();
                goto LAB_40120d7d;
              }
              if (uVar7 < 4) {
                iVar6 = iVar10 + 4;
                if (uVar7 == 1) {
                  iVar3 = iVar4;
                  if ((0x18 < iVar6) && (iVar3 = iVar5, iVar10 < 0x19)) {
                    iVar6 = 0x24;
                  }
                  uVar11 = 7;
                  uStack_b8 = *(uint *)(iVar3 + iVar6 + -4) & 0xff;
                  memw();
                  memw();
                  goto LAB_40120d03;
                }
                if (uVar7 < 2) {
LAB_40120ec0:
                  iVar6 = iVar10 + 4;
                  iVar3 = iVar4;
                  if ((0x18 < iVar6) && (iVar3 = iVar5, iVar10 < 0x19)) {
                    iVar6 = 0x24;
                  }
                  uStack_b8 = *(uint *)(iVar3 + iVar6 + -4);
                  uVar11 = 9;
                  memw();
                  goto LAB_40120cbf;
                }
                iVar3 = iVar4;
                if ((0x18 < iVar6) && (iVar3 = iVar5, iVar10 < 0x19)) {
                  iVar6 = 0x24;
                }
                uVar11 = 8;
                uStack_b8 = *(uint *)(iVar3 + iVar6 + -4) & 0xffff;
                memw();
                memw();
              }
              else {
                if (uVar7 == 5) {
                  uVar7 = iVar10 + 7U & 0xfffffff8;
                  iVar10 = uVar7 + 8;
                  iVar3 = iVar4;
                  if ((0x18 < iVar10) && (iVar3 = iVar5, (int)uVar7 < 0x19)) {
                    iVar10 = 0x28;
                  }
                  uStack_b4 = *(undefined4 *)(iVar3 + iVar10 + -4);
                  uVar11 = 0xc;
                  uStack_b8 = *(uint *)(iVar3 + iVar10 + -8);
                  memw();
                  goto LAB_40120def;
                }
                if (uVar7 < 5) {
                  uVar7 = iVar10 + 7U & 0xfffffff8;
                  iVar10 = uVar7 + 8;
                  iVar3 = iVar4;
                  if ((0x18 < iVar10) && (iVar3 = iVar5, (int)uVar7 < 0x19)) {
                    iVar10 = 0x28;
                  }
                  uStack_b4 = *(undefined4 *)(iVar3 + iVar10 + -4);
                  uVar11 = 0xb;
                  uStack_b8 = *(uint *)(iVar3 + iVar10 + -8);
                  goto LAB_40120fb5;
                }
                if (uVar7 == 6) goto LAB_40120ec0;
                if (uVar7 != 7) goto LAB_40120d29;
                iVar6 = iVar10 + 4;
                iVar3 = iVar4;
                if ((0x18 < iVar6) && (iVar3 = iVar5, iVar10 < 0x19)) {
                  iVar6 = 0x24;
                }
                uStack_b8 = *(uint *)(iVar3 + iVar6 + -4);
                uVar11 = 0xd;
                memw();
              }
LAB_40120d4d:
              memw();
              iVar10 = iVar6;
              goto LAB_40120db8;
            }
            if (bVar2 == 0x69) goto LAB_40120cd1;
            if (bVar2 < 0x6a) {
              bVar9 = 0x67;
              goto LAB_40120b6e;
            }
          }
          else {
            if ((bVar2 == 0x75) || (bVar2 == 0x78)) goto LAB_40120ea9;
            if (bVar2 == 0x73) {
              iVar6 = iVar10 + 4;
              iVar3 = iVar4;
              if ((0x18 < iVar6) && (iVar3 = iVar5, iVar10 < 0x19)) {
                iVar6 = 0x24;
              }
              uStack_b8 = *(uint *)(iVar3 + iVar6 + -4);
              if (uStack_b8 != 0) {
                memw();
                (*(code *)&SUB_4008c01c)(uStack_b8);
              }
              uVar11 = 0x10;
              goto LAB_40120d03;
            }
          }
LAB_40120b0c:
          iVar3 = iVar10 + 4;
          if ((0x18 < iVar3) && (iVar10 < 0x19)) {
            iVar3 = 0x24;
          }
          iVar10 = iVar3;
          memw();
          goto LAB_40120d29;
        }
        if (bVar2 == 0x4f) {
LAB_40120bcc:
          iVar6 = iVar10 + 4;
          iVar3 = iVar4;
          if ((0x18 < iVar6) && (iVar3 = iVar5, iVar10 < 0x19)) {
            iVar6 = 0x24;
          }
          uStack_b8 = *(uint *)(iVar3 + iVar6 + -4);
          uVar11 = 0xb;
          memw();
          iVar10 = iVar6;
          goto LAB_40120db8;
        }
        if (0x4f < bVar2) {
          if (bVar2 == 0x58) goto LAB_40120ea9;
          if (bVar2 < 0x59) {
            if (bVar2 == 0x55) goto LAB_40120bcc;
          }
          else {
            if (bVar2 == 0x61) goto LAB_40120b71;
            if (bVar2 == 99) {
              iVar6 = iVar10 + 4;
              iVar3 = iVar4;
              if ((0x18 < iVar6) && (iVar3 = iVar5, iVar10 < 0x19)) {
                iVar6 = 0x24;
              }
              uVar11 = 0;
              uStack_b8 = *(uint *)(iVar3 + iVar6 + -4) & 0xff;
              memw();
              memw();
              goto LAB_40120cbf;
            }
          }
          goto LAB_40120b0c;
        }
        if (bVar2 == 0x44) {
          iVar6 = iVar10 + 4;
          iVar3 = iVar4;
          if ((0x18 < iVar6) && (iVar3 = iVar5, iVar10 < 0x19)) {
            iVar6 = 0x24;
          }
          uStack_b8 = *(uint *)(iVar3 + iVar6 + -4);
          uVar11 = 3;
LAB_40120cbf:
          memw();
          iVar10 = iVar6;
          goto LAB_40120db8;
        }
        if (bVar2 < 0x45) {
          if (bVar2 != 0x41) goto LAB_40120b0c;
        }
        else {
          bVar9 = 0x47;
LAB_40120b6e:
          if (bVar9 < bVar2) goto LAB_40120b0c;
        }
LAB_40120b71:
        if (uVar7 == 3) break;
        if (uVar7 == 8) {
          uVar7 = iVar10 + 7U & 0xfffffff8;
          iVar10 = uVar7 + 8;
          iVar3 = iVar4;
          if ((0x18 < iVar10) && (iVar3 = iVar5, (int)uVar7 < 0x19)) {
            iVar10 = 0x28;
          }
          uStack_b4 = *(undefined4 *)(iVar3 + iVar10 + -4);
          uVar11 = 0xf;
          uStack_b8 = *(uint *)(iVar3 + iVar10 + -8);
          memw();
LAB_40120fb5:
          memw();
          goto LAB_40120e34;
        }
      } while (uVar7 != 0);
      uVar7 = iVar10 + 7U & 0xfffffff8;
      iVar10 = uVar7 + 8;
      iVar3 = iVar4;
      if ((0x18 < iVar10) && (iVar3 = iVar5, (int)uVar7 < 0x19)) {
        iVar10 = 0x28;
      }
      uStack_b4 = *(undefined4 *)(iVar3 + iVar10 + -4);
      uStack_b8 = *(uint *)(iVar3 + iVar10 + -8);
      uVar12 = 8;
      uVar11 = 0xe;
      memw();
LAB_40120e34:
      memw();
      iVar3 = FUN_401209a8(auStack_7c,&uStack_b9,uVar11,uVar12,&uStack_b8);
    }
LAB_40120e40:
    uStack_3c = uStack_b9;
    memw();
    memw();
    iVar10 = (*(code *)&SUB_40091660)(0);
    if (iVar10 != 0) {
      (*(code *)&SUB_4008bfd4)(auStack_3b,iVar10,0x10);
    }
    iVar10 = -1;
    if (_DAT_3ffc6d2c != (code *)0x0) {
      iVar10 = (*_DAT_3ffc6d2c)(&uStack_a0,0x78,_DAT_3ffc6d30);
    }
  } while( true );
}

