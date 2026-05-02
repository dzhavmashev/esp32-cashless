// Function : FUN_4010c1b0
// Address  : 0x4010c1b0
// Size     : 352 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4010c1b0(int param_1)

{
  byte bVar1;
  uint *puVar2;
  int iVar3;
  byte *pbVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  int iVar12;
  int in_t0;
  
  iVar9 = 0;
  if (DAT_3ffc83f8 != 6) {
    iVar9 = (*(code *)&LAB_40185492_2)(_DAT_3ffc83e4,_DAT_3ffc83b8);
  }
  pbVar4 = *(byte **)(param_1 + 4);
  if (*pbVar4 >> 4 == 6) {
    bVar1 = pbVar4[6];
  }
  else {
    bVar1 = pbVar4[9];
  }
  uVar10 = 0;
  uVar11 = 0x2e;
  puVar2 = _DAT_3ffc6330;
  puVar6 = (uint *)0x0;
  do {
    puVar5 = puVar2;
    if (puVar5 == (uint *)0x0) {
LAB_4010c2a0:
      memw();
      return uVar10;
    }
    if (((byte)puVar5[0xe] == bVar1) &&
       (((char)puVar5[0xc] == '\0' ||
        ((char)puVar5[0xc] == (char)(*(char *)(_DAT_3ffc83bc + 0xee) + '\x01'))))) {
      if ((byte)puVar5[5] == uVar11) goto LAB_4010c225;
      if ((uint)DAT_3ffc83f8 == (uint)(byte)puVar5[5]) {
        uVar7 = *puVar5;
        if (iVar9 == 0) {
          if (DAT_3ffc83f8 == 6) {
            if ((((uVar7 != 0) || (puVar5[1] != 0)) || (puVar5[2] != 0)) || (puVar5[3] != 0)) {
              if (((_DAT_3ffc83e4 != uVar7) || (puVar5[1] != _DAT_3ffc83e8)) ||
                 ((puVar5[2] != _DAT_3ffc83ec || (puVar5[3] != _DAT_3ffc83f0)))) goto LAB_4010c2e8;
              uVar7 = (uint)DAT_3ffc83f4;
              uVar8 = (uint)(byte)puVar5[4];
LAB_4010c2e2:
              if (uVar7 != uVar8) goto LAB_4010c2e8;
            }
          }
          else {
            uVar8 = _DAT_3ffc83e4;
            if (uVar7 != 0) goto LAB_4010c2e2;
          }
LAB_4010c225:
          if ((*(byte *)((int)puVar5 + 0x39) & 1) == 0) {
LAB_4010c26c:
            if ((code *)puVar5[0xf] != (code *)0x0) {
              iVar12 = *(int *)(param_1 + 4);
              memw();
              iVar3 = (*(code *)puVar5[0xf])(puVar5[0x10],puVar5,param_1,&DAT_3ffc83cc);
              if (iVar3 != 0) {
                uVar10 = 1;
                if (puVar6 != (uint *)0x0) {
                  puVar6[0xd] = puVar5[0xd];
                  puVar5[0xd] = (uint)_DAT_3ffc6330;
                  _DAT_3ffc6330 = puVar5;
                }
                goto LAB_4010c2a0;
              }
              if (*(int *)(param_1 + 4) != iVar12) {
                iVar9 = in_t0;
                (*(code *)&SUB_40094c54)(" packet",0xc1,"_if_src","f_alloc");
                in_t0 = iVar9;
              }
              uVar10 = 2;
            }
          }
          else if (DAT_3ffc83e0 == (char)puVar5[0xb]) {
            uVar8 = puVar5[6];
            uVar7 = _DAT_3ffc83cc;
            if (DAT_3ffc83e0 == '\x06') {
              if (((_DAT_3ffc83cc != uVar8) || (puVar5[7] != _DAT_3ffc83d0)) ||
                 ((puVar5[8] != _DAT_3ffc83d4 || (puVar5[9] != _DAT_3ffc83d8)))) goto LAB_4010c2e8;
              uVar7 = (uint)(byte)puVar5[10];
              uVar8 = (uint)DAT_3ffc83dc;
            }
            if (uVar7 == uVar8) goto LAB_4010c26c;
          }
        }
        else if (uVar7 == 0) goto LAB_4010c225;
      }
    }
LAB_4010c2e8:
    puVar2 = (uint *)puVar5[0xd];
    puVar6 = puVar5;
  } while( true );
}

