// Function : FUN_4018c9f0
// Address  : 0x4018c9f0
// Size     : 663 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4018c9f0(uint *param_1,ushort param_2,undefined4 param_3)

{
  ushort uVar1;
  bool bVar2;
  ushort uVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  uint uVar8;
  ushort *puVar9;
  char *pcVar10;
  uint uVar11;
  char cVar12;
  bool bVar13;
  
  puVar7 = *(uint **)(_DAT_3ffc06fc + 4);
  *(char *)puVar7 = (char)*puVar7 - DAT_3ffc072a;
  memw();
  memw();
  uVar5 = FUN_4018b754(puVar7);
  uVar8 = uVar5 & 0xffff;
  if (uVar8 == 0) {
    cVar12 = *(char *)((int)puVar7 + 0x1b);
  }
  else {
    cVar12 = *(char *)((int)puVar7 + 0x1b);
    pcVar10 = (char *)((int)puVar7 + (uVar5 & 0xffff) + 0x18);
    memw();
    iVar6 = FUN_40165300(puVar7 + 6,pcVar10);
    if (iVar6 == 2) {
      uVar8 = 0;
    }
    else if (iVar6 == 0) {
      cVar12 = pcVar10[3];
    }
  }
  if ((cVar12 != '\0') && (cVar12 != -0xb)) {
    if (((cVar12 == 'A') || (cVar12 == 'b')) &&
       ((DAT_3ffc072c != '\0' && ((_DAT_3ffc0730 & 8) != 0)))) {
      FUN_40165750(param_1,param_2 & 0xff);
    }
    goto LAB_4018ca7a;
  }
  puVar9 = (ushort *)((int)puVar7 + uVar8 + 0x1c);
  uVar5 = puVar7[1] & 0x8000000;
  uVar1 = *puVar9;
  puVar7[2] = puVar7[2] & 0xfff0ffff | (DAT_3ffc0728 & 0xf) << 0x10;
  memw();
  cVar4 = FUN_40189cfc();
  *(char *)(puVar7 + 2) = cVar4;
  memw();
  uVar8 = *puVar7;
  if ((DAT_3ffc072c == '\x01') && (uVar5 == 0)) {
    if ((int)uVar8 < 0) {
      memw();
      FUN_40165750(param_1,param_2 & 0xff,cVar12);
    }
LAB_4018cb21:
    uVar8 = *puVar7;
    uVar11 = 1;
    uVar3 = *puVar9;
    bVar13 = false;
    if ((uVar8 & 0x30000000) != 0) {
      if ((uVar1 & 0xf) == 4) {
        _DAT_3ffc7d04 = _DAT_3ffc7d04 + 1;
        if (((uVar1 & 0xf0) == 0x80) || ((uVar1 & 0xf0) == 0xa0)) {
LAB_4018cc82:
          bVar13 = true;
          uVar11 = 0;
        }
        else {
          memw();
          uVar11 = FUN_401659b8(uVar1,param_1,param_2);
          bVar13 = false;
        }
      }
      else if ((uVar1 & 0xf) == 8) {
        uVar11 = 0;
        bVar13 = (uVar1 & 0x70) == 0x40;
        _DAT_3ffc7cfc = _DAT_3ffc7cfc + 1;
        memw();
      }
      else {
        bVar13 = false;
        uVar11 = 1;
        if ((uVar1 & 0xf) == 0) {
          if ((uVar1 & 0xf0) == 0x40) {
            *puVar7 = uVar8 & 0xefffffff | 0x20000000;
            memw();
            iVar6 = FUN_4018ba60();
            if ((iVar6 != 0) && (_DAT_3ffc7914 != (code *)0x0)) {
              (*_DAT_3ffc7914)(puVar9,puVar7[6] & 0xfff,(int)(char)*puVar7);
            }
          }
          else if ((uVar1 & 0xf0) == 0x80) {
            *puVar7 = uVar8 & 0xdfffffff | 0x10000000;
          }
          _DAT_3ffc7d00 = _DAT_3ffc7d00 + 1;
          memw();
          goto LAB_4018cc82;
        }
      }
    }
    if ((uVar3 & 0x400) != 0) {
      bVar13 = false;
    }
LAB_4018cbfe:
    memw();
    iVar6 = FUN_4018ba60(1);
    if ((iVar6 == 0) || ((*puVar7 & 0x20000000) == 0)) {
      memw();
      iVar6 = FUN_4018ba60(0);
      if ((iVar6 == 0) || ((*puVar7 & 0x10000000) == 0)) goto LAB_4018ca7a;
    }
  }
  else {
    if (uVar5 == 0) goto LAB_4018cb21;
    uVar11 = (uint)((uVar8 & 0x30000000) == 0);
    bVar2 = false;
    if ((DAT_3ffc072c == '\x01') && ((uVar8 & 0x80000000) != 0)) {
      uVar11 = 0;
      bVar2 = true;
    }
    bVar13 = false;
    _DAT_3ffc7cf8 = _DAT_3ffc7cf8 + 1;
    if (!bVar2) {
      memw();
      goto LAB_4018cbfe;
    }
  }
  if (uVar11 == 0) {
    memw();
    if ((*param_1 >> 0xc & 0xfff) == 0) {
      memw();
      FUN_40147fe4(6,0x800,1," %s %u\n","duSched","DataAll",0x65c);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    if (uVar5 == 0) {
      FUN_4018c75c(bVar13,0,param_1,param_2,param_3);
      return;
    }
    FUN_4018ae98(param_1,param_2,param_3);
    return;
  }
LAB_4018ca7a:
  FUN_4018b770(param_1,param_2);
  return;
}

