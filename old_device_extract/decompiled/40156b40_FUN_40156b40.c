// Function : FUN_40156b40
// Address  : 0x40156b40
// Size     : 2064 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40156b40(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char cVar8;
  uint *puVar9;
  undefined4 uVar10;
  int aiStack_70 [8];
  uint uStack_50;
  int iStack_4c;
  int iStack_48;
  uint uStack_44;
  uint uStack_40;
  int iStack_3c;
  int iStack_38;
  uint *puStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  
  uStack_44 = param_3 & 0xff;
  uStack_50 = (uint)*(byte *)(*(int *)(param_1 + 0x2c) + 8);
  iStack_38 = _DAT_3ffc8800;
  cVar8 = **(char **)(param_1 + 0x10);
  uStack_40 = *(uint *)(*(char **)(param_1 + 0x10) + 0x14) >> 0x1f;
  iVar5 = *(int *)(*(int *)(param_1 + 4) + 4);
  memw();
  iStack_48 = FUN_4015b24c(uStack_50);
  if (iStack_48 == 0) {
    memw();
    FUN_40147fe4(1,0x800,1,"",&DAT_3f424014,0x635);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  bVar4 = *(byte *)(param_2 + 4);
  uVar1 = FUN_40155040();
  if ((bVar4 < uVar1) ||
     (bVar4 = *(byte *)(param_2 + 4), uVar1 = FUN_40155000(), puVar9 = _DAT_3ffbfd50, uVar1 < bVar4)
     ) {
    FUN_40147fe4(1,8,4,0x3f4339a2,*(undefined1 *)(param_2 + 4));
    return -1;
  }
  if ((*(char *)((int)_DAT_3ffbfd50 + 0xa3) == '\0') &&
     ((*(char *)(*(int *)(param_2 + 0x24) + 1) == '\0' ||
      (*(char *)(*(int *)(param_2 + 0x24) + 2) == '\0')))) {
    if (iStack_38 == 0) {
      return 0;
    }
    if (*(int *)(iStack_38 + 0xe4) == 0) {
      return 0;
    }
    iVar5 = (*(code *)&SUB_4008b33c)(*(int *)(iStack_38 + 0xe4) + 4,iVar5 + 0x10,6);
    if (iVar5 != 0) {
      return 0;
    }
    iStack_3c = 1;
    memw();
  }
  else {
    iStack_3c = 0;
  }
  if (uStack_50 != *(byte *)(param_2 + 4)) {
    if (_DAT_3ffc8864 == 0) {
      memw();
      return -1;
    }
    if (((*(byte *)((int)puVar9 + 0x46) & 1) != 0) && ((*puVar9 & 0x8000) == 0)) {
      iVar5 = FUN_4015b24c();
      if (iVar5 != 0) {
        return -1;
      }
      FUN_40147fe4(1,0x800,1,"",&DAT_3f424014,0x64c);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    iVar5 = FUN_4015a384();
    if (iVar5 == 0) {
      return -1;
    }
    if (*(char *)(_DAT_3ffbfc54 + 0x92) == '\0') {
      return -1;
    }
    iVar5 = (*(code *)&SUB_4008b33c)
                      (_DAT_3ffbfc54 + 0x93,*(int *)(*(int *)(param_1 + 4) + 4) + 0x10,6);
    return -(uint)(iVar5 != 0);
  }
  if ((*(byte *)((int)puVar9 + 0x46) & 1) != 0) {
    (**(code **)(_DAT_3ffc1a34 + 0xec))(_DAT_3ffbfdf0 + 0x24);
  }
  iVar5 = *(int *)(*(int *)(param_1 + 4) + 4);
  if ((uStack_44 == 0) && ((_DAT_3ffc8a2c & 1) != 0)) {
    FUN_40156a8c(param_2);
  }
  iVar6 = *(int *)(param_2 + 0x78);
  bVar4 = 0;
  if ((iVar6 != 0) && (bVar4 = 0, 8 < *(byte *)(iVar6 + 1))) {
    bVar4 = *(byte *)(iVar6 + 10) >> 6 & 1;
  }
  iStack_4c = (int)cVar8;
  iVar6 = 0;
  if (((*(byte *)((int)_DAT_3ffbfd50 + 0x46) & 1) != 0) && ((char)_DAT_3ffbfd50[0x26] == '\0')) {
    iStack_30 = iVar5 + 10;
    puStack_34 = _DAT_3ffbfd50;
    memw();
    iVar2 = FUN_401569d8(iStack_30);
    iVar6 = 0;
    if (iVar2 == 0) {
      cVar8 = *(char *)((int)puStack_34 + 0xa2);
      if (*(char *)((int)puStack_34 + 0x99) == '\x01') {
        iVar7 = *(int *)(param_2 + 0x24);
        iVar6 = iVar2;
        if (cVar8 == '\x01') {
          if (puStack_34[0x1d] == (uint)*(byte *)(iVar7 + 1)) {
            memw();
            iStack_28 = iVar2;
            iVar2 = (*(code *)&SUB_4008c080)(puStack_34 + 0x1e,iVar7 + 2);
            iVar6 = iStack_28;
            if (iVar2 == 0) {
              iVar2 = (*(code *)&SUB_4008b33c)(puStack_34 + 0x27,iStack_30,6);
              iVar6 = 0;
              if (iVar2 == 0) {
                memw();
                FUN_40155d28(iVar5,param_2,iStack_4c,(int)*(short *)(param_1 + 0x18),
                             *(undefined2 *)(iStack_48 + 2),uStack_40,bVar4);
                FUN_40147fe4(1,8,5,0x3f435da3);
                if ((*_DAT_3ffbfd50 & 0x400) != 0) {
                  *(byte *)((int)_DAT_3ffbfd50 + 0x46) = *(byte *)((int)_DAT_3ffbfd50 + 0x46) | 4;
                  memw();
                  uVar10 = 0x3f435d90;
                  memw();
                  goto LAB_40156e72;
                }
                goto LAB_40156e78;
              }
            }
          }
        }
        else if (puStack_34[0x1d] == (uint)*(byte *)(iVar7 + 1)) {
          memw();
          iStack_28 = iVar2;
          iVar2 = (*(code *)&SUB_4008c080)(puStack_34 + 0x1e,iVar7 + 2);
          iVar6 = iStack_28;
          if (iVar2 == 0) {
            memw();
            FUN_40155d28(iVar5,param_2,iStack_4c,(int)*(short *)(param_1 + 0x18),
                         *(undefined2 *)(iStack_48 + 2),uStack_40,bVar4);
            FUN_40147fe4(1,8,5,0x3f435d78);
            if ((*_DAT_3ffbfd50 & 0x400) != 0) {
              *(byte *)((int)_DAT_3ffbfd50 + 0x46) = *(byte *)((int)_DAT_3ffbfd50 + 0x46) | 4;
              memw();
              uVar10 = 0x3f435d65;
              memw();
              cVar8 = '\x01';
              goto LAB_40156e72;
            }
            goto LAB_40156e78;
          }
        }
      }
      else {
        if (cVar8 == '\x01') {
          memw();
          iStack_28 = iVar2;
          iVar2 = (*(code *)&SUB_4008b33c)(puStack_34 + 0x27,iStack_30,6);
          iVar6 = iStack_28;
          if (iVar2 != 0) goto LAB_40156eaa;
          memw();
          FUN_40155d28(iVar5,param_2,iStack_4c,(int)*(short *)(param_1 + 0x18),
                       *(undefined2 *)(iStack_48 + 2),uStack_40,bVar4);
          FUN_40147fe4(1,8,5,0x3f435d52);
          if ((*_DAT_3ffbfd50 & 0x400) != 0) {
            uVar10 = 0x3f435d3f;
            *(byte *)((int)_DAT_3ffbfd50 + 0x46) = *(byte *)((int)_DAT_3ffbfd50 + 0x46) | 4;
            memw();
LAB_40156e72:
            memw();
            FUN_40147fe4(cVar8,8,5,uVar10);
          }
LAB_40156e78:
          FUN_40155820(_DAT_3ffbfd50 + 0x1e,uStack_50,*(undefined1 *)(*(int *)(param_2 + 0x24) + 1),
                       bVar4);
        }
        else {
          memw();
          FUN_40155d28(iVar5,param_2,iStack_4c,(int)*(short *)(param_1 + 0x18),
                       *(undefined2 *)(iStack_48 + 2),uStack_40,bVar4);
        }
        iVar6 = 1;
      }
    }
  }
LAB_40156eaa:
  if (((_DAT_3ffc89ac != (int *)0x0) && (*_DAT_3ffc89ac != 0)) && (*(int *)(_DAT_3ffca40c + 4) != 0)
     ) {
    memw();
    iStack_2c = iVar6;
    FUN_40186a44(param_2,aiStack_70);
    (*(code *)*_DAT_3ffc89ac)(aiStack_70);
    iVar6 = iStack_2c;
  }
  if ((*(int *)(_DAT_3ffc89a4 + 0x50) != 0) && (iVar6 != 0)) {
    FUN_401552e8(param_1,uStack_44);
  }
  iVar6 = _DAT_3ffbfc54;
  if (*(uint *)(_DAT_3ffbfc54 + 4) + 1 < 2) {
    FUN_40147fe4(1,8,5,0x3f435d2c);
    return 0;
  }
  if ((char)_DAT_3ffbfd50[0x11] == '\x03') {
    return 0;
  }
  if ((((iStack_3c != 0) ||
       (*(uint *)(_DAT_3ffbfc54 + 4) != (uint)*(byte *)(*(int *)(param_2 + 0x24) + 1))) ||
      (iVar2 = (*(code *)&SUB_4008b33c)(_DAT_3ffbfc54 + 8,*(int *)(param_2 + 0x24) + 2), iVar2 != 0)
      ) && ((*(char *)(iVar6 + 0x92) == '\0' ||
            (iVar6 = (*(code *)&SUB_4008b33c)(iVar6 + 0x93,iVar5 + 0x10,6), iVar6 != 0)))) {
    if (iStack_3c == 0) {
      return 0;
    }
    iVar6 = (*(code *)&SUB_4008b33c)(*(int *)(iStack_38 + 0xe4) + 4,iVar5 + 0x10,6);
    if (iVar6 != 0) {
      return 0;
    }
  }
  if ((*(byte *)(_DAT_3ffc8800 + 0x154) & 0xfb) != 1) {
    return 0;
  }
  pcVar3 = (char *)FUN_4015a07c();
  if ((((*pcVar3 != '\0') || (_DAT_3ffc89a8 != 0)) && ((*(ushort *)(param_2 + 6) & 0x10) == 0)) &&
     (uVar10 = 0x3f433975, _DAT_3ffc8864 == 0)) goto LAB_40157361;
  if (*(char *)(_DAT_3ffc8800 + 0x154) == '\x05') {
    iVar6 = *(int *)(_DAT_3ffc8800 + 0xe4);
    if (iVar6 == 0) goto LAB_40157355;
    if (1 < (byte)(DAT_3ffc89ed - 0xbU)) {
      if (*(int *)(param_2 + 0x3c) == 0) {
        if (*(char *)(iVar6 + 0x341) == '\0') {
LAB_40156fe4:
          if (*(int *)(param_2 + 0x34) == 0) {
            if (*(char *)(iVar6 + 0x30) == '\0') {
LAB_40157000:
              if (*(int *)(param_2 + 0x80) == 0) {
                if (*(char *)(iVar6 + 0x32d) != '\0') goto LAB_40157355;
              }
              else if ((*(char *)(iVar6 + 0x32d) == '\0') ||
                      (*(char *)(*(int *)(param_2 + 0x80) + 2) != *(char *)(iVar6 + 0x32e)))
              goto LAB_40157355;
              goto LAB_40157023;
            }
          }
          else if ((*(char *)(iVar6 + 0x30) != '\0') &&
                  (iVar2 = (*(code *)&SUB_4008b33c)(*(int *)(param_2 + 0x34),iVar6 + 0x33),
                  iVar2 == 0)) goto LAB_40157000;
        }
      }
      else if ((*(char *)(iVar6 + 0x341) != '\0') &&
              (iVar2 = (*(code *)&SUB_4008b33c)(*(int *)(param_2 + 0x3c),iVar6 + 0x342), iVar2 == 0)
              ) goto LAB_40156fe4;
LAB_40157355:
      uVar10 = 0x3f43394c;
      goto LAB_40157361;
    }
  }
LAB_40157023:
  iVar7 = iVar5 + 0x10;
  iVar2 = FUN_4015c820(iVar7);
  iVar6 = FUN_40155e78(iVar5,param_2,uStack_44);
  if ((iVar6 != 0) && (*(int *)(_DAT_3ffc89a4 + 0x58) != 0)) {
    puVar9 = (uint *)&DAT_3ffc87f0;
    if ((*(int *)(_DAT_3ffc89a4 + 0x50) != 0) && (*(char *)(_DAT_3ffc8800 + 0x154) != '\x05')) {
      puStack_34 = (uint *)&DAT_3ffc87f0;
      memw();
      FUN_401552e8(param_1,uStack_44);
      puVar9 = puStack_34;
    }
    iVar6 = (**(code **)(puVar9[0x6d] + 0x58))(iVar7);
  }
  if ((*(char *)(_DAT_3ffbfc54 + 0x499) == '\x01') && (*(int *)(param_2 + 0x80) == 0)) {
    if ((byte)(*(char *)(param_2 + 0x7c) - 6U) < 2) {
      uVar10 = 0x3f433915;
LAB_40157361:
      FUN_40147fe4(1,4,4,uVar10);
      return -1;
    }
    puStack_34 = (uint *)&DAT_3ffbfc54;
    memw();
    iStack_30 = *(int *)(param_2 + 0x80);
    iStack_2c = iVar6;
    FUN_40147fe4(1,4,4,0x3f4338d9);
    *(char *)(*puStack_34 + 0x499) = (char)iStack_30;
    memw();
    iVar6 = iStack_2c;
  }
  if (iVar6 == 0) {
    *(byte *)((int)_DAT_3ffbfd50 + 0x46) = *(byte *)((int)_DAT_3ffbfd50 + 0x46) & 0xfb;
    memw();
    if (iVar2 == 0) {
      return 0;
    }
    if (_DAT_3ffc8864 != 0) {
      return 0;
    }
    *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) & 0xfffffffb;
    memw();
    return 0;
  }
  if (iVar2 != 0) {
    *(char *)(iVar2 + 0xab) = (char)uStack_50;
    memw();
    memw();
    FUN_4015d474(iVar2,iStack_4c,2);
    if (((*(char *)(_DAT_3ffc8800 + 0x154) == '\x05') && (_DAT_3ffc8a54 != 0)) &&
       (*(char *)(iVar2 + 0xa4) < _DAT_3ffc8a54)) {
      _DAT_3ffc8a54 = 0;
      memw();
      aiStack_70[0] = (int)*(char *)(iVar2 + 0xa4);
      FUN_40147240(0x12,aiStack_70,4);
    }
    FUN_4015d4e8(iVar2,6,1);
    FUN_40186aa4(iVar2,5,0);
    iVar5 = *(int *)(param_2 + 0x18);
    if (iVar5 != 0) {
      *(undefined1 *)(iVar2 + 0x2f) = *(undefined1 *)(iVar5 + 2);
      memw();
      *(undefined1 *)(iVar2 + 0x2e) = *(undefined1 *)(iVar5 + 3);
      memw();
    }
    *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(*(int *)(param_1 + 0x2c) + 4);
    memw();
    FUN_4015d904(iVar2,param_2,uStack_44);
    goto LAB_40157291;
  }
  memw();
  iVar2 = FUN_4015d158(iVar7,iStack_4c,*(undefined1 *)(param_2 + 0x7c));
  if (iVar2 == 0) {
    return -1;
  }
  FUN_4015c3d8(iVar2,_DAT_3ffc8800);
  iStack_28 = iVar2 + 0x200;
  *(undefined1 *)(iVar2 + 0x2f6) = 0;
  *(byte *)(iVar2 + 0x2f8) = bVar4;
  memw();
  iStack_2c = 0;
  memw();
  FUN_4015d474(iVar2,iStack_4c,2);
  FUN_4015d4e8(iVar2,10,0);
  FUN_40186aa4(iVar2,5,0);
  FUN_4015d590(iVar2,param_2,iVar5);
  FUN_4014cf74(iVar2,*(undefined1 *)(param_2 + 0x7d),*(undefined1 *)(param_2 + 0x7e));
  *(char *)(iVar2 + 0xab) = (char)uStack_50;
  memw();
  *(char *)(iVar2 + 0xac) = (char)iStack_2c;
  memw();
  *(undefined1 *)(iStack_28 + 0x8b) = *(undefined1 *)(param_2 + 0x7c);
  memw();
  *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(*(int *)(param_1 + 0x2c) + 4);
  memw();
  FUN_4015d904(iVar2,param_2,uStack_44);
  *(bool *)(iStack_28 + 0x8a) = *(char *)(param_2 + 0x70) != '\0';
  memw();
  if ((_DAT_3ffc8864 == 0) || (memw(), DAT_3ffc1a3c != '\0')) {
LAB_401571a9:
    FUN_4015c860(iVar2);
  }
  else {
    if (*(int *)(param_2 + 0x54) != 0) {
      memw();
      goto LAB_401571a9;
    }
    FUN_40147270(0x1f,0,0);
  }
  memw();
  FUN_40155a54(0x3ffc88c0,iVar5,param_2,iStack_4c,(int)*(short *)(param_1 + 0x18),
               *(undefined2 *)(iStack_48 + 2),uStack_40);
  if ((*(char *)(_DAT_3ffbfc54 + 0x35c) == '\0') && ((char)_DAT_3ffbfd50[0x11] == '\x02')) {
    (**(code **)(_DAT_3ffc1a34 + 0xec))(_DAT_3ffbfdf0 + 0x38);
    (**(code **)(_DAT_3ffc1a34 + 0xe8))(_DAT_3ffbfdf0 + 0x38,0,0);
  }
LAB_40157291:
  if ((*(char *)(_DAT_3ffbfc54 + 0x92) != '\0') &&
     (iVar5 = (*(code *)&SUB_4008b33c)(_DAT_3ffbfc54 + 0x93,iVar7,6), iVar5 == 0)) {
    *(byte *)((int)_DAT_3ffbfd50 + 0x46) = *(byte *)((int)_DAT_3ffbfd50 + 0x46) | 4;
    memw();
    memw();
    FUN_40147fe4(1,8,4,0x3f4338be);
  }
  if ((*_DAT_3ffbfd50 & 0x400) != 0) {
    *(byte *)((int)_DAT_3ffbfd50 + 0x46) = *(byte *)((int)_DAT_3ffbfd50 + 0x46) | 4;
    memw();
    memw();
    FUN_40147fe4(1,8,4,0x3f4338a1);
  }
  iVar5 = _DAT_3ffbfc54;
  *(byte *)(iVar2 + 10) = *(byte *)(iVar2 + 10) | 4;
  memw();
  memw();
  FUN_40155820(iVar5 + 8,uStack_50,*(undefined1 *)(iVar5 + 4),bVar4);
  return 0;
}

