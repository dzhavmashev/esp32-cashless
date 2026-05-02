// Function : FUN_40158a34
// Address  : 0x40158a34
// Size     : 1404 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40158a34(int *param_1,int param_2,uint param_3,undefined4 param_4,undefined4 param_5)

{
  byte bVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  int iVar9;
  int iVar10;
  byte *pbVar11;
  byte *pbVar12;
  byte *pbVar13;
  undefined4 uVar14;
  byte *local_60;
  byte *pbStack_5c;
  byte *pbStack_58;
  byte *pbStack_54;
  byte *pbStack_50;
  byte *pbStack_4c;
  byte *pbStack_3c;
  byte *pbStack_38;
  
  if ((param_1 == (int *)0x0) || (iVar9 = *param_1, iVar9 == 0)) {
    memw();
    FUN_40147fe4(1,0x800,1,"0 (TUs)","om user",0x99a);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  uVar6 = (uint)*(ushort *)(param_2 + 0x1a);
  pbVar13 = (byte *)(param_2 + 0x1e);
  if (uVar6 != 0) {
    if ((((uVar6 != 0x1e) || (iVar5 = FUN_401869ec(0x38,pbVar13,param_3 - (int)pbVar13), iVar5 == 0)
         ) || (param_3 < iVar5 + 7U)) ||
       ((*(char *)(iVar5 + 2) != '\x03' || (*(uint *)(iVar5 + 3) == 0)))) {
      FUN_40147fe4(1,4,1,"A Q req");
      FUN_40157594(&DAT_3ffc87f0,0,uVar6 << 8 | 0x10);
      iVar5 = FUN_40186978();
      if (iVar5 != 0) {
        iVar9 = iVar9 + 4;
        (**(code **)(_DAT_3ffc1a34 + 0xec))(iVar9);
        (**(code **)(_DAT_3ffc1a34 + 0xf0))(iVar9);
        (**(code **)(_DAT_3ffc1a34 + 0xf4))(iVar9,0x4015b8d8,0);
        (**(code **)(_DAT_3ffc1a34 + 0xe8))(iVar9,1000,0);
      }
      return 0xff;
    }
    if (*(uint *)(iVar5 + 3) < 0x1389) {
      FUN_40147fe4(1,4,3,0x3f435015);
      iVar10 = iVar9 + 0x54;
      (**(code **)(_DAT_3ffc1a34 + 0xec))(iVar9 + 4);
      (**(code **)(_DAT_3ffc1a34 + 0xf0))(iVar9 + 4);
      (**(code **)(_DAT_3ffc1a34 + 0xec))(iVar10);
      (**(code **)(_DAT_3ffc1a34 + 0xf0))(iVar10);
      (**(code **)(_DAT_3ffc1a34 + 0xf4))(iVar10,&LAB_40157474,0);
      (**(code **)(_DAT_3ffc1a34 + 0xf8))(iVar10,(uint)*(uint3 *)(iVar5 + 3) << 10,0);
      return 0;
    }
    FUN_40147fe4(1,4,1,"to INIT");
    uVar14 = 0;
    param_4 = 0xd010;
    goto LAB_40158f71;
  }
  uVar2 = *(undefined2 *)(param_2 + 0x18);
  uVar3 = *(undefined2 *)(param_2 + 0x1c);
  memw();
  local_60 = (byte *)0x0;
  pbStack_5c = (byte *)0x0;
  pbStack_58 = (byte *)0x0;
  pbStack_54 = (byte *)0x0;
  pbStack_50 = (byte *)0x0;
  pbStack_4c = (byte *)0x0;
  pbStack_3c = (byte *)0x0;
  pbStack_38 = (byte *)0x0;
  pbVar8 = (byte *)0x0;
  pbVar12 = (byte *)0x0;
  for (; 1 < (int)(param_3 - (int)pbVar13); pbVar13 = pbVar13 + pbVar13[1] + 2) {
    uVar6 = (uint)pbVar13[1];
    if ((int)(param_3 - (int)pbVar13) <= (int)(uVar6 + 1)) {
      return 0xff;
    }
    bVar1 = *pbVar13;
    pbVar7 = pbVar8;
    pbVar11 = pbVar12;
    pbVar4 = pbStack_38;
    if (bVar1 == 0x3d) {
      memw();
      pbStack_5c = pbVar13;
    }
    else if (bVar1 < 0x3e) {
      pbVar11 = pbVar13;
      if (bVar1 != 0x2d) {
        if (bVar1 == 0x32) {
          memw();
          pbVar11 = pbVar12;
          pbStack_58 = pbVar13;
        }
        else {
          if (bVar1 == 1) {
            local_60 = pbVar13;
          }
          memw();
          pbVar11 = pbVar12;
        }
      }
    }
    else {
      pbVar7 = pbVar13;
      if (bVar1 != 0x7f) {
        if (bVar1 == 0xdd) {
          if ((uVar6 < 4) || (*(int *)(pbVar13 + 2) != 0x2f25000)) {
            if ((_DAT_3ffc8874 == 0) || ((uVar6 < 4 || (*(int *)(pbVar13 + 2) != 0x734fe18)))) {
              if ((*(uint *)(iVar9 + 0x158) & 0x10000000) == 0) {
                if (_DAT_3ffc8864 != 0) {
                  memw();
                  iVar5 = (*_DAT_3ffc79b0)(pbVar13,param_2 + 10);
                  if (iVar5 == 0) {
                    iVar5 = (*_DAT_3ffc79f4)(pbVar13);
                    if (iVar5 == 0) {
                      iVar5 = (*_DAT_3ffc79f8)(pbVar13);
                      pbVar7 = pbVar8;
                      pbVar4 = pbVar13;
                      if (iVar5 == 0) {
                        iVar5 = (*_DAT_3ffc7a10)(pbVar13);
                        if (iVar5 != 0) {
                          pbStack_50 = pbVar13;
                        }
                        memw();
                        pbVar4 = pbStack_38;
                      }
                    }
                    else {
                      memw();
                      pbVar7 = pbVar8;
                      pbStack_3c = pbVar13;
                    }
                    goto LAB_40158da8;
                  }
                }
                pbVar7 = pbVar8;
                if (3 < pbVar13[1]) {
                  if (*(uint *)(pbVar13 + 2) == 0xdd34fe18) {
                    if (_DAT_3ffc888c != (code *)0x0) {
                      (*_DAT_3ffc888c)(4,param_2 + 10,pbVar13 + 7,pbVar13 + 10,pbVar13[1] - 8,
                                       param_5);
                    }
                  }
                  else if (((*(uint *)(pbVar13 + 2) & 0xffffff) != 0x34fe18) &&
                          (_DAT_3ffc88b8 != (code *)0x0)) {
                    (*_DAT_3ffc88b8)(_DAT_3ffc88bc,4,param_2 + 10,pbVar13,param_5);
                  }
                }
              }
              else {
                pbVar7 = pbVar8;
                if (3 < uVar6) {
                  if (*(int *)(pbVar13 + 2) == 0x334c9000) {
                    if (pbVar12 == (byte *)0x0) {
                      pbVar11 = pbVar13;
                    }
                  }
                  else if ((pbStack_5c == (byte *)0x0) && (*(int *)(pbVar13 + 2) == 0x344c9000)) {
                    pbVar11 = pbVar13;
                  }
                }
              }
            }
            else {
              memw();
              FUN_4014c768(param_1,pbVar13 + 7,0);
              iVar5 = FUN_40186948(param_1);
              pbVar7 = pbVar8;
              if (iVar5 != 0) {
                FUN_4014c68c(param_1,0);
              }
            }
          }
          else {
            memw();
            pbVar7 = pbVar8;
            pbStack_54 = pbVar13;
          }
        }
        else {
          if (bVar1 == 0x4a) {
            pbStack_4c = pbVar13;
          }
          memw();
          pbVar7 = pbVar8;
        }
      }
    }
LAB_40158da8:
    pbStack_38 = pbVar4;
    pbVar8 = pbVar7;
    pbVar12 = pbVar11;
  }
  if (local_60 == (byte *)0x0) {
    return 0xff;
  }
  if (0xf < local_60[1]) {
    return 0xff;
  }
  if ((pbStack_58 != (byte *)0x0) && ((int)(0xf - (uint)local_60[1]) < (int)(uint)pbStack_58[1])) {
    return 0xff;
  }
  memw();
  FUN_4014c490(param_1,local_60,pbStack_58,0x2f);
  *(undefined2 *)((int)param_1 + 0x2a) = uVar2;
  memw();
  iVar5 = *(int *)(iVar9 + 0xac);
  *(undefined2 *)((int)param_1 + 0x26) = uVar3;
  memw();
  if (iVar5 == 0) {
    if (((DAT_3ffc1a44 == '\0') || (memw(), DAT_3ffc1a3c != '\0')) || (_DAT_3ffc1a40 == 0)) {
      memw();
      iVar5 = _DAT_3ff73c00 + _DAT_3ffc1a30;
    }
    else {
      memw();
      iVar5 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
    }
    *(int *)(iVar9 + 0xac) = iVar5;
  }
  if (((*(uint *)(iVar9 + 0xa4) & 0x2000) == 0) || (pbStack_54 == (byte *)0x0)) {
LAB_40158e78:
    param_1[3] = param_1[3] & 0xfffffffd;
  }
  else {
    memw();
    iVar5 = FUN_4015868c(param_1,pbStack_54);
    if (iVar5 < 0) goto LAB_40158e78;
    param_1[3] = param_1[3] | 2;
    memw();
    FUN_40154c20(param_1,(int)param_1 + 0x87);
  }
  if (((pbVar12 != (byte *)0x0) && (pbStack_5c != (byte *)0x0)) &&
     ((*(uint *)(iVar9 + 0x158) & 0x80000) != 0)) {
    memw();
    FUN_4014b470(param_1);
    FUN_4014ba40(param_1,pbVar12,pbStack_5c);
    FUN_4014bbe4(param_1,pbVar12,0x30);
    FUN_4014bca4(param_1,pbStack_5c);
  }
  if (_DAT_3ffc8864 != 0) {
    param_2 = param_2 + 10;
    (*_DAT_3ffc79ac)(param_4,param_2,pbStack_3c,param_5);
    (*_DAT_3ffc79bc)(param_2,pbStack_38);
    (*_DAT_3ffc79c0)(param_4,param_2,pbStack_50,0);
  }
  if ((_DAT_3ffc8a2c & 1) != 0) {
    param_1[0xba] = 0;
    if ((pbVar8 != (byte *)0x0) && ((pbVar8[2] & 1) != 0)) {
      param_1[0xba] = 1;
      memw();
      FUN_40147fe4(1,4,4,0x3f433c0c);
    }
    FUN_40158968(param_1,pbStack_4c);
  }
  FUN_401869d0(&DAT_3ffc87f0,*(ushort *)((int)param_1 + 0x2a) & 0x400);
  if (((byte)(*(char *)((int)param_1 + 0x32) - 2U) < 2) && ((*(ushort *)(param_1 + 0xb) & 2) != 0))
  {
    _DAT_3ffc880c = _DAT_3ffc880c | 0x100000;
  }
  else {
    _DAT_3ffc880c = _DAT_3ffc880c & 0xffefffff;
  }
  *(int **)(_DAT_3ffc87f0 + 0xec0) = param_1;
  memw();
  FUN_40147fe4(1,0xc,4,0x3f433bf3,6);
  FUN_4015a448(6);
  uVar14 = 5;
LAB_40158f71:
  FUN_40157594(&DAT_3ffc87f0,uVar14,param_4);
  return 0;
}

